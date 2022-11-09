#include "texteditor.h"
#include "ui_texteditor.h"

//THE SOURCE FILE INCLUDING ADVANCED TEXT EDITOR FEATURES, INCLUDING FIND/REPLACE, UNDO/REDO AND SETTINGS

void textEditor::undoInput() {

    ui->textArea->undo();

    return;
}

void textEditor::redoInput() {

    ui->textArea->redo();

    return;
}

void textEditor::initFindReplace() {

    string consContent = (ui->textArea->toPlainText()).toStdString();
    findContent.initContent(consContent);
    findContent.show();

    return;
}

void textEditor::receiveMatchIndex(int pos, int len) {

    cursorHopTo(pos, len);

    return;
}

void textEditor::receiveUpdatedStr(string updatedContent, int newLen) {

    flushTextArea();
    qPos[_newlen] = newLen;
    this->textAreaStr = updatedContent;
    ui->textArea->appendPlainText(QString::fromStdString(updatedContent));
    cursorHopTo(qPos[_pos], qPos[_newlen]);

    return;
}

void textEditor::cursorHopTo(int pos , int len) {

    qPos[_pos] = pos, qPos[_len] = len;
    qc.setPosition(pos, QTextCursor::MoveAnchor);
    qc.setPosition(pos + len, QTextCursor::KeepAnchor);

    ui->textArea->setTextCursor(qc);

    return;
}

void textEditor::initStatistics() {

    string content = ui->textArea->toPlainText().toStdString();
    int blocks = ui->textArea->blockCount();
    fileStats.initStats(content, blocks);
    fileStats.show();

    return;
}

void textEditor::initCompression() {

    string content = ui->textArea->toPlainText().toStdString();
    fileCompress.flushData();
    fileCompress.setEnTextAreaStr(content);
    fileCompress.show();

    return;
}

void textEditor::initComparison() {

    fileCompare.show();
    string content = ui->textArea->toPlainText().toStdString();
    fileCompare.updateCurTextContent(content);

    return;
}

void textEditor::showAboutHelp() {

    helpDocs.show();

    return;
}

