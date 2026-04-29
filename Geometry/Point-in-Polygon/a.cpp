#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point2d {
    ll x, y;
    point2d(): x(0), y(0){}
    point2d(ll x, ll y): x(x), y(y) {}
    point2d operator-(const point2d &t) const {
        return point2d(x - t.x, y - t.y);
    }
};

ll cross_prod(const point2d &a, const point2d &b) {
    return a.x * b.y - a.y * b.x;
}

bool contains(const point2d &a, const point2d &b, const point2d &p) {
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<point2d> polygon(n);
    for(int i = 0; i < n; i++){
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    for(int i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        point2d p(x, y);
        
        bool boundary = false;
        int count_inter = 0;
        
        for(int j = 0; j < n; j++){
            point2d a = polygon[j];
            point2d b = polygon[(j + 1) % n];
            
            if (cross_prod(a - p, b - p) == 0 && contains(a, b, p)) {
                boundary = true;
                break;
            }
            
            if (a.y <= p.y && b.y > p.y) { 
                if (cross_prod(b - a, p - a) > 0) count_inter++;
            } 
            else if (b.y <= p.y && a.y > p.y) { 
                if (cross_prod(a - b, p - b) > 0) count_inter++;
            }
        }
        
        if (boundary) {
            cout << "BOUNDARY\n";
        } else if (count_inter % 2 != 0) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
    return 0;
}
