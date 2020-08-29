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
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int ans = INF;
bool flg = false;
int r=0, g=0, b=0;
void dfs(deque<char> que, string s, int i){
    if(flg) return;
    if(i==s.size()){
        chmin(ans, (int)que.size());
        if(ans==(r%2 + g%2 + b%2)) flg = true; 
        return;
    }
    else if(que.empty()){
        que.push_back(s[i]);
        dfs(que, s, i+1);
    }
    else if(que.back() == s[i]){
        que.pop_back();
        dfs(que, s, i+1);
    }
    else if(que.front() == s[i]){
        que.pop_front();
        dfs(que, s, i+1);
    }
    else {
        que.push_back(s[i]);
        dfs(que, s, i+1);
        que.pop_back();
        que.push_front(s[i]);
        dfs(que, s, i+1);
    }
}

int main()
{
    deque<char> que;
    int n; string s; cin >> n >> s;
    rep(i, n) {
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }
    dfs(que, s, 0);
    pr(ans);
    return 0;}