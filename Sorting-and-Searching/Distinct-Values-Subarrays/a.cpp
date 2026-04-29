#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll s_n(ll len){
    ll ans = (len+1)*len;
    ans /= 2;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &x: nums)
        cin >> x;
    int l = 0, r= 0;
    map<int, int> window;
    ll cnt= 0;
    while(r <= n-1){
        if(window.count(nums[r]) == 0){
            //cerr << "No repetido " << endl;
            //cerr << "L " << l << " R " << r << endl;
            window[nums[r]] = r;
        }
        else{
            //cerr << "Repetido "  << endl;
            //cerr << "L " << l << " R " << r << endl;
            cnt += s_n(r-l);
            l = window[nums[r]]+1;
            cnt -= s_n(r-l);
            window[nums[r]] = r;
        }
        if(r == n-1){
            //cerr << "Ultimo "  << endl;
            //cerr << "L " << l << " R " << r << endl;
            int len = r-l+1;
            cnt += s_n(len);
        }
        r++;
    }
    cout << cnt << endl;
   
    return 0;
}
