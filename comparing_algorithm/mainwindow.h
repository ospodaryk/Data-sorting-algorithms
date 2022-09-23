#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVector>


#include <QMainWindow>
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    int *arr;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Random_3_clicked();

    void on_a_bubble_clicked();

    void on_a_selectionsort_clicked();

    void on_a_shella_clicked();

    void on_a_qssort_clicked();

    void on_a_cs_clicked();

    void on_a_merge_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
