#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

Stack<string> *reverseString(string sentence)
{
    int n = sentence.length();
    Stack<string> *st = new Stack<string>();

    for (int i = 0; i < n; i++)
    {
        string word = " ";
        while (sentence[i] != ' ' && i < n)
        {
            word += sentence[i];
            i++;
        }
        st->push(word);
    }

    return st;
}

int main()
{

    string sentence = "I am Rakib Tushar";
    reverseString(sentence);
    Stack<string> *st = reverseString(sentence);
    while (!st->isEmpty())
    {
        cout << st->top();
        st->pop();
    }

    // cout<<st->top()<<endl;

    return 0;
}