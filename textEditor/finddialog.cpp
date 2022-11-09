#include "finddialog.h"
#include "ui_finddialog.h"

#include<QLineEdit>
#include<QMessageBox>
#include<QString>
#include<QPushButton>

#define PRIOR_ENABLED 0

findDialog::findDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findDialog) {

    ui->setupUi(this);

    findBeginFlag = false;
    replacementAvailable = false;

    patternLength = -1;
    matchIndex = -1;

    string placeholder = "Pattern string";
    ui->targetStr->setPlaceholderText(QString::fromStdString(placeholder));

    placeholder = "Replacement string";
    ui->replacementStr->setPlaceholderText(QString::fromStdString(placeholder));

    connect(ui->targetStr, &QLineEdit::textEdited, this, &findDialog::updateTargetStr);
    connect(ui->replacementStr, &QLineEdit::textEdited, this, &findDialog::updateReplacementStr);

    connect(ui->findReplace, SIGNAL(clicked()), this, SLOT(on_findReplace_clicked()));
    connect(ui->findBegin, &QPushButton::clicked, this, &findDialog::toggleFindStatus);
    connect(ui->findCancel, &QPushButton::clicked, this, &findDialog::resetFindDialog);
    setWindowFlags((windowFlags() & ~Qt::WindowCloseButtonHint));
    setAttribute(Qt::WA_QuitOnClose,false);

    ui->findReplace->setEnabled(false);
    ui->findNext->setEnabled(false);
    connect(ui->findNext, &QPushButton::clicked, this, &findDialog::gotoNextMatch);
    connect(ui->findNext, SIGNAL(clicked()), this, SLOT(on_findNext_clicked()));

#if PRIOR_ENABLED
    ui->findPrior->setEnabled(false);
    connect(ui->findPrior, SIGNAL(clicked()), this, SLOT(on_findNext_clicked()));
    connect(ui->findPrior, &QPushButton::clicked, this, &findDialog::gotoPriorMatch);
#endif;

    return;
}

void findDialog::initContent(string& content) {

    this->textAreaStr = content;

    return;
}

void findDialog::toggleFindStatus() {

    if (!findBeginFlag && patternLength != -1) {
        findBeginFlag = true;

        ui->targetStr->setEnabled(false);
        ui->findNext->setEnabled(true);
        //ui->findPrior->setEnabled(true);
        ui->findBegin->setEnabled(false);

        getAllMatches();
    }

    return;
}

void findDialog::getAllMatches() {

    if (!findBeginFlag) {
        return;
    }

    matches.clear();

    QString qPattern = QString::fromStdString(this->pattern);

    fullMatch(textAreaStr, pattern);
    maxMatchIndex = matches.size();

    if (matches.size() == 0) {
        QMessageBox warningNoMatches;
        warningNoMatches.setIcon(QMessageBox::Critical);
        QString title = "Text Editor";
        warningNoMatches.setWindowTitle(title);
        warningNoMatches.setText("Cannot find any matches of the given pattern string.");
        warningNoMatches.exec();

        resetFindDialog();
    }

    return;
}

void findDialog::fullMatch(string const& str, string const& pattern) {

    vector<int> next;
    next.push_back(-1);

    for (int i = 0, j = -1; i < pattern.length();) {
        //make the next vector
        if (j == -1 || pattern[i] == pattern[j]) {
            i++, j++;
            if (i != pattern.length() && pattern[j] == pattern[i]) {
                next.push_back(next[j]);
            }
            else {
                next.push_back(j);
            }
        }
        else {
            j = next[j];
        }
    }

    for (int i = 0, j = 0; i < str.length() && j < (int)pattern.length();) {
        if (j == -1 || str[i] == pattern[j]) {
            i++, j++;
            if (j == pattern.length()) {
                this->matches.push_back(i - j);
                j = next[j];
            }
        }
        else {
            j = next[j];
        }
    }

    return;
}

void findDialog::updateTargetStr() {

    string target = (ui->targetStr->text()).toStdString();

    if (target.empty()) {
        patternLength = -1;

        return;
    }
    pattern = target;
    patternLength = target.length();

    return;
}

void findDialog::updateReplacementStr() {

    replacement = ui->replacementStr->text().toStdString();
    replacementLength = replacement.length();
    if (replacement.empty()) {
        replacementAvailable = false;
        ui->findReplace->setEnabled(false);
    }
    else {
        replacementAvailable = true;
        ui->findReplace->setEnabled(true);
    }

    return;
}

int findDialog::gotoNextMatch() {

    matchIndex + 1 < maxMatchIndex ? matchIndex++ : matchIndex = 0;

    return matchIndex;
}

#if PRIOR_ENABLED
int findDialog::gotoPriorMatch() {

    matchIndex - 1 >= 0 ? matchIndex-- : matchIndex = maxMatchIndex - 1;

    return matchIndex;
}
#endif;

int findDialog::getCurMatchIndex() {

    return matchIndex;
}

int findDialog::getCurMatchPos() {

    return matches[matchIndex];
}

void findDialog::replaceContent() {

    if (matchIndex == -1) {

        return;
    }
    textAreaStr.replace(matches[matchIndex], replacementLength, replacement);

    return;
}

string findDialog::getTextAreaStr() {

    return this->textAreaStr;
}


void findDialog::resetFindDialog() {

    findBeginFlag = false;
    replacementAvailable = false;

    ui->targetStr->setEnabled(true);
    ui->replacementStr->setEnabled(true);

    ui->findBegin->setEnabled(true);
    ui->findNext->setEnabled(false);
    //ui->findPrior->setEnabled(false);
    ui->findReplace->setEnabled(false);

    string placeholder = "Pattern string";
    ui->targetStr->setText("");

    placeholder = "Replacement string";
    ui->replacementStr->setText("");

    pattern.clear(); patternLength = -1;

    matches.clear();

    matchIndex = -1;
    maxMatchIndex = 0;

    hide();
    this->close();
    resize(400, 200);

    return;
}

findDialog::~findDialog() {

    delete ui;
}

void findDialog::on_findNext_clicked() {

    emit sendMatchIndex(matches[matchIndex], patternLength);

    return;
}

void findDialog::on_findReplace_clicked() {

    emit sendUpdatedStr(textAreaStr, replacementLength);
    replaceContent();

    return;
}
