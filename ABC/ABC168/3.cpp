#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}
void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}
 
int main()
{
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    
    double l, s;
    s = 30.0*h + m/2.0;
    l = 6.0*m;

    double ad, bd, rad;
    ad = a; bd = b;
    rad = M_PI * (l-s) / 180.0;
    // printf("%lf\n", rad);
    printf("%.14lf\n",  sqrt(ad*ad + bd*bd - 2*ad*bd*cos(rad)));
    return 0;
}