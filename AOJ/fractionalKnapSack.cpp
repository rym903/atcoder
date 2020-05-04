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

struct Item{
    int v;
    int w;
    double b;
};

bool compare(Item &x, Item &y){
    return x.b > y.b;
}
 
int main()
{
    int N, W_int;
    scanf("%d %d", &N, &W_int);

    double W=(double)W_int;
    Item items[N];
    REP(i, N) scanf("%d %d", &items[i].v, &items[i].w);
    REP(i, N) items[i].b = (double)items[i].v / items[i].w;

    sort(items, items+N, compare);

    // printf("W=%lf, item=%lf\n", W, items[0].b);


    int item=0;
    double ans=0;
    while(W>0 && item<N){
        if(W>items[item].w){
            ans += (double)items[item].v;
            W -= items[item].w;
        }else{
            ans += items[item].v * W / items[item].w;
            W = 0;
        }
        item++;
    }
    printf("%lf\n", ans);

    return 0;
}