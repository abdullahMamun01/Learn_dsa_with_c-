#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

void insertAtBottom(Stack<int> &st, int checkElement)
{

    //check stack empty or not
    if (st.isEmpty())
    {
        st.push(checkElement);
        return;
    }
    int topElement = st.top() ; 
    st.pop(); // 3
    insertAtBottom(st, checkElement);
    st.push(topElement);

}
//reverse stack
void reverseStack(Stack<int> &st)
{
    if (st.isEmpty())
    {
        return;
    }
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);


    // st->pop();
    // st->pop();
    // st->pop();
    return 0;
}