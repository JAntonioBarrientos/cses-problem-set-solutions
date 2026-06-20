#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
vector<ll> nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    nums.resize(n);
    for(int i =0 ; i < n; i++){
        cin >> nums[i];
    }
    map<int, int> freq;
    map<int, set<int>> freq_inv;
    for(int i = 0; i <k ; i++){
        freq[nums[i]]++;
    }
    for(auto [key, val]: freq){
        freq_inv[val].insert(key);
    }
    ll mode = *(freq_inv.rbegin()->second).begin();
    vector<int> ans;
    ans.push_back(mode);
    for(int i = k; i< n; i++){
        freq_inv[freq[nums[i]]].erase(nums[i]);
        if(freq_inv[freq[nums[i]]].size() == 0){
            freq_inv.erase(freq[nums[i]]);
        }
        freq[nums[i]]++;
        freq_inv[freq[nums[i]]].insert(nums[i]);

        freq_inv[freq[nums[i-k]]].erase(nums[i-k]);
        if(freq_inv[freq[nums[i-k]]].size() == 0){
            freq_inv.erase(freq[nums[i-k]]);
        }
        freq[nums[i-k]]--;

        if(freq[nums[i-k]] > 0){
            freq_inv[freq[nums[i-k]]].insert(nums[i-k]);
        }
        else{
            freq.erase(nums[i-k]);
        }

        mode = *(freq_inv.rbegin()->second).begin();
        ans.push_back(mode);
    }
    for(int i =0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
   
    return 0;
}
