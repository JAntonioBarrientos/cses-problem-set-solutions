#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n>> x;
    vector<int> children(n);
    for(int i =0; i < n;i++)
        cin >> children[i];

    int ans = 0;
    sort(children.begin(), children.end());

    int p_end = n-1;
    int p_beg = 0;

    while(p_beg <= p_end){
        if(children[p_end] + children[p_beg] <= x)
            p_beg++;
        p_end--;
        ans++;
    }


    cout << ans << endl;

   
    return 0;
}
