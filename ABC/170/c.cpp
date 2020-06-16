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
 
int main()
{
    int x, n; cin >> x >> n;
    set<int> s;
    int k;
    rep(i, n) {
        cin >> k;
        s.insert(k);
    }

    int dist=0;
    while(1){
        int neg = x-dist;
        int pos = x+dist;
        if(s.find(neg)==s.end()){
            pr(neg);
            return 0;
        }else if(s.find(pos)==s.end()){
            pr(pos);
            return 0;
        }
        dist++;
    }
    return 0;}