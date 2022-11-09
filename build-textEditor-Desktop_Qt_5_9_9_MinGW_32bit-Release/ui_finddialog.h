/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_findDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *targetStr;
    QLineEdit *replacementStr;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *findBegin;
    QPushButton *findNext;
    QPushButton *findCancel;
    QPushButton *findReplace;

    void setupUi(QDialog *findDialog)
    {
        if (findDialog->objectName().isEmpty())
            findDialog->setObjectName(QStringLiteral("findDialog"));
        findDialog->resize(400, 200);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/find.ico"), QSize(), QIcon::Normal, QIcon::Off);
        findDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(findDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        targetStr = new QLineEdit(findDialog);
        targetStr->setObjectName(QStringLiteral("targetStr"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        targetStr->setFont(font);

        verticalLayout->addWidget(targetStr);

        replacementStr = new QLineEdit(findDialog);
        replacementStr->setObjectName(QStringLiteral("replacementStr"));
        replacementStr->setFont(font);

        verticalLayout->addWidget(replacementStr);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(findDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        findBegin = new QPushButton(findDialog);
        findBegin->setObjectName(QStringLiteral("findBegin"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        findBegin->setFont(font1);

        horizontalLayout->addWidget(findBegin);

        findNext = new QPushButton(findDialog);
        findNext->setObjectName(QStringLiteral("findNext"));
        findNext->setFont(font1);

        horizontalLayout->addWidget(findNext);

        findCancel = new QPushButton(findDialog);
        findCancel->setObjectName(QStringLiteral("findCancel"));
        findCancel->setFont(font1);

        horizontalLayout->addWidget(findCancel);


        verticalLayout_2->addLayout(horizontalLayout);

        findReplace = new QPushButton(findDialog);
        findReplace->setObjectName(QStringLiteral("findReplace"));
        findReplace->setFont(font1);

        verticalLayout_2->addWidget(findReplace);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(findDialog);

        QMetaObject::connectSlotsByName(findDialog);
    } // setupUi

    void retranslateUi(QDialog *findDialog)
    {
        findDialog->setWindowTitle(QApplication::translate("findDialog", "Find & Replace", Q_NULLPTR));
        findBegin->setText(QApplication::translate("findDialog", "Begin", Q_NULLPTR));
        findNext->setText(QApplication::translate("findDialog", "Next", Q_NULLPTR));
        findCancel->setText(QApplication::translate("findDialog", "Cancel", Q_NULLPTR));
        findReplace->setText(QApplication::translate("findDialog", "Replace", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findDialog: public Ui_findDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
