#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    double a, b, c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f){
        double x = (c*e - b*f)/(a*e - b*d);
        double y = (-c*d + a*f)/(a*e - b*d);
        int xi = (int)1000*0.9566;
        int yi = (int)1000*y;
        printf("%.3f %.3f\n", xi/1000.0, yi/1000.0);
    }
    return 0;}