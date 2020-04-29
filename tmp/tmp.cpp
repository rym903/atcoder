#define FOR(i, a, b) for(int i=a; i<b; i++)
#include<bits/stdc++.h>
using namespace std;

bool IsPrime(int m){
    if(m<2) return false;
    if(m==2) return true;
    if(m%2==0) return false;

    double root_m = sqrt(m);

    for(int i=3; i<root_m; i+=2){
        if(m%i==0) return false;
    }

    return true;
}

int main(){
    int n, m;
    cin >> n;

    int ans=0;
    FOR(i, 0, n) {
        cin >> m;
        if(IsPrime(m)) ans++;
    }
    printf("%d\n", ans);

    return 0;
}