#define FOR(i, a, b) for(int i=a; i<b; i++)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<utility>
#include<string>
#include<iostream>
using namespace std;

struct item {
  int value; 
  int weight;
  double one_benefit;
  int num;
  int full_benefit;
};

bool comp(item& x, item& y){
    return x.full_benefit < y.full_benefit;
}

int main(){
    int n = 3, W=7;
    int w[] = {4,3,2}, v[]={5,4,3};

    item items[n];
    FOR(i, 0, n){
        items[i].value = v[i];
        items[i].weight = w[i];
        items[i].one_benefit = (double)v[i] / w[i];
        items[i].num = W / w[i];
        items[i].full_benefit = items[i].value * items[i].num; 
    } 

    int ans = 0;
    while(W>0 || n>0){
        sort(items, items+n, comp);
        item it = items[n-1]; // 一番利得の大きいもの
        ans += it.full_benefit;
        W -= it.num * it.weight;
        
        n--;
        FOR(i, 0, n) {
            items[i].num = W / w[i];
            items[i].full_benefit = items[i].value * items[i].num; 
        }
    }

    printf("%d\n", ans);

    return 0;
}