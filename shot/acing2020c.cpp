#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define N 10000
vector<int> f(N+1, 0);

int func(vector<int> A){
    int k = A[0]*A[0];
    if(A.size()>1) k += A[1]*A[1] + A[1]*A[0];
    if(A.size()>2) k += A[2]*A[2] + A[2]*A[0] + A[2]*A[1];
    return k;
}

int xyz(int x, int y, int z){
    return x*x + y*y + z*z + x*y + y*z + z*x;
}

void dfs(vector<int> A){
    prvec(A); pr(func(A));
    if(A.size()==3){
        int k = func(A);
        if(k<=N){
            if(A[0]==A[1] && A[0]==A[2]) f[k]++;
            else if(A[0]!=A[1] && A[0]!=A[2] && A[1]!=A[2]) f[k]+=6;
            else f[k] += 3;
        } 
        return;
    }else{
        while(func(A)<=N){
            int b = A.back();
            for(int i=b; func(A)+i*i<=N; i++){
                vector<int> B=A;
                B.push_back(i);
                dfs(B);
            }
            A[A.size()-1]++;
        }
    }
}

int main()
{
    int n; cin >> n;
    vector<int> a(3);
    int x=1;
    while(x*x < 10000){
        int y = x;
        while(x*x + x*y + y*y < 10000){
            int z = y;
            while(xyz(x, y, z) <= 10000){
                if(x==y && y==z) f[xyz(x, y, z)]++;
                else if(x!=y && y!=z && z!=x) f[xyz(x, y, z)] += 6;
                else f[xyz(x, y, z)] += 3;
                z++;
            }
            y++;
        }
        x++;
    }

    rep(i, n) pr(f[i+1]);
    return 0;}