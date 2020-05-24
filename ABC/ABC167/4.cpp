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
    ll N, K;
    cin >> N >> K;
    int a[N], b[N], c[N];
    rep(i, N) {
        cin>>a[i];
        a[i]--;
        b[i] = 0;
        c[i] = 0;
    }

    int tmp, loop;
    rep(i, N){
        tmp = i;
        loop=0;
        rep(j, N){
            if(a[tmp]!=i && j==N-1){
                b[i] = -1;
                break;
            }
            if(a[tmp]==i){
                loop++;
                b[i]=loop;
                break;
            }
            loop++;
            tmp = a[tmp];
        }
    }
    rep(i, N){
        if(b[i]>0) {
            c[i] = i;
            continue;
        }

        tmp=i;
        loop=0;
        while(b[tmp]<0){
            loop++;
            tmp = a[tmp];
        }
        c[i] = tmp;
        b[i] = -loop;
    }

    // rep(i, N) printf("%d\n", b[i]);

    ll d;
    int ans;
    if(b[0]>0){
        d = K%b[0];
        ans = 0;
        while(d>0){
            ans = a[ans];
            d--;
        }
    }else{
        if(K < -b[0]){
            d = K;
            ans = 0; 
        }else{
            K += b[0];
            ans = c[0];
            d = b[ans];
        }
        while(d>0){
            ans = a[ans];
            d--;
        }
    }

    printf("%d\n", ans+1);
    return 0;
}