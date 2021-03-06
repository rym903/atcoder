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
mint COM(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*finv[k]*finv[n-k];
}

int main()
{
    int n, k; cin >> n >> k;
    vector<ll> a, b;
    rep(i, n) {
        ll c; cin >> c;
        if(c>=0) a.push_back(c);
        else b.push_back(c);
    }
    sort(ALL(a));
    reverse(ALL(a));
    sort(ALL(b));
    mint ans = 1;
    if(a.size()==0 && k%2==1){
        reverse(ALL(b));
        rep(i, k) ans *= b[i];
        pr(ans);
        return 0;
    }
    int ai=0, bi=0;
    int sgn = 1;
    rep(i, k){
        if(ai==a.size()){
            ans *= b[bi++];
            sgn *= -1;
        }else if(bi==b.size()){
            ans *= a[ai++];
        }else{
            if(a[ai] > abs(b[bi])) ans *= a[ai++];
            else {ans *= b[bi++]; sgn *= -1;}
        }
    }
    if(a.size() + b.size()==k) {pr(ans); return 0;}
    if(bi==b.size()){
        if(sgn < 0) {
            // pr(1);
            ans /= b[bi-1];
            ans *= a[ai];
        }
    }else if(ai==a.size()){
        if(sgn < 0){
            ans /= a[ai-1];
            ans *= b[bi];
        }
    }else{
        if(sgn < 0){
            ll aw = a[ai-1] * a[ai];
            ll bw = b[bi-1] * b[bi];
            if(aw > bw){
                ans /= b[bi-1];
                ans *= aw;
            }else{
                ans /= a[ai-1];
                ans *= bw;
            }
        }
    }
    pr(ans);
    return 0;}