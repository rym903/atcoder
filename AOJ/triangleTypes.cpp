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
int type[3]={};
bool isTriangle(int a, int b, int c){
    if(a+b <= c || b+c <= a || c+a <= b) return false;
    return true;
}

void types(int a, int b, int c){
    a *= a;
    b *= b;
    c *= c;
    if(a+b == c || b+c == a || c+a == b) type[0]++;
    else if(a+b < c || b+c < a || c+a < b) type[2]++;
    else type[1]++;
}

int main()
{
    int a, b, c;
    
    while(cin >> a >> b >>c){
        if(!isTriangle(a,b,c)) break;
        types(a,b,c);
    }
    printf("%d %d %d %d\n", type[0] + type[1] + type[2], type[0], type[1], type[2]);
    return 0;} 
