#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> events;
    int a, b;
   for(int i = 0; i < n; i++){
        cin >> a >> b;
        events.emplace_back(a, 0, i);
        events.emplace_back(b, 1, i);
    }
    sort(events.begin(), events.end());
    set<int> clients;
    vector<int> rooms(n, -1);
    set<int> free_rooms;
    for(int i = 1; i <= n; i++){
        free_rooms.insert(i);
    }
    int needed_rooms = 0;
    for(auto &[time, type, id]: events){
        if(type == 0){
            clients.insert(id);
            auto it = free_rooms.begin();
            rooms[id] = *it; 
            free_rooms.erase(it);
        }
        else{
            clients.erase(id);
            free_rooms.insert(rooms[id]);
        }
        needed_rooms = max(needed_rooms, int(clients.size()));
    }
    cout << needed_rooms << endl;
    for(int i = 0; i < n; i++){
        cout << rooms[i] << " ";
    }
    cout << endl;
    return 0;
}
