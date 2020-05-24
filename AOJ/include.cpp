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
    int N, M;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    cin >> M;
    vector<int> b(M);
    rep(i, M) cin >> b[i];
    sort(a.begin(), a.end());

    bool flag=true;
    int left, right, mid;
    for(int i: b){
        flag=true;
        left=0; right=N-1; mid=(left+right)/2;
        while(1){
            if(left>right){
                flag=false;
                break;
            }
            if(a[mid]==i){
                break;
            }else if(a[mid]<i){
                left = mid + 1;
                mid = (left+right)/2;
            }else if(a[mid]>i){
                right = mid - 1;
                mid = (left+right)/2;
            }
        }
        if(flag==false) break;
    }
    if(flag) printf("1\n");
    else printf("0\n");

    return 0;
}