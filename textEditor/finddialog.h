#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QTextCursor>
#include <QPlainTextEdit>

#include<iostream>
#include<vector>
#include<string>

using namespace std;

namespace Ui {
class findDialog;
}

class findDialog : public QDialog
{
    Q_OBJECT

public:
    explicit findDialog(QWidget *parent = nullptr);
    ~findDialog();

    void initContent(string&);

    void updateTargetStr();
    void updateReplacementStr();

    bool getFindStatus();
    void toggleFindStatus();

    void getAllMatches();
    void fullMatch(string const&, string const&);

    //void partialMatch(string const&, string const&);

    int gotoNextMatch();
    //int gotoPriorMatch();

    int getCurMatchIndex();
    int getCurMatchPos();

    void replaceContent();
    string getTextAreaStr();

    void resetFindDialog();

private:
    Ui::findDialog *ui;

    string pattern;
    string replacement;
    int patternLength;
    int replacementLength;

    bool findBeginFlag;
    bool replacementAvailable;

    string textAreaStr;
    vector<int> matches; //the index of the matches in the textAreaStr
    int matchIndex;
    int maxMatchIndex;

private slots:
    void on_findNext_clicked();
    void on_findReplace_clicked();

signals:
    void sendMatchIndex(int, int);
    void sendUpdatedStr(string, int);
};

#endif // FINDDIALOG_H
