#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (10000)
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
using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

int dp[100][3][2]={};
int n, k;

int main()
{
    cin >> n >> k;
    vector<P> d(k);
    rep(i, k){
        int a, b; cin >> a>> b;
        a--; b--;
        d[i] = {a, b};
    }
    sort(ALL(d));
    int p=0;
    if(d[0].first==0){
        dp[0][d[0].second][0] = 1;
        p++;
    }else{
        rep(i, 3){
            dp[0][i][0] = 1;
        }
    }

    FOR(i, 1, n){

        // rep(c, 3) {rep(q, 2) printf("%d ", dp[i-1][c][q]);} pr("");
        // int ans=0;
        // rep(c, 3) rep(q, 2) ans += dp[i-1][c][q];
        // pr(ans%MOD);

        if(i==d[p].first){
            int c = d[p++].second;
            rep(j, 3){
                if(j==c) dp[i][j][1] += dp[i-1][j][0];
                else{
                    rep(q, 2){
                        dp[i][c][0] += dp[i-1][j][q];
                        dp[i][c][0] %= MOD;
                    }
                }
            }
        }
        else{
            int t=0;
            int tc[3]={};
            rep(j, 3) rep(q, 2) {t += dp[i-1][j][q]; tc[j]+=dp[i-1][j][q];}
            t %= MOD;
            rep(j, 3) tc[j] %= MOD;

            rep(c, 3) dp[i][c][1] += dp[i-1][c][0];
            rep(c, 3) dp[i][c][0] += (t - tc[c] + MOD)%MOD;
        }
    }

    int ans=0;
    rep(c, 3) rep(q, 2) ans += dp[n-1][c][q];
    pr(ans%MOD);
    return 0;}