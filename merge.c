#include <stdio.h>
void merge(int array[],int low,int mid,int high){
    int lend=mid,l=low;
    int r=mid+1,rend=high;
    int b[high+1];
    int i=0;
    while(l<=mid && r<=high){
        if(array[l]<=array[r]){
            b[i++]=array[l++];
        }else{
            b[i++]=array[r++];
        }
    }
    while(l<=mid){
        b[i++]=array[l++];
    }
    while(r<=high){
        b[i++]=array[r++];
    }
    int m=0;
    for(int k=low;k<=high;k++){
        array[k]=b[m++];
    }
}
void mergesort(int array[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(array,l,mid);
        mergesort(array,mid+1,r);
        merge(array,l,mid,r);
    }else{
        return;
    }
}
int main(){
    int array[]={8,7,95,5,6,2,9};
    int n=sizeof(array)/sizeof(array[0]);
    printf("%d\n",n);
    mergesort(array,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}