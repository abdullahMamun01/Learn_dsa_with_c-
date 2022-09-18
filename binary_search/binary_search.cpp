/*
1. Array must be sorted before logic of binary search tree;
2.
*/
#include <bits/stdc++.h>
using namespace std;

int binary_search(int n, int arr[], int search_Element)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cout << "hello" << endl;
        if (arr[mid] == search_Element)
        {
            return mid;
        }
        else if (arr[mid] < search_Element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int search_element;
    cout << "Enter search element : ";
    cin >> search_element;
    int res = binary_search(n, arr, search_element);
    cout << res << endl;
}

// This code is contributed by mayanktyagi1709
