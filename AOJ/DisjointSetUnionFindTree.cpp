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

int find(vector<int>& p, int x){
    if(x == p[x]){
        return x;
    }else{
        find(p, p[x]);
    }
}

void unite(vector<int>& z, vector<int>& p, int x, int y){
    x = find(p, x); y = find(p, y);
    if(x==y) return;

    if(z[x] < z[y]) swap(x, y);
    z[x] += z[y];
    p[y] = x;
}

void same(vector<int>& p, int x, int y){
    printf("%d\n", find(p,x)==find(p,y));
}
 
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> z(n), p(n);
    rep(i, n){
        z[i] = 1;
        p[i] = i;
    }

    int com, x, y;
    set<int> tmp;

    rep(i, q){
        cin >> com >> x >> y;
        if(com==0){ //unite
            unite(z, p, x, y);
        }else if(com==1){
            same(p, x, y);
        }
    }

    return 0;
}