#include <bits/stdc++.h>
using namespace std;
// #define rep(i,n) for(int i=0; i<(n); i++)
// #define FOR(i,x,n) for(int i=x; i<(n); i++)
// #define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
// typedef unsigned int ui;
// typedef unsigned long long ull;
// template <class T>
// void print(T& x){printf("%d\n", x);}
// void printvec(vector<int> a){
//     rep(i, a.size()-1){
//         printf("%d ", a[i]);
//     }
//     printf("%d\n", a[a.size()-1]);
// }
 
int main()
{
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    if(A+B>=K){
        printf("%lld\n", A);
    }else{
        printf("%lld\n", A - (K-A-B));
    }
    return 0;
}