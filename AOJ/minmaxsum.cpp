#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
void print(int x){printf("%d\n", x);}
void print(ll x){printf("%lld\n", x);}
void printvec(vector<int>& a){
rep(i, a.size()-1){
printf("%d ", a[i]);
}
printf("%d\n", a[a.size()-1]);
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n;
    cin >> n;
    ll max_=INT64_MIN, min_=INT64_MAX;
    ll s=0;
    ll tmp;
    rep(i, n){
        scanf("%lld", &tmp);
        chmax(max_, tmp);
        chmin(min_, tmp);
        s += tmp;
    }
    printf("%lld %lld %lld\n", min_, max_, s);
    return 0;
}