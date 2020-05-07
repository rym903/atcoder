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
    int n=4, m=3;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    int tmp=0;
    FOR(i, 2, n+1){
        FOR(j, 1, m+1){
            if(i==j){
                dp[i][j] = 1;
                break;
            }
            tmp=0;
            FOR(k, 1, j+1) tmp+=dp[i-j][k];
            dp[i][j] = tmp; 
        }
        // printf("i=%d\n", i);
        // rep(i, n+1){
        //     rep(j, m+1){
        //         printf("%d, ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
    }

    int ans=0;
    rep(i, m+1) ans += dp[n][i];
    print(ans);
    return 0;
}