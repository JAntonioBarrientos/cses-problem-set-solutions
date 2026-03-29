#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_X = 1e6;

vector<int> num_div(MAX_X+1, 1); 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 2; i <= MAX_X; i++){
        int mult = i;
        while(mult <= MAX_X){
            num_div[mult]++;
            mult +=i;
        }
    }
    while(n--){
        int x;
        cin >> x;
        cout << num_div[x] << "\n";
    }
    return 0;
}
