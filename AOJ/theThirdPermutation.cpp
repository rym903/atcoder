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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void prarr(vector<vector<T>>& a){
rep(i, a.size()){
rep(j, a[i].size()){
cout << a[i][j]; printf(" ");}
printf("\n");} printf("\n");}

int getdigit(int n){
    int k = 10000;
    int dig = 5;
    while(k>0){
        if(n/k>0) return dig;
        dig--;
        k /= 10;
    }
    return -1;
}

int joint(int a, int b){
    int c = getdigit(b);
    a *= (int)pow(10, c);
    return a + b;
}

int main()
{
    int n; cin >> n;
    arr<int> a(5);

    rep(i, n){
        int t; cin >> t;
        a[getdigit(t)-1].push_back(t);
    }
    // prarr(a);

    arr<int> b;
    int num=0, ai=0;
    while(num<3){
        if(a[ai].size()==0) {
            ai++;
            continue;
        }
        num += a[ai].size();
        b.push_back(a[ai++]);
    }
    rep(i, b.size()) sort(ALL(b[i]));
    // prarr(b);
    if(b.size()==3){
        pr(min(joint(b[0][0], b[2][0]), joint(b[2][0], b[0][0])));
    }else if(b.size()==1){
        if(b[0].size()==3) pr(joint(b[0][1], b[0][0]));
        else pr(joint(b[0][0], b[0][3]));
    }else if(b[0].size()==2){
        pr(min(joint(b[0][0], b[1][0]), joint(b[1][0], b[0][0])));
    }else{
        //まず、b[1]の2つ目とb[0][0]のjointを全てとる。
        vector<int> c;
        rep(i, 2) {
            c.push_back(joint(b[0][0], b[1][i]));
            c.push_back(joint(b[1][i], b[0][0]));
        }
        // b[1]のサイズが3以上ならば、b[1][2]とのjointも含める。
        if(b[1].size()>2){
            c.push_back(joint(b[0][0], b[1][2]));
            c.push_back(joint(b[1][2], b[0][0]));
        }
        sort(ALL(c));
        pr(c[2]);
    }
    return 0;}