#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int, int> nums;
    int n;
    cin >> n;
    int x;
    int max_val = 1;
    for(int i = 0; i < n; i++){
        cin >> x;
        nums[x]++;
        max_val = max(max_val, x);
    }
    int ans = 1;
    for(auto &[key, value]: nums){
        if(value > 1){
            ans = max(ans, value);
        }
        for(int i = value*2; i <= max_val; i+=value){
            if(nums.count(i) > 0){
                ans = max(ans, value);





    }

    cout << ans << endl;

   
    return 0;
}
