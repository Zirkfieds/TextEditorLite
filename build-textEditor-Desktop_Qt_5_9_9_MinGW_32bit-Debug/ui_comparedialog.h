/********************************************************************************
** Form generated from reading UI file 'comparedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREDIALOG_H
#define UI_COMPAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_compareDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *openSrcFile;
    QPushButton *openSrcCur;
    QLineEdit *srcFilePath;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openStrFile;
    QPushButton *openStrCur;
    QLineEdit *strFilePath;
    QHBoxLayout *horizontalLayout_6;
    QLabel *simResultText;
    QLabel *simResult;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cmpMethod1;
    QPushButton *cmpMethod2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cmpMethodHelp;
    QVBoxLayout *verticalLayout;
    QLabel *filePreview;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *srcTextArea;
    QPlainTextEdit *strTextArea;

    void setupUi(QWidget *compareDialog)
    {
        if (compareDialog->objectName().isEmpty())
            compareDialog->setObjectName(QStringLiteral("compareDialog"));
        compareDialog->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/sim.ico"), QSize(), QIcon::Normal, QIcon::Off);
        compareDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(compareDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        openSrcFile = new QPushButton(compareDialog);
        openSrcFile->setObjectName(QStringLiteral("openSrcFile"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        openSrcFile->setFont(font);

        horizontalLayout->addWidget(openSrcFile);

        openSrcCur = new QPushButton(compareDialog);
        openSrcCur->setObjectName(QStringLiteral("openSrcCur"));
        openSrcCur->setFont(font);

        horizontalLayout->addWidget(openSrcCur);

        srcFilePath = new QLineEdit(compareDialog);
        srcFilePath->setObjectName(QStringLiteral("srcFilePath"));
        srcFilePath->setFont(font);
        srcFilePath->setReadOnly(true);

        horizontalLayout->addWidget(srcFilePath);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        openStrFile = new QPushButton(compareDialog);
        openStrFile->setObjectName(QStringLiteral("openStrFile"));
        openStrFile->setFont(font);

        horizontalLayout_2->addWidget(openStrFile);

        openStrCur = new QPushButton(compareDialog);
        openStrCur->setObjectName(QStringLiteral("openStrCur"));
        openStrCur->setEnabled(false);
        openStrCur->setFont(font);

        horizontalLayout_2->addWidget(openStrCur);

        strFilePath = new QLineEdit(compareDialog);
        strFilePath->setObjectName(QStringLiteral("strFilePath"));
        strFilePath->setFont(font);
        strFilePath->setReadOnly(true);
        strFilePath->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(strFilePath);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        simResultText = new QLabel(compareDialog);
        simResultText->setObjectName(QStringLiteral("simResultText"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(10);
        simResultText->setFont(font1);

        horizontalLayout_6->addWidget(simResultText);

        simResult = new QLabel(compareDialog);
        simResult->setObjectName(QStringLiteral("simResult"));
        simResult->setFont(font1);

        horizontalLayout_6->addWidget(simResult);


        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cmpMethod1 = new QPushButton(compareDialog);
        cmpMethod1->setObjectName(QStringLiteral("cmpMethod1"));
        cmpMethod1->setFont(font);

        horizontalLayout_4->addWidget(cmpMethod1);

        cmpMethod2 = new QPushButton(compareDialog);
        cmpMethod2->setObjectName(QStringLiteral("cmpMethod2"));
        cmpMethod2->setFont(font);

        horizontalLayout_4->addWidget(cmpMethod2);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        cmpMethodHelp = new QPushButton(compareDialog);
        cmpMethodHelp->setObjectName(QStringLiteral("cmpMethodHelp"));
        cmpMethodHelp->setFont(font);

        horizontalLayout_5->addWidget(cmpMethodHelp);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filePreview = new QLabel(compareDialog);
        filePreview->setObjectName(QStringLiteral("filePreview"));
        filePreview->setFont(font1);

        verticalLayout->addWidget(filePreview);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        srcTextArea = new QPlainTextEdit(compareDialog);
        srcTextArea->setObjectName(QStringLiteral("srcTextArea"));
        srcTextArea->setFont(font1);
        srcTextArea->setReadOnly(true);

        horizontalLayout_3->addWidget(srcTextArea);

        strTextArea = new QPlainTextEdit(compareDialog);
        strTextArea->setObjectName(QStringLiteral("strTextArea"));
        strTextArea->setFont(font1);
        strTextArea->setReadOnly(true);

        horizontalLayout_3->addWidget(strTextArea);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(compareDialog);

        QMetaObject::connectSlotsByName(compareDialog);
    } // setupUi

    void retranslateUi(QWidget *compareDialog)
    {
        compareDialog->setWindowTitle(QApplication::translate("compareDialog", "Compare", Q_NULLPTR));
        openSrcFile->setText(QApplication::translate("compareDialog", "Open File1", Q_NULLPTR));
        openSrcCur->setText(QApplication::translate("compareDialog", "Current", Q_NULLPTR));
        srcFilePath->setPlaceholderText(QApplication::translate("compareDialog", "No File Selected", Q_NULLPTR));
        openStrFile->setText(QApplication::translate("compareDialog", "Open File2", Q_NULLPTR));
        openStrCur->setText(QApplication::translate("compareDialog", "Current", Q_NULLPTR));
        strFilePath->setPlaceholderText(QApplication::translate("compareDialog", "No File Selected", Q_NULLPTR));
        simResultText->setText(QApplication::translate("compareDialog", "Similarity (Click About for more info):", Q_NULLPTR));
        simResult->setText(QApplication::translate("compareDialog", "0.000", Q_NULLPTR));
        cmpMethod1->setText(QApplication::translate("compareDialog", "Method I", Q_NULLPTR));
        cmpMethod2->setText(QApplication::translate("compareDialog", "Method II", Q_NULLPTR));
        cmpMethodHelp->setText(QApplication::translate("compareDialog", "About the methods", Q_NULLPTR));
        filePreview->setText(QApplication::translate("compareDialog", "File Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class compareDialog: public Ui_compareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREDIALOG_H
