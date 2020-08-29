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

int f(int n){
    int rec = 0;
    while(n!=0){
        // pr(n);
        rec++;
        int k = popcount(n);
        n = n%k;
    }
    return rec;
}

int main()
{
    int n; string x;
    cin >> n >> x;

    int one=0;
    rep(i, n) if(x[i]=='1') one++;

    // if(one==0) {pr(0); return 0;}

    vector<int> add(n), sub(n);
    add[n-1] = 1;
    sub[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        add[i] = (add[i+1]*2)%(one+1);
        if(one!=1) sub[i] = (sub[i+1]*2)%(one-1);
    }

    int a=0, b=0;
    rep(i, n){
        if(x[i]=='1'){
            a += add[i];
            a %= (one+1);
            if(one!=1){
                b += sub[i];
                b %= (one-1);
            }
        }
    }

    rep(i, n){
        int c;
        if(x[i]=='1'){
            if(one==1){
                pr(0);
                continue;
            }
            c = (b - sub[i] + one - 1)%(one-1);
            pr(f(c)+1);
        }else{
            if(one==0){
                pr(1);
                continue;
            }
            c = (a + add[i])%(one+1);
            pr(f(c)+1);
        }
    }
    return 0;}