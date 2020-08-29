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
    string s; cin >> s;
    int cab = 5;
    int normal = 10, charge = 50;
    double ans = 0;
    int comb = 0;

    int nt[5][3]={};
    rep(i, 5) rep(j, 3) nt[i][j] = -1;
    int ct[3]={};
    double dn[5] = {};
    double dc=0;
    rep(i, 3) ct[i] = -1;
    rep(q, s.size()){
        rep(i, 5) rep(j, 3) nt[i][j]--;
        rep(i, 3) ct[i]--;

        if(ct[0]==0){
            ct[1] = 1;
        }else if(ct[1]==0){
            ans += dc;
            comb++;
            ct[2]=5;
        }else if(ct[2]==0){
            cab += 3;
        }

        rep(i, 5){
            if(nt[i][0]==0){
                nt[i][1]=1;
            }else if(nt[i][1]==0){
                ans += dn[i];
                comb++;
                nt[i][2] = 5;
            }else if(nt[i][2]==0){
                cab++;
            }
        }
        if(ct[0]>0) continue;
        // printf("cab=%d, ans=%lld, nt[1][1]=%d\n", cab, ans, nt[1][1]);

        if(s[q]=='-') continue;
        if(s[q]=='N') {
            if(cab==0) continue;
            nt[5-cab][1] = 2;
            dn[5-cab] = (normal * (1 + floor(comb/10.0)*0.1));
            cab--;
        }else if(s[q]=='C'){
            if(cab<3) continue;
            ct[0]=3;
            dc = (charge * (1 + floor(comb/10.0)*0.1));
            cab -= 3;
        }
    }

    rep(i, 5) {
        if(nt[i][1]>0) ans += dn[i];
    }
    if(ct[0]>0 || ct[1]>0) ans += dc;

    pr(ans);
    return 0;}