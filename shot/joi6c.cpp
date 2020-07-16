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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

vector<P> p;
int n;
int ans = 0;

void makeSquare(P A, P B){
    int a, b, c, d;
    tie(a, b) = A;
    tie(c, d) = B;
    int xd, yd;
    xd = c - a; yd = d - b;

    P C, D;
    C.first = a + yd; C.second = b - xd;
    D.first = c + yd; D.second = d - xd;
    if(C == *lower_bound(ALL(p), C) && D == *lower_bound(ALL(p), D)){
        // prp(A); prp(B); prp(C); prp(D);
        // pr(xd*xd + yd*yd);
        chmax(ans, xd*xd + yd*yd);
    }
    C.first = a - yd; C.second = b + xd;
    D.first = c - yd; D.second = d + xd;
    if(C == *lower_bound(ALL(p), C) && D == *lower_bound(ALL(p), D)){
        // prp(A); prp(B); prp(C); prp(D);
        // pr(xd*xd + yd*yd);
        chmax(ans, xd*xd + yd*yd);
    }
}

int main()
{
    cin >> n;
    p.resize(n);
    rep(i, n){
        int a, b; cin >> a >> b;
        p[i] = {a, b};
    }
    sort(ALL(p));
    rep(i, n){
        FOR(j, i+1, n) makeSquare(p[i], p[j]);
    }
    pr(ans);
    return 0;}