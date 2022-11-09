#ifndef COMPAREDIALOG_H
#define COMPAREDIALOG_H

#include <QWidget>
#include<QFileDialog>
#include<QMessageBox>

#include "similarity.h"
#include "aboutcmpmethods.h"

#include<iomanip>
#include<fstream>

using namespace std;

namespace Ui {
class compareDialog;
}

class compareDialog : public QWidget
{
    Q_OBJECT

public:
    explicit compareDialog(QWidget *parent = nullptr);

    enum fileOpenAsList {
        SOURCE = 0, TOBECOMPARED
    };

    enum similarityMethodsList {
        NONE = 0, DISTANCE, COSINE
    };

    void updateCurTextContent(string&);

    void openSrcFile();
    void openCurAsSrc();
    void openStrFile();

    void updateFilePaths();

    void updateSrcText();
    void updateStrText();

    void cmpInDistanceMethod();
    void cmpInCosineMethod();

    void aboutCmpMethods();

    void updateSimResult();

    void flushPreviousData();

    //Overload
    void closeEvent(QCloseEvent *event);

    ~compareDialog();

private:


    string srcFilePath, strFilePath;
    bool srcOpened, strOpened;

    string srcTextContent, strTextContent;
    string curTextContent;

    double simResult;

    class aboutCmpMethods c;

    Ui::compareDialog *ui;

};

#endif // COMPAREDIALOG_H
