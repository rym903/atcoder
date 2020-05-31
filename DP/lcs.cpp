#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void print(T x){cout << x << endl;}
template<class T>void printvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dp[3100][3100]={0};
int main()
{

    string s, t;
    cin >> s >> t;

    FOR(i, 0, s.size()){
        FOR(j, 0, t.size()){
            if(s[i]==t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    string ans="";
    int si=s.size(), ti=t.size();
    while(si>0 && ti>0){
        if(dp[si][ti]==dp[si-1][ti]){
            si--;
        }else if(dp[si][ti]==dp[si][ti-1]){
            ti--;
        }else{
            ans = s[si-1] + ans;
            si--;ti--;
        }
    }

    print(ans);
    return 0;
}