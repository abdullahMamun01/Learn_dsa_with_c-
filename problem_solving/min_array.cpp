// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Write C++ code here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort((arr), arr + n);
        int firs_el = arr[0];
        int set;
        for (int i = 0; i < n; i++)
        {
            if (firs_el == arr[i])
            {
                set = i;
            }
        }
        cout << n - set;
    }
    return 0;
}