#include "texteditor.h"
#include "ui_texteditor.h"

//THE SOURCE FILE INCLUDING ALL BASIC TEXT EDITOR FEATURES, MAINLY FILE IO

#include<fstream>
#include<sstream>

using namespace std;

textEditor::textEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::textEditor) {

    ui->setupUi(this);

    ui->textArea->setLineWrapMode(QPlainTextEdit::WidgetWidth);

    this->setWindowTitle(QString::fromStdString(winTitle));

    fileOpened = false;
    fileSaved = true;
    isNewFile = true;

    qc = ui->textArea->textCursor();
    connect(ui->actionOpen, &QAction::
            triggered, this, &textEditor::openFile);

    ui->actionSaveFile->setEnabled(false);
    connect(ui->actionSaveFile, &QAction::triggered, this, &textEditor::saveFile);
    connect(ui->actionSaveAs, &QAction::triggered, this, &textEditor::saveAsFile);

    connect(ui->actionClose, &QAction::triggered, this, &textEditor::closeFile);

    connect(ui->actionNew, &QAction::triggered, this, &textEditor::newFile);

    connect(ui->textArea, &QPlainTextEdit::textChanged, this, &textEditor::updateSaveStatus);

    connect(ui->actionUndo, &QAction::triggered, this, &textEditor::undoInput);
    connect(ui->actionRedo, &QAction::triggered, this, &textEditor::redoInput);

    connect(ui->actionFind, &QAction::triggered, this, &textEditor::initFindReplace);
    connect(&findContent, SIGNAL(sendMatchIndex(int, int)), this, SLOT(receiveMatchIndex(int, int)));
    connect(&findContent, SIGNAL(sendUpdatedStr(string, int)), this, SLOT(receiveUpdatedStr(string, int)));

    connect(ui->actionStatistics, &QAction::triggered, this, &textEditor::initStatistics);
    connect(ui->actionCompress, &QAction::triggered, this, &textEditor::initCompression);
    connect(ui->actionCompare, &QAction::triggered, this, &textEditor::initComparison);

    connect(ui->actionAbout, &QAction::triggered, this, &textEditor::showAboutHelp);

    return;
}

void textEditor::openFile() {

    string fpath;
    QString fileName = QFileDialog::getOpenFileName(NULL,"Selected a file to open: ",".","*.txt *.data *.c *.cpp *.java *.py");
    fpath = fileName.toStdString();

    if (fpath.empty()) {
        //if no file(s) selected
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Warning);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("No file(s) selected. Failed to open.");
        warningNoFilesSelected.exec();

        return;
    }
    else if (fpath.compare(filePath) == 0) {

        return;
    }

    this->filePath = fpath;

    QFileInfo fileInfo = QFileInfo(QString::fromStdString(this->filePath));
    this->fileName = fileInfo.fileName().toStdString();

    ui->fileName->setText(QString::fromStdString(this->fileName));

    fileOpened = true;
    isNewFile = false;

    ifstream srcFile(filePath);
    string s;
    while (getline(srcFile, s)) {

        //raw string data
        string strContent = s;
        if (srcFile.peek() != EOF) {
            strContent += '\n';
        }
        textAreaContent.push_back(s);
        textAreaStr.append(strContent);

        //QString data
        textAreaQContent.push_back(QString::fromStdString(s));
        textAreaQStr.append(QString::fromStdString(strContent));

    }
    srcFile.close();

    flushTextArea();
    ui->textArea->appendPlainText(textAreaQStr);
    fileSaved = true;

    flushContainers();

    return;
}

void textEditor::saveFile() {

    bool haveToSave = false;
    if (isNewFile && !(ui->textArea->toPlainText().isEmpty())) {
        haveToSave = true;
    }
    else if (!fileSaved) {
        haveToSave = true;
    }

    if (haveToSave) {

        updateTextContent();

        if (isNewFile) {
            string fpath;
            QString fileName = QFileDialog::getSaveFileName(NULL,"Save file as: ",".","*.txt *.data *.c *.cpp *.java *.py");
            fpath = fileName.toStdString();

            if (!fpath.empty()) {

                this->filePath = fpath;
                QFileInfo fileInfo = QFileInfo(QString::fromStdString(this->filePath));
                this->fileName = fileInfo.fileName().toStdString();


                fileOpened = true;
                isNewFile = false;

                writeFile();
                fileSaved = true;

                ui->fileName->setText(QString::fromStdString(this->fileName));

                return;
            }
            else {
                QMessageBox warningNoFilesSelected;
                warningNoFilesSelected.setIcon(QMessageBox::Warning);
                QString title = "Text Editor";
                warningNoFilesSelected.setWindowTitle(title);
                warningNoFilesSelected.setText("No file(s) selected! Failed to save.");
                warningNoFilesSelected.exec();

                return;
            }
        }
        else {
            writeFile();
            fileSaved = true;

            return;
        }
    }

}

