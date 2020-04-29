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
    int n;
    cin >> n;

    int m,ans = INT32_MIN;
    cin >> m;
    int minv = m;
    FOR(i, 1, n){
        cin >> m;
        ans = max(ans, m-minv);
        minv = min(minv, m);
    }

    print(ans);
    return 0;
}