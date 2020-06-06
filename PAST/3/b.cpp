#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, q, m; cin >> n >> m >> q;
    vector<int> score(n, 0);
    vector<vector<int>> prob(m); // 問題prob[n]を解いた人
    vector<vector<int>> solve(n); // nが解いた問題

    int a, b, c;
    rep(i, q){
        cin >> a >> b;
        if(a==1){
            int t = 0;
            for(int j: solve[a-1]) t += n - prob[j].size();
            printf("%d\n", t);
        }else{
            cin >> c;
            prob[c-1].push_back(b-1);
            solve[b-1].push_back(c-1);
        }
    }


    return 0;
}