#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "text.h"
#include <cstdio>
#include <cstring>

#include <vector>

#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
 Text obj;
 obj.indyvidual(ui->text1,ui->text2,ui->res,ui->time,ui->ttime);
}

