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
    vector<int> S;
    int n, m, t;
    cin >> n;

    REP(i, n){
        cin >> t;
        S.emplace_back(t);
    }

    cin >> m;
    int ans=0;
    REP(i, m){
        cin >> t;
        if(binary_search(ALL(S), t)) ans++;
    }
    
    print(ans);
    return 0;
}