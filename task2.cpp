// Bubble Sort Algorithm
#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n-i-1;j++){ // as we know in first allteration last get sorted
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for (int i=0;i<n;i++){
    cout<<arr[i]<<endl;
   }
    
}

int main()
{
    int arr[]={34,6,22,10,11,23,2,5,67,4};
    bubbleSort(arr,10);
    
    return 0;
}