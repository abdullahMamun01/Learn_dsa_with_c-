#include <iostream>
#include "MYSTACK.h"
using namespace std;
int prefix(string str){
    Stack <int> pref;
    int len = str.length();
    for(int i=len-1;i>=0;i--){
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
    cout<<prefix("+*827"); // 827-+

    return 0;
}