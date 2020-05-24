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
    int n, q;
    cin >> n >> q;
    priority_queue<int> que[n];

    int com, t, x;
    rep(i, q){
        scanf("%d %d", &com, &t);
            if(com==0){
                scanf("%d", &x);
                que[t].push(x);
            }else if(com==1){
                if(que[t].empty()) continue;
                printf("%d\n", que[t].top());
            }else if(com==2){
                if(que[t].empty()) continue;
                que[t].pop();
            }
    }
    return 0;
}