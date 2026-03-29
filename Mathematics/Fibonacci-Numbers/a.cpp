#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

const vector<vector<ll>> fib = {
    {0,1},
    {1, 1}
};

const vector<vector<ll>> id = {
    {1, 0},
    {0, 1}
};

const vector<vector<ll>> ini = {
    {0},
    {1}
};

inline long long mod(ll x){
    return ((x % MOD) + MOD) % MOD;
}

inline long long mul(ll a, ll b){
    return mod(a*b);
}

inline long long add(ll a, ll b){
    return mod(a+b);
}

vector<vector<ll>> mult_mat(const vector<vector<ll>> &A, const vector<vector<ll>> &B){
    int ra, ca, rb, cb;
    ra = A.size();
    ca = A[0].size();
    rb = B.size();
    cb = B[0].size();
    vector<vector<ll>> C(ra, vector<ll>(cb, 0));
    for(int i = 0; i < ra; i++){
        for(int j = 0; j < cb; j++){
            for(int k = 0; k < ca; k++){
                C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
            }
        }
    }
    return C; 
}

vector<vector<ll>> binpow(const vector<vector<ll>> &A, ll n){
    if(n == 0)
        return id; 
    if(n & 1)
        return mult_mat(A, binpow(A, n-1));
    auto res = binpow(A, n/2);
    return mult_mat(res, res);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << mult_mat(binpow(fib, n-1), ini)[1][0] << endl;

    return 0;
}
