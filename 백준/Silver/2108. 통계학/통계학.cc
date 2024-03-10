#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int N,flag,mode,mid,range,avg,max=0;
    double sum = 0;
    
    std::vector<int> v;
    int arr[8001] = {0};
    int most = 0;

    std::cin>>N;
    for(int i=0; i<N; i++){
        int temp;
        std::cin >> temp;
        v.push_back(temp);
        arr[temp+4000]++;
        sum += temp;
    }

    sort(v.begin(),v.end());
    if(sum < 0){
        avg = sum / N - 0.5;
    }
    else{
        avg = sum / N + 0.5;
    }
    mid = v[N/2];

    flag = 0;
    for(int i=0; i<8001; i++){
        if(!arr[i]) continue;
        if (arr[i] == most){
            if (flag)
            {
                mode = i - 4000;
                flag = 0;
            }
        }
        if(arr[i] > most){
            mode = i - 4000;
            most = arr[i];
            flag = 1;
        }    
    }

    range = v[v.size()-1] - v[0];

    std::cout<<avg<<'\n'<<mid<<'\n'<<mode<<'\n'<<range;

    return 0;
}