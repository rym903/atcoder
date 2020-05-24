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
    int A, B, C;
    cin >> A >> B >> C;

    int ans=0;
    ans += 7 * (C / (7*A+B));

    C %= (7*A+B);
    if(C > 7*A){
        ans += 7;
    }else{
        ans += C/A;
        if(C%A != 0) ans++;
    }

    print(ans);
    return 0;
}