#include <bits/stdc++.h>
using namespace std;
using ftype = long long;

struct point2d{
    ftype x;
    ftype y;

    point2d(): x(0), y(0) {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    point2d& operator+=(const point2d &t){
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t){
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t){
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t){
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const{
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const{
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const{
        return point2d(*this) *=t;
    }
    point2d operator/(ftype t) const{
        return point2d(*this) /=t;
    }
};
point2d operator*(ftype a, point2d b){
    return b*a;
}

ftype cross_product(const point2d &a, const point2d &b){
    return a.x * b.y - a.y * b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ftype x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point2d a(x2-x1, y2-y1);
        point2d b(x3-x1, y3-y1);
        ftype ans = cross_product(a,b);
        if(ans < 0){
            cout << "RIGHT\n";
        }
        else if( ans == 0){
            cout << "TOUCH\n";
        }
        else{
            cout << "LEFT\n";
        }
    }
    return 0;
}

