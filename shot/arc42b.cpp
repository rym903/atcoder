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

double dist(double x, double y, double ax, double ay, double bx, double by){
    if(ax == bx){
        return abs(x - ax);
    }
    if(ay == by){
        return abs(y - ay);
    }

    double a = ay - by;
    double b = -(ax-bx);
    double c = ay*(ax - bx) - ax*(ay - by);

    double res = abs(a*x + b*y + c);

    return res / sqrt(a*a + b*b);
}

int main()
{
    double x, y; cin >> x >> y;
    int n; cin >> n;
    double a[n], b[n];
    rep(i, n){
        cin >> a[i] >> b[i];
    }

    double ans = __DBL_MAX__;

    rep(i, n-1){
        chmin(ans, dist(x, y, a[i], b[i], a[i+1], b[i+1]));
    }
    chmin(ans, dist(x, y, a[0], b[0], a[n-1], b[n-1]));

    printf("%.10lf\n", ans);
    return 0;}