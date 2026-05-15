#include <stdio.h>
int main(){
    int n,i,j=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]!=0){
            a[j]=a[i];
            j++;
        }
    }
    while(j<n){
        a[j]=0;
        j++;
    }
    printf("The array is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}