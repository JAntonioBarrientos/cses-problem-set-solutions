#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Point = complex<ll>;

#define X real()
#define Y imag()

struct comp{
    bool operator()(const Point &a,const  Point &b){
        if(a.X != b.X){
            return a.X < b.X;
        }
        return a.Y < b.Y;
    }
};

ll cross_prod(Point a, Point b){
    return (conj(a) * b).Y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Point> pts;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        pts.emplace_back(x,y);
    }

    sort(pts.begin(), pts.end(), comp());
    vector<Point> st;
    st.push_back(pts[0]);
    st.push_back(pts[1]);
    for(int i = 2; i < n; i++){
        Point a,b,c;
        c = pts[i];
        while(st.size() >= 2){
            a = st[int(st.size())-2];
            b = st.back();
            Point vec1 = b-a;
            Point vec2 = c-a;
            if(cross_prod(vec1, vec2)<= 0){
                break;
            }
            st.pop_back();
        }
        st.push_back(c);
    }
    vector<Point> ans(st.begin(), st.end());

    reverse(pts.begin(), pts.end());
    st.clear();
    st.push_back(pts[0]);
    st.push_back(pts[1]);
    for(int i = 2; i < n; i++){
        Point a,b,c;
        c = pts[i];
        while(st.size() >= 2){
            a = st[int(st.size())-2];
            b = st.back();
            Point vec1 = b-a;
            Point vec2 = c-a;
            if(cross_prod(vec1, vec2)<= 0){
                break;
            }
            st.pop_back();
        }
        st.push_back(c);
    }
    ans.insert(ans.end(), st.begin()+1, st.end()-1);
    sort(ans.begin(), ans.end(), comp());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << "\n";
    for(auto p: ans){
        cout << p.X << " " << p.Y << endl;
    }
    return 0;
}
