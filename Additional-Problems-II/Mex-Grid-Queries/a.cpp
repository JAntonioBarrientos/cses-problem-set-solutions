#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll y, ll x){
    if(y == x){
        return 0;
    }
    if(y >x){
        swap(y,x);
    }
    if(y % 2 == 1 and x == y+1){
        return 1;
    }
    bool increasing = true;
    int temp = x;
    temp--;
    temp /= 2;
    if(temp % 2 == 0){
        increasing = false;
    }
    int or_x, or_y;
    if(x % 2 == 0){
        or_x = x;
        or_y = or_x-1;
    }
    else{
        or_x = x+1;
        or_y = or_x-1;
    }
    ll ans = 1;
    if(increasing){
        ans += or_y - y;
        if(x  % 2 == 1){
            if(y % 2 == 1){
                ans--;
            }
            else{
                ans++;
            }
        }
    }
    else{
        ans = or_y-1;
        ans += y-1;
        if(x % 2 == 0){
            if(y % 2 == 0){
                ans--;
            }
            else{
                ans++;
            }
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int y,x;
    cin >> y >> x;
    cout << solve(y,x) << endl;
    return 0;
}
