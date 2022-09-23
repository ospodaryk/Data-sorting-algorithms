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
    setCentralWidget(ui->tabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->res->setText("");
    Text obj;
    obj.indyvidual2(ui->text12,ui->out12,ui->num,ui->time12,ui->alltime12);
    ui->res_12->insertPlainText(obj.logging);
    obj.logging="";
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->res->insertPlainText("");

    Text obj;
    obj.indyvidual(ui->text1,ui->text2,ui->time,ui->ttime);
    ui->res->insertPlainText(obj.logging);
    obj.logging="";
}

