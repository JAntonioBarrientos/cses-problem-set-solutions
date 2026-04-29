#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> val(n);
    for(int i = 0; i <n ; i++)
        cin >> val[i];

    vector<bool> dp(1e5+1, false);
    dp[0] = true;

    sort(val.begin(), val.end());

    for(int i = 0; i < n; i++)
        for(int j = 1e5; j >= 0; j--)
            if(j-val[i] >= 0 and dp[j-val[i]])
                dp[j] = true;
    int cnt = -1;
    for(auto x: dp)
        if(x)
            cnt++;
    cout << cnt << "\n";
    for(int i = 1; i <= 1e5; i++)
        if(dp[i])
            cout << i << " ";

    cout << endl;

    return 0;
}

