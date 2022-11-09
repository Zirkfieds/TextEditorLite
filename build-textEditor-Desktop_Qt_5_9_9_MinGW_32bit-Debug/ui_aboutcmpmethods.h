/********************************************************************************
** Form generated from reading UI file 'aboutcmpmethods.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTCMPMETHODS_H
#define UI_ABOUTCMPMETHODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutCmpMethods
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *helpTitle;
    QTextEdit *helpContentArea;

    void setupUi(QWidget *aboutCmpMethods)
    {
        if (aboutCmpMethods->objectName().isEmpty())
            aboutCmpMethods->setObjectName(QStringLiteral("aboutCmpMethods"));
        aboutCmpMethods->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        aboutCmpMethods->setWindowIcon(icon);
        gridLayout = new QGridLayout(aboutCmpMethods);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        helpTitle = new QLabel(aboutCmpMethods);
        helpTitle->setObjectName(QStringLiteral("helpTitle"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        helpTitle->setFont(font);

        verticalLayout->addWidget(helpTitle);

        helpContentArea = new QTextEdit(aboutCmpMethods);
        helpContentArea->setObjectName(QStringLiteral("helpContentArea"));
        helpContentArea->setFont(font);
        helpContentArea->setReadOnly(true);

        verticalLayout->addWidget(helpContentArea);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(aboutCmpMethods);

        QMetaObject::connectSlotsByName(aboutCmpMethods);
    } // setupUi

    void retranslateUi(QWidget *aboutCmpMethods)
    {
        aboutCmpMethods->setWindowTitle(QApplication::translate("aboutCmpMethods", "Methods", Q_NULLPTR));
        helpTitle->setText(QApplication::translate("aboutCmpMethods", "Detailed Explanation of Method I and II", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutCmpMethods: public Ui_aboutCmpMethods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTCMPMETHODS_H
