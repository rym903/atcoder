#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}

struct Node{
    int num;
    Node *left;
    Node *right;
};

ll calc_length(Node *node, int depth){
    if(node->left==NULL){
        return depth * node->num;
    }
    return calc_length(node->left, depth+1) + calc_length(node->right, depth+1);
}

// void print_length(Node *node, int depth){
//     if(node->left==NULL){
//         printf("(%d %d)\n", node->num, depth);
//         return;
//     }
//     print_length(node->left, depth+1);
//     print_length(node->right, depth+1);
// }

int coef(Node *p){
    if(p->left == NULL && p->right==NULL){
        return 1;
    }else{
        return 2;
    }
}


bool compare(Node* p1, Node* p2){
    return p1->num > p2->num;
}

int main()
{
    char S[100005];
    scanf("%s", S);
    unordered_map<char, int> dict_u;
    int n_len=0;
    while(S[n_len] != '\0'){
        dict_u[S[n_len]]++;
        n_len++;
    }
    
    vector<Node*> num;  
    int n=0;
    for(auto i=dict_u.begin(); i!=dict_u.end(); i++){
        Node* p=(Node*)malloc(sizeof(Node));
        p->num=i->second; p->left=NULL; p->right=NULL;
        num.emplace_back(p);
        n++;
    }

    sort(ALL(num), compare);
    
    for(int i=n-1; i>0; i--){
        // REP(j, i+1) printf("%d ", num[j]->num);
        // printf("\n");
        Node *right=num[i], *left=num[i-1];
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->num = (right->num) + (left->num);

        newnode->left = left; newnode->right = right;
        // printf("right.num = %d, length=%d\n", right->num, right->length);
        // printf("left.num = %d, length=%d\n", left->num, left->length);
        // printf("newnode.num = %d\n", (right->num) + (left->num));
        num[i-1] = newnode;

        sort(num.begin(), num.begin()+i, compare);
    }
    // printf("%d\n", num[0]->num);
    Node *head = num[0];
    if(head->left == NULL){
        printf("%d\n", num[0]->num);
    }
    else{
        printf("%lld\n", calc_length(head, 0));
        // print_length(head, 0);
    }

    return 0;
}