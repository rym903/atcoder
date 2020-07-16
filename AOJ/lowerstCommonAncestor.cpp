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
int n;
arr<int> G, rG;
vector<int> depth;
vector<int> parent;

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
template<class T>T extGCD(T a, T b, T& x, T& y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

// aのmod mにおける逆元を返す。(aとmは互いに素)
// extGCDが定義されている必要がある
template<class T>T invmod(T a, T m){
    T x, y;
    extGCD(a,m,x,y);
    x%=m;
    if(x<0) x+=m;
    return x;
}

int main()
{
    cin >> n;
    G.resize(n); depth.resize(n); parent.assign(n, -1);

    int k, c;
    rep(i, n){
        cin >> k;
        rep(j, k){
            cin >> c;
            G[i].push_back(c);
            parent[c] = i;
        }
    }

    int q; cin >> q;
    rep(i, q){
        int a, b; cin >> a >> b;
        set<int> s;
        while(b!=-1){
            if(a==b) break;
            s.insert(b);
            b = parent[b];
        }
        if(a==b) {pr(a); continue;}
        while(s.find(a)==s.end()){
            a = parent[a];
        }

        pr(a);
    }

    return 0;}