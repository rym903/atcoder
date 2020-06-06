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
    int n; cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    string ans;

    int l=0, r=n-1;
    bool flag;
    while(l<=r){
        flag = false;
        rep(i, n){
            FOR(j, i, n){
                if(a[l][i] == a[r][j]){
                    ans.push_back(a[l][i]);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) break;
        l++;
        r--;
    }

    if(!flag) printf("-1\n");
    else if(n%2==0){
        cout << ans;
        reverse(ALL(ans));
        cout << ans << endl;
    }else{
        cout << ans;
        reverse(ALL(ans));
        FOR(i, 1, ans.length()) cout << ans[i];
        cout << endl;
    }
    return 0;
}