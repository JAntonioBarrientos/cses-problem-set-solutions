#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> sums;
    vector<int> val(n);
    for(int i = 0;i < n; i++){
        cin >> val[i];
    }
    sums.insert(val[0]);
    for(int i = 1; i <n; i++){
        set<int> temp;
        temp.insert(val[i]);
        for(auto x: sums){
            temp.insert(x+val[i]);
        }
        sums.merge(temp);
        temp.clear();
    }
    cout << sums.size() << "\n";
    for(auto x: sums)
        cout << x << " ";
    cout << endl;
    return 0;
}
