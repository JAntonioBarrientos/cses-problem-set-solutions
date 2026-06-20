#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e4;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> bits(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int num = 0;
        for(int j = 0;j <k; j++){
            if(s[j] == '1'){
                num |= (1 <<j );
            }
        }
        bits[i] = num;
    }
    int ans = INF;
    for(int i =0; i <n-1; i++){
        for(int j = i+1; j <n; j++){
            ans = min(ans, __builtin_popcount(bits[j]^bits[i]));
        }
    }
    cout << ans << endl;
    return 0;
}
