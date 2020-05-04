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
    vector<int> coins = {25, 10, 5, 1}; 
    int ans=0, tmp;
    FOR(i, 0, coins.size()){
        ans += n / coins[i];
        n %= coins[i];
    }
    print(ans);
    return 0;
}