#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n< 4){
        cout << "IMPOSSIBLE";
        return 0;
    }
    ll x;
    cin >> x;
    vector<pair<ll,int>> nums(n);
    for(int i = 0; i < n; i++){
        ll val;
        cin >> val;
        nums[i] = {val,i};
    }
    sort(nums.begin(), nums.end());
    map<ll, pair<int,int>> pairs;
    ll fsum = nums[0].first + nums[1].first;
    pairs[fsum] = {0,1};
    for(int i = 2; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            ll sum = nums[i].first + nums[j].first;
            ll complement = x-sum;
            auto it = pairs.find(complement);
            if(it != pairs.end()){
                auto &[x1,y1] = it->second;
                cout << nums[i].second +1 << " ";
                cout << nums[j].second +1 << " ";
                cout << nums[x1].second +1 << " ";
                cout << nums[y1].second +1 << " ";
                cout << endl;
                return 0;
            }
        }
        for(int j = 0; j < i; j++){
            ll newsum = nums[i].first + nums[j].first;
            pairs[newsum] = {j, i};
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;

}

