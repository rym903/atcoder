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
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

int main()
{
    string s; cin >> s;
    vector<int> v;
    rep(i, s.size()-1){
        if(s[i]=='R' && s[i+1]=='L') v.push_back(i);
    }

    vector<int> ans(s.size(), 0);

    rep(i, v.size()){
        int L = v[i];
        int R = v[i]+1;
        int l, r, x;
        for(l=v[i]-1; l>=0; l--){
            if(s[l]=='L') {break;}
        }
        l = L - l - 1;
        for(r=R+1; r<s.size(); r++){
            if(s[r]=='R') {break;}
        }
        r = r - R - 1;

        // cout << l << " " << L << " " << R << " " << r << endl;
        x = min(l, r);
        ans[L] = 1 + (l+r)/2 + (l-x)%2;
        ans[R] = 1 + (l+r)/2 + (r-x)%2;
        if((r+l-x)%2==1) swap(ans[L], ans[R]);
    }

    prvec(ans);

    return 0;}