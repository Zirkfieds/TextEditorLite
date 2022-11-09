#include "abouthelp.h"
#include "ui_abouthelp.h"

#define PATTERN "*"

aboutHelp::aboutHelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutHelp) {

    ui->setupUi(this);

    connect(ui->helpEntries, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        [=](int index){ aboutHelp::cursorHopTo(segments[index]); });

    setAttribute(Qt::WA_QuitOnClose,false);

    loadHelpContent();
    locateSegments();

    displayHelpContent();

    return;
}

void aboutHelp::loadHelpContent() {

    helpContent.clear();

    QFile src(":/about/help.hp");
    src.open(QIODevice::ReadOnly);
    QTextStream ssrc(&src);

    qHelpContent = ssrc.readAll();
    helpContent = qHelpContent.toStdString();

    return;
}

void aboutHelp::locateSegments() {

    string pattern = PATTERN;

    vector<int> next;
    next.push_back(-1);

    for (int i = 0, j = -1; i < pattern.length();) {
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

    for (int i = 0, j = 0; i < helpContent.length() && j < (int)pattern.length();) {
        if (j == -1 || helpContent[i] == pattern[j]) {
            i++, j++;
            if (j == pattern.length()) {
                this->segments.push_back(i - j);
                j = next[j];
            }
        }
        else {
            j = next[j];
        }
    }

    return;
}

void aboutHelp::displayHelpContent() {

    ui->helpContentArea->clear();

    ui->helpContentArea->setText(this->qHelpContent);

    QTextCursor qc = ui->helpContentArea->textCursor();
    qc.movePosition(QTextCursor::End);
    ui->helpContentArea->setTextCursor(qc);

    return;
}

void aboutHelp::cursorHopTo(int pos) {

    QTextCursor qc = ui->helpContentArea->textCursor();
    qc.setPosition(pos, QTextCursor::MoveAnchor);
    ui->helpContentArea->setTextCursor(qc);

    return;
}

aboutHelp::~aboutHelp() {

    delete ui;
}
