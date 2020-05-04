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
 
int main()
{
    vector<ll> vec;
    int n;
    cin >> n;
    int t, s;
    REP(i, n){
        scanf("%d", &t);
        if(t==0){
            scanf("%d", &s);
            vec.emplace_back(s);
        }else if(t==1){
            scanf("%d", &s);
            printf("%d\n", vec[s]);
        }else if(t==2){
            vec.pop_back();
        }
    }    
    return 0;
}