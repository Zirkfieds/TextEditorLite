#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include<QMainWindow>

#include<QPlainTextEdit>
#include<QString>
#include<QFileDialog>
#include<QFileInfo>
#include<QMessageBox>

#include "finddialog.h"
#include "statisticsdialog.h"
#include "compressiondialog.h"
#include "comparedialog.h"
#include "abouthelp.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class textEditor; }
QT_END_NAMESPACE

class textEditor : public QMainWindow
{
    Q_OBJECT

public:

    enum findDataPackageFormat {
        _pos = 0, _len, _newlen
    };

    textEditor(QWidget *parent = nullptr);
    ~textEditor();

    void openFile();
    void saveFile();
    void saveAsFile();
    void closeFile();
    void writeFile();

    void newFile();

    void updateTextContent();
    void updateSaveStatus();

    void flushTextArea();
    void flushContainers();

    void undoInput();
    void redoInput();

    void initFindReplace();
    void nextMatch();
    void priorMatch();
    void cursorHopTo(int pos, int len);

    void initStatistics();
    void initCompression();
    void initComparison();

    void showAboutHelp();

    QPlainTextEdit* getTextArea();

    //Overload
    void closeEvent(QCloseEvent* event);

private:
    Ui::textEditor *ui;
    string winTitle = "Text Editor";

    bool fileOpened, fileSaved;
    bool isNewFile;

    const string defaultPath = "./files";
    string filePath;
    string fileName;

    QTextCursor qc;

    int qPos[3];

    vector<string> textAreaContent;
    vector<QString> textAreaQContent;
    string textAreaStr;
    QString textAreaQStr;

    findDialog findContent;
    statisticsDialog fileStats;
    compressionDialog fileCompress;
    compareDialog fileCompare;

    aboutHelp helpDocs;

private slots:
    void receiveMatchIndex(int, int);
    void receiveUpdatedStr(string, int);
};

#endif // TEXTEDITOR_H
