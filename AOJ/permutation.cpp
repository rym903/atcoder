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

int find_id_dec(vector<int> a, int x, int id){ //xより小さく、絶対値が最小のインデックス
    int abs_id=id+1;
    FOR(i, id+1, a.size()){
        if(a[i] < x && abs(x - a[abs_id]) > abs(x - a[i])){
            abs_id = i;
        }
    }
    return abs_id;
}

int find_id_inc(vector<int> a, int x, int id){ //xより大きく、絶対値が最小のインデックス
    int abs_id=id+1;
    FOR(i, id+1, a.size()){
        // printf("i=%d, ab=%d, x=%d, abs=%d\n", i, abs_id, x, abs(x-a[i]));
        if(a[i] > x && abs(x - a[abs_id]) > abs(x - a[i])){
            abs_id = i;
        }
    }
    return abs_id;
}

void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}

void decrement(vector<int> a){
    int n = a.size();
    int id=n-2;
    if(id<0) return;
    while(a[id] < a[id+1]) {
        if(id==0){
            return;
        }
        id--;
    }
    int swap_id = find_id_dec(a, a[id], id);
    swap(a[id], a[swap_id]);
    reverse(a.begin()+id+1, a.end());
    printvec(a);
}

void increment(vector<int> a){
    int n = a.size();
    int id=n-2;
    if(id<0) return;
    while(a[id] > a[id+1]) {
        if(id==0){
            return;
        }
        id--;
    }
    int swap_id = find_id_inc(a, a[id], id);
    swap(a[id], a[swap_id]);

    reverse(a.begin()+id+1, a.end());
    printvec(a);
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }

    decrement(a);
    printvec(b);
    increment(c);

    return 0;
}