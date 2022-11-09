#ifndef ABOUTHELP_H
#define ABOUTHELP_H

#include <QWidget>
#include<QComboBox>
#include<QFile>
#include<QTextStream>
#include<QTextCursor>

#include<iostream>
#include<string>
#include<vector>

using namespace std;

namespace Ui {
class aboutHelp;
}

class aboutHelp : public QWidget
{
    Q_OBJECT

public:
    explicit aboutHelp(QWidget *parent = nullptr);
    ~aboutHelp();

    void loadHelpContent();
    void locateSegments();

    void displayHelpContent();

    void cursorHopTo(int);

private:
    Ui::aboutHelp *ui;

    enum helpSectionName {
        INTRODUCTION = 0, FILE_INTERACTIONS, FIND_REPLACE, STATISTICS, COMPRESSION, SIMILARITY
    };

    string helpContent;
    QString qHelpContent;

    vector<int> segments;

    // vector<pair<string, int>> helpSections;
};

#endif // ABOUTHELP_H
