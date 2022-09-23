#ifndef LAB4_H
#define LAB4_H

#include<limits.h>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>

class Array2D
{

protected:
    int length=5;
    int *arr=new int[length ];
    int **arr2D = new int*[ length];


public:
 Array2D();
 ~Array2D();

void initialisation2Darray();

int DIVIDE(QTextEdit *edit,int index, int arrray[], int tocompare, int length);
int TMP(QTextEdit *edit,int arrray[], int k, int tocompare, int length);
void Display(QTextEdit *edit) const;
void allocate();
void SWAP(int *arrray[],int iindex1,int iindex2);
void quickSorttmp(QTextEdit *edit,int *arr, int begin, int end);
int partition(QTextEdit *edit,int arr[], int begin, int end);
void qs_sort(QTextEdit *edit );

};

#endif // LAB4_H
