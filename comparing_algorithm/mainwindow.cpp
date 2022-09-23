#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Array pArr;

    ui->ssssss->insertPlainText(QString::number(pArr.GetLength()));

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Random_3_clicked()
{
    ui->farray->clear();
    ui->time_b->clear();
    ui->time_counting->clear();
    ui->time_qt->clear();
    ui->time_selection->clear();
    ui->time_shella->clear();
ui->time_merge->clear();
    QString text = ui->ssssss->toPlainText();
    int n=text.toInt();
    Array pArr;
   pArr.Random(n);
   pArr.DisplayString(ui->farray);
}


void MainWindow::on_a_bubble_clicked()
{
    Array pArr;
//    pArr.ReadString(ui->farray);

clock_t start = clock();
pArr.Bubble();
clock_t finish = clock();
double time = ((double)finish - start) / CLOCKS_PER_SEC;

ui->time_b->insertPlainText(QString::number(time));
}


void MainWindow::on_a_selectionsort_clicked()
{
    Array pArr;
//    pArr.ReadString(ui->farray);

clock_t start = clock();
pArr.SelectionSort();
clock_t finish = clock();
double time = ((double)finish - start) / CLOCKS_PER_SEC;

ui->time_selection->insertPlainText(QString::number(time));












}


void MainWindow::on_a_shella_clicked()
{
    Array pArr;
//    pArr.ReadString(ui->farray);

clock_t start = clock();
pArr.Shella();
clock_t finish = clock();
double time = ((double)finish - start) / CLOCKS_PER_SEC;

ui->time_shella->insertPlainText(QString::number(time));
}


void MainWindow::on_a_qssort_clicked()
{
    Array pArr;
//    pArr.ReadString(ui->farray);

clock_t start = clock();
pArr.qs_sort();
clock_t finish = clock();
double time = ((double)finish - start) / CLOCKS_PER_SEC;

ui->time_qt->insertPlainText(QString::number(time));
}


void MainWindow::on_a_cs_clicked()
{
    Array pArr;
//    pArr.ReadString(ui->farray);

clock_t start = clock();
pArr.CountingSort();
clock_t finish = clock();
double time = ((double)finish - start) / CLOCKS_PER_SEC;

ui->time_counting->insertPlainText(QString::number(time));
}


void MainWindow::on_a_merge_clicked()
{
    Array pArr;
//    pArr.ReadString(ui->farray);

clock_t start = clock();
pArr.Merge();
clock_t finish = clock();
double time = ((double)finish - start) / CLOCKS_PER_SEC;

ui->time_merge->insertPlainText(QString::number(time));
}

