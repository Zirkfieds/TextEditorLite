/********************************************************************************
** Form generated from reading UI file 'texteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textEditor
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionStatistics;
    QAction *actionCompress;
    QAction *actionCompare;
    QAction *actionNew;
    QAction *actionFont;
    QAction *actionFormat;
    QAction *actionAbout;
    QAction *actionEncryption;
    QAction *actionSaveFile;
    QAction *actionSaveAs;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *textArea;
    QLabel *fileName;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *textEditor)
    {
        if (textEditor->objectName().isEmpty())
            textEditor->setObjectName(QStringLiteral("textEditor"));
        textEditor->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon/main.ico"), QSize(), QIcon::Normal, QIcon::Off);
        textEditor->setWindowIcon(icon);
        actionOpen = new QAction(textEditor);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(textEditor);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionUndo = new QAction(textEditor);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(textEditor);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionFind = new QAction(textEditor);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        actionReplace = new QAction(textEditor);
        actionReplace->setObjectName(QStringLiteral("actionReplace"));
        actionStatistics = new QAction(textEditor);
        actionStatistics->setObjectName(QStringLiteral("actionStatistics"));
        actionCompress = new QAction(textEditor);
        actionCompress->setObjectName(QStringLiteral("actionCompress"));
        actionCompare = new QAction(textEditor);
        actionCompare->setObjectName(QStringLiteral("actionCompare"));
        actionNew = new QAction(textEditor);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionFont = new QAction(textEditor);
        actionFont->setObjectName(QStringLiteral("actionFont"));
        actionFormat = new QAction(textEditor);
        actionFormat->setObjectName(QStringLiteral("actionFormat"));
        actionFormat->setVisible(false);
        actionAbout = new QAction(textEditor);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionEncryption = new QAction(textEditor);
        actionEncryption->setObjectName(QStringLiteral("actionEncryption"));
        actionSaveFile = new QAction(textEditor);
        actionSaveFile->setObjectName(QStringLiteral("actionSaveFile"));
        actionSaveAs = new QAction(textEditor);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        centralwidget = new QWidget(textEditor);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textArea = new QPlainTextEdit(centralwidget);
        textArea->setObjectName(QStringLiteral("textArea"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        textArea->setFont(font);

        gridLayout->addWidget(textArea, 1, 0, 1, 1);

        fileName = new QLabel(centralwidget);
        fileName->setObjectName(QStringLiteral("fileName"));
        fileName->setFont(font);

        gridLayout->addWidget(fileName, 0, 0, 1, 1);

        textEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(textEditor);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp_2 = new QMenu(menubar);
        menuHelp_2->setObjectName(QStringLiteral("menuHelp_2"));
        textEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(textEditor);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        textEditor->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp_2->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuSave->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionNew);
        menuSave->addAction(actionSaveFile);
        menuSave->addAction(actionSaveAs);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuTools->addAction(actionStatistics);
        menuTools->addAction(actionCompress);
        menuTools->addAction(actionCompare);
        menuTools->addSeparator();
        menuHelp_2->addAction(actionAbout);

        retranslateUi(textEditor);

        QMetaObject::connectSlotsByName(textEditor);
    } // setupUi

    void retranslateUi(QMainWindow *textEditor)
    {
        textEditor->setWindowTitle(QApplication::translate("textEditor", "textEditor", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("textEditor", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("textEditor", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("textEditor", "Close", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("textEditor", "Ctrl+W", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("textEditor", "Undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("textEditor", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("textEditor", "Redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("textEditor", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("textEditor", "Find / Replace", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("textEditor", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("textEditor", "Replace", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("textEditor", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionStatistics->setText(QApplication::translate("textEditor", "Statistics", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionStatistics->setShortcut(QApplication::translate("textEditor", "Ctrl+Shift+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCompress->setText(QApplication::translate("textEditor", "Compress", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCompress->setShortcut(QApplication::translate("textEditor", "Ctrl+Shift+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCompare->setText(QApplication::translate("textEditor", "Similarity", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCompare->setShortcut(QApplication::translate("textEditor", "Ctrl+Shift+B", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNew->setText(QApplication::translate("textEditor", "New", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("textEditor", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFont->setText(QApplication::translate("textEditor", "Font", Q_NULLPTR));
        actionFormat->setText(QApplication::translate("textEditor", "Format", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("textEditor", "About", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("textEditor", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionEncryption->setText(QApplication::translate("textEditor", "Encryption", Q_NULLPTR));
        actionSaveFile->setText(QApplication::translate("textEditor", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSaveFile->setShortcut(QApplication::translate("textEditor", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("textEditor", "Save As", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSaveAs->setShortcut(QApplication::translate("textEditor", "Ctrl+Alt+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        fileName->setText(QApplication::translate("textEditor", "Untitled", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("textEditor", "File", Q_NULLPTR));
        menuSave->setTitle(QApplication::translate("textEditor", "Save", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("textEditor", "Edit", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("textEditor", "Tools", Q_NULLPTR));
        menuHelp_2->setTitle(QApplication::translate("textEditor", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class textEditor: public Ui_textEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H
