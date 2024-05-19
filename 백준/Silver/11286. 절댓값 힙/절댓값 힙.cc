#include <iostream>
#include <queue>
#include <vector>

using namespace std;


class cmp{
    public:
    bool operator()(int &a, int &b){
        int _a, _b;
        _a = abs(a);
        _b = abs(b);

        if(_a == _b){
            return a > b;
        }
        else{
            return _a > _b;
        }
    }
    int abs(const int &a)
    {
        if (a > 0)
            return a;
        else
            return -a;
    }
};

int main(){
    cout.sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    priority_queue<int, vector<int>,cmp> h;
    int cnt, temp;

    cin>>cnt;

    while(cnt--){
        cin>>temp;
        if(temp){
            h.push(temp);
        }
        else{
            if(h.empty()){
                cout<<"0"<<'\n';
            }
            else{
                cout<<h.top()<<'\n';
                h.pop();
            }
        }
    }

    return 0;
}