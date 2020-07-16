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
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string add(string a, string b){
    string ans;
    int carry=0, sum, digit;
    int alen = a.size(), blen=b.size();

    int ai=a.size()-1, bi=b.size()-1;

    while(ai >= 0 || bi >= 0){
        int ak = ai >= 0 ? a[ai] - '0' : 0;
        int bk = bi >= 0 ? b[bi] - '0' : 0;
        sum = carry + ak + bk;
        carry = sum / 10;
        digit = sum % 10;
        ans.push_back(digit + '0');
        ai--; bi--;
    }

    reverse(ALL(ans));

    return ans;
}

// a - b
string sub(string a, string b){
    string ans;
    int carry=0, diff, digit;
    int alen = a.size(), blen=b.size();

    int ai=a.size()-1, bi=b.size()-1;

    while(ai >= 0 || bi >= 0){
        int ak = ai >= 0 ? a[ai] - '0' : 0;
        int bk = bi >= 0 ? b[bi] - '0' : 0;
        diff = ak - bk - carry;
        if(diff < 0) {
            carry = -1;
            digit = 10 - diff;
        } else {
            carry = 0;
            digit = diff;
        }
        ans.push_back(digit + '0');
        ai--; bi--;
    }

    reverse(ALL(ans));

    return ans;
}

int main()
{
    string a, b; cin >> a >> b;
    pr(sub({"512"}, {"499"}));
    return 0;}