#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}
 
int main()
{
    ll A, B, N;
    scanf("%lld %lld %lld", &A, &B, &N);
    // printf("A=%d, B=%d, N=%d\n", A, B, N);
    double t;
    ll x;
    ll tmp1, tmp2;
    ll ans;

    if(N<B){
        x = N;
    }else{
        x = B-1;
    }
    t = (double)x/B;
    tmp1 = A * t;
    tmp2 = t;
    tmp2 *= A;
    ans = tmp1-tmp2;
    // printf("%lld, %lld, %lld, %lf\n", A, B, N, t);
    // printf("%lld, %lld, %lld\n", tmp1, tmp2, ans);
    print(ans);
    return 0;
}