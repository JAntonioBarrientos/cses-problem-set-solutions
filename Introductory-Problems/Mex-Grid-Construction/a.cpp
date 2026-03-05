#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector(n, 0));
    for(int i = 0; i < n; i++){
        grid[0][i] = i;
        grid[i][0] = i;
    }
    for(int i = 1; i< n; i++){
        for(int j = 1; j < n; j++){
            vector<bool> mex(2*n+2, false);

            for(int x = 0; x < i; x++){
                mex[grid[x][j]] = true;
            }
            for(int y = 0; y < j; y++){
                mex[grid[i][y]] = true;
            }

            int ans = 0;
            for(int i = 0; i<2*n+2; i++){
                if(!mex[i]){
                    ans = i;
                    break;
                }
            }
            grid[i][j] = ans;
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j <n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
