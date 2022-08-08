// Online C++ compiler to run C++ program online
/*
 1. start from leftmost element of array and compare with finding value
  one by one of array element ;

  2.if matches the target value of array element it will be return index
  3.if does not match target value of array element it will be return -1
  4.time complexcity is O(n);
 */

#include <bits/stdc++.h>
using namespace std;

int linear_search(int size, int arr[], int value)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40,10};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(n ,arr ,x);
    cout<<result ;
    return 0;
}