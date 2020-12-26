/*
C++ program to sort an array in increasing and decreasing order using STL  
*/



// Input '1' to perform sorting in increasing order and '2' for decreasing order

#include<iostream>
#include <typeinfo>
#include<sstream>
#include<algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
string token = argv[1]; //To find the sorting order, increasing or decreasing
stringstream token_int(token);// For casting string to int
int temp = 0; //Stores the string values as an int in variable temp
token_int >>temp;

if(temp==1)
{
    cout<<"Perform sorting in Increasing order"<<endl;
}
if(temp==2)
{
    cout<<"Perform sorting in Decreasing oder"<<endl;
}
if (!(temp==2 || temp==1))
{
    cout<<"Type either 1 or 2"<<endl;
    return 0;
}

int arr[] = { 1, 62, 54, 23, 45, 24, 15, 4, 14, 15, 17 }; // initialize the array
int n = sizeof(arr) / sizeof(arr[0]); // To find the size of array
cout<<"Unsorted Array : ";
for(int i =0; i<n; i++) //Prints the array
{
    cout<<arr[i]<<',';
}
cout<<endl;
//Increasing Order
if(temp==1)
{
    sort(arr, arr + n ); // Sort in increasing order
    cout<<"Sorted Array : ";
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<',';
    }
    cout<<endl;
}
//Decreasing Order
if(temp==2)
{
    sort(arr, arr + n, greater<int>() ); // Sort in increasing order
    cout<<"Sorted Array : ";
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<',';
    }
    cout<<endl;
}

return 0; 
}




