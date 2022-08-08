// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void print_array(int n ,int arr[]){
    for(int i =0 ;i<n ;i++){
        cout<<arr[i] << " " ;
    }
}
int main() {
    // Write C++ code here
    int n = 5 ;
    int arr[5] = {5,4,1,2,3};
    print_array(n,arr);
    cout<<endl;
    for(int i=1 ;i<n ;i++){
        int key = arr[i] ;
        int j = i-1 ;
        while(j>=0 && arr[j] > key){
            cout<<"before sorted "<<"arr["<<j<<"]="<<arr[j]<<" key->"<<key<<endl;
         cout<<"now j ="<<j <<endl;
            arr[j+1] = arr[j] ;
         j-- ;
         
         print_array(n,arr);
         cout<<endl;
        }
        cout<<endl ;
        arr[j+1] = key ;
        cout<<"after sorted "<<endl;
        print_array(n,arr);
        cout<<endl;
    }

//   for(int i=0 ;i<n ;i++){
//       cout<<arr[i] << " ";
//     }
    return 0;
}