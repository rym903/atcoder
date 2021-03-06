#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    string s; cin >> s;
    int n = s.size();
    int p = 0;
    ll t = 0;
    int m = 0;
    vint ans;
    ans.push_back(p);
    int i = 0;
    while(i<n){
        p = 0;
        ll up = 0;
        vint v;
        while(i+up < n && s[i+up]=='<') {
            p++;
            up++;
        }
        i = i+up;

        ll down = 1;
        while(i+down < n && s[i+down]=='>'){
            p--;
            down++;
        }
        i += down;
        // cout << up << ":" << down << endl;

        if(up < down) swap(up, down);
        t += (up+1)*up/2 + (down-1)*down/2;
        
        // cout << t <<  " " << i << endl;
    }
    // prvec(ans);
    pr(t);
    return 0;}