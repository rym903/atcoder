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
    int n; cin >> n;
    int m = 1, k = 0;
    bool flg = false;
    while(n > k){
        m++;
        k = m * (m-1) / 2;
        if(n==k) flg = true;
    }

    if(!flg){pr("No"); return 0;}
    else pr("Yes");

    pr(m);

    vector<int> s[m];
    s[0].push_back(1);
    s[1].push_back(1);
    FOR(i, 2, m){
        int nd = s[i-1].back() + 1;
        rep(j, i){
            s[j].push_back(nd);
            s[i].push_back(nd);
            nd++;
        }
    }

    rep(i, m){
        cout << s[i].size() << " ";
        prvec(s[i]);
    }

    return 0;}