#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"
#include "LAb2.h"
#include "lab4.h"

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

void MainWindow::on_Bubble_clicked()
{

    ui->tmp_b->clear();
        ui->res_b->clear();
     Array pArr;
        pArr.ReadString(ui->farray_b);
//     pArr.Indyvidual1();
        pArr.Bubble(ui->tmp_b);
        pArr.DisplayString(ui->res_b);

}


void MainWindow::on_SelectionSort_clicked()
{
    ui->res_ss->clear();
       ProductList pArr;
   pArr.SortAlphabet(ui->list_ss,ui->tmp_ss);
   pArr.DisplayString(ui->res_ss);

}


void MainWindow::on_Random_b_clicked()
{
    ui->tmp_b->clear();
    ui->res_b->clear();
    ui->farray_b->clear();
    QString text = ui->size_b->toPlainText();
    int n=text.toInt();
    Array pArr;
   pArr.Random(n);
   pArr.DisplayString(ui->farray_b);
}


void MainWindow::on_a_bubble_clicked()
{
    ui->a_tmp->clear();
    ui->tmp_b->clear();
        ui->res_b->clear();
     Array pArr;
     pArr.ReadString(ui->a_farray);
pArr.Bubble(ui->a_tmp);
pArr.DisplayString(ui->a_res);

}


void MainWindow::on_a_selectionsort_clicked()
{
    ui->a_tmp->clear();
           Array pArr;
        pArr.ReadString(ui->a_farray);
   pArr.SelectionSort(ui->a_tmp);
   pArr.DisplayString(ui->a_res);

}
















void MainWindow::on_a_shella_clicked()
{
    ui->a_tmp->clear();
           Array pArr;
        pArr.ReadString(ui->a_farray);

   pArr.Shella(ui->a_tmp);
   pArr.DisplayString(ui->a_res);
}


void MainWindow::on_a_qssort_clicked()
{
    ui->a_tmp->clear();
           Array pArr;
        pArr.ReadString(ui->a_farray);

   pArr.qs_sort(ui->a_tmp);
   pArr.DisplayString(ui->a_res);
}


void MainWindow::on_Shella_clicked()
{
    ui->tmp_shella->clear();
           Array pArr;
        pArr.ReadString(ui->farray_shella);

   pArr.Shella(ui->tmp_shella);
   pArr.DisplayString(ui->res_shella);
}


void MainWindow::on_QS_clicked()
{
    ui->tmp_qs->clear();
    ui->farray_qs->clear();

    Array2D pArr;
           pArr.initialisation2Darray();
           pArr.Display(ui->farray_qs);

         pArr.qs_sort( ui->tmp_qs);
           pArr.Display(ui->res_qs);
//   pArr.qs_sort(ui->tmp_qs );
//   pArr.Display(ui->res_qs);
}


void MainWindow::on_Merge_clicked()
{
    ui->tmp_shella->clear();
           Array pArr;
        pArr.ReadString(ui->farray_m);
pArr.Indyvidual3(ui->tmp_m);
   pArr.merge_sort(0,pArr.GetLength(),ui->tmp_m);
   pArr.DisplayString(ui->res_m);
}


void MainWindow::on_Counting_clicked()
{
           Array pArr;
        pArr.ReadString(ui->farray_c);
//        pArr.Indyvidual4(ui->tmp_c);
   pArr.CountingSort(ui->tmp_c);
   pArr.DisplayString(ui->res_c);

}


void MainWindow::on_a_cs_clicked()
{
    ui->a_tmp->clear();
           Array pArr;
        pArr.ReadString(ui->a_farray);

   pArr.CountingSort(ui->a_tmp );
   pArr.DisplayString(ui->a_res);
}


void MainWindow::on_Random_3_clicked()
{
    ui->a_tmp->clear();
    ui->a_res->clear();
    ui->a_farray->clear();
    QString text = ui->all->toPlainText();
    int n=text.toInt();
    Array pArr;
   pArr.Random(n);
   pArr.DisplayString(ui->a_farray);
}


void MainWindow::on_pushButton_clicked()
{
}

