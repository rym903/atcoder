#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    double a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    double slope, intercept;
    bool slopeinf=false;
    if(a1==a2) slopeinf = true;
    else if(b1==b2) slope = 0;
    else slope = (b1-b2) / (a1-a2);
    intercept = b1 - (slope*a1);

    double dist, sl_inv, x, y, xx, yy;
    double ansx, ansy;
    
    int n; cin >> n;
    rep(i, n){
        cin >> x >> y;
        dist = abs(slope*x - y + intercept) / sqrt(slope*slope + 1);
        if(slopeinf){
            yy = y;
            if(a1<x) xx = a1;
            else xx = a1;
        }else{
            xx = (slope*slope*a1 - slope*b1 + x + slope*y) / (slope*slope+1);
            if(slope==0) yy = 0;
            else yy = (x - xx) / slope + y;
        }
        xx = 2*xx - x; yy = 2*yy - y;
        printf("%.12lf %.12lf\n", xx, yy);
    }
    return 0;
}