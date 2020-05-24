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
    int n,q;
    cin >> n >> q;
    vector<vector<int>> v(n);

    int c, t, x;
    rep(i, q){
        cin >> c >> t;
        if(c==0){
            cin >> x;
            v[t].emplace_back(x);
        }else if(c==1){
            if(v[t].empty()){
                printf("\n");
                continue;
            }
            printf("%d", v[t][0]);
            for(int j = 1; j<v[t].size(); j++){
                printf(" %d", v[t][j]);
            }
            printf("\n");
        }else if(c==2){
            v[t].clear();
        }
    }

    return 0;
}