void textEditor::saveAsFile() {

    bool haveToSave = false;
    if (!(ui->textArea->toPlainText().isEmpty())) {
        haveToSave = true;
    }
    if (haveToSave) {

        updateTextContent();

        string fpath;
        QString fileName = QFileDialog::getSaveFileName(NULL, "Save file as: ", ".", "*.txt *.data *.c *.cpp *.java *.py");
        fpath = fileName.toStdString();

        if (!fpath.empty()) {

            this->filePath = fpath;
            QFileInfo fileInfo = QFileInfo(QString::fromStdString(this->filePath));
            this->fileName = fileInfo.fileName().toStdString();

            fileOpened = true;
            isNewFile = false;

            writeFile();
            fileSaved = true;

            ui->fileName->setText(QString::fromStdString(this->fileName));

            return;
        }
        else {
            QMessageBox warningNoFilesSelected;
            warningNoFilesSelected.setIcon(QMessageBox::Warning);
            QString title = "Text Editor";
            warningNoFilesSelected.setWindowTitle(title);
            warningNoFilesSelected.setText("No file(s) selected! Failed to save.");
            warningNoFilesSelected.exec();

            return;
        }
    }
}

void textEditor::closeFile() {

    if (!ui->textArea->document()->isEmpty() && !fileSaved) {
        const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr("Text Editor"),
                tr("Current file is not saved yet, save now?\n"),
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        //proceed the user's choice
        string s = "Untitled";
        switch (ret) {
        case QMessageBox::Save:
            saveFile();
            ui->fileName->setText(QString::fromStdString(this->fileName));
            filePath.clear();
            flushTextArea();
            flushContainers();
            this->newFile();
            break;
        case QMessageBox::Discard:
            filePath.clear();
            ui->fileName->setText(QString::fromStdString(s));
            flushTextArea();
            flushContainers();
            this->newFile();
            break;
        default:
            return;
        }
    }
    else {
        filePath.clear();
        flushTextArea();
        flushContainers();
        fileOpened = false;
        isNewFile = true;
        fileSaved = false;
        string s = "Untitled";
        ui->fileName->setText(QString::fromStdString(s));

        return;
    }

    return;
}

void textEditor::writeFile() {

    ofstream dstFile(filePath);
    for (auto& s : textAreaContent) {
        dstFile << s << '\n';
    }
    flushContainers();
    dstFile.close();

    return;
}

void textEditor::newFile() {

    if (!isNewFile || !ui->textArea->document()->isEmpty()) {
        closeFile();
    }
    else {
        saveFile();
    }
    isNewFile = true;
    fileOpened = false;
    string s = "Untitled";
    ui->fileName->setText(QString::fromStdString(s));

    return;
}

void textEditor::updateSaveStatus() {

    if (fileSaved) {
        fileSaved = false;
        ui->actionSaveFile->setEnabled(true);
    }

    return;
}

void textEditor::updateTextContent() {

    flushContainers();

    QString newFileContent = ui->textArea->toPlainText();
    textAreaQStr = newFileContent;
    textAreaStr = newFileContent.toStdString();

    istringstream ist(textAreaStr);

    string s;
    while (getline(ist, s)) {

        //raw string data
        string strContent = s + '\n';
        textAreaContent.push_back(s);
        textAreaStr.append(strContent);

        //QString data
        textAreaQContent.push_back(QString::fromStdString(s));
        textAreaQStr.append(QString::fromStdString(strContent));

    }

    return;
}

void textEditor::flushTextArea() {

    ui->textArea->clear();
    return;
}

QPlainTextEdit* textEditor::getTextArea() {

    return ui->textArea;
}

void textEditor::flushContainers() {

    textAreaContent.clear();
    textAreaQContent.clear();
    textAreaStr.clear();
    textAreaQStr.clear();

    return;
}

void textEditor::closeEvent(QCloseEvent *event) {

    if (!ui->textArea->document()->isEmpty() && !fileSaved) {
        const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr("Text Editor"),
                tr("Current file is not saved yet, save now?\n"),
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        //proceed the user's choice
        switch (ret) {
        case QMessageBox::Save:
            saveFile();
            filePath.clear();
            flushTextArea();
            flushContainers();
            event->accept();
            break;
        case QMessageBox::Discard:
            filePath.clear();
            flushTextArea();
            flushContainers();
            event->accept();
            break;
        default:
            event->ignore();

            return;
        }
    }
    else {
        filePath.clear();
        flushTextArea();
        flushContainers();
        fileOpened = false;
        event->accept();

        return;
    }

    return;
}

textEditor::~textEditor() {

    delete ui;
}
