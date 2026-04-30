#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int k = 6;

struct Matrix{
    ll m[k][k];

    Matrix(){
        memset(m, 0, sizeof(m));
    }

    static Matrix identity(){
        Matrix id;
        for(int i = 0; i < k; i++){
            id[i][i] = 1;
        }
        return id;
    }

    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i = 0; i< k; i++){
            for(int l = 0; l < k; l++){
                for(int j = 0; j < k; j++){
                    res[i][j] += (m[i][l] * other.m[l][j]) % MOD;
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix binpow(ll p){
        if(p == 0)
            return identity();
        if(p & 1){
            return (*this) * binpow(


    Matrix& operator^(ll p){
       return binpow(p); 
    }




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll dp[6] = {0};
    dp[0] = 1; 
    for(int i = 1; i <=5; i++){
        for(int j = 1; j <= 6; j++){
            if(i-j >=0){
                dp[i] += dp[i-j];
            }
        }
    }
    Matrix m;



   
    return 0;
}
