#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int curr = 1;
    int ans = 1;
    for(int i = 1; i <n;i++){
        if(s[i] != s[i-1])
            curr = 0;
        curr++;
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}