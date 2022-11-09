#include "texteditor.h"

#include <QApplication>
#include <QWidget>
#include <QTextCodec>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);

    textEditor w;
    w.show();

    return a.exec();
}
