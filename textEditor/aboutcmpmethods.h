#ifndef ABOUTCMPMETHODS_H
#define ABOUTCMPMETHODS_H

#include<QWidget>
#include<QImage>
#include<QImageReader>
#include<QTextDocument>
#include<QFile>
#include<QTextStream>

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

namespace Ui {
class aboutCmpMethods;
}

class aboutCmpMethods : public QWidget
{
    Q_OBJECT

public:
    explicit aboutCmpMethods(QWidget *parent = nullptr);

    void flushHelpContent();

    void loadImgs();
    void loadText();

    void updateHelpContent();

    ~aboutCmpMethods();

private:

    vector<string> helpContent;
    QString helpFullContent;

    vector<pair<string, QImage>> imgs;

    Ui::aboutCmpMethods *ui;
};

#endif // ABOUTCMPMETHODS_H
