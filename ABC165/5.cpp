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
    int N, M;
    scanf("%d %d", &N, &M);

    int cnt=0,st=0,end;
    int st2, end2;
    int max_dist = M;
    int dist = max_dist;
    while(cnt<M){
        end = st+dist;
        st2 = st+M+1; end2=st2+dist-1;
        printf("%d %d\n", st+1, end+1);
        cnt++;
        if(cnt==M) break;

        printf("%d %d\n", st2+1, end2+1);
        cnt++;
        st++;
        dist -= 2;
    }
    return 0;
}