#include <stdio.h>
#include <stdlib.h>
void reverseArray(int *arr,int n){
    int i=0;
    while(n>0){
        printf("%d",arr[--n]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    reverseArray(arr,n);
    return 0;
}
