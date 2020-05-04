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
template <class T>
void printarr(T& arr){
    
}
 
int main()
{
    int n, m;
    int a[1001], b[1001];
    cin >> n;
    REP(i, n){
        scanf("%d", &a[i]);
    }
    cin >> m;
    REP(i, m){
        scanf("%d", &b[i]);
    }

    int max_a=0, max_b=0; //最高位
    REP(i, n){
        if(a[n-i-1]!=0) max_a = i+1;
    }
    REP(i, m){
        if(b[m-i-1]!=0) max_b = i+1;
    }

    int is_1 = -1;
    REP(i, min(n, m)){
        if(a[i] < b[i]){
            is_1 = 1;
            break;
        }else if(a[i] > b[i]){
            is_1 = 0;
            break;
        }
    }

    if(is_1==-1){
        if(n<m){
            is_1 = true;
        }else{
            is_1 = false;
        }
    }
    printf("%d\n", is_1);
    return 0;
}