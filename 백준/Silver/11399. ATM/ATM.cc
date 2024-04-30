#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N,temp,sum;
    std::vector<int> v,s;
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>temp;
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end());

    sum = 0;
    for(int i=0; i<N; i++){
        sum += v[i];
        s.push_back(sum);
    }

    sum = 0;
    for(int i=0; i<N; i++){
        sum += s[i];
    }

    std::cout<<sum;

    return 0;
}