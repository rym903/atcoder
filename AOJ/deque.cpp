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
    deque<int> que;
    int q;
    cin >> q;

    int com, d, x;
    rep(i, q){
        cin >> com;
        if(com==0){
            cin >> d >> x;
            if(d==0){
                que.emplace_front(x);
            }else{
                que.emplace_back(x);
            }
        }else if(com==1){
            cin >> d;
            print(que[d]);
        }else if(com==2){
            cin >> d;
            if(d==0) que.pop_front();
            else que.pop_back();
        }
    }
    return 0;
}