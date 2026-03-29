#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int josephus(int k, int n){
    return 0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    int k,n;
    cin >> k >> n;
    //while(q--)
    //    cout << josephus(k, n) << "\n";
    for(int i = 1; i <= 14; i++){
        vector<int> v;
        for(int j = 0; j < i; j++)
            v.push_back(j);
        int idx = 0;
        cout << "Len " << i << endl;
        k = 1;
        while (!v.empty()) {
            idx = (idx + k) % v.size();
            cout << v[idx] << " ";
            v.erase(v.begin() + idx);
        }
        cout << endl;
    }




    return 0;
}
