#include "text.h"
#include "mainwindow.h"
#include <vector>
#include <string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<string>
#include <cstring>
#include <cstring>
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using namespace std;
Text::Text()
{

}


int Text::search(string word,string text,QTextEdit *time) {
    auto begin = chrono::high_resolution_clock::now();
    bool check;
    int sz = word.length();
    vector<int> prefix(sz);

    int index=0;
    for (int i = 1; i < sz; ++i) {
        int j = prefix[i - 1];
        while (j > 0 && word[i] != word[j]) {
            j = prefix[j - 1];
        }
        if (word[i] == word[j]) {
            ++j;
        }
        prefix[i] = j;
    }
    logging+= "Pi : ";

    for (int i = 0; i < sz; ++i) {
        logging += QString::number(prefix[i]) + " ";    }
    logging+= "\n";

    int M = word.length();
    int N = text.length();

    int i = 0, j = 0;

    while(i < N){

        if(j > 0 && word[j] != text[i + j]){
            i += j - prefix[j - 1];
            j = 0;
            logging += QString::number(i) + ")";

            logging += text[i + j];
            logging+="!=" ;
            logging+= word[j];
            logging+= "\n";
            check=false;
        }
        if(word[j] == text[i + j]){
            logging +=  QString::number(j + 1) + ")";

            logging += text[i + j];
            logging+="==" ;
            logging+= word[j];
            logging+= "\n";
            check=true;
            j++;
        } else {
            i++;
            logging +=QString::number(i) + ")";
            logging += text[i + j];
            logging+="!=" ;
            logging+= word[j];
            logging+= "\n";
            check=false;

        }

        if (j == M) {
            logging += "---------------------\n";
            if(check==false) {logging += "We not find our word =(";}else{logging += "We find our word at position: "+ QString::number(i);}
            break;
        }
    }

    auto threads_time = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - begin).count();
    time->insertPlainText(QString::number(threads_time));
}

void Text::indyvidual(QTextEdit *edit, QTextEdit *edit2, QTextEdit *time, QTextEdit *ALLtime) {
    auto begin = chrono::high_resolution_clock::now();

    string text1 = edit->toPlainText().toStdString();
    string text2 =  edit2->toPlainText().toStdString();
//    double leng=0;
//    double avg=0;
//    QStringList todivide= QString::fromStdString(text1).split(" ");

//    for(int i=0;i<todivide.size();i++){
//        leng+=todivide[i].length();
//    }
//    avg=leng/todivide.size();
    //logging+="Length "+QString::number(leng)+"\n"+"Size "+QString::number(todivide.size())+"\n"+"AVG "+QString::number(avg)+"\n";
    logging += "---------------------\n";

    string word="abcba";
//    for(int i=0;i<todivide.size();i++){
//        if(todivide[i].length()==avg){
//            word=todivide[i].QString::toStdString();
//        }
//    }
    search(word,text2,time);


    auto threads_time = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - begin).count();
    ALLtime->insertPlainText(QString::number(threads_time));
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
int Text::search2(string word,string text,QTextEdit *time) {
    std::map<char, int> result;
    bool check;

    int m = word.length();
    int step=1;
    for(int i = m - 2; i >= 0; i--){
        if(result.count(word[i]) == 0){
            result[word[i]] = step;
        }
        step++;
    }

    char last = word[m - 1];
    if(result.count(last) == 0) {
        result[last] = m;
    }

    logging += "Pi:\n";
    for(auto sym: result){
        logging += QString(sym.first)+" ";
    }
    logging += "\n";

    for(auto sym: result){
        logging += QString::number(sym.second) + " ";
    }
    logging += "\n";


    int n = text.length();

    if(m > n){
        return 404;
    }

    int i = m - 1;
    int j = m - 1;

    while((j > 0) && (i < n)){
        if(text[i] == word[j]){
            i--;
            j--;
            check=true;
            if(i < n){
                logging+="\n";
     logging+=text[i]+"\n" ;
                logging +=  QString::number(i) + ")";

                logging += text[i];
                logging+="==" ;
                logging+= word[j];
                logging+= "\n";
            }
        } else{
            check=false;
            logging+="\n";
 logging+=text[i]+"\n" ;

            if(result.count(text[i]) == 0){
                i += m;
            } else {
                i += result[text[i]];
            }
            logging +=QString::number(i) + ")";
            logging += text[i];
            logging+="!=" ;
            logging+= word[j];
            logging+= "\n";
            j = m - 1;
        }
    }
    logging += "--------------------------------------------\n";
    if(check==false) {logging += "We not find our word =(";}else{logging += "We find our word at position: "+ QString::number(i)+"\n";}
}
void Text::indyvidual2(QTextEdit *edit, QTextEdit *edit2,QTextEdit *num, QTextEdit *time, QTextEdit *ALLtime) {
    auto begin = chrono::high_resolution_clock::now();

    string word = "Britain";

    QString tmp="London is the capital of Great Britain";
//    QStringList strings=tmp.split("\n");
//    tmp=  strings[num->toPlainText().toInt()]  ;

//    strings[num->toPlainText().toInt()]=strings[strings.size()-2];
//    strings[strings.size()-2]=tmp;
//    QString t;
//    for(int i=0;i<strings.size();i++){
//        t+= strings[i];
//        if(i!=strings.size()-1){
//            t+="\n";}

//    }
//    edit->setText(t);
    string text1 = tmp.toStdString();

    auto st = chrono::high_resolution_clock::now();

    std::map<char, unsigned> result;
//    for(int i=0;i<strings.size();i++){
    //    logging+="________"+QString::number(i)+"________\n";
        search2(word,text1,time);

//    }
    auto thre = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - st).count();
    time->insertPlainText(QString::number(thre));
    auto threads_time = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - begin).count();
    ALLtime->insertPlainText(QString::number(threads_time));
}
