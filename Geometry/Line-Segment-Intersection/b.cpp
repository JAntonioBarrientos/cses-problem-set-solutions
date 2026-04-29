#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point2d{
    ll x;
    ll y;
    point2d(): x(0), y(0) {}
    point2d(ll x, ll y): x(x), y(y){}
    point2d& operator+=(const point2d& t){
        x += t.x;
        y += t.y;
        return (*this);
    }
    point2d& operator-=(const point2d& t){
        x -= t.x;
        y -= t.y;
        return (*this);
    }
    point2d operator+(const point2d &t) const{
        return point2d(*this) +=t;
    }
    point2d operator-(const point2d &t) const{
        return point2d(*this) -=t;
    }
};

ll cross_prod(const point2d &a, const point2d &b){
    return a.x * b.y - a.y* b.x;
}

int sng(ll x){
    if (x > 0)
        return 1;
    if (x <0)
        return -1;
    return x;
}

bool contains(const point2d &a, const point2d &b, const point2d &p){
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<point2d> points;
    while(t--){
        bool touch = true;
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point2d a(x1,y1);
        point2d b(x2,y2);
        point2d c(x3,y3);
        point2d d(x4,y4);

        if(sng(cross_prod(a-b, a-c)) == sng(cross_prod(a-b, a-d))){
            touch = false;
        }
        if(sng(cross_prod(c-d, c-a)) == sng(cross_prod(c-d, c-b)))
            touch = false;
        if(cross_prod(a-b, a-c) == 0 and cross_prod(a-b, a-d) == 0){
            if(contains(a,b,c) or contains(a,b, d) or contains(c,d, a) or contains(c,d, b))
                touch = true;
        }
        if(touch)
            cout << "YES\n";
        else
            cout << "NO\n";
        points.clear();
    }
    return 0;
}





