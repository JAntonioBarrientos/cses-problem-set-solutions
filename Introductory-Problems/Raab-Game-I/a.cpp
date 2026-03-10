#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;

        if(a+b > n ){
            cout << "NO\n";
            continue;
        }
        int ties = n -(a+b);
        vector<int> player1;
        vector<int> player2;
        if(!(a>0 and b>0) and ties != n){
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < ties; i++){
            player1.push_back(n);
            player2.push_back(n);
            n--;
        }
        vector<bool> taken1(n+1);
        vector<bool> taken2(n+1);

        int rounds = max(a,b);
        int id1 = 2;
        while(rounds--){
            if(id1 >= n){
                id1 = n;
            }
            if(taken2[id1-1]){
                id1++;
            }

            taken1[id1] = true;
            taken2[id1-1] = true;
            player1.push_back(id1);
            player2.push_back(id1-1);
            id1+=2;
            if(id1 == n+2){
               id1 = 3;
            }
        }
        rounds = min(a,b); 
        id1 = 1;
        int id2 = 1;
        while(rounds--){
            while(taken1[id1]){
                id1++;
            }
            while(taken2[id2]){
                id2++;
            }
            player1.push_back(id1);
            player2.push_back(id2);
            id1++;
            id2++;
        }
        cout << "YES" << "\n";
        if(a >= b){
                
            for(int i = 0; i < player1.size(); i++){
                cout << player1[i] << " ";
            }
            cout << "\n";
            
            for(int i = 0; i < player2.size(); i++){
                cout << player2[i] << " ";
            }
            cout << "\n";
        }
        else{

            for(int i = 0; i < player2.size(); i++){
                cout << player2[i] << " ";
            }
            cout << "\n";

            for(int i = 0; i < player1.size(); i++){
                cout << player1[i] << " ";
            }
            cout << "\n";
        }
    }

   
    return 0;
}
