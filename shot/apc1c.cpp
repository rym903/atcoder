#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
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
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    int i=0;
    string s;
    string lefts, rights, mids;

    pr(i);
    cin >> s;

    if(s=="Vacant"){
        return 0;
    }
    lefts = s;

    pr(n-1);
    cin >> s;
    if(s=="Vacant"){
        return 0;
    }
    rights = s;

    int left = 0, right = n;
    int mid = (left+right)/2;

    while(1){
        pr(mid);
        cin >> mids;
        if(mids=="Vacant") return 0;
        
        if(mids == lefts){
            if((mid - left)%2 == 0){
                left = mid;
                lefts = mids;
            }else{
                right = mid;
                rights = mids;
            }
        }else{
            if((mid - left)%2 == 0){
                right = mid;
                rights = mids;
            }else{
                left = mid;
                lefts = mids;
            }
        }

        mid = (left+right)/2;
    }
    return 0;}