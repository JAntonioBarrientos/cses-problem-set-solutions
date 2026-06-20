#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12;

struct Segment{
    vector<ll> st;
    int n;
    vector<ll> elem;
    
    Segment(int n, const vector<ll> &elem): n(n), elem(elem){
        st.resize(4*n);
        build(1, 1, n);
    }

    void build(int v, int l, int r){
        if(l == r){
            st[v] = elem[l];
            return;
        }
        int m = (l+r)/2;
        build(2*v,l, m); 
        build(2*v+1, m+1, r);
        st[v] = min(st[v*2], st[v*2+1]);
    }

    ll query(int v, int l, int r, int a, int b){
        if(l<= a and b <= r){
            return st[v];
        }
        if(b< l or a > r){
            return INF;
        }
        int m = (a+b)/2;
        ll x = query(2*v,l,r, a, m);
        ll y = query(2*v+1,l, r, m+1, b);  
        return min(x,y);
    }

    void update(int v, ll x, int p, int a, int b){
        if(a == b){
            st[v] = x;
            return;
        }
        int m = (a+b)/2;
        if( p <=m){
            update(2*v, x, p, a, m);
        }
        else{
            update(2*v+1,x,p,m+1,b);
        }
        st[v] = min(st[v*2], st[v*2+1]);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> elem(n+1);
    for(int i = 1; i<=n; i++)
        cin >> elem[i];
    int t, l, r;
    Segment s(n, elem);
    while(q--){
        cin >> t >> l >> r;
        if(t == 1)
             s.update(1, r, l, 1, n);
        else
            cout << s.query(1, l, r, 1, n) << "\n"; 
    }
    return 0;
}
