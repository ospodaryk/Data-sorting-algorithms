#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = "";

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->array->clear();
    Array pArr;
    pArr.DisplayString(ui->array);
    int k=ui->element->toPlainText().toInt();
    pArr.BinarSearchfind(k,ui->position);
}

