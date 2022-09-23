#ifndef ARRAY_H
#define ARRAY_H


#include<limits.h>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<unordered_map>
class Array {
protected:
    int length=0;
//    int *arr;
//    int *arr2D[];
    double *arr;


public:
    Array();
     ~Array();
    int GetLength();

    void ReadString(QTextEdit *edit);
    void DisplayString(QTextEdit *edit) const;
    void Bubble(QTextEdit *edit);
void Random(int n);
void Indyvidual1();
void Indyvidual2();
void Indyvidual3(QTextEdit *edit);
void Indyvidual4(QTextEdit *edit,double tmp[]);

void Shella(QTextEdit *edit);

void SelectionSort(QTextEdit *edit);

void swap( long pos1, long pos2);

int DIVIDE(QTextEdit *edit,int index, int arrray[], int tocompare, int length);
void Display(QTextEdit *edit, int arrays[]) const;
void merge( int begin, int end, int middleofarray,QTextEdit *edit);
void merge_sort( int begin, int end,QTextEdit *edit);
void CountingSort(QTextEdit *edit);
void SelectionSort(double tmparray[]);
void quickSorttmp(QTextEdit *edit,int *arr, int begin, int end);
int partition(QTextEdit *edit,int arr[], int begin, int end);
void qs_sort(QTextEdit *edit );

};

#endif // ARRAY_H
