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
    int N, Q;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    cin >> Q;
    int t;
    int left, right, mid;
    bool flag=false;
    rep(i, Q){
        cin >> t;
        left=0; right=N-1; mid=(left + right)/2;
        flag=false;
        while(left <= right){
            if(a[mid]==t){
                flag=true;
                break;
            }else if(a[mid]<t){
                left = mid + 1;
                mid = (left+right)/2;
            }else if(a[mid]>t){
                right = mid - 1;
                mid = (left+right)/2;
            }
        }

        if(flag) printf("1\n");
        else printf("0\n");
    }
    return 0;
}