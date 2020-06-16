#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e12)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int c[10][1005];
int main()
{
    int h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<int> v;
    int wchoco, ans=INF, num;
    bool flag;

    for(int div=0; div < (1<<(h-1)); div++){
        int g=0; //グループ数
        vector<int> id(h);
        rep(i, h){
            id[i] = g;
            if(div>>i&1) g++;
        }
        g++;
        rep(i, g) rep(j, w) c[i][j] = 0;
        rep(i, h) rep(j, w) c[id[i]][j] += (s[i][j] - '0');

        num = g-1;
        vector<int> now(g);
        auto add = [&](int j){
            rep(i, g) now[i] += c[i][j];
            rep(i, g) if(now[i] > k) return false;
            return true; 
        };
        rep(j, w){
            if(!add(j)){
                num++;
                now.assign(g, 0);
                if(!add(j)){
                    num = INF;
                    break;
                }
            }
        }
        chmin(ans, num);
    }
    pr(ans);
    return 0;}