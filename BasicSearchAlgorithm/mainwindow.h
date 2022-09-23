#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

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


    void on_Bubble_clicked();



    void on_SelectionSort_clicked();

    void on_Random_b_clicked();

    void on_a_bubble_clicked();

    void on_a_selectionsort_clicked();

    void on_a_shella_clicked();

    void on_a_qssort_clicked();

    void on_Shella_clicked();

    void on_QS_clicked();

    void on_Merge_clicked();

    void on_Counting_clicked();

    void on_a_cs_clicked();

    void on_Random_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
