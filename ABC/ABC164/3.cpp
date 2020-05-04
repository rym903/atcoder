#define FOR(i, a, b) for(int i=a; i<b; i++)
#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#include<cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    char ss[n][100];
    string s[n];
    bool scanned[n];

    FOR(i, 0, n){
        scanf("%s", ss[i]);
        printf("%s\n", ss[i]);
        if(strcmp(ss[0], ss[i])==0) printf("a\n");
        scanned[i] = false;
    }

    int ans=0;
    FOR(i, 0, n){   
        if(scanned[i]) continue;
        ans++;
        FOR(j, i, n){
            if(scanned[j]) continue;
            if(strcmp(ss[i], ss[j])==0) scanned[j] = true;
        }
    }

    printf("%d\n", ans);
}