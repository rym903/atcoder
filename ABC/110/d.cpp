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
using P=pair<int, int>;

int cnt;

template<class T>
vector<pair<int, int>> factorize(T n){
    vector<pair<int, int>> res;
    int cnt;
    if(!(n&1)){
        cnt = 0;
        while(n!=1 && !(n&1)){
            cnt++;
            n /= 2;
        }
        res.push_back({2, cnt});
    }

    for(int i=3; i*i<n; i+=2){
        if(n%i==0){
            cnt = 0;
            while(n!=1 && n%i==0){
                cnt++;
                n /= i;
            }
            res.push_back({i, cnt});
        }
    }

    if(n!=1) res.push_back({n, 1});
    return res;
} 

void cnt_how_to_divide(vector<int> A, int& item_num, int& person){ //k個のモノをn人で分ける
    // prvec(A);
    if(A.size()==person){
        cnt++; return;
    }

    A.push_back(A.back());
    while(A.back()<=item_num){
        cnt_how_to_divide(A, item_num, person);
        A.back()++;
    }
}

int modPow(ll a, ll n, ll p) { //繰り返し二乗法 a**n % p
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main()
{
    int n, m; cin >> n >> m;

    vector<P> f = factorize(m);
    for(P p: f) printf("%d %d\n", p.first, p.second);

    vector<int> ans;

    int r=1;
    for(P p: f){
        cnt = 0; ans.clear();
        ans.push_back(0);
        cnt_how_to_divide(ans, p.second, n);
        r *= cnt;
        r %= MOD;
    }
    pr(r);
    return 0;}