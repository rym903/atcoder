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

ull X=0;
void test_b(ll i) {
    if(X & ((ll)1<<i)){
        printf("1\n");
    }else{
        printf("0\n");
    }
}

void set_b(ll i){
    X = X | ((ll)1<<i);
}

void clear_b(ll i){
    X = X & ~((ll)1<<i);
}

void flip_b(ll i){
    X = X ^ ((ll)1<<i);
}

void all_b(){
    if((X ^ ~0) == 0){
        printf("1\n");
    }else{
        printf("0\n");
    }
}
 
void any_b(){
    if((X | 0) == 0){
        printf("0\n");
    }else{
        printf("1\n");
    }
}

void none_b(){
    if((X | 0) == 0){
        printf("1\n");
    }else{
        printf("0\n");
    }
}

void count_b(){
    ll ans = 0;
    // cout << bitset<64>(X) << endl;
    for(ll i=0; i<64; i++){
        if((X & ((ll)1<<i)) > 0) {
        ans++;
        }
    }
    cout << ans << endl;
}

void count_b_(ll tmp){
    ll ans = 0;
    for(ll i=0; i<64; i++){
        if((tmp & ((ll)1<<i)) > 0) {
            cout << bitset<64>((ll)1<<i) << endl;
            ans++;
        }
    }
    cout << ans << endl;
}

void val_b(){
    cout << X << endl;
}

int main()
{
    ll q;
    cin >> q;
    ll c, i;

    //0, 1,...,8 は操作の種類を示し、それぞれtest(i), set(i), clear(i), flip(i), all, any, none, count, val を表します。
    rep(k, q){
        scanf("%lld", &c);
        if(c==0){
            scanf("%lld", &i);
            test_b(i);

        }else if(c==1){
            scanf("%lld", &i);
            set_b(i);
        }else if(c==2){
            scanf("%lld", &i);
            clear_b(i);
        }else if(c==3){
            scanf("%lld", &i);
            flip_b(i);
        }else if(c==4){
            all_b();
        }else if(c==5){
            any_b();
        }else if(c==6){
            none_b();
        }else if(c==7){
            count_b();
        }else if(c==8){
            val_b();
        }
        // cout << bitset<64>(X) << endl;
    }
    return 0;
}