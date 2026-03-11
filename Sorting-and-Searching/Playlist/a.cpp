#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> songs(n);
    int x;
    for(int i = 0; i<n; i++){
        cin >> songs[i];
    }
    map<int, int> window;
    int m_size = 0;
    int l = 0;
    for(int r = 0; r<n; r++){
        if(window.count(songs[r]) == 0){
            window[songs[r]] = r; 
            m_size = max(m_size, int(window.size()));
        }
        else{
            int id = window[songs[r]];
            for(int i = l; i <= id; i++){
                window.erase(songs[i]);
            }
            window[songs[r]] = r;
            l = id+1;
        }
    }

    cout << m_size << endl;
   
    return 0;
}
