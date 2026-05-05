#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point{
    ll x;
    ll y;
    point(): x(0), y(0) {}
    point(ll x, ll y): x(x), y(y) {}

    point& operator+=(const point other){
        x += other.x;
        y += other.y;
        return (*this);
    }
    point& operator-=(const point other){
        x -= other.x;
        y -= other.y;
        return (*this);
    }
    point operator+(const point &other) const{
        return point(*this) += other;
    }
    point operator-(const point &other)const{
        return point(*this) -= other;
    }
};

ll shoelace(const vector<point> &pol, int n){
    ll ans = 0;
    for(int i = 0; i <n; i++){
        ans += pol[i].x*pol[(i+1)%n].y;
        ans -= pol[i].y * pol[(i+1)%n].x;
    }
    return abs(ans);
}

ll boundary(const vector<point> &pol, int n){
    ll ans = n;
    for(int i = 0; i < n; i++){
        point p = pol[(i+1) % n] - pol[i];
        ans+= gcd(p.x, p.y)-1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll x, y;
    vector<point> polygon(n);
    for(int i = 0;  i < n; i++){
        cin >> x >> y;
        polygon[i] = point(x,y);
    }
    ll area2 = shoelace(polygon, n);
    ll b = boundary(polygon, n);
    ll i = (area2+2 -b)/2;
    cout << i << " " << b << endl;
    return 0;
}

