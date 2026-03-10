#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> event;
    int a,b;
    for(int i = 0; i < n;i++){
        cin >> a >> b;
        event.push_back({a, 0});
        event.push_back({b, 1});
    }
    sort(event.begin(), event.end());
    int count = 0;
    int ans = 0;
    for(auto &[time, type]: event){
        if(type == 0)
            count++;
        else
            count--;
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}
