#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void print(T x){cout << x << endl;}
template<class T>void printvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> d[i][j];

    vector<int> a(n, -1);
    rep(i, n){
        rep(j, n){
            if(d[i][j]==1) a[i]=j;
        }
    }

    int ans=0, r;
    rep(i, n){
        int pos=-1;
        FOR(j, i, n){
            if(a[j] <= i){
                pos=j;
                break;
            }
        }

        for(int j=pos; j>i; j--){
            swap(a[j], a[j-1]);
            ans++;
        }
    }

    print(ans);
    return 0;
}