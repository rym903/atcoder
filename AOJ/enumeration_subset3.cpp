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

ll N, K, X;

void printnum(ll i, ll n){
    ll bit;
    printf("%lld:", i);
    for(ll j=0; j<n; j++){
        if(i&(1<<j)) printf(" %d", j);
    }
    printf("\n");
}

void iter(ll x, ll bit){
    // cout << "x=" << x << ", bit=" << bit << endl;
    // cout << bitset<32>(x) << endl;
    // cout << bitset<32>(1<<bit) << endl;
    // cout << bitset<32>(X) << endl;
    if(bit<0){
        printnum(x, N);
        return;
    }
    // printf("%d\n", X & (1<<bit));
    // if((X & (1<<bit))==0) {
    //     printf("returned\n");
    //     return;
    // }
    //unuse
    iter(x, bit-1);

    // use
    if((X & (1<<bit))!=0) {
        iter(x|(1<<bit), bit-1);
    }
    
}
 
int main()
{
    cin >> N;
    cin >> K;
    ll tmp;
    rep(i, K){
        cin >> tmp;
        X |= (1 << tmp);
    }

    iter(0, N);

    return 0;
}