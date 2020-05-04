#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    int t_prev=0, x_prev=0, y_prev=0;
    int t_next, x_next, y_next;
    int dist, time_dif;
    bool flag=true;

    for(int i=0; i<N; i++){
        scanf("%d %d %d", &t_next, &x_next, &y_next);
        dist = abs(x_next-x_prev) + abs(y_next-y_prev);
        time_dif = t_next - t_prev;
        
        if(dist==0 || dist > time_dif){
            flag = false;
            break;
        }

        if((time_dif-dist)%2==1){
            flag = false;
            break;
        }
    }

    if(flag) printf("Yes\n");
    else printf("No\n");

    return 0;
}