#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> aplicants(n);
    vector<int> appartments(m);

    for(int i =0; i < n; i++)
        cin >> aplicants[i];
    for(int i =0; i < m; i++)
        cin >> appartments[i];

    sort(aplicants.begin(), aplicants.end());
    sort(appartments.begin(), appartments.end());

    int idx_apli = 0;
    int idx_app = 0;
    int cnt= 0;
    while(idx_apli < n and idx_app < m){
        if(aplicants[idx_apli]-k<= appartments[idx_app] and appartments[idx_app] <= aplicants[idx_apli] + k){
            cnt++;
            idx_apli++;
            idx_app++;
        
        }
        else if(appartments[idx_app] < aplicants[idx_apli]-k){
            idx_app++;
        }
        else{
            idx_apli++;
        }
    }
    cout << cnt << endl;

    return 0;
}
