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
void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}

void print(const list<int> l)
{
    if(l.empty()){
        printf("\n");
        return;
    }
    list<int> ls=l;
    printf("%d", ls.front());
    ls.pop_front();
    for(auto x: ls){
        printf(" %d", x);
    }
    printf("\n");
}
 
int main()
{
    int n, q;
    cin >> n >> q;

    list<int> l[n];
    
    int c, s, t;
    rep(i, q){
        cin >> c >> s;
        if(c==0){
            cin >> t;
            l[s].push_back(t);
        }else if(c==1){
            print(l[s]);
        }else if(c==2){
            cin >> t;
            l[t].splice(l[t].end(), std::move(l[s]));
        }
    }

    return 0;
}