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
    ull X;
    cin >> X;
    ull gaku=100;
    ull ans=0;
    while(X>gaku){
        gaku *= 1.01;
        ans++;
    }
    print(ans);
    return 0;
}