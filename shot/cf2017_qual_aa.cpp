#include <bits/stdc++.h>
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
    int h, w; cin >> h >> w;
    unordered_map<char, int> a;
    rep(i, h*w){
        char c; cin >> c;
        a[c]++;
    }

    vint v;
    for(auto p: a) v.push_back(p.second);
    sort(v.rbegin(), v.rend());
    // prvec(v);

    if(h==1 && w==1) {pr("Yes"); return 0;}
    if(h==1 || w==1){
        if(w==1) swap(h, w);
        int odd=0, even=0;
        rep(i, v.size()){
            if(v[i]%2==1)  even++;
            else odd++;
        }

        if(w%2==0){
            if(even==0) pr("Yes");
            else pr("No");
            return 0;
        }else{
            if(even==1) pr("Yes");
            else pr("No");
            return 0;
        }
    }

    int odd=0, even=0, four=0;
    rep(i, v.size()){
        four += v[i]/4;
        v[i] %= 4;
        even += v[i]/2;
        v[i] %= 2;
        if(v[i]==1) odd++;
    }

    // cout << four << " " << even << " " << odd << endl;

    // 両方とも2の倍数のとき
    if(h%2==0 && w%2==0){
        if(odd==0 && even==0) pr("Yes");
        else pr("No");
        return 0;
    }

    if(h%2==1 && w%2==1){
        int fp = (h/2) * (w/2);
        four -= fp;
        if(four<0 || odd!=1) pr("No");
        else pr("Yes");
        return 0;
    }

    int fp = (h/2) * (w/2);
    four -= fp;
    // cout << four << " " << even << endl;
    if(four<0 || odd>0) pr("No");
    else pr("Yes");

    return 0;}