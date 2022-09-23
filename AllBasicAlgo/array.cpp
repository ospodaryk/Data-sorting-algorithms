#include "array.h"
#include <unordered_map>
#include <vector>

Array::Array() {

}

Array::~Array() {
    delete[]arr;
};

int Array::GetLength() {
    int l = length;
    return l;
}



void Array::ReadString(QTextEdit *edit) {
    QStringList split = edit->toPlainText().split(';');
    length = split.size();
    arr = new double[length];
    for (int i = 0; i < length; i++) {
        arr[i] = split[i].toInt();
    }
}

void Array::Random(int n) {
    arr = new double[n];
    for (int i = 0; i < n; i++) {
        arr[i] = arc4random() % 10;
    }
    length = n;
}

void Array::DisplayString(QTextEdit *edit) const {
    QString str = "";
    for (int i = 0; i < length; i++) {
        str += QString::number(arr[i]);
        if (i != length - 1) {
            str += ";";
        }
    }
    str += "\n";
    edit->insertPlainText(str);
}

void Array::Display(QTextEdit *edit,int arrays[]) const {
    QString str = "";
    for (int i = 0; i < length; i++) {
        str += QString::number(arrays[i]);
        if (i != length - 1) {
            str += ";";
        }
    }
    str += "\n";
    edit->insertPlainText(str);
}



void Array::Bubble(QTextEdit *edit) {
    int fl = 0;
    int tmp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                fl = 1;
                DisplayString(edit);
            }
        }
        if (fl == 0) { break; }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------//

void Array::SelectionSort(QTextEdit *edit) {
    //    int tmp;
    //    int max = 0;
    //    int minj = 0;
    //    for (int i = 0; i < length; i++) {
    //        max = 0;
    //        minj = 0;
    //        for (int j = i; j < length; j++) {
    //            if (max < arr[j]) {
    //                max = arr[j];
    //                minj = j;
    //            }
    //        }
    //        if (arr[i] > max) {
    //            tmp = arr[i];
    //            arr[i] = arr[minj];
    //            arr[minj] = tmp;
    //        }
    //        DisplayString(edit);
    //    }
    int tmp;
    int min = arr[0];
    int minj = 0;
    for (int i = 0; i < length; i++) {
        min = arr[i];
        for (int j = i; j < length; j++) {
            if (min > arr[j]) {
                min = arr[j];
                minj = j;
            }
        }
        if (arr[i] > min) {
            tmp = arr[i];
            arr[i] = arr[minj];
            arr[minj] = tmp;
        }
        DisplayString(edit);
    }


}






































//----------------------------------------------------------------------------------------------------------------------------------------//


void Array::Shella(QTextEdit *edit) {
    Indyvidual2();
    DisplayString(edit);
    double tmp;
    int step = length / 2;
    while (step > 0) {
        for (int i = 0; i < length - step; i++) {
            for (int j = i; j >= 0; j--) {
                if (arr[j] > arr[j + step]) {
                    tmp = arr[j];
                    arr[j] = arr[j + step];
                    arr[j + step] = tmp;
                }
            }
        }
        step = step / 2;
        DisplayString(edit);
    }
}

void Array::Indyvidual2() {
    int arrtmp[length];
    for (int i = 0; i < length; i++) { arrtmp[i] = arr[i]; }
    for (int i = 0; i < length; i++) {
        if (arrtmp[i] % 2 == 0.0) {arr[i] = pow(fabs(arr[i] - 10), 0.5); } }
}



//----------------------------------------------------------------------------------------------------------------------------------------//

void Array::qs_sort(QTextEdit *edit) {
    int forsorting[length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }
    quickSorttmp(edit,forsorting,0, length-1);
    for (int i = 0; i < length; i++) {
        arr[i] = forsorting[i];
    }
}

int Array::partition(QTextEdit *edit,int arr[], int begin, int end) {
    int tmp = 0;
    int pivot = arr[end];
    int pIndex = begin;
    for (int i = begin; i < end; i++) {
        if (arr[i] < pivot) {
            tmp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = tmp;
            pIndex++;} }
    for (int j = begin; j < end; j++) { edit->insertPlainText(QString::number(arr[j])+";");}
    edit->insertPlainText("\n");
    tmp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = tmp;
    for (int j = begin; j < end; j++) {edit->insertPlainText(QString::number(arr[j])+";"); }
    edit->insertPlainText("\n");
    return pIndex;
}
void Array::quickSorttmp(QTextEdit *edit,int arr[], int begin, int end) {
    if (begin < end) {
        int indextodivide = partition(edit,arr, begin, end);
        quickSorttmp(edit,arr, begin, (indextodivide - 1));
        quickSorttmp(edit,arr, (indextodivide + 1), end); }
}


