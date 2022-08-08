// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int binary_search(int n , int arr[],int target){
    int left = 0;
    int right = n-1;
   //Input: [11,22,44,60], 13
   
    while (left <= right) { // terminates when lo == hi
        int mid = left + ((right - left) / 2);
        if (arr[mid] == target) {
            return mid ;
        } else if(arr[mid] < target) {
            left = mid + 1;
            if(arr[left+1] > target && arr[left] < target  ){
                return left+1 ;
            }
        }else{
            right = mid - 1 ;
            if(arr[right-1] < target && arr[right] > target  ){
                return right ;
            }
        }
    }
    return left;
}
int main() {
    // Write C++ code here
    int n;
    cin>>n ;
    int arr[n];
    for(int i=0 ;i<n;i++){
        cin>>arr[i] ;
    }
    int target ;
    cin>>target;
    // cout<<"Ta"
    int r = binary_search(n ,arr,target);
    cout<<r;
    return 0;
}