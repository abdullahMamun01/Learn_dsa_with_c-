#include <iostream>
#include "MYSTACK.h"
using namespace std;
int postfix(string str){
    Stack <int> pref;
    int len = str.length();
    for(int i=0;i<len;i++){
        if(str[i] > '0' && str[i]<='9'){
            pref.push(str[i] - '0');
        }else{
            int a = pref.pop();
            int b = pref.pop();
            switch (str[i])
            {
            case '+':
                pref.push(a+b);
                break;
            case '-':
                pref.push(a-b);
                break;
            case '*':
                pref.push(a*b);
                break;
            case '/':
                pref.push(a/b);
                break;
            default:
                break;
            }
        }
    }
    return pref.top();
    
}
int main()
{
    cout<<postfix("435++"); 

    return 0;
}