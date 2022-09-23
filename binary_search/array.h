#ifndef ARRAY_H
#define ARRAY_H

#include <QTextEdit>

class Array
{
protected:
    int length=0;
    int *arr;

public:
    int GetLength();
    void DisplayString(QTextEdit *edit) const;

    Array();
    void BinarSearchfind(int element, QTextEdit *edit);

};

#endif // ARRAY_H
