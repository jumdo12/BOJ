#include <iostream>
#include <queue>

using namespace std;

int main(){
    cout.sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    priority_queue<int> heap;
    int cnt,temp;

    cin>>cnt;

    while(cnt--){
        cin>>temp;
        if(!temp){
            if(heap.empty()){
                cout<<"0"<<'\n';
            }
            else{
                cout<<heap.top()<<'\n';
                heap.pop();
            }
        }
        else{
            heap.push(temp);
        }
    }

    return 0;
}