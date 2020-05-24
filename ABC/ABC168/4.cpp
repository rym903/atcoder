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

vector<int> p, r;
vector<vector<int>> e;
vector<bool> vst;

// int find(int x){
//     if(p[x] == x){
//         return x;
//     }
//     find(p[x]);
// }

int main()
{
    int n, m;
    cin >> n >> m;
    e.resize(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        e[a-1].push_back(b-1);
        e[b-1].push_back(a-1);
    }

    vst.resize(n);
    FOR(i, 0, n) vst[i]=false;
    vst[0] = true;

    p.resize(n); r.resize(n);
    rep(i, n) {
        p[i] = i;
        r[i] = 1;
    }

    vector<int> ans(n);
    rep(i, n) ans[i] = -1;
    vector<int> vset[n];
    vset[0].push_back(0);
    int vset_wholesize = 1;

    int k = 0;
    while(1){
        // printvec(vset[k]);
        if(vset_wholesize==n) break;
        for(auto i=vset[k].begin(); i!=vset[k].end(); i++){
            int from = *i;
            for(auto to=e[from].begin(); to!=e[from].end(); to++){
                if(vst[*to] == true) continue;
                ans[*to] = from;
                vset[k+1].push_back(*to);
                vst[*to] = true;
                vset_wholesize++;
            }
        }
        k++;
    }

    if(vset_wholesize < n){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    FOR(i, 1, n){
        printf("%d\n", ans[i]+1);
    }
    printf("\n");
    return 0;
}