//----------------------------------------------------------------------------------------------------------------------------------------//


void Array::merge_sort( int begin, int end,QTextEdit *edit) {
    int middleofarray;
    if (begin < end) {
        middleofarray = (begin + end) / 2;
        merge_sort( begin, middleofarray,edit);
        merge_sort( middleofarray + 1, end,edit);
        merge( begin, end, middleofarray,edit); }}


void Array::merge( int begin, int end, int middleofarray,QTextEdit *edit) {
    int i, j, k, z[50];
    i = begin;
    k = begin;
    j = middleofarray + 1;
    while ((i <= middleofarray) && (j <= end)) {
        if (arr[i] < arr[j]) {
            z[k] = arr[i];
            i++; } else {
            z[k] = arr[j];
            j++; }
        k++;}
    while (i <= middleofarray) {
        z[k] = arr[i];
        k++;
        i++;}
    while (j <= end) {
        z[k] = arr[j];
        k++;
        j++; }
    for (i = begin; i < k; i++) {  arr[i] = z[i]; }
    DisplayString(edit);
}



void Array::Indyvidual3(QTextEdit *edit) {
    int max = 0;
    int maxi = 0;
    int tmp[length];

    int k=0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if(arr[i]==arr[j]){
                k++;} }
        tmp[i]=k;
        k=0; }
    for (int j = 0; j < length; j++) {
        if (max < tmp[j]) {
            max = tmp[j];
            maxi=j;} }
    for (int j = 0; j < length; j++) {tmp[j]=arr[j]; }

    std::unordered_map<int, int> mp;
    for (int i = 0; i < length; ++i) {

        mp[tmp[i]]++;}
    int f=0;
    for (int i = 0; i < length; ++i) {

        if (mp[tmp[i]] < max) {
            arr[f]=tmp[i];
            f++;}}
    length-=max;}




//----------------------------------------------------------------------------------------------------------------------------------------//

void Array::CountingSort( QTextEdit *edit) {
    for (int i = 0; i < length; i++) {
        if(arr[i]<0){
            arr[i]=sin(arr[i]);
        }}
    std::unordered_map<int, int> mp;
    for (int i = 0; i < length; ++i) {
        mp[arr[i]]++;
    }
    double tmp[length];
    std:: vector<double> temp;
    for (int i = 0; i < length; ++i) {
        int flag = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[j] == arr[i]) {
                flag = 0;
                break;
            }
        }
        if (flag==1) { temp.push_back(arr[i]); }
    }
    length = temp.size();
    for (int i = 0; i < length; ++i)
        arr[i] = temp[i];
    for (int j = 0; j < length; ++j) {
        tmp[j]=arr[j];
    }
    SelectionSort(tmp);
    for (int j = 0; j < length; ++j) {
        arr[j]=tmp[j];
    }
    SelectionSort(tmp);
    edit->insertPlainText("\n" );
    std:: vector<double> result;
    for (int j = 0; j < length; j++) {
        for(int i=0;i<mp[tmp[j]];i++){
            result.push_back(tmp[j]);
        }
    }
    length = result.size();
    for (int i = 0; i < length; ++i)
    {arr[i] = result[i];}
    DisplayString(edit);
}


void Array::Indyvidual4(QTextEdit *edit,double tmp[]) {
    for (int i = 0; i < length; i++) {
        if(arr[i]<0){
            tmp[i]=sin(tmp[i]);
        }}
    DisplayString(edit);
}

void Array::SelectionSort(double tmparray[]) {
        double tmp;
        int step = length / 2;
        while (step > 0) {
            for (int i = 0; i < length - step; i++) {
                for (int j = i; j >= 0; j--) {
                    if (tmparray[j] < tmparray[j + step]) {
                        tmp = tmparray[j];
                        tmparray[j] = tmparray[j + step];
                        tmparray[j + step] = tmp;
                    }
                }
            }
            step = step / 2;
        }
}














































void Array::Indyvidual1() {
    int max = 0;
    int maxi = 0;
    for (int i = 0; i < length; i++) {
        if (max < arr[i]) {
            max = arr[i];
            maxi = i;
        }
    }
    int min = max;
    int mini = 0;
    for (int i = 0; i < length; i++) {
        if (min > arr[i]) {
            min = arr[i];
            mini = i;
        }
    }
    for (int i = maxi; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    length--;
    for (int i = mini; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    length--;
}
//----------------------------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------------------------------------------------//

