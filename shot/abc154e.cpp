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
    string s; cin >> s;
    int k; cin >> k;
    int keta = s.size();

    if(k > keta){
        pr(0);
        return 0;
    }

    int d[101][4]={};
    FOR(i, 1, 101){
        FOR(j, 1, 4){
            if(j==1) d[i][j] = 9;
            else{
                int sec, thi;
                if(j > i) continue;
                if(j==2) d[i][j] = 9 * (i-1) * 9;
                if(j==3) d[i][j] = 9 * (i-1) * (i-2) * 9 * 9 / 2;
            }
        }
    }

    int ans = 0;
    FOR(i, 1, keta) ans += d[i][k];

    int a, b, c;
    a = s[0] - '0';
    if(keta>=2) b = s[1] - '0';
    if(keta>=3) c = s[2] - '0';

    if(k==1){
        ans += a;
        pr(ans);
        return 0;
    }

    if(k==2){
        if(b>0) ans += a * (keta-2) * 9;
        else {
            if(c>0) ans += a * (keta-3) * 9;
            ans += (a-1) * 9;;
            ans += c;
        }
        ans += (a-1) * 9 + b;
        pr(ans);
        return 0;
    }

    if(k==3){
        if(b>0 && c>0) ans += a * (keta-2) * (keta-3) * 9 * 9 / 2;

        int sec = 0;
        if(b>0) {
            sec += (a-1) * 9 * 9;
            sec += b * 9;
            sec *= keta-3;
            ans += sec;
        }

        sec = 0;
        sec += (a-1) * 9 * 9;
        if(b>0) sec += (b-1) * 9;
        sec += c;
        ans += sec;

        if(b==0 && c==0){
            int t = keta;
            FOR(i, 2, t){
                if(s[i]!='0'){
                    a = s[i] - '0';
                    b = s[i+1] - '0';
                    keta = keta - i;
                    FOR(j, 1, keta) ans += d[j][2];
                    if(b>0) ans += a * (keta-2) * 9;
                    ans += (a-1) * 9 + b;
                    break;
                } 
            }
        }

        pr(ans);
        return 0;
    }

    return 0;}