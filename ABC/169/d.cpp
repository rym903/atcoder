#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct node{
    ll d, c, e;
};

vector<node> divs;

bool isprime(ll a){
    if(!(a&1)) return false;

    for(int i=3; i*i<a; i+=2){
        if(a%i==0){
            return false;
        }
    }

    return true;
}

void makedivs(ll a){
    if((a&1)==0){
        divs.push_back({2, 0, 1});
        while(a%2==0){
            divs.back().c++;
            a /= 2;
        }
    }

    for(ll i=3; i*i<a; i+=2){
        if(!isprime(i)) continue;

        if(a%i==0){
            divs.push_back({i, 0, 1});
            while(a%i==0){
                divs.back().c++;
                a /= i;
            }
        }
    }

    if(a!=1) divs.push_back({a, 1, 1});
}
 
int main()
{
    ll n; cin >> n;
    makedivs(n);
    
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, divs.size()) que.push(powl(divs[i].d, divs[i].e));
    
    ll cnt = 0;
    while(n!=1 && !que.empty()){
        ll div = que.top(); que.pop();
        pr(div);
        n /= div; cnt++;
        rep(i, divs.size()){
            if(div==powl(divs[i].d, divs[i].e)){
                divs[i].e++;
                divs[i].c -= divs[i].e;
                if(divs[i].c>=0) que.push(divs[i].d*div);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}