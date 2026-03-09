#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int q;
    cin >> q;
    while(q--){

        ll k;
        cin >>k;
        if(k <= 9){
            cout << k << endl;
            continue;
        }
        ll sum = 0;
        ll number_digits = 1;
        ll multiplier= 1;
        while(sum + 9*number_digits*multiplier< k){
           sum += 9*number_digits*multiplier;
           multiplier*=10;
           number_digits++;
        }
        ll ans = 1;
        for(int i = 1; i < number_digits; i++){
            ans*=10;
        }
        ll x = k-sum;
        x--;
        x /= number_digits;
        ans += x;
        int idx = number_digits - ((k-sum-1)%number_digits);
        idx--;
        while(idx >0){
            ans /=10;
            idx--;
        }
        cout << ans % 10 <<"\n";
    }

    return 0;
}
