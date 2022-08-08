// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void print_a(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    };
    int max = 0; // define max variable for set max element from a[n] array
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    };
    // now find our max element from a[n] element
    int counter[max + 1] = {0}; // define counter variable which lange max + 1 . max+1 for easy to prefex array calculation
    for (int i = 0; i < n; i++)
    {
        counter[a[i]]++; // counter array for how many elements have in a[i] array suppose if 3 element have duplicate 2 so counter array position 3 in stor 2 
    };
    cout << endl;
    for (int i = 1; i <= max; i++)
    {
        counter[i] += counter[i - 1]; //  now calculate prefex array (not understand wahat is prefex array please search in google about prefex array)
    }
    //after calculation prefex array now we can print what happend in counter array(optional)
    print_a(counter, max+1);
    cout << endl;
    int final[n]; // now define a final array which length exact a[n] array
    for (int i = 0; i < n; i++)
    {
        counter[a[i]]--;       // reduce counter value for final array value position
        int k = counter[a[i]]; // find a[i] value in counter prefex array
        final[k] = a[i];       // finaly set final array value which is come from k
        cout << "counter[a[i]]-- = " << counter[a[i]] << "; k :" << k << "; a[i] = " << a[i] << endl; //for visualization whatts happen
    };

    print_a(final, n);

    return 0;
}
