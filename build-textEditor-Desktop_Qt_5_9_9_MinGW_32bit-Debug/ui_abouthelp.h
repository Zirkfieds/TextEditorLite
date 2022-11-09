/********************************************************************************
** Form generated from reading UI file 'abouthelp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTHELP_H
#define UI_ABOUTHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutHelp
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *helpTitle;
    QComboBox *helpEntries;
    QTextEdit *helpContentArea;

    void setupUi(QWidget *aboutHelp)
    {
        if (aboutHelp->objectName().isEmpty())
            aboutHelp->setObjectName(QStringLiteral("aboutHelp"));
        aboutHelp->resize(640, 480);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        aboutHelp->setWindowIcon(icon);
        gridLayout = new QGridLayout(aboutHelp);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        helpTitle = new QLabel(aboutHelp);
        helpTitle->setObjectName(QStringLiteral("helpTitle"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        helpTitle->setFont(font);

        horizontalLayout->addWidget(helpTitle);

        helpEntries = new QComboBox(aboutHelp);
        helpEntries->setObjectName(QStringLiteral("helpEntries"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(9);
        helpEntries->setFont(font1);

        horizontalLayout->addWidget(helpEntries);


        verticalLayout->addLayout(horizontalLayout);

        helpContentArea = new QTextEdit(aboutHelp);
        helpContentArea->setObjectName(QStringLiteral("helpContentArea"));
        helpContentArea->setFont(font);
        helpContentArea->setLineWrapMode(QTextEdit::WidgetWidth);
        helpContentArea->setReadOnly(true);

        verticalLayout->addWidget(helpContentArea);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(aboutHelp);

        QMetaObject::connectSlotsByName(aboutHelp);
    } // setupUi

    void retranslateUi(QWidget *aboutHelp)
    {
        aboutHelp->setWindowTitle(QApplication::translate("aboutHelp", "Help", Q_NULLPTR));
        helpTitle->setText(QApplication::translate("aboutHelp", "Help Menu of textEditor", Q_NULLPTR));
        helpEntries->clear();
        helpEntries->insertItems(0, QStringList()
         << QApplication::translate("aboutHelp", "Introduction", Q_NULLPTR)
         << QApplication::translate("aboutHelp", "File Interactions", Q_NULLPTR)
         << QApplication::translate("aboutHelp", "Find/Repalce", Q_NULLPTR)
         << QApplication::translate("aboutHelp", "Statistics", Q_NULLPTR)
         << QApplication::translate("aboutHelp", "Compression", Q_NULLPTR)
         << QApplication::translate("aboutHelp", "Similarity", Q_NULLPTR)
        );
        helpEntries->setCurrentText(QApplication::translate("aboutHelp", "Introduction", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutHelp: public Ui_aboutHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTHELP_H
