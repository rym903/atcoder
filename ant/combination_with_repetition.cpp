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
    int n=3, m=3, M=10000;
    int a[] = {1,2,3};

    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i, n+1) dp[i][1] = i;
    rep(i, a[0]) dp[1][i+1] = 1;

    FOR(i, 2, n+1){
        FOR(j, 2, m+1){
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        printf("i=%d\n", i);
        rep(i, n+1){
            rep(j, m+1){
                printf("%d, ", dp[i][j]);
            }
            printf("\n");
        }
        }

    printf("%d\n", dp[n][m]%M);
    return 0;
}