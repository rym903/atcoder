#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
void print(int x){printf("%d\n", x);}
void print(ll x){printf("%lld\n", x);}
void printvec(vector<int>& a){
rep(i, a.size()-1){
printf("%d ", a[i]);
}
printf("%d\n", a[a.size()-1]);
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n;
    cin >> n;
    vector<int> md(3, 0);
    int r;
    rep(i, n){
        scanf("%d", &r);
        md[r%3]++;
    }
    // printvec(md);
    if(md[1]==0 && md[2]==0){
        printf("1\n");
        return 0;
    }

    int ans=md[0];
    if(md[1]==md[2]){
        ans += 2*md[1];
    }else if(md[1]>md[2]){
        if(md[1]==1) {
            ans++;
        }else{
            md[1] -= 2;
            int m = min(md[1], md[2]);
            ans += 2*m + 2;
            md[1] -= m; md[2] -= m;
            if(md[2]==0){
                if(md[1]!=0) ans++;
            }else if(md[2]==1){
                ans++;
            }else{
                ans+=2;
            }
        }
    }else{
        if(md[2]==1) {
            ans++;
        }else{
            md[2] -= 2;
            int m = min(md[1], md[2]);
            ans += 2*m + 2;
            md[1] -= m; md[2] -= m;
            if(md[1]==0){
                if(md[2]!=0) ans++;
            }else if(md[1]==1){
                ans++;
            }else{
                ans+=2;
            }
        }
    }

    print(ans);
    return 0;
}