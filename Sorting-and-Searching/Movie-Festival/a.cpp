#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    vector<tuple<int, int, int>> events;
    vector<pair<int, int>> movies;
    for(int i = 0; i< n; i++){
        cin >> a >> b;
        events.emplace_back(a, 0, i);
        events.emplace_back(b, 1, i);
        movies.emplace_back(a, b);
    }
    sort(events.begin(), events.end());
    int watched = 0;
    int current = -1;
    for(const auto&[time, type, id]: events){
        if(id == current and type == 1){
            current = -1;
            watched++;
            continue;
        }
        if(type == 0){
            if(current == -1){
                current = id;
            }
            if(movies[current].second == time){
                current = id;
                watched++;
                continue;
            }
            else if(movies[current].second > movies[id].second){
                current = id;
            }
        }

    }
    cout << watched << endl;
    return 0;
}
