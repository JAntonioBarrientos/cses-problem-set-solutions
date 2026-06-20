#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    nth_element(nums.begin(), nums.begin()+n/2, nums.end());
    ll val = nums[n/2];

    ll cost =0;
    for(auto x: nums){
        cost+= abs(x-val);
    }
    cout << cost << endl;
    return 0;
}

