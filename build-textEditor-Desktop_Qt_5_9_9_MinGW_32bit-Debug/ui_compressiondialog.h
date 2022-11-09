/********************************************************************************
** Form generated from reading UI file 'compressiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPRESSIONDIALOG_H
#define UI_COMPRESSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_compressionDialog
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *filePreview;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *enTextArea;
    QPlainTextEdit *deTextArea;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *enCode;
    QPushButton *saveHCFile;
    QHBoxLayout *horizontalLayout;
    QPushButton *deCode;
    QPushButton *openHCFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *compressionDialog)
    {
        if (compressionDialog->objectName().isEmpty())
            compressionDialog->setObjectName(QStringLiteral("compressionDialog"));
        compressionDialog->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        compressionDialog->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/compress.ico"), QSize(), QIcon::Normal, QIcon::Off);
        compressionDialog->setWindowIcon(icon);
        centralwidget = new QWidget(compressionDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filePreview = new QLabel(centralwidget);
        filePreview->setObjectName(QStringLiteral("filePreview"));
        QFont font1;
        font1.setPointSize(10);
        filePreview->setFont(font1);

        verticalLayout->addWidget(filePreview);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        enTextArea = new QPlainTextEdit(centralwidget);
        enTextArea->setObjectName(QStringLiteral("enTextArea"));
        enTextArea->setFont(font1);

        horizontalLayout_4->addWidget(enTextArea);

        deTextArea = new QPlainTextEdit(centralwidget);
        deTextArea->setObjectName(QStringLiteral("deTextArea"));
        deTextArea->setFont(font1);

        horizontalLayout_4->addWidget(deTextArea);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        enCode = new QPushButton(centralwidget);
        enCode->setObjectName(QStringLiteral("enCode"));

        horizontalLayout_2->addWidget(enCode);

        saveHCFile = new QPushButton(centralwidget);
        saveHCFile->setObjectName(QStringLiteral("saveHCFile"));

        horizontalLayout_2->addWidget(saveHCFile);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        deCode = new QPushButton(centralwidget);
        deCode->setObjectName(QStringLiteral("deCode"));

        horizontalLayout->addWidget(deCode);

        openHCFile = new QPushButton(centralwidget);
        openHCFile->setObjectName(QStringLiteral("openHCFile"));

        horizontalLayout->addWidget(openHCFile);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        compressionDialog->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(compressionDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        compressionDialog->setStatusBar(statusbar);

        retranslateUi(compressionDialog);

        QMetaObject::connectSlotsByName(compressionDialog);
    } // setupUi

    void retranslateUi(QMainWindow *compressionDialog)
    {
        compressionDialog->setWindowTitle(QApplication::translate("compressionDialog", "Compression", Q_NULLPTR));
        filePreview->setText(QApplication::translate("compressionDialog", "File Preview", Q_NULLPTR));
        enTextArea->setPlaceholderText(QApplication::translate("compressionDialog", "Type or paste the text here.", Q_NULLPTR));
        deTextArea->setPlaceholderText(QApplication::translate("compressionDialog", "Type or paste the text here.", Q_NULLPTR));
        enCode->setText(QApplication::translate("compressionDialog", "Encode", Q_NULLPTR));
        saveHCFile->setText(QApplication::translate("compressionDialog", "Save HuffmanCodings File (.hcf)", Q_NULLPTR));
        deCode->setText(QApplication::translate("compressionDialog", "Decode", Q_NULLPTR));
        openHCFile->setText(QApplication::translate("compressionDialog", "Open HuffmanCodings File (.hcf)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class compressionDialog: public Ui_compressionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPRESSIONDIALOG_H
