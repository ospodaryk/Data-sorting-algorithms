#ifndef LAB2_H
#define LAB2_H

#include<limits.h>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<QTableWidget>

class ProductList
{

protected:
    int length=0;
    QString *arr;
    int *array;

    int*pruce;
public:
    void ReadString(QTextEdit *edit);
    void Display(QTextEdit *edit) const;

    ProductList();
     ~ProductList();
void Read(QTextEdit *edit);
void DisplayString(QTextEdit *edit);
void SortAlphabet(QTableWidget *list, QTextEdit *edit);
void SelectionSort(QTextEdit *edit);
double FindAverage(QTableWidget *list) ;void Print(QTableWidget *list,QTextEdit *edit) ;


};

#endif // LAB2_H
