#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k;
vector<int> nums;

struct Mex{
    map<int,int> inside;
    set<int> outside;

    Mex(){
        for(int i = 0; i<= k; i++){
            outside.insert(i);
        }
    }

    void insert(int x){
        inside[x]++;
        if(inside[x] == 1){
            outside.erase(x);
        }
    }

    void erase(int x){
        auto it = inside.find(x);
        it->second--;
        if(it->second == 0){
            outside.insert(x);
            inside.erase(it);
        }
    }

    int mex(){
        return *outside.begin();
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Mex m;
    for(int i = 0 ; i < k; i++){
        m.insert(nums[i]);
    }
    cout << m.mex() << " ";
    for(int i = k; i < n; i++){
        m.insert(nums[i]);
        m.erase(nums[i-k]);
        cout << m.mex() << " ";
    }
    cout << "\n";
   
    return 0;
}
