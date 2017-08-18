#include <stdio.h>
#define MAX 50
int stackr[MAX]={-1};
int rtop=-1;
int stackc[MAX]={-1};
int ctop=-1;
void pushr(int key){
    if(rtop==MAX-1){
        return;
    }
    stackr[++rtop]=key;
}
int popr(){
    if(rtop==-1){
        return -1;
    }
    return stackr[rtop--];
}
void pushc(int key){
    if(ctop==MAX-1){
        return;
    }
    stackc[++ctop]=key;
}
int popc(){
    if(ctop==-1){
        return -1;
    }
    return stackc[ctop--];
}
void traverse(int n,int array[][n],int visited[][n]){
    visited[0][0]=1;
    int i=0,j=0;
    while(i<n && j<n){
        printf("in while loop with i and j %d,%d\n",i,j);
        printf("%d,%d,%d,%d\n",array[i][j+1],array[i+1][j],array[i][j-1],array[i-1][j]);
        if(i==n-1 && j==n-1){
            break;
        }
        if(array[i][j+1]==1 && j+1<n){
            j++;
            pushr(i);
            pushc(j);
            visited[i][j]++;
        }else{
            printf("in first:%d,%d,%d\t",i,j,array[i][j+1] );
        }
        if(array[i+1][j]==1 && i+1<n){
            i++;
            pushr(i);
            pushc(j);
            visited[i][j]++;
        }else{
            printf("in second %d,%d,%d\t",i,j,array[i+1][j]);
        }
        if(array[i][j-1]==1 && j-1>=0){
            j--;
            pushr(i);
            pushc(j);
            visited[i][j]++;
        }else{
            printf("in third:%d,%d,%d\t",i,j,array[i][j-1]);
        }
        if(array[i-1][j]==1 && i-1>0){
            i--;
            pushr(i);
            pushc(j);
            visited[i][j]++;
        }else{
            printf("in fourth:%d,%d,%d\t",i,j,array[i-1][j]);
        }
        if(array[i][j+1]==0 && array[i+1][j]==0 && array[i][j-1]==0 && array[i-1][j]==0){
            i=popr();
            j=popc();
        }
    }
}
int main(){
    int n=4;
    int array[4][4];
    int visited[4][4]={{0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&array[i][j]);
        }
    }
    traverse(n,array,visited);
}