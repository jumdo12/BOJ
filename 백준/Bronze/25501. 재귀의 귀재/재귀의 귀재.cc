#include <stdio.h>
#include <string.h>

void recursion(const char *s, int l, int r, int cnt){
    if (l >= r){
        printf("1 %d\n",cnt);
    }
    else if (s[l] != s[r]){
        printf("0 %d\n", cnt);
    }
    else    recursion(s, l + 1, r - 1 ,cnt + 1);
}

void isPalindrome(const char *s){
    recursion(s, 0, strlen(s) - 1,1);
    return;
}

int main()
{
    int N;
    char buffer[1001];

    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%s",buffer);
        isPalindrome(buffer);
    }
    return 0;
}