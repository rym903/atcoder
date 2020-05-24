#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
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
    char s[10], t[10];
    string ss, tt;
    scanf("%s", s);
    scanf("%s", t);

    ss = s;
    tt = t;
    bool flag = true;
    for(int i=0;i<ss.length(); i++){
        if(s[i]!=t[i]){
            flag = false;
            break;
        }
    }

    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}