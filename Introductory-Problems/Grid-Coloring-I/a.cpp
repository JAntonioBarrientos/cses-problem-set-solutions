#include <bits/stdc++.h>
using namespace std;
 
int mex(const vector<int> &a){
    int n = a.size();
    vector<bool> usados(n+1);
    for(int i = 0; i < n; i++){
        if(a[i] < n)
            usados[a[i]] = true;
    }
    int id = 0;
    int mex = 0;
    while(usados[id]){
        mex++;
        id++;
    }
    return mex;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    char x;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            a[i][j] = x - 'A';
        }
    }
 
    vector<vector<int>> sol(n, vector<int> (m, 0));
    sol[0][0] = mex({a[0][0]});
    for(int i = 1; i < n; i++){
        sol[i][0] = mex({sol[i-1][0], a[i][0]});
    }
 
    for(int j = 1; j < m; j++){
        sol[0][j] = mex({sol[0][j-1], a[0][j]});
    }
 
    for(int i = 1; i <n; i++){
        for(int j = 1; j < m; j++){
            sol[i][j] = mex({sol[i-1][j], sol[i][j-1], a[i][j]});
        }
    }
 
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cout << char(sol[i][j]+'A');
        }
        cout << "\n";
    }
 
 
    return 0;
}
