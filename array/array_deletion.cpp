// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter delete position number : ";
    int del_pos;
    cin >> del_pos;
    if (del_pos == n - 1)
        n--;
    else
    {
        for (int i = del_pos + 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        n--;
    }

    // n--;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}