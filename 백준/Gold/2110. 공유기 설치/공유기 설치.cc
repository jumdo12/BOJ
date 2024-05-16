#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> router;
int N,C;

int solv(){
    int start,end,dist,cnt=0,ans;
    int left = 1, right = router[router.size()-1];

    while(left <= right){
        int mid = (left + right) / 2;

        cnt = 1;
        start = 0;

        for(int i = 1; i<router.size(); i++){
            end = i;

            if(router[end] - router[start] >= mid){
                cnt++;
                start = end;
            }
        }
        if(cnt >= C){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    int tmp;
    std::cin>>N>>C;

    for(int i=0; i<N; i++){
        std::cin>>tmp;
        router.push_back(tmp);
    }
    std::sort(router.begin(),router.end());

    std::cout<<solv();
    return 0;
}