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

//nコからkコを取り出す。
//for(int bit = (1<<k)-1; bit < (1<<n); bit=next_combination(bit)){}
int next_combination(int sub) {
int x = sub & -sub, y = sub + x;
return (((sub & ~y) / x) >> 1) | y;
}

int dist_from_neighbor(vector<int>& a, int v){
    int t = lower_bound(ALL(a), v) - a.begin();
    if(a[t]==v) return 0;
    if(t==0) return abs(v-a[t]);
    if(t==a.size()) return abs(v - a[t-1]);
    return min(abs(v-a[t-1]), abs(v-a[t]));
}

int main()
{
    int n; cin >> n;
    vector<int> x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i] >> p[i];

    ll tmp = 0;
    rep(i, n){
        tmp += min(abs(x[i]), abs(y[i])) * p[i];
    }
    pr(tmp);


    bool is_zero = false;
    FOR(k, 1, n+1){
        if(is_zero) {pr(0); continue;}

        ll ans = INFL;
        for(int bit = (1<<k)-1; bit < (1<<n); bit=next_combination(bit)){
            vector<int> c;
            rep(i, n) if(bit>>i & 1) c.push_back(i);

            rep(sel, (int)pow(2, k)){
                vector<int> linex, liney;
                linex.push_back(0); liney.push_back(0);
                rep(i, k){
                    if(sel>>i & 1) liney.push_back(y[c[i]]);
                    else linex.push_back(x[c[i]]);
                }

                sort(ALL(linex)); sort(ALL(liney));

                ll dist = 0;
                rep(i, n) {
                    if(bit>>i & 1) continue;
                    int dx=INF, dy=INF;
                    rep(j, linex.size()){
                        chmin(dx, (int)abs(linex[j]-x[i])); 
                    }
                    rep(j, liney.size()){
                        chmin(dy, (int)abs(liney[j]-y[i])); 
                    }
                    // printf("%d, %d, %d, %d, %d\n", x[i], dx, y[i], dy, p[i]);
                    int tmppp = min(dx, dy) * p[i];
                    // pr(tmppp);
                    dist += tmppp;
                }
                // prvec(c);
                // prvec(linex);
                // prvec(liney);
                // printf("k=%d, dist=%d\n\n", k, dist);
                chmin(ans, dist);
            }
        }

        pr(ans);
        if(ans==0) is_zero = true;
    }
    return 0;}