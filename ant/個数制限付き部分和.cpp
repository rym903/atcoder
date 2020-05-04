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
    int n;
    cin >> n;

    int w[n], m[n];
    REP(i, n) scanf("%d %d", &w[i], &m[i]);

    int K;
    cin >> K;

    bool dp[n+1][K+1];
    REP(i, n+1) dp[i][0]=false;
    dp[0][0] = true;

    FOR(i, 0, n){
        printf("w[i] = %d\n", w[i]);
        REP(j, K+1){
            dp[i+1][j] = false;
            int tmp_max = m[i];
            REP(tmp, tmp_max+1){
                if(j-tmp*w[i] < 0) break;
                if(dp[i][j-tmp*w[i]]==true){
                    dp[i+1][j] = true;
                    break;
                }
            }
            printf("dp[%d][%d]=%s\n", i+1, j, dp[i+1][j] ? "true" : "false");
        }
    }
    if(dp[n][K]){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    
    return 0;
}