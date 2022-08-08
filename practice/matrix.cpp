// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
/*
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1

n - 

*/

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }

    }
    int mid = n / 2 ;
    int firs_row_half = (n/2) - 1; 
    int last_col = n-1 ;
    int last_row_half =n - firs_row_half -1 ; 
    int sum = 0;

      for(int i=0;i<=firs_row_half;i++)
    {
        sum+=arr[0][i] ;
        sum+=arr[i][last_col];
    }
      for(int i=last_row_half;i<n;i++)
    {
        sum+=arr[n-1][i] ;
        sum+=arr[i][0];
    }
      for(int i=0;i<n;i++)
    {
        // cout<<"mid : "<<arr[i][mid]<<" ";
        // sum+=arr[mid][i] ;
        // sum+=arr[i][mid];
    }
    cout<<sum<<endl;
;

    return 0;
}