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

int N, M, X;
int ans;

bool is_over(vector<int> *a, ll select){
    int tmp[M];
    memset(tmp, 0, sizeof(tmp));
    rep(i, N){
        if((select >> i)%2 == 1){
            rep(j, M){
                tmp[j] += a[i][j];
            }
        }
    }

    bool flag = true;
    rep(i, M){
        if(tmp[i] < X){
            flag = false;
            break;
        }
    }

    return flag;
}

void is_can(vector<int> c, vector<int> *a, int mid, int book, int sm, ll select, bool *flag){
    if(is_over(a, select)){
        *flag = true;
        return;
    }
    //加える
    if(book < N){
        if(sm+c[book] <= mid){
            is_can(c, a, mid, book+1, sm+c[book], select+(ll)pow(2,book), flag);
        }

        //加えない
        is_can(c, a, mid, book+1, sm, select, flag);
    }
}
 
int main()
{
    cin >> N >> M >> X;
    vector<int> a[N];
    vector<int> c(N);
    rep(i, N) a[i].resize(M);

    rep(i, N){
        cin >> c[i];
        rep(j, M){
            cin >> a[i][j];
        }
    }

    ans = 0;
    int left=0, right, mid;
    vector<bool> is_selected(N);
    rep(i, N) is_selected[i] = false;
    rep(i, N) right+=c[i];
    mid = (left+right)/2;

    bool flag, tmp;

    while(left<=right){
        flag = false;
        tmp = false;
        // is_can(c, a, mid, 0, 0, 0, &tmp);
        // printf("%d\n", tmp);

        is_can(c, a, mid, 0, 0, 0, &flag);
        if(flag){
            ans = mid;
            right = mid-1;
            mid = (left+right)/2;
        }else{
            left = mid+1;
            mid = (left+right)/2;
        }
    }

    if(ans==0) printf("-1\n");
    else print(ans);
    return 0;
}