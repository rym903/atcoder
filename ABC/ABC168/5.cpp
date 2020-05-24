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
void printvec(vector<ll> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}
 
ll n;
vector<ll> a, b;
int main()
{
    cin >> n;
    a.resize(n); b.resize(n);

    rep(i, n){
        scanf("%lld %lld", &a[i], &b[i]);
    }

    vector<ll> fishes(n, LONG_MIN);
    priority_queue<ll> que;
    que.push(0);
    ll rel;

    while(!que.empty()){
        int fish = que.top(); que.pop();
        printf("fish=%d\n", fish);
        if(fishes[fish]!=LONG_MIN) continue;

        int cnt=0;
        vector<int> in;
        FOR(i, fish+1, n){
            rel = a[fish]*a[i] + b[fish]*b[i];
            if(rel==0){
                que.push(i);
            }else{
                cnt++;
                fishes[i] = -cnt;
                in.push_back(i);
            }
        }
        fishes[fish] = cnt;
        for(auto j: in){
            fishes[j] = cnt + fishes[j] + 1;
        }
    }

    ll ans = 0;
    printvec(fishes);
    rep(i, n) ans += powl(2, fishes[i]);
    printf("%lld\n", ans%MOD);
    return 0;
}