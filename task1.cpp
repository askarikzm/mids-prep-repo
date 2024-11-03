// Insertion Sort Sorting algorithm
#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
   for (int i=0;i<n;i++){
    cout<<arr[i]<<endl;
   }
}

int main()
{
    int arr[10]={34,6,22,10,11,23,2,5,67,4};
    insertionSort(arr,10);
    
    return 0;
}