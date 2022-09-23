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
class Text
{
public:
    Text();
    int  search(std::string pat,  char* txt, QTextEdit *edit, QTextEdit *time);
    void indyvidual(QTextEdit *edit, QTextEdit *edit2, QTextEdit *time, QTextEdit *ttime, QTextEdit *res);

};

#endif // TEXT_H
