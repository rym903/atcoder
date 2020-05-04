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
    ll ans=-10;
    double t;
    ll tmp1, tmp2=-1;
    ll fl;
    ll x=0;
    while(1){
        if(x+B-1 > N){
            t = (double)N/B;
            tmp1 = A*t;
            tmp2++;;
            fl = tmp1 - A*tmp2;
            if(ans < fl){
                ans = fl;
            }
            break;
        }else{
            x = x+B-1;
            t = (double)x/B;
            tmp1 = A*t;
            tmp2++;;
            fl = tmp1 - A*tmp2;
            if(ans < fl){
                ans = fl;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}