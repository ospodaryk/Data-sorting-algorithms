#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <algorithm>
#include <QMainWindow>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<QCheckBox>
#include<QComboBox>
#include<QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
