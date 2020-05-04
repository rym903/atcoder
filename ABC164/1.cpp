#define FOR(i, a, b) for(int i=a; i<b; i++)
#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#include<cstdlib>

int main(){
    int s, w;

    scanf("%d %d", &s, &w);

    if(s > w){
        printf("safe\n");
    }else{
        printf("unsafe\n");
    }
    return 0;
}