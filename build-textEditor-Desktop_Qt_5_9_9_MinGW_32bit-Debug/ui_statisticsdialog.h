/********************************************************************************
** Form generated from reading UI file 'statisticsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSDIALOG_H
#define UI_STATISTICSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_statisticsDialog
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *statsArea;

    void setupUi(QDialog *statisticsDialog)
    {
        if (statisticsDialog->objectName().isEmpty())
            statisticsDialog->setObjectName(QStringLiteral("statisticsDialog"));
        statisticsDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/stats.ico"), QSize(), QIcon::Normal, QIcon::Off);
        statisticsDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(statisticsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        statsArea = new QPlainTextEdit(statisticsDialog);
        statsArea->setObjectName(QStringLiteral("statsArea"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        statsArea->setFont(font);

        gridLayout->addWidget(statsArea, 0, 0, 1, 1);


        retranslateUi(statisticsDialog);

        QMetaObject::connectSlotsByName(statisticsDialog);
    } // setupUi

    void retranslateUi(QDialog *statisticsDialog)
    {
        statisticsDialog->setWindowTitle(QApplication::translate("statisticsDialog", "Statistics", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statisticsDialog: public Ui_statisticsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSDIALOG_H
