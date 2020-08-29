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

int N = 200000;
int DEPTH = ceil(log2(N));
int LEAFHEAD = int(pow(2, DEPTH))+1;
int NODES = int(pow(2, DEPTH+1))-1;
int n, q;
int ans;
set<int> ansset;
vector<int> a;

vector<set<int>> tree(NODES);

void treeinit(int x, int l, int r){
    if(l==r) {
        if(l<n) tree[x].insert(a[l]);
    }
    else{
        int chl = 2*x+1; 
        int chr = 2*x+2;
        int mid = (l+r)/2;
        treeinit(chl, l, mid);
        treeinit(chr, mid+1, r);
        set_union(ALL(tree[chl]), ALL(tree[chr]), inserter(tree[x], end(tree[x])));
    }
}

void getrange(int x, int l, int r , int a, int b){
    if(r<a || b<l) return;
    if(a<=l && r<=b) {
        set<int> t = ansset;
        set_union(ALL(t), ALL(tree[x]), inserter(ansset, end(ansset)));
        return;
    }else{
        int chl = 2*x+1; 
        int chr = 2*x+2;
        int mid = (l+r)/2;
        getrange(chl, l, mid, a, b);
        getrange(chr, mid+1, r, a, b);
    }
}

int main()
{
    cin >> n >> q;
    a.resize(n);
    rep(i, n) cin >> a[i];
    treeinit(0, 0, n-1);

    rep(i, q){
        int l, r; cin >> l >> r;
        ansset.clear();
        getrange(0, 0, n-1, l, r);
        pr(ansset.size());
    }
    return 0;}