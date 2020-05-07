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
 
int main()
{
    ll x;
    cin >> x;
    cout << bitset<32>(x) << endl;
    cout << bitset<32>(~x) << endl;
    cout << bitset<32>(x << 1) << endl;
    cout << bitset<32>(x >> 1) << endl;
    return 0;
}