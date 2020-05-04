#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}

bool match(int row_st, int col_st, vector<string> matrix, vector<string> p_matrix, int r, int c){
    FOR(i, 0, r){
        FOR(j, 0, c){
            if(p_matrix[i][j] != matrix[i+row_st][j+col_st]) return false;
        }
    }
    return true;
}

int main()
{
    int H, W;
    cin >> H; cin >> W;
    vector<string> matrix;
    string row;

    REP(i, H){
        cin >> row;
        matrix.emplace_back(row);
    }

    int R, C;
    cin >> R; cin >> C;
    vector<string> p_matrix;

    REP(i, R){
        cin >> row;
        p_matrix.emplace_back(row);
    }

    REP(i, H-R+1){
        REP(j, W-C+1){
            // printf("%d %d\n", i, j);
            if(match(i, j, matrix, p_matrix, R, C)){
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}