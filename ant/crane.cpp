#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
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

const int ST_SIZE = (1<<15) - 1;
#define MAX_N 100
#define MAX_C 1000
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_C];

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

double prv[MAX_N];


void init(int k, int l, int r){
    ang[k] = vx[k] = 0.0;

    if(r-l == 1) vy[k] = L[l];
    else{
        int chl = 2*k + 1, chr = chl+1;
        init(chl, l, (l+r)/2);
        init(chr, (l+r)/2, r);
        vy[k] = vy[chl] + vy[chr];
    }
}

void change(int s, double a, int v, int l, int r){
    if(s <= l) return;
    else if(s < r){
        int chl = 2*v+1, chr=2*v + 2;
        int m = (l+r)/2;
        change(s, a, chl, l, m);
        change(s, a, chr, m, r);
        if(s<=m) ang[v] += a;
        double sn = sin(ang[v]), cs = cos(ang[v]);
        vx[v] = vx[chl] + (cs*vx[chr] - sn*vy[chr]);
        vy[v] = vy[chl] + (sn*vx[chr] + cs*vy[chr]); 
    }
}

 
void solve(){
    init(0, 0, N);
    rep(i, N) prv[i] = M_PI;

    rep(i, C){
        int s = S[i];
        double a = A[i] * M_PI / 180.0;

        change(s, a-prv[s], 0, 0, N);
        prv[s] = a;

        printf("%.2f %.2f\n", vx[0], vy[0]);
    }
}

int main(){
    cin >> N >> C;
    rep(i, N) cin >> L[i];
    rep(i, C) cin >> S[i];
    rep(i, C) cin >> A[i];

    solve();
}