#include <stdio.h>
void quicksort(int a[],int l,int r){
    if(l<r){
        int q=partition(a,l,r);
        quicksort(a,l,q-1);
        quicksort(a,q+1,r);
    }
}
int partition(int array[],int l,int r){
    int pivot=array[r];
    int pIndex=l-1;
    for(int i=l;i<=r-1;i++){
        if(array[i]<=pivot){
            pIndex++;
            int temp=array[i];
            array[i]=array[pIndex];
            array[pIndex]=temp;
        }
    }
    int temp=array[r];
    array[r]=array[pIndex+1];
    array[pIndex+1]=temp;
    return pIndex+1;
}
int main(){
    int array[]={8,7,95,5,6,2,9};
    int n=sizeof(array)/sizeof(array[0]);
    quicksort(array,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}