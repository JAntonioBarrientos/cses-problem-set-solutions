#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    vector<ll> acc(n+1, 0);
 
    for(int i = 1 ; i<=n; i++){
        acc[i] += acc[i-1] + arr[i-1];
    }
 
    ll ans = -INF;
    int low = 0;
    bool neg = true;
    ll maxi = -INF;
    for(int i = 1; i <= n; i++){
        if(acc[i] < acc[low]){
            low = i;
        }
        if(arr[i-1] >= 0){
            neg = false;
        }
        else{
            maxi = max(maxi, arr[i-1]);
        }
        ans = max(ans, acc[i]-acc[low]);
    }
 
    if(neg){
    ans = maxi;
    }
    cout << ans << endl;
   
    return 0;
}
