#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* stack[100];
int top=-1;
void push(node* data){
    stack[++top]=data;
}
node* pop(){
    return stack[top--];
}
node* newNode(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
node* search(node* root,int data){
    if(root==NULL||root->data==data){
        return root;
    }
    if(root->data<data){
        return search(root->right,data);
    }else{
        return search(root->left,data);
    }
}
node* insert(node* root,int key){
    if(root==NULL){
        return newNode(key);
    }
    if(root->data>key){
        root->left=insert(root->left,key);
    }
    else if(root->data<key){
        root->right=insert(root->right,key);
    }
    return root;
}
node* succesor(node* root){
    node* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* delete(node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=delete(root->left,key);
    }
    else if(key>root->data){
        root->right=delete(root->right,key);
    }
    else{
    if(root->left==NULL){
        node* temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        node* temp=root->left;
        free(root);
        return temp;
    }
    node* temp=succesor(root->right);
    root->data=temp->data;
    root->right=delete(root->right,temp->data);
    }
    return root;
}
void printpath(node* root,int key){
    if(root!=NULL){
        printf("%d->",root->data);
        if(root->data==key){
            printf("inside if \n");
            return;
        }
        printpath(root->left,key);
        printpath(root->right,key);
    }
}
void print(node* root,int key){
    if(root==NULL){
        return;
    }
    push(root);
    while(top!=-1){
        node* temp=pop();
        printf("%d->",temp->data);
        // if(temp->data==key){
        //     break;
        // }
        if(root->left){
            root=root->left;
            push(root);
        }
        if(root->right){
            root=root->right;
            push(root->left);
        }
    }
    // for(int i=0;i<=top;i++){
    //     printf("%d->",stack[i]->data);
    // }
}
int main(){
    node* root=NULL;
    root=insert(root,80);
    insert(root,20);
    insert(root,90);
    insert(root,40);
    insert(root,100);
    // inorder(root);
    printf("\n");
    // node* temp=succesor(root);
    // printf("%d\n",temp->left);
    // root=delete(root,70);
    // inorder(root);
    // printpath(root,40);
    print(root,40);
}