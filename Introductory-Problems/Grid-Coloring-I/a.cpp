#include <bits/stdc++.h>
using namespace std;
using ll = long long;


char mex(const vector<char> &letter){
    vector<bool> vecmex(4);
    for(auto x: letter){
        vecmex[int(x-'A')]= true;
    }

    for(int i = 0; i< 4; i++){
        if(!letter[i]){
            return char(i+'A');
        }
    }
    return 'A';
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> grid;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    for(int i = 0; i <n; i++){
        for(int j = 0; j <m; j++){



        }
    }

   
    return 0;
}
