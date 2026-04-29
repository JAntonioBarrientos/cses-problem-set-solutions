#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point2d{
    ll x;
    ll y;
    point2d(){}
    point2d(ll x, ll y): x(x), y(y) {}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point2d> pts;
    ll x,y;
    for(int i = 0; i <n;i++){
        cin >> x >> y;
        pts.emplace_back(x, y);
    }
    pts.push_back(pts[0]);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += pts[i].x * pts[i+1].y;
        sum -= pts[i].y * pts[i+1].x;
    }
    cout << abs(sum) << endl;
    return 0;
}
