#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void prt(T x){cout << x << endl;}
template<class T>void prtvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef pair<double, double> P;
void koch(int n, P p1, P p2){
    if(n==0) return;

    P s, t, u;
    s.first = (p2.first + 2*p1.first)/3;
    s.second = (p2.second+2*p1.second)/3;
    t.first = (2*p2.first+p1.first)/3;
    t.second = (2*p2.second+p1.second)/3;
    u.first = (t.first - s.first)*cos(M_PI/3) - (t.second - s.second)*sin(M_PI/3) +s.first;
    u.second = (t.first - s.first)*sin(M_PI/3) + (t.second - s.second)*cos(M_PI/3) +s.second; 

    koch(n-1, p1, s);
    printf("%lf %lf\n", s.first, s.second);
    koch(n-1, s, u);
    printf("%lf %lf\n", u.first, u.second);
    koch(n-1, u, t);
    printf("%lf %lf\n", t.first, t.second);
    koch(n-1, t, p2);
}

int main()
{
    int n;cin>>n;
    P p1=P(0.0, 0.0), p2=P(100.0, 0);
    printf("%lf %lf\n", p1.first, p1.second);
    koch(n, p1, p2);

    printf("%lf %lf\n", p2.first, p2.second);
    return 0;
}