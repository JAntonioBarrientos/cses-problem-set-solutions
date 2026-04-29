#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<ll> nums(n);
    for(auto &y: nums)
        cin >> y;
    int l = 0; ll sum = 0; ll cnt = 0;
    for(int r = 0; r < n; r++){
        sum += nums[r];
        while(sum > x and l<=r){
            sum -= nums[l];
            l++;
        }
        if(sum == x)
            cnt++;
    }
    cout << cnt << endl;
   return 0;
}
