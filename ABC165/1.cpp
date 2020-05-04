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
    int K, A, B;
    cin >> K;
    scanf("%d %d", &A, &B);

    bool flag = false;
    REP(i, K){
        if(i+A >B) break;
        // printf("%d\n", i+A);
        if((i+A)%K == 0){
            flag=true;
            break;
        }
    }
    if(flag){
        printf("OK\n");
    }else{
        printf("NG\n");
    }
    return 0;
}