#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<bool> taken(n+1);
    ll sum = (n*(n+1))>> 1;
    if(sum % 2 == 1){
        cout << "NO" << endl;
        return 0;
    }
    ll target = sum >> 1;
    int id = n;
    int cnt = 0;
    while(target != 0){
       target -= id;
       taken[id] = true;
       cnt++;
       id--;
       if(0 < target and target < id){
           taken[target] = true;
           target = 0;
           cnt++;
       }
    }
    cout <<"YES" << "\n" << cnt << "\n";
    for(int i = 1; i < n+1; i++){
        if(taken[i])
            cout << i << " ";
    }
    cout << "\n" << n - cnt << "\n";
    for(int i = 1; i < n+1;i++){
        if(!taken[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
