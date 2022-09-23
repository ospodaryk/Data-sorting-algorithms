#include "array.h"
#include <iostream>
#include <algorithm>

Array::Array() {
    length = 100xxq;
    arr = new int[length];
    for (int i = 0; i < length; i++) {
        arr[i] = arc4random() % length;
    }
//    for (int i = 0; i < length; i++) {
//        arr[i] =(pow(-1,i))*( arc4random() % 10);
//    }
    std::sort(arr,arr+length);
}

int Array::GetLength() {
    int l = length;
    return l;
}

void Array::DisplayString(QTextEdit *edit) const {
    QString str = "";
    for (int i = 0; i < length; i++) {
        str += QString::number(arr[i]);
        if (i != length - 1) {
            str += "; ";
        }
    }
    str += "\n";
    edit->insertPlainText(str);
}

void Array::BinarSearchfind(int element, QTextEdit *edit) {
    edit->clear();
    int right = 0;
    int left = length;
    int count=0;
    int med = length / 2;
    while ((right <= left) && (arr[med] != element)) {
        count++;
        if (arr[med] < element) { right = med + 1; }
        else { left = med - 1; }
        med = left - ((left - right) / 2);

    }
    if(arr[med]==element){   edit->append("\nПозиція: " + QString::number(med)+"|Кількість порівнянь: " + QString::number(count));
         }else{ edit->append("Елемент не знайдено" );}
}
