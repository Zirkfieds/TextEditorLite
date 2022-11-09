#include "compressiondialog.h"
#include "ui_compressiondialog.h"

#include"huffmancoding.h"

#include<QSlider>

compressionDialog::compressionDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::compressionDialog) {

    ui->setupUi(this);
    hCoder = new huffmanCoding();

    setAttribute(Qt::WA_QuitOnClose,false);

    connect(ui->enCode, &QPushButton::clicked, this, &compressionDialog::hCompression);
    connect(ui->deCode, &QPushButton::clicked, this, &compressionDialog::hDecompression);

    connect(ui->openHCFile, &QPushButton::clicked, this, &compressionDialog::openHCFile);
    connect(ui->saveHCFile, &QPushButton::clicked, this, &compressionDialog::saveHCFile);

    connect(ui->enTextArea, &QPlainTextEdit::textChanged, this, &compressionDialog::updateCodableStatus);

    return;
}

void compressionDialog::setEnTextAreaStr(string& content) {

    this->enTextAreaStr = content;
    hCoder->setContentStr(enTextAreaStr);
    ui->enTextArea->appendPlainText(QString::fromStdString(content));

    return;
}

void compressionDialog::updateCodableStatus() {

    hCoder->clearStr();
    string target = ui->enTextArea->toPlainText().toStdString();
    hCoder->setContentStr(target);

    if (target.empty()) {
        hCoder->updateCodableStatus(false);

        return;
    }
    char ch = target[0];
    for (auto c : target) {
        if (ch != c) {
            hCoder->updateCodableStatus(true);

            return;
        }
    }
    hCoder->updateCodableStatus(false);

    return;
}

void compressionDialog::hCompression() {

    if (hCoder->getCodableStatus()){

        hCoder->getCharFreq();
        ui->enTextArea->setReadOnly(true);
        hCoder->createHTree();
        hCoder->hEncode();

        ui->deTextArea->clear();
        ui->deTextArea->appendPlainText(QString::fromStdString(hCoder->getCodedStr()));
    }
    else {
        QMessageBox warningUnableToEncode;
        warningUnableToEncode.setIcon(QMessageBox::Critical);
        QString title = "Text Editor";
        warningUnableToEncode.setWindowTitle(title);
        warningUnableToEncode.setText("Cannot encode the given text!");
        warningUnableToEncode.exec();
    }

    return;
}

void compressionDialog::hDecompression() {

    ui->enTextArea->clear();
    deTextAreaStr = ui->deTextArea->toPlainText().toStdString();

    hCoder->clearCodedStr();
    hCoder->hDecode(deTextAreaStr);
    ui->enTextArea->setPlainText(QString::fromStdString(hCoder->getDecodedStr()));

    return;
}

void compressionDialog::openHCFile(){

    string fpath;
    QString fileName = QFileDialog::getOpenFileName(NULL,"Selected a HuffmanCodings File to open:",".","*.hcf");
    fpath = fileName.toStdString();

    if (fpath.empty()) {
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Warning);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("No .hcf file(s) selected.");
        warningNoFilesSelected.exec();

        return;
    }
    else {
        hCoder->setHCFileInfo(fpath);
    }

    hCoder->loadHCFile();
    ui->deTextArea->setPlainText(QString::fromStdString(hCoder->getCodedStr()));

    return;
}

void compressionDialog::saveHCFile() {

    if (hCoder->getHCodeStatus()) {
        string fpath;
        QString fileName = QFileDialog::getSaveFileName(NULL,"Save .hcf file as:",".","*.hcf");
        fpath = fileName.toStdString();

        if (!fpath.empty()) {
            hCoder->setHCFileInfo(fpath);
            hCoder->generateHCFile();
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
        QMessageBox warningNoFilesSelected;
        warningNoFilesSelected.setIcon(QMessageBox::Information);
        QString title = "Text Editor";
        warningNoFilesSelected.setWindowTitle(title);
        warningNoFilesSelected.setText("Please encode the text first!");
        warningNoFilesSelected.exec();

        return;
    }
}

void compressionDialog::flushData() {

    this->enTextAreaStr.clear();
    ui->enTextArea->clear();

    return;
}

void compressionDialog::closeEvent(QCloseEvent *event){

    hide();
    hCoder->flushPreviousData();

    ui->deTextArea->clear();
    ui->enTextArea->clear();
    ui->enTextArea->setReadOnly(false);
    resize(800, 600);

    return;
}

compressionDialog::~compressionDialog()
{
    delete ui;
}
