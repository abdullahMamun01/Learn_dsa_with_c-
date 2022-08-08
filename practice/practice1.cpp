/*
remove duplicate element of array
*/

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// void sorted_array(int size, int arr[])
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 swap(arr[i], arr[j]);
//             }
//         }
//     }
// }

// void remove_duplicate_elements(int size, int arr[])
// {
//     int k = size -1 ;
//     sorted_array(size, arr);
//     for(int i=0 ;i<size;i++){
//         if(arr[i-1] == arr[i]){
//             arr[i-1] = arr[k];
//             k-- ;
//         }
//     }

// }

int main()
{
    // Write C++ code here
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };
    int tmp[n];
    for (int i = 0; i < n; i++)
    {
        int k =  n ;
        for (int j = i + 1; j < k; j++)
        {
            if (arr[i] == arr[j])
            {
                int tmp = arr[j];
                arr[j] = arr[n-1];
                arr[n-1] = tmp;
                // for(int k=j ;k<n;k++){
                //     arr[k] = arr[k+1];
                // }
                n -- ; 
                // cout<<j <<" j "<<arr[j] <<endl;
                // j-- ;
                cout<<j <<endl;
            }
          
            // --n;
        }
    };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    };

    return 0;
}