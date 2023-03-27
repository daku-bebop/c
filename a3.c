#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
struct treenode{
    struct treenode *lchild; 
    int data; 
    struct treenode *rchild; 
};typedef struct treenode* BSTREE; 
BSTREE insert(BSTREE root, int num); 
BSTREE insert_from_file(BSTREE root, FILE *fp);
void inorder_traversal(BSTREE root, FILE *fp); 

int main (void) { 
    BSTREE root = NULL;                             
    for(int i = 0; i <=5; i++){
        int num = rand() %66 +2; 
        root = insert(root, num); 
    }
    FILE *fp = fopen("insertion.txt","w"); 
    inorder_traversal(root, fp); 
    fclose(fp); 
  /*  free(root); 
    root = NULL; 
    fp = fopen("dataToBuildDS.txt","r");
    double executionTime; 
    clock_t start = clock(); 
    if(fp == NULL){
        printf("error opening"); 
        exit(1);
    }*/ 
    
}
//insert node into bst 
BSTREE insert(BSTREE root, int num){
    if(root==NULL){                                     //ins at root
        root = (BSTREE)malloc(sizeof(BSTREE)); 
        root->data = num; 
        root->lchild=NULL; 
        root->rchild=NULL; 
    }else if(root->data > num ){                    //if root > than num
        root->lchild = insert(root->lchild, num); 
    }else if(root->data < num){
        root->rchild = insert(root->rchild,num); 
    }
    return root; 
}
BSTREE insert_from_file(BSTREE root, FILE *fp){

}
//traverse and print to file; 
void inorder_traversal(BSTREE root, FILE *fp){
    if(root != NULL){
        inorder_traversal(root->lchild, fp); 
        fprintf(fp,"%d\n",root->data); 
        inorder_traversal(root->rchild,fp); 
    }
}