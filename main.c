#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node*left;
    struct node*right;

}tree;
typedef struct {
    struct node*top;

 }stack;


tree*creatnewnode(char value){
    tree*newnode = (tree*)malloc(sizeof(tree));
    if(newnode == NULL)return NULL;

    newnode -> data = value;
    newnode -> left = NULL;
    newnode ->right =NULL;

    return newnode;
}


tree*buildtree(char postfix[]){
    tree*s[100] ;
    int top = -1;

    for(int i = 0;postfix[i]!='\0';i++){
        char c =postfix[i];

        if(c != '+' && c != '-' && c != '*' && c != '/'){
                s[++top] = creatnewnode(postfix[i]);

}
        else{
            tree* newnode = creatnewnode(postfix[i]);
            newnode-> right =s[top--];
            newnode-> left =s[top--];
            s[++top] = newnode;

        }
    }return s[top];
}

void inorder(tree*root){
    if(root != NULL){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}


void preorder(tree*root){
    if(root != NULL){
        printf("%c", root-> data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(tree*root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);

    }

}

int evaluate(tree*root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            return root->data - '0';
        }
        int eve_left = evaluate(root->left);
        int eve_right = evaluate(root->right);

        int result;
       switch(root->data){
            case '+':
              result = eve_left + eve_right;
              break;
            case '-':
                result = eve_left - eve_right;
                break;
            case '*':
                result = eve_left * eve_right;
                break;
            case '/':
                result = eve_left / eve_right;
                break;

}return result;
    }
return 0;
}

void menu(){
    tree*root = NULL;
    char postfix[100];
    int choice;

    printf("\n--menu-driven prigram--\n");
    printf("number 1 for bulding an expretion tree from a postfix expretion !\n");
    printf("number 2 for displaying traversala !\n");
    printf("number 3 for evaluate the expretion tree !\n");
    printf("number 4 for exit !\n ");

    do{
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("enter postfix expretion = ");
            scanf("%s",postfix);
            root = buildtree(postfix);
            if(root != NULL){
                printf("the tree created successfully");
            }
            else{
                printf("invalid expretion");
            }

            break;
        case 2:
            if(root == NULL){
                printf("try to use the instruction with the number '1'");
            }
            int traversal;
            printf("enter '1' for inorder \n'2' for preorder\n'3' for postorder\n");
            scanf("%d",&traversal);
            switch(traversal){
                case 1:
                    inorder(root);
                    break;
                case 2:
                    preorder(root);
                    break;
                case 3:
                    postorder(root);
                    break;

            default:
                    printf("invalid choice");
                    break;

            break;
            }
            break;
        case 3 :
            printf("the result is %d",evaluate(root));
            break;
        case 4:
            printf(" u didn't follow the rules");
            break;
}
} while(choice != 4 );
}


int main()
{

    /*char postfix[] = "45+";
    tree*root = buildtree(postfix);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    int result = evaluate(root);
    printf("the result is %d",result);*/
    menu();

    return 0;
}
