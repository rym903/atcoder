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
    ll n; cin >> n;

    if(n==2) {print(1); return 0;}

    ll ans=2;
    ll sqn = (ll)sqrt(n);

    ll next;
    for(ll i=2; i<=sqn; i++){
        // printf("\n%d: ",i);
        ll mod = n%i;
        if(mod==1){
            // printf("1: %lld %lld\n", i, (n-1)/i);
            if((n-1)/i == i) ans++;
            else ans+=2;
            continue;
        }

        if(mod==0){
            next = n;
            while(mod==0) {
                next /= i;
                mod = next%i;
            }
            if(mod==1) ans++;
        }

    }

    print(ans);
    return 0;
}