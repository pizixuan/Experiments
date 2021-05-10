/*
    假设二叉树中的每个节点值为单个字符，采用二叉链存储结构存储，
    设计一个算法把二叉树b的左右子树进行交换，要求不破坏原二叉树。
    二叉树为：N( a(n,C(h(H,g))),K(o(,U(I,v)),e(r(s,i),t(y))))
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

void createBTree(BTNode * &t, ElemType * str){
    BTNode * store[MAXSIZE];        //顺序栈数组
    BTNode * temp;                  //用于创建二叉树
    int top = -1;                   //栈顶指针
    int order = 0;                  //用于判断连接指令
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
                temp->lchild = temp->rchild = NULL;
                if (t == NULL)
                    t = temp;
                else{
                    if (order == 1)
                        store[top]->lchild = temp;
                    if (order == 2)
                        store[top]->rchild = temp;
                }
        }
    }
}

BTNode * filpBTree(BTNode * &t){
    if (t != NULL){
        BTNode * temp = (BTNode *)malloc(sizeof(BTNode));       //创建一个结点
        temp->data = t->data;
        temp->lchild = filpBTree(t->rchild);
        temp->rchild = filpBTree(t->lchild);
        return temp;
    }
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
    BTNode * oldTree, * newTree;
    ElemType str[] = "N(a(n,C(h(H,g))),K(o(,U(I,v)),e(r(s,i),t(y))))";
    createBTree(oldTree, str);
    printf("创建的原树：\n");
    dispBTree(oldTree);
    printf("\n翻转后的新树：\n");
    newTree = filpBTree(oldTree);
    dispBTree(newTree);
    printf("\n翻转后的原树：\n");
    dispBTree(oldTree);
    return 0;
}