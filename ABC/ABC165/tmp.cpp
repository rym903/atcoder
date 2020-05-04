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
 

int n, m, q;
vector<int> a, b, c, d;
int ans=0;

void dfs(vector<int> A){
    if(A.size()==n+1){
        int now=0;
        REP(i, q){
            if(A[b[i]] - A[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans, now);
        return;
    }

    A.push_back(A.back());
    while(A.back() <= m){
        dfs(A);
        A.back()++;
    }
}
int main()
{
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    REP(i, q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    dfs(vector<int>(1, 1));
    cout << ans << endl;

    return 0;
}