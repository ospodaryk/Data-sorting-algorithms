#include "LAb2.h"

ProductList::ProductList() {

}



ProductList::~ProductList() {
};



void  ProductList::ReadString(QTextEdit *edit) {
    QStringList split = edit->toPlainText().split(',');
    length = split.size();
    array = new int[length];
    for (int i = 0; i < length; i++) {
        array[i] = split[i].toInt();
    }
}



void ProductList::Read(QTextEdit *edit) {
    QStringList split = edit->toPlainText().split(',');
    length = split.size();
    arr = new QString[length];
    for (int i = 0; i < length; i++) {
        { arr[i] = split[i]; }
    }
}


void ProductList::DisplayString(QTextEdit *edit) {
    for (int i = 0; i < length; i++) {
        edit->insertPlainText(arr[i] + "\n");
    }
}

void ProductList::Display(QTextEdit *edit) const {
    QString str = "";
    for (int i = 0; i < length; i++) {
        str += QString::number(array[i]);
        if (i != length - 1) {
            str += ",";
        }
    }
    str+="\n";
    edit->insertPlainText(str);
}

void ProductList::SortAlphabet(QTableWidget *list, QTextEdit *edit) {

    QString productlist;

    length = list->rowCount();


    double avg =FindAverage(list);
    //------------------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < list->rowCount(); i++) {
        QTableWidgetItem* product = list->item(i,0);
        productlist +=product->text();
        productlist += ",";}
    double price[ list->rowCount()];
    for (int i = 0; i < list->rowCount(); i++) {
        price[i]=list->item(i, 1)->text().toDouble();
    }
    //------------------------------------------------------------------------------------------------------------------------------

    QStringList splittt = productlist.split(',');
    length = splittt.size();
    arr = new QString[length];
    for (int i = 0; i < length; i++) {
        {arr[i] = splittt[i];}
    }

    //------------------------------------------------------------------------------------------------------------------------------
    QString max;
    QString tmp;

    int maxj;
    for (int i = 0; i < length; i++) {
        if(price[i]<avg){
            max=arr[i];
            maxj=i;
            for (int j = i; j < length; j++) {
                if(price[j]<avg){
                    if(max>arr[j]){
                        max=arr[j];
                        maxj=j;
                    }}
            }
            if(arr[i]>max){
                tmp=arr[i];
                arr[i]=arr[maxj];
                arr[maxj]=tmp;
            }}
        DisplayString(edit);
    }
    //------------------------------------------------------------------------------------------------------------------------------




}

double ProductList::FindAverage(QTableWidget *list) {
    double avg = 0;
    for (int i = 0; i < list->rowCount(); i++) {
        avg += list->item(i, 1)->text().toDouble();
    }
    avg /= list->rowCount();
    return avg;
}








void ProductList::SelectionSort(QTextEdit *edit) {

    int tmp;
    int min=0;
    int minj=0;
    for (int i = 0; i < length-i; i++) {
        min=0;
        minj=0;
        for (int j = i; j < length; j++) {
            if(min<array[j]){
                min=array[j];
                minj=j;
            }

        }
        if(array[i]<min){
            tmp=array[i];
            array[i]=array[minj];
            array[minj]=tmp;
        }
        DisplayString(edit);
    }

}





