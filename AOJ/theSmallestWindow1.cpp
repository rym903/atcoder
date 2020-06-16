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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int left=0, right=0;
    int sum=0;
    int ans = INF;
    while(left < n){
        while(sum<k){
            right++;
            if(right > n) break;
            sum += a[right-1];
        }
        if(left==0 && right==n+1 && sum < k) {
            ans = 0;
            break;
        }
        chmin(ans, right-left);
        while(left <= right){
            left++;
            sum -= a[left-1];
            if(sum < k) break;
            chmin(ans, right-left);
        }
    }
    pr(ans);
    return 0;}