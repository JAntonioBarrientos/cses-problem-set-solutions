#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> customers;
    for(int i =0; i< n; i++){
        int x;
        cin >> x;
        tickets.insert(x);
    }

    for(int i =0; i< m; i++){
        int cus;
        cin >> cus;
        auto it = tickets.upper_bound(cus);
        if(it != tickets.begin()){
            it--;
            cout << *it << "\n";
            tickets.erase(it);
        }
        else{
            cout << -1 << "\n";
        }
    }

    return 0;
}
