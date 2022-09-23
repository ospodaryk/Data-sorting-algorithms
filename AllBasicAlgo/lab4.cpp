#include "lab4.h"


Array2D::Array2D() {
    arr2D[length] = new int[ length];
    for (int i = 0; i < length; i++) {
        arr2D[i] = new int[length];
    }
}

Array2D::~Array2D() {
    delete[]arr;
};


void Array2D::initialisation2Darray() {

    length = 5;
    arr2D[length] = new int[ length];
    for (int i = 0; i < length; i++) {
        arr2D[i] = new int[length];
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {

            arr2D[i][j] =arc4random() % 10;
        }
    }
    length = 5;
}


void Array2D::allocate() {
    for (int i = 0; i < length; i++) {
        arr2D[i] = new int[length];
    }}


void Array2D::qs_sort( QTextEdit *edit) {  
    int forsorting[5];
    for (int i = 0; i < 5; i++) {forsorting[i] = arr2D[0][i];}
    for (int i = 0; i < 5; i++) {  forsorting[i] = arr2D[0][i]; }
    quickSorttmp(edit,forsorting,0, 4);
    for (int i = 0; i < 5; i++) {  arr2D[0][i] = forsorting[i];  }
}

int Array2D::partition(QTextEdit *edit,int arr[], int begin, int end) {
    int tmp = 0;
    int pivot = arr[end];
    int pIndex = begin;
    for (int i = begin; i < end; i++) {
        if (arr[i] < pivot) {
            tmp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = tmp;
            for (int k = 1; k < 5; k++) {
                tmp= arr2D[k][pIndex];
                arr2D[k][pIndex]=arr2D[k][i];
                arr2D[k][i]=tmp;  }
            pIndex++;} }
    for (int j = begin; j < end; j++) {edit->insertPlainText(QString::number(arr[j])+";");}
    edit->insertPlainText("\n");
    tmp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = tmp;
    for (int k = 1; k < 5; k++) {
        tmp= arr2D[k][pIndex];
        arr2D[k][pIndex]=arr2D[k][end];
        arr2D[k][end]=tmp; }
    for (int j = begin; j < end; j++) { edit->insertPlainText(QString::number(arr[j])+";");}
    edit->insertPlainText("\n");
    return pIndex;}
void Array2D::quickSorttmp(QTextEdit *edit,int arr[], int begin, int end) {
    if (begin < end) {
        int indextodivide = partition(edit,arr,  begin, end);
        quickSorttmp(edit,arr, begin, (indextodivide - 1));
        quickSorttmp(edit,arr, (indextodivide + 1), end);
    }
}



void Array2D::SWAP(int *arrray2D[],int iindex1,int iindex2) {
    int tmp;
    for (int i = 1; i < 5; i++) {
        tmp= arrray2D[i][iindex1];
        arrray2D[i][iindex1]=arrray2D[i][iindex2];
        arrray2D[i][iindex2]=tmp;
    }
}
void Array2D::Display(QTextEdit *edit) const {
    QString str = "";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            str += QString::number(arr2D[i][j]);

            str += ";";

        } str += "\n";}
    str += "\n";
    edit->insertPlainText(str);
}
