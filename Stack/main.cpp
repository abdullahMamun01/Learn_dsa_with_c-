#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;

int main()
{
    // Write C++ code her;
    Stack * st = new Stack();
    cout<<"Choice 1 : push"<<endl
        <<"Choice 2 : Node size"<<endl
        <<"Choice 3 : pop "<<endl
        <<"Choice 4 : check top"<<endl
        <<"Choice 5 : display all element"<<endl
        <<"Choice 0 : Exit "<<endl ;
    cout<<"Next choice : ";
    int choice ;
    cin>>choice ;
    while (choice !=0)
    {
        /* code */
        switch (choice)
        {
        case 1:
            cout<<"insert to push value ";
            int p ;
            cin>>p;
            st->push(p);
            break;
        case 2: 
            int s ;

            s = st->size() ;
            cout<<s<<endl;
            break;
        case 3:
            st->pop() ;
            break;
        case 4:
            int v ;
            v = st->top();
            cout<<v<<endl;
            break;
        case 5 :
            st->display() ;
            break;

        default:
            break;
        }
        cout<<"Next choice :";
        cin>>choice;
    }
    
    
    return 0;
}