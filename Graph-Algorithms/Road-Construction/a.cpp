#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU{
    vector<int> parent, size;
    int cc, mcc;
    
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
        cc = n;
        mcc = 1;
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    bool union_s(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        cc--;
        mcc = max(mcc, size[a]);
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        dsu.union_s(a-1, b-1);
        cout << dsu.cc << " " << dsu.mcc << "\n";
    }
    return 0;
}
