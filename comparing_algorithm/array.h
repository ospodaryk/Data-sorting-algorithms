#ifndef ARRAY_H
#define ARRAY_H


#include<limits.h>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<unordered_map>
class Array
{

protected:
    int length=0;
    int *arr;

public:
public:
    Array();
     ~Array();
    int GetLength();

    void Bubble();
void Random(int n);

void DisplayString(QTextEdit *edit) const;
void ReadString(QTextEdit *edit);

void Shella();

void SelectionSort();
void Merge( );


void quickSorttmp(int *arr, int begin, int end);
int partition(int arr[], int begin, int end);
void qs_sort( );
int DIVIDE(int index, int arrray[], int tocompare, int length);
int TMP(int arrray[], int begin, int end);
void merge(int forsorting[], int begin, int end, int middleofarray);
void merge_sort(int arrr[], int begin, int end);
void CountingSort();
void SelectionSort(int tmparray[]);

};

#endif // ARRAY_H
