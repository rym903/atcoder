#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}

int main()
{
    int n, q, t;
    cin >> n;

    vector<int> A;
    REP(i, n){
        cin >> q;
        A.emplace_back(q);
    }

    bool dp[n+1][2001];
    REP(j, 2001) dp[0][j] = false;
    dp[0][0] = true;

    REP(i, n){
        REP(j, 2001){
            if(j >= A[i]){
                dp[i+1][j] = dp[i][j] || dp[i][j-A[i]];
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    
    cin >> q;
    REP(i, q){
        cin >> t;
        if(dp[n][t]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}