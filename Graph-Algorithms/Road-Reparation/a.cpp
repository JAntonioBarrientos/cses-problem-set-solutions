#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU{
    vector<int> parent, size;

    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool union_s(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)
            return false;
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<ll, int,int>> edges;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a-1, b-1});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll total = 0;
    int edcnt = 0;
    for(auto [w, a, b]: edges){
        if(dsu.union_s(a,b)){
            total += w;
            edcnt++;
            if(edcnt == n-1){
                break;
            }
        }
    }
    if(edcnt != n-1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << total << "\n";
    }
    return 0;
}
