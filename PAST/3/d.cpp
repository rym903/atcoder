#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
char zero[5][3] = {
    {'#','#','#'},
    {'#','.','#'},
    {'#','.','#'},
    {'#','.','#'},
    {'#','#','#'},
};
char one[5][3] = {
    {'.','#','.'},
    {'#','#','.'},
    {'.','#','.'},
    {'.','#','.'},
    {'#','#','#'},
};

char two[5][3] = {
    {'#','#','#'},
    {'.','.','#'},
    {'#','#','#'},
    {'#','.','.'},
    {'#','#','#'},
};

char three[5][3] = {
    {'#','#','#'},
    {'.','.','#'},
    {'#','#','#'},
    {'.','.','#'},
    {'#','#','#'},
};
char four[5][3] = {
    {'#','.','#'},
    {'#','.','#'},
    {'#','#','#'},
    {'.','.','#'},
    {'.','.','#'},
};
char five[5][3] = {
    {'#','#','#'},
    {'#','.','.'},
    {'#','#','#'},
    {'.','.','#'},
    {'#','#','#'},
};
char six[5][3] = {
    {'#','#','#'},
    {'#','.','.'},
    {'#','#','#'},
    {'#','.','#'},
    {'#','#','#'},
};
char seven[5][3] = {
    {'#','#','#'},
    {'.','.','#'},
    {'.','.','#'},
    {'.','.','#'},
    {'.','.','#'},
};
char eight[5][3] = {
    {'#','#','#'},
    {'#','.','#'},
    {'#','#','#'},
    {'#','.','#'},
    {'#','#','#'},
};
char nine[5][3] = {
    {'#','#','#'},
    {'#','.','#'},
    {'#','#','#'},
    {'.','.','#'},
    {'#','#','#'},
};

int main()
{
    int n; cin >> n;
    vector<string> p(5);
    rep(i, 5) cin >> p[i];

    // rep(i, 5){
    //     cout << p[i] << endl;
    // }

    rep(i, n){
        bool flag;
        flag = true;

        // cout << i << endl;
        // rep(j, 5){
        //     for(int k=0; k <= 2; k++){
        //         cout << p[j][4*(i+1) + k - 3] << " ";
        //     }
        //     cout << endl;
        //     // if(!flag) break;
        // }

        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != zero[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("0"); continue;}
        
        flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != one[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("1"); continue;}

        flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != two[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("2"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != three[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("3"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != four[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("4"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != five[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("5"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != six[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("6"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != seven[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("7"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != eight[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("8"); continue;}

                flag = true;
        rep(j, 5){
            for(int k=0; k <= 2; k++){
                if(p[j][4*(i+1) + k - 3] != nine[j][k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) {printf("9"); continue;}

        printf("baka\n");
    }
    return 0;
}