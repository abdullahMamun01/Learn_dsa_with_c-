#include <iostream>
#include <string>
using namespace std;

int main()
{
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
        int key = arr[0] ;
        int count = 0;
         for (int i = 1; i < n; i++)
        {
            int key = arr[i] ;
            if(arr[i]==key){
                continue;
            }else{
                arr[i+1] = key ;
                count++;
            }
            arr[i-1] = key ;
        }
        cout<<count<<endl;
    }
    return 0;
}