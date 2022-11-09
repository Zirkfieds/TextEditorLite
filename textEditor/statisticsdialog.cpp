#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"

statisticsDialog::statisticsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statisticsDialog) {

    ui->setupUi(this);

    for (int i = 0; i < typeCount; i++) {
        statisticsData.push_back(-1);
    }

    setAttribute(Qt::WA_QuitOnClose,false);

    ui->statsArea->setReadOnly(true);

    return;
}

void statisticsDialog::initStats(string& content, int paras) {

    this->textAreaStr = content;

    proceedStatistics(paras);
    fabricateStatsStr();

    return;
}

void statisticsDialog::proceedStatistics(int paras) {

//    enum statisticsType {
//        totalWords = 0, totalCharacters, totalCharactersWithoutSpacers, paragraphs, typeCount
//    };

    statisticsData[totalCharacters] = textAreaStr.length();

    int spacerCnt = 0, wordCnt = 0;
    for (auto& ch : textAreaStr) {
        if (ch == '\t' || ch == ' ' || ch == '\n') {
            spacerCnt++;
        }
    }
    statisticsData[totalCharactersWithoutSpacers] = statisticsData[totalCharacters] - spacerCnt;

    istringstream textAreaSStream(textAreaStr);
    string s;
    while(textAreaSStream >> s) {
        wordCnt++;
    }
    statisticsData[totalWords] = wordCnt;
    statisticsData[paragraphs] = paras - 1;

    return;
}

void statisticsDialog::fabricateStatsStr() {

    ui->statsArea->clear();
    finalStatsStr.clear();

    finalStatsStr.append("Total words: ");
    finalStatsStr.append(to_string(statisticsData[totalWords]));
    finalStatsStr.append("\nTotal characters: ");
    finalStatsStr.append(to_string(statisticsData[totalCharacters]));
    finalStatsStr.append("\nTotal characters without spacers: ");
    finalStatsStr.append(to_string(statisticsData[totalCharactersWithoutSpacers]));
    finalStatsStr.append("\nTotal paragraphs: ");
    finalStatsStr.append(to_string(statisticsData[paragraphs]));

    ui->statsArea->appendPlainText(QString::fromStdString(finalStatsStr));

    return;
}

void statisticsDialog::closeEvent(QCloseEvent *event) {

    hide();
    resize(400, 300);

    return;
}

statisticsDialog::~statisticsDialog() {

    delete ui;
}
