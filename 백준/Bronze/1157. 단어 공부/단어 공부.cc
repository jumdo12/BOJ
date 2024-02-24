#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin>>str;

    int arr[26] = {0};
    int len = str.length();

    for(int i=0; i<len; i++){
        int temp;
        if(str[i] < 'a')   temp = str[i] - 65;
        else temp = str[i] - 97;

        arr[temp]++;
    }

    int idx =0;
    int flag = 0;
    for(int i=1; i<26; i++){
        if(arr[i] > arr[idx]){
            idx = i;
            flag = 0;
        }
        else if(arr[i] == arr[idx]){
            flag = 1;
        }
    }
    
    char Ans = idx + 65;
    if(flag)    std::cout<<"?";
    else    std::cout<<Ans;

    return 0;
}