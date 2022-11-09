#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

#include <QDialog>

namespace Ui {
class statisticsDialog;
}

class statisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statisticsDialog(QWidget *parent = nullptr);
    ~statisticsDialog();

    enum statisticsType {
        totalWords = 0, totalCharacters, totalCharactersWithoutSpacers, paragraphs, typeCount
    };

    void initStats(string&, int);
    void proceedStatistics(int);

    void fabricateStatsStr();

    //Overload
    void closeEvent(QCloseEvent *event);

private:

    Ui::statisticsDialog *ui;

    vector<long int> statisticsData;

    string textAreaStr;

    string finalStatsStr;


};

#endif // STATISTICSDIALOG_H
