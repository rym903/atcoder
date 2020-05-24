#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}
void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}
 
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N){
        a[i] = 0;
    }
    int com, s, t;
    ll ans;
    rep(i, Q){
        cin >> com >> s >> t;
        if(com==0){
            a[s-1] += t;
        }else if(com==1){
            ans = 0;
            FOR(j, s-1, t){
                //if(ans > a[j]) 
                ans += a[j];
            }
            print(ans);
        }
    }
    return 0;
}