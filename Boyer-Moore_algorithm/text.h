#ifndef TEXT_H
#define TEXT_H

#include "mainwindow.h"
#include <iostream>
#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>
#include <QMainWindow>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<QCheckBox>
#include<QComboBox>
#include<QFileDialog>
#include <QIntValidator>
#include <QListWidget>
#include <fstream>
#include <string>

class Text
{
public:
    QString logging;
    Text();
    int  search(std::string word,  std::string text, QTextEdit *time);
    void indyvidual(QTextEdit *edit, QTextEdit *edit2, QTextEdit *time, QTextEdit *ALLtime);
    int  search2(std::string word,  std::string text, QTextEdit *time);
    void indyvidual2(QTextEdit *edit, QTextEdit *edit2, QTextEdit *num, QTextEdit *time, QTextEdit *ALLtime);
    QVector<int> prefixFunction(QString pattern);
    int KMPsearch(QString pattern, QString text);
};

#endif // TEXT_H
