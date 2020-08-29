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
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int X[101], Y[101];

    rep(i, 25){
        int r[4];
        r[0] = 100-i;
        rep(j, 3) r[j+1] = 3*i + j + 1;

        int xb, yb;
        xb = 75; 
        // xb += (i%10) * 150;
        yb = 75;
        // yb += (i/10) * 150;

        X[r[0]] = xb;
        Y[r[0]] = yb;

        X[r[2]] = xb + 100 - i + r[2];
        Y[r[2]] = yb;

        X[r[3]] = xb;
        Y[r[3]] = yb + 100 - i + r[3];

        int k = ceil( (100.0 - i + 3*i + 1) / sqrt(2) );
        X[r[1]] = xb + k;
        Y[r[1]] = yb + k;
    }

    FOR(i, 73, 77){
        cout << X[i] << " " << Y[i] << endl;
    }

    int x[4], y[4];
    FOR(i, 73, 77){
        x[i-73] = X[i];
        y[i-73] = Y[i];
    }

    rep(i, 3){
        cout << sqrt(pow(x[i] - x[3], 2) + pow(y[i] - y[3], 2)) << endl;
    }
    return 0;}