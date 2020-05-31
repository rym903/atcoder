#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void p(T x){cout << x << endl;}
template<class T>void pvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<int> a;
vector<string> res;

string rec(int pos, int i, int n, int d, string ans){
    // cout << ans << endl;
    if(i==n){
        return ans;
    }else{
        bool flag = false;
        if(pos - a[i] >= -d) {
            ans.push_back('L');
            flag = true;
            return rec(pos-a[i], i+1, n, d, ans); 
        }
        if(pos + a[i] <= d) {
            if(flag) ans.back() = 'R';
            else ans.push_back('R');
            return rec(pos+a[i], i+1, n, d, ans); 
        }
    }
} 

int main()
{
    int d, n; cin >> d >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];

    string ans;
    ans = rec(0, 0, n, d, ans);

    // rep(i, res.size()){
        cout << ans << endl;    
    // }
    return 0;
}