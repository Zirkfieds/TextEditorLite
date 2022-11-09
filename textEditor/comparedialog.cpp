#include "comparedialog.h"
#include "ui_comparedialog.h"

compareDialog::compareDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::compareDialog) {

    ui->setupUi(this);

    simResult = 0.0;

    setAttribute(Qt::WA_QuitOnClose,false);

    srcOpened = false; strOpened = false;

    connect(ui->openSrcFile, &QPushButton::clicked, this, &compareDialog::openSrcFile);
    connect(ui->openSrcCur, &QPushButton::clicked, this, &compareDialog::openCurAsSrc);
    connect(ui->openStrFile, &QPushButton::clicked, this, &compareDialog::openStrFile);

    connect(ui->cmpMethod1, &QPushButton::clicked, this, &compareDialog::cmpInDistanceMethod);
    connect(ui->cmpMethod2, &QPushButton::clicked, this, &compareDialog::cmpInCosineMethod);
    connect(ui->cmpMethodHelp, &QPushButton::clicked, this, &compareDialog::aboutCmpMethods);

    c.loadImgs();
    c.loadText();

    return;
}

void compareDialog::updateCurTextContent(string& content) {

    this->curTextContent = content;

    return;
}

void compareDialog::openSrcFile() {

    string fpath;
    QString fileName = QFileDialog::getOpenFileName(NULL,"Selected a file to open: ",".","*.txt *.data *.c *.cpp *.java *.py");
    fpath = fileName.toStdString();

    if (fpath.empty()) {
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Warning);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("No file(s) selected. Failed to open.");
        warningNoFilesSelected.exec();
        ui->srcFilePath->clear();

        return;
    }

    this->srcFilePath = fpath;
    ifstream srcFile(srcFilePath);
    string s;
    srcTextContent.clear();
    while (getline(srcFile, s)) {
        string strContent = s;
        if (srcFile.peek() != EOF) {
            strContent += '\n';
        }
        srcTextContent.append(strContent);
    }
    srcFile.close();

    QFont qf = ui->srcFilePath->font();
    if (qf.italic()) qf.setItalic(false);
    ui->srcFilePath->setFont(qf);
    ui->srcFilePath->setText(QString::fromStdString(fpath));
    updateSrcText();

    srcOpened = true;

    return;
}

void compareDialog::openCurAsSrc() {

    ui->srcFilePath->clear();
    srcFilePath.clear();

    srcTextContent.clear();
    srcTextContent.append(curTextContent);

    QFont qf = ui->srcFilePath->font();
    if (!qf.italic()) qf.setItalic(true);
    ui->srcFilePath->setFont(qf);
    ui->srcFilePath->setText("Current File");

    srcOpened = true;

    updateSrcText();

    return;

}

void compareDialog::openStrFile() {

    string fpath;
    QString fileName = QFileDialog::getOpenFileName(NULL,"Selected a file to open: ",".","*.txt *.data *.c *.cpp *.java *.py");
    fpath = fileName.toStdString();

    if (fpath.empty()) {
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Warning);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("No file(s) selected. Failed to open.");
        warningNoFilesSelected.exec();
        ui->strFilePath->clear();

        return;
    }

    this->strFilePath = fpath;
    ifstream strFile(strFilePath);
    string s;
    strTextContent.clear();
    while (getline(strFile, s)) {
        string strContent = s;
        if (strFile.peek() != EOF) {
            strContent += '\n';
        }
        strTextContent.append(strContent);
    }
    strFile.close();

    ui->strFilePath->setText(QString::fromStdString(fpath));
    updateStrText();

    srcOpened = true;

    return;
}

void compareDialog::updateSrcText() {

    ui->srcTextArea->clear();
    ui->srcTextArea->appendPlainText(QString::fromStdString(this->srcTextContent));

    return;
}

void compareDialog::updateStrText() {

    ui->strTextArea->clear();
    ui->strTextArea->appendPlainText(QString::fromStdString(this->strTextContent));

    return;
}

void compareDialog::cmpInDistanceMethod() {

    if (srcTextContent.empty() || strTextContent.empty()) {
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Critical);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("Invalid file(s) input.");
        warningNoFilesSelected.exec();

        return;
    }

    similarity sCore(srcTextContent, strTextContent);
    sCore.sliceStrings(); sCore.initAVLTree();
    sCore.getSimilarity(similarityMethodsList::DISTANCE);
    simResult = sCore.getSimResult();
    updateSimResult();

    return;
}

void compareDialog::cmpInCosineMethod() {

    if (srcTextContent.empty() || strTextContent.empty()) {
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Critical);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("Invalid file(s) input.");
        warningNoFilesSelected.exec();

        return;
    }

    similarity sCore(srcTextContent, strTextContent);
    sCore.sliceStrings(); sCore.initAVLTree();
    sCore.getSimilarity(similarityMethodsList::COSINE);
    simResult = sCore.getSimResult();
    updateSimResult();

    return;
}

void compareDialog::aboutCmpMethods() {

    c.updateHelpContent();
    c.show();

    return;
}

void compareDialog::updateSimResult() {

    stringstream s;
    s << std::setiosflags(std::ios::fixed) << std::setprecision(3) << simResult;
    string ret; ret = s.str();
    ui->simResult->clear();
    ui->simResult->setText(QString::fromStdString(ret));

    return;
}

void compareDialog::flushPreviousData(){

    srcTextContent.clear();
    curTextContent.clear();
    strTextContent.clear();

    srcFilePath.clear();
    strFilePath.clear();
    srcOpened = false;
    strOpened = false;

    return;
}

void compareDialog::closeEvent(QCloseEvent *event){

    hide();
    c.close();
    c.flushHelpContent();
    c.resize(800, 600);

    flushPreviousData();

    ui->srcFilePath->clear();
    ui->strFilePath->clear();
    ui->srcTextArea->clear();
    ui->strTextArea->clear();

    resize(800, 600);

    return;
}

compareDialog::~compareDialog() {

    delete ui;

    return;
}
