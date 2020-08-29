#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<class T>T gcd(T a, T b) {if(b==0) return a; return gcd(b, a%b);}
template<class T>T lcm(T a, T b) {return a*b/gcd(a, b);}

ll make(ll n, int k){
    map<ll, int> res;
    if(n%2==0){
        while(n!=1 && n%2==0){
            res[2]++;
            n/=2;
        }
    }

    for(ll i=3; i*i<=n; i+=2){
        while(n!=1 && n%i==0){
            res[i]++;
            n /= i;
        }
    }

    if(n!=1) res[n]++;

    ll ans = 1;
    for(auto p: res){
        if(p.second >= k) {
            int t = p.second / k;
            ans *= (ll)pow(p.first, t);
        }
        // cout << p.first << " " << p.second << endl;
    }

    return ans;
}

int main()
{
    int n; ll p; cin >> n >> p;

    pr(make(p, n));
    return 0;}