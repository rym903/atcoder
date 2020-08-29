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



int main()
{
    int n; cin >> n;
    vint sieve(1000005, 0);
    vint a(n);
    rep(i, n) cin >> a[i];

    rep(i, n){
        if(a[i]%2==0) sieve[2]++;
        while(a[i]!=1 && a[i]%2==0) a[i] /= 2;

        int j = 3;
        for(j=3; j*j<=a[i]; j+=2){
            if(a[i]%j==0) sieve[j]++;
            while(a[i]!=1 && a[i]%j==0) a[i] /= j;
        }

        if(a[i] >= j) sieve[a[i]]++;
    }

    bool set_flg = false;

    // rep(i, 10) pr(sieve[i]);
    rep(i, 1000006){
        if(sieve[i]==n) {
            cout << "not coprime" << endl;
            return 0;
        }
        if(sieve[i]>1) set_flg = true;
    }

    if(set_flg) cout << "setwise coprime" << endl;
    else cout << "pairwise coprime" << endl;
    return 0;}