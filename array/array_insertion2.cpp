// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n;
    cin >> n;
    int arr[10];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Intsert position number : ";
    int pos;
    cin >> pos;
    cout<<"Enter value " ;
    int value;
    cin>>value ;
    if (pos < 0||pos > n)
        cout<<"Invalid inset position";
    else
    {
        arr[n] = arr[pos] ;
        arr[pos] = value ;
    }
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}