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
Text::Text() {

}

int Text::search(string word, char *text, QTextEdit *edit,QTextEdit *time) {
    auto begin = chrono::high_resolution_clock::now();
    int index = 0;
    int wordlength = (word).length();
    int textlength = strlen(text);
    vector<string> steps;
    for (int i = 0; i <= textlength - wordlength; i++) {
        int j;
        for (j = 0; j < wordlength; j++){
            if (text[i + j] != word[j]) {

                string q;
                q = text[i + j];
                steps.push_back(q);
                steps.push_back(" != ");

                string l;

                l += word[j];
                steps.push_back(l);
                steps.push_back("\n");
                break;
            }else{
                steps.push_back("----------------\n");
                string q;
                q = text[i + j];
                steps.push_back(q);
                steps.push_back(" = ");
                string l;
                l += word[j];
                steps.push_back(l);
                steps.push_back("\n");
            }

        }
        if (j == wordlength)  {
            steps.push_back("Element find in Position ");
            steps.push_back(QString::number(i).toStdString());
            index = i;
            break;
        }
    }
    for (int i = 0; i < steps.size(); i++) {
        string s = steps[i];
        edit->insertPlainText(QString::fromStdString(steps[i]));
    }
    auto threads_time = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - begin).count();
    time->insertPlainText(QString::number(threads_time));

    return index;
}

void Text::indyvidual(QTextEdit *edit, QTextEdit *edit2, QTextEdit *time, QTextEdit *ttime, QTextEdit *res) {
    auto begin = chrono::high_resolution_clock::now();
    string ctext1_a = edit->toPlainText().toStdString();
    string ctext2_a = edit2->toPlainText().toStdString();
    char ctext1[edit->toPlainText().size()];
    char ctext2[edit2->toPlainText().size()];

    for (int i = 0; i < edit->toPlainText().size(); i++) {
        ctext1[i] = ctext1_a[i];
    }
    for (int i = 0; i < edit2->toPlainText().size(); i++) {
        ctext2[i] = ctext2_a[i];
    }
    int text1_length = strlen(ctext1);
    int text2_length = strlen(ctext2);
    std::vector<string> words;
    std::vector<int> countofletters;
    int k = 0;
    for (int i = 0; i < text1_length; i++) {
        if (ctext1[i] == ' ') {
            string tmp;
            for (int t = k; t < i; t++) {
                tmp += (ctext1[t]);
            }
            k = i + 1;
            words.push_back(tmp);
        }
    }
    int count = 0;
    for (int j = 0; j < words.size(); j++) {
        int length = words[j].length();
        for (int i = 0; i < length; i++) {
            char c = words[j][i];
            if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'y')) {
                count++;
            }
        }
        countofletters.push_back(count);
        count = 0;
    }

    int max = 10;
    int index = 0;
    for (int j = 0; j < countofletters.size(); j++) {
        if (countofletters[j] < max) {
            max = countofletters[j];
            index = j;
        }
    }

    int length = words[index].length();
    std::vector<char> temporary;

    for (int j = 0; j < length; j++) {
        temporary.push_back(words[index][j]);
    }
    std::reverse(temporary.begin(), temporary.end());

    char ourfinalword[length];

    for (int j = 0; j < temporary.size(); j++) {
        ourfinalword[j] = temporary[j];
    }
    char cword[length];

    for (int i = 0; i < length; i++) {
        cword[i] = words[index][i];
    }
    string wordd;
    for (int j = 0; j < length; j++) {
        wordd += cword[j];
    }
    int p = search(wordd, ctext2,  time,res);
    int o = 0;
    for (int i = p; i < length + p; i++) {
        ctext2[i] = ourfinalword[o];
        o++;
    }
    string t;
    for (int i = 0; i < text2_length; i++) {
        t += ctext2[i];
    }
    edit2->clear();
    edit2->insertPlainText(QString::fromStdString(t));


    auto threads_time = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - begin).count();
    ttime->insertPlainText(QString::number(threads_time));
}
