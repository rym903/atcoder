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

int main()
{
    int k; cin >> k;
    int ans = 0;
    set<int> loop;
    int loop_init = 7%k;
    loop.insert(loop_init);
    if(loop_init==0) ans = 1;
    else if(k%2==0) ans = -1;
    else{
        int s = 77;
        int cnt = 2;
        int mod = s % k;
        while(1){
            if(mod == 0){
                ans = cnt;
                break;
            }
            if(loop.find(mod)!=loop.end()){
                ans = -1;
                break;
            }
            loop.insert(mod);
            mod = (mod*10 + 7) % k;
            cnt++;
        }
    }
    pr(ans);
    return 0;}