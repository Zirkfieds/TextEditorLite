#ifndef COMPRESSIONDIALOG_H
#define COMPRESSIONDIALOG_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include "huffmancoding.h"

namespace Ui {
class compressionDialog;
}

class compressionDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit compressionDialog(QWidget *parent = nullptr);

    void setEnTextAreaStr(string&);

    void hCompression();
    void hDecompression();

    void openHCFile();
    void saveHCFile();

    void flushData();

    void updateCodableStatus();

    //Overload
    void closeEvent(QCloseEvent *event);

    ~compressionDialog();

private:
    Ui::compressionDialog *ui;

    huffmanCoding* hCoder;

    string enTextAreaStr;
    string deTextAreaStr;

};

#endif // COMPRESSIONDIALOG_H
