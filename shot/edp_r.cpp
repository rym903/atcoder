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
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// modint: mod 計算を int を扱うように扱える構造体
template<ll mod> class modint{
public:
    ll val=0;
    //コンストラクタ
    modint(ll x=0){while(x<0)x+=mod;val=x%mod;}
    //コピーコンストラクタ
    modint(const modint &r){val=r.val;}
    //算術演算子
    modint operator -(){return modint(-val);} //単項
    modint operator +(const modint &r){return modint(*this)+=r;}
    modint operator -(const modint &r){return modint(*this)-=r;}
    modint operator *(const modint &r){return modint(*this)*=r;}
    modint operator /(const modint &r){return modint(*this)/=r;}
    //代入演算子
    modint &operator +=(const modint &r){
        val+=r.val;
        if(val>=mod)val-=mod;
        return *this;
    }
    modint &operator -=(const modint &r){
        if(val<r.val)val+=mod;
        val-=r.val;
        return *this;
    }
    modint &operator *=(const modint &r){
        val=val*r.val%mod;
        return *this;
    }
    modint &operator /=(const modint &r){
        ll a=r.val,b=mod,u=1,v=0;
        while(b){
            ll t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        val=val*u%mod;
        if(val<0)val+=mod;
        return *this;
    }
    //等価比較演算子
    bool operator ==(const modint& r){return this->val==r.val;}
    bool operator <(const modint& r){return this->val<r.val;}
    bool operator <=(const modint& r){return this->val<=r.val;}
    bool operator >(const modint& r){return this->val>r.val;}
    bool operator >=(const modint& r){return this->val>=r.val;}
    bool operator !=(const modint& r){return this->val!=r.val;}
};

using mint = modint<MOD>;

//入出力ストリーム
istream &operator >>(istream &is,mint& x){//xにconst付けない
    ll t;is >> t;
    x=t;
    return (is);
}
ostream &operator <<(ostream &os,const mint& x){
    return os<<x.val;
}
//累乗
mint modpow(const mint &a,ll n){
    if(n==0)return 1;
    mint t=modpow(a,n/2);
    t=t*t;
    if(n&1)t=t*a;
    return t;
}

// 行列累乗
template<class T> 
arr<T> modpowmat(arr<T> &a, ll n){
    int s = a.size();
    arr<T> b(s, vector<T>(s, 0));
    rep(i, s) b[i][i] = 1;

    while(n>0){
        if(n&1) {
            arr<T> c(s, vector<T>(s, 0));
            rep(i, s) rep(j, s) rep(k, s) c[i][j] += a[i][k] * b[k][j];
            b = c;
        }
        arr<T> c(s, vector<T>(s, 0));
        rep(i, s) rep(j, s) rep(k, s) c[i][j] += a[i][k] * a[k][j];
        a = c;
        n >>= 1;
    }
    return b;
}

//二項係数の計算
#define MAXR 100000
mint fac[MAXR+1],finv[MAXR+1],inv[MAXR+1];
//テーブルの作成
void COMinit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    FOR(i,2,MAXR){
        fac[i]=fac[i-1]*mint(i);
        inv[i]=-inv[MOD%i]*mint(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}
//演算部分
mint PER(ll n, ll k){
   if(n<k)return 0;
   if(n<0 || k<0)return 0;
   return fac[n]*finv[n-k];
}
mint COM(ll n,ll k){
   return PER(n, k)*finv[k];
}



int main()
{
    int n; ll k; cin >> n >> k;
    arr<mint> a(n, vector<mint>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    a = modpowmat(a, k);
    mint ans = 0;
    rep(i, n) rep(j, n) ans += a[i][j];
    pr(ans);
    // prvec(dp);
    return 0;}