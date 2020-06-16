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
 
// 以下、BM法
int main()
{
    string t, p; cin >> t >> p;
    if(t.length() < p.length()){
        return 0;
    }
    map<char, int> zurashi;
    for(int i=p.length()-1; i>=0; i--){
        if(zurashi[p[i]] != 0) continue;
        zurashi[p[i]] = (p.length() -1) - i;
    }

    int s = 0;
    while(s <= t.length() - p.length()){
        // pr(s);
        int miss = -1;
        for(int i = p.length()-1; i>=0; i--){
            if(t[s+i] != p[i]){
                miss = i;
                break;
            }
        }
        if(miss==-1) {
            pr(s);
            // s++;
            s += zurashi[p[0]];
        }else if(miss=p.length()-1){
            if(zurashi[t[s+miss]]!=0) s += zurashi[t[s+miss]];
            else s += p.length();
        }else{
            if(zurashi[t[s+miss]]!=0){
                s += miss - zurashi[t[s+miss]];
            }else{
                s += p.length();
            }
        }
    }

    return 0;}