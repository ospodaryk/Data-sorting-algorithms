#include "array.h"
#include <unordered_map>
#include <vector>

Array::Array() {
   int n=1000;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = arc4random() % 100;
    }
    length = 1000;
}

Array::~Array() {
    delete[]arr;
};

int Array::GetLength() {
    int l = length;
    return l;
}


void Array::Random(int n) {
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = arc4random() % 10000;
    }
    length = n;
}

void Array::ReadString(QTextEdit *edit) {
    QStringList split = edit->toPlainText().split(';');
    length = split.size();
    arr = new int[length];
    for (int i = 0; i < length; i++) {
        arr[i] = split[i].toInt();
    }
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
void Array::Bubble() {
    int *forsorting=new int[length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }

    int fl = 0;
    int tmp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (forsorting[j] > forsorting[j + 1]) {
                tmp = forsorting[j + 1];
                forsorting[j + 1] = forsorting[j];
                forsorting[j] = tmp;
                fl = 1;
            }
        }
        if (fl == 0) { break; }
    }
    delete []forsorting;

}

//----------------------------------------------------------------------------------------------------------------------------------------//

void Array::SelectionSort() {
    int *forsorting=new int[length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }
    int tmp;
    int min = forsorting[0];
    int minj = 0;
    for (int i = 0; i < length; i++) {
        min = forsorting[i];
        for (int j = i; j < length; j++) {
            if (min > forsorting[j]) {
                min = forsorting[j];
                minj = j;
            }
        }
        if (forsorting[i] > min) {
            tmp = forsorting[i];
            forsorting[i] = forsorting[minj];
            forsorting[minj] = tmp;
        }
    }
    delete []forsorting;


}

//----------------------------------------------------------------------------------------------------------------------------------------//


void Array::Shella() {
    int *forsorting=new int[length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }


    int step = length / 2;
       while (step > 0)
       {
           for (int i = 0; i < length - step; i++)
           {
               int j = i;
               while ((j >= 0) && (forsorting[j] > forsorting[j + step]))
               {
                       int temp = forsorting[j];
                       forsorting[j] = forsorting[j + step];
                       forsorting[j + step] = temp;

                   j--;
               }
           }
           step = step/2;
       }
       delete []forsorting;

}

//----------------------------------------------------------------------------------------------------------------------------------------//

void Array::qs_sort() {

    int forsorting[length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }
    quickSorttmp(forsorting,0, length-1);
\
}


int Array::partition(int arr[], int begin, int end) {
    int tmp = 0;

        int pivot = arr[end];
        int pIndex = begin;
        for (int i = begin; i < end; i++) {
            if (arr[i] < pivot) {
                tmp = arr[i];
                arr[i] = arr[pIndex];
                arr[pIndex] = tmp;
                pIndex++;

            }
        }

        tmp = arr[end];
        arr[end] = arr[pIndex];
        arr[pIndex] = tmp;

        return pIndex;
}
void Array::quickSorttmp(int arr[], int begin, int end) {
    if (begin < end) {
           int indextodivide = partition(arr, begin, end);
           quickSorttmp(arr, begin, (indextodivide - 1));
           quickSorttmp(arr, (indextodivide + 1), end);
       }
}





//----------------------------------------------------------------------------------------------------------------------------------------//

void Array::Merge( ) {
    int *forsorting=new int[2*length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }
merge_sort(forsorting, 0, length) ;
delete []forsorting;
}

void Array::merge_sort(int arrr[], int begin, int end) {

    int middleofarray;
    if (begin < end) {
        middleofarray = (begin + end) / 2;
        merge_sort(arrr, begin, middleofarray);
        merge_sort(arrr, middleofarray + 1, end);
        merge(arrr, begin, end, middleofarray);

    }
}

void Array::merge( int forsorting[],int begin, int end, int middleofarray) {

    int i, j, k;
    int *z=new int[length];;
    i = begin;
    k = begin;
    j = middleofarray + 1;
    while ((i <= middleofarray) && (j <= end)) {
        if (forsorting[i] < forsorting[j]) {
            z[k] = forsorting[i];
            i++; } else {
            z[k] = forsorting[j];
            j++; }
        k++;}
    while (i <= middleofarray) {
        z[k] = forsorting[i];
        k++;
        i++;}
    while (j <= end) {
        z[k] = forsorting[j];
        k++;
        j++; }
    for (i = begin; i < k; i++) {  forsorting[i] = z[i]; }
    delete []z;

}


void Array::CountingSort( ) {
    std::unordered_map<int, int> mp;
        for (int i = 0; i < length; ++i) {
            mp[arr[i]]++;
}
        int *forsorting=new int[length];
    for (int i = 0; i < length; i++) {
        forsorting[i] = arr[i];
    }
    int *tmp= new int[length];
    std:: vector<int> temp;
    for (int i = 0; i < length; ++i) {
        int flag = 1;
        for (int j = 0; j < i; ++j) {
            if (forsorting[j] == forsorting[i]) {
                flag = 0;
                break;
            }
        }
        if (flag==1) { temp.push_back(forsorting[i]); }
    }
    length = temp.size();
    for (int i = 0; i < length; ++i)
    {forsorting[i] = temp[i];}


    for (int j = 0; j < length; ++j) {
        tmp[j]=forsorting[j];
    }
    SelectionSort(tmp);

    std:: vector<int> result;


    for (int j = 0; j < length; j++) {
      for(int i=0;i<mp[tmp[j]];i++){
          result.push_back(tmp[j]);

        }
    }
    length = result.size();

    for (int i = 0; i < length; ++i)
    {forsorting[i] = result[i];}
    delete []forsorting;
    delete []tmp;

}






void Array::SelectionSort(int tmparray[]) {



    int tmp;
    int min = tmparray[0];
    int minj = 0;
    for (int i = 0; i < length; i++) {
        min = tmparray[i];
        for (int j = i; j < length; j++) {
            if (min > tmparray[j]) {
                min = tmparray[j];
                minj = j;
            }
        }
        if (tmparray[i] > min) {
            tmp = tmparray[i];
            tmparray[i] = tmparray[minj];
            tmparray[minj] = tmp;
        }
    }

}
