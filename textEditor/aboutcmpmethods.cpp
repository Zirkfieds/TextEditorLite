#include "aboutcmpmethods.h"
#include "ui_aboutcmpmethods.h"

aboutCmpMethods::aboutCmpMethods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutCmpMethods) {

    ui->setupUi(this);

    setAttribute(Qt::WA_QuitOnClose,false);

    return;
}

void aboutCmpMethods::flushHelpContent() {

    ui->helpContentArea->clear();
    return;
}

void aboutCmpMethods::updateHelpContent() {

    flushHelpContent();

    QTextCursor cursor = ui->helpContentArea->textCursor();
    QTextDocument * t = ui->helpContentArea->document();

    for (auto qimg : imgs) {
        QString urlStr = QString::fromStdString(qimg.first);
        t->addResource(QTextDocument::ImageResource, QUrl(urlStr), qimg.second);
        cursor.insertImage(urlStr);
        ui->helpContentArea->append(QString::fromStdString("\n"));
        cursor = ui->helpContentArea->textCursor();
    }

    ui->helpContentArea->append(helpFullContent);

    return;
}

void aboutCmpMethods::loadImgs() {

    QImage imgM1 = QImageReader(":/help/simM1.png").read();
    imgs.push_back(make_pair("imgSimM1", imgM1));

    QImage imgM2 = QImageReader(":/help/simM2.png").read();
    imgs.push_back(make_pair("imgSimM2", imgM2));

    return;
}

void aboutCmpMethods::loadText() {

    helpFullContent.clear();

    QFile src(":/cmp/cmpHelpFile.hp");
    src.open(QIODevice::ReadOnly);
    QTextStream ssrc(&src);

    helpFullContent = ssrc.readAll();

    return;
}

aboutCmpMethods::~aboutCmpMethods() {

    delete ui;
}
