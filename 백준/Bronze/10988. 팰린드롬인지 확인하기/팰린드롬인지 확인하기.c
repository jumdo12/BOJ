#include <stdio.h>

int main(){
    char arr[101], arr2[101];
    int idx=0,flag =0;

    scanf("%s",&arr);

    while(arr[idx]){
        idx++;
    }
    
    for(int i=idx-1; i>(idx-1)/2; i--){
        arr2[idx-i-1] = arr[i];
    }

    for(int i=0; i<idx/2; i++){
        if(arr[i] != arr2[i]){
            flag=1;
        }
    }

    if(!flag){
        printf("1");
    }
    else{
        printf("0");
    }

    return 0;
}