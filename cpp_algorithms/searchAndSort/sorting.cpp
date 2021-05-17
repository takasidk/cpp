#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
    int min=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
        }
        int temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
    }
}
void bubbleSort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        int flag=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(flag==0) {cout<<n-i<<" iterations"<<endl;break;}
    }
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
       // int val=arr[i];
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
void merge(int *L,int nl,int *R,int nr,int arr[]){
    int i=0,j=0,k=0;
    while(i<nl && j<nr){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<nr){
        arr[k]=R[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int n){
    
    if(n<2){
        return;
    }
    int mid=n/2;
   int *L=new int [mid];
    int * R =new int [n-mid];
    for(int i=0;i<mid;i++){
        L[i]=arr[i];
    }
    for(int i=mid;i<n;i++){
        R[i-mid]=arr[i];
    }
    mergeSort(L,mid);
    mergeSort(R,n-mid);
    merge(L,mid,R,n-mid,arr);
    delete []L;
    delete []R;
}
int partition(int arr[],int start,int end){
    int pindex=start;
    int pivot=arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex],arr[end]);
    return pindex;
}
void quickSort(int arr[],int start,int end){
    if(start<end){
        int pindex=partition(arr,start,end);
        quickSort(arr,start,pindex-1);
        quickSort(arr,pindex+1,end);
    }
}
int main(){
    int arr[6]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    //selectionSort(arr,n);
    //bubbleSort(arr,n);
    //insertionSort(arr,n);
   // mergeSort(arr,n);
    quickSort(arr,0,n-1);
    for(auto x:arr){cout<<x<<" ";}
}
