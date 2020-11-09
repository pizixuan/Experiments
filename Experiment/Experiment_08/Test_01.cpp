/*  假设二叉树中的每个节点值为单个字符，采用二叉链存储结构存储，设计一个算法求二叉树b中最小值的节点值。
     二叉树为：N(a(n,C(h(H,g))),K(o(,U(I,v)),e(r(s,i),t(y))))

    遇到一个字母就存下来，遇到一个'('就表示为之前一个结点的左孩子，遇到','表示为前一个节点的右孩子，
    遇到')'栈顶节点的子树已经创建完毕，则退栈栈顶元素
*/

#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 10
typedef char ElemType;
typedef struct node{
    ElemType data;
    struct node * lchild;
    struct node * rchild;
}BTNode;

ElemType createBTree(BTNode * &t, ElemType * str){
    BTNode * store[MAXSIZE];        //顺序栈数组
    BTNode * temp;                  //用于创建二叉树
    int top = -1;                   //栈顶指针
    int order = 0;                  //用于判断连接指令
    ElemType minData = 'z';
    t = NULL;
    for (int i = 0; str[i] != '\0'; i++){
        switch (str[i]){
            case '(':               //为栈顶节点的左孩子
                top++;
                store[top] = temp;
                order = 1;          
                break;
            case ',':
                order = 2;          //为栈顶节点的右孩子
                break;
            case ')':
                top--;
                break;
            default :
                temp = (BTNode *)malloc(sizeof(BTNode));
                temp->data = str[i];
                if (temp->data < minData)
                    minData = temp->data;
                temp->lchild = temp->rchild = NULL;
                if (t == NULL)
                    t = temp;
                else{
                    if (order == 1)
                        store[top]->lchild = temp;
                    if (order == 2)
                        store[top]->lchild = temp;
                }
        }
    }
    return minData;
}

void dispBTree(BTNode * t){
    if (t != NULL){
        printf("%c", t->data);
        if (t->lchild != NULL || t->rchild != NULL){
            printf("(");
            dispBTree(t->lchild);
            if (t->rchild != NULL)
            printf(",");
            dispBTree(t->rchild);
            printf(")");
        }
    }
}

int main(){
    BTNode * tree;
    ElemType str[] = "N(a(n,C(h(H,g))),K(o(,U(I,v)),e(r(s,i),t(y))))";
    printf("二叉树最小节点值为：\n");
    printf("%c", createBTree(tree, str));
    return 0;
}