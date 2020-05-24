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
void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
struct Node{
    int ch;
    int remains[3];
};

int main()
{
    int n;
    string s_;
    cin >> n >> s_;

    vector<Node> s(n);
    int r[3]={};
    rep(i, n){
        if(s_[i]=='R'){
            s[i].ch = 0;
            r[0]++;
        }else if(s_[i]=='G'){
            s[i].ch = 1;
            r[1]++;
        }else if(s_[i]=='B'){
            s[i].ch = 2;
            r[2]++;
        }
    }

    rep(i, n){
        r[s[i].ch]--;
        rep(j, 3) s[i].remains[j] = r[j];
    }

    ll ans=0;

    rep(i, n-2){
        FOR(j, i+1, n-1){
            if(s[i].ch==s[j].ch) continue;
            if(2*j-i<n && s[2*j-i].ch==3-s[i].ch-s[j].ch) ans--;
            ans += (ll)s[j].remains[3-s[i].ch-s[j].ch];
        }
    }

    print(ans);
    return 0;
}