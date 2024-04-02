#include <iostream>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int o=0,idx=0,len,temp;
    std::string b;
    std::cin>>b;
    len = b.length();

    if(len % 3 == 1){
        std::cout<<b[idx++];
    }
    else if(len % 3 == 2){
        std::cout<<(b[idx++] - '0') * 2 + (b[idx++] - '0');
    }

    while(idx < len){
        std::cout << (b[idx++] - '0') * 4 + (b[idx++] - '0') * 2 + (b[idx++] - '0');
    }

    return 0;
}