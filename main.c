#include <stdlib.h>
#include <stdio.h>
#include <time.h>


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void print(struct Node *temp);
struct Node * insert(struct Node *head,int i);

int size=0;

struct Node * insert(struct Node *head,int i)
{
    //struct Node *newNode = createNode(i);
    //struct Node *back=NULL;



    if (head==NULL)
    {
        size++;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }

    if ( i >(head->data))
    {
        head->right=insert(head->right,i);

    }
    else if (i < (head->data))
    {
        head->left=insert(head->left,i);

    }

    return head;
}



void print(struct Node *temp)
{

   if (temp == NULL)
    {
        return;
    }

    print(temp->left);
    printf("%d ",temp->data);
    print(temp->right);


}



int counter=0;
struct Node * Find(struct Node *temp,int data)
{


    if (temp == NULL)
    {
        printf("Couldn't find %d in the bst \n",data);
    }
    else if (data==temp->data)
    {
        counter++;
        //printf("%d", counter);
    }
    else if(data < temp->data)
    {
        counter++;
        temp->left= Find(temp->left,data);
    }
    else if(data>temp->data)
    {
        counter++;
        temp->right= Find(temp->right,data);
    }
    else
    {
        printf("Couldn't find %d in the bst",data);
    }


    return temp;

}




int pp=0;
void leftDistribution(struct Node *temp)
{

    if (temp == NULL)
    {
        return;
    }
    while(temp->left  != NULL)
    {
        pp++;
        temp=temp->left;
    }
}

int p=0;
void rightDistribution(struct Node *temp)
{

    if (temp == NULL)
    {
        return;
    }

    while(temp->right  != NULL)
    {
        p++;
        temp=temp->right;
    }

}
void  levels(struct Node *temp)
{

    if(p == pp)
    {
        printf("Tie- left and right are the same %d",pp);
    }
    else if (p < pp)
    {
        printf("Right is bigger %d",p);
    }
    else
    {
        printf("left is bigger %d",pp);
    }

}


int sizef()
{
    return size;
}
int count()
{
    return counter;
}



int main()
{

    struct Node *head = NULL;


    head= insert(head, 120);
    head= insert(head, 83);
    head= insert(head, 39);
    head= insert(head, 520);
    head= insert(head, 870);


    printf("\nThe Bst: \n");

    print(head);
    printf("\n");

    printf("\n---------------------------------------\n");

    //Head is 1, if the node doesn't exist then it's zero
    printf("\nDepth test:\n");
    Find(head,520);
    printf("Find depth of 520: %d nodes deep",count());
    printf("\n");

    counter=0;
    Find(head,39);
    printf("Find depth of 39: %d nodes deep",count());
    printf("\n");

    printf("Find depth of 120: %d nodes deep",count());
    Find(head,120);
    printf("\n");

    counter=0;
    Find(head,83);
    printf("Find depth of 83: %d nodes deep",count());
    printf("\n");

    counter=0;
    printf("Find depth of 90 : %d nodes deep\n",count());
    Find(head,90);

    printf("\n---------------------------------------\n");
    
    printf("\nSize %d\n",sizef());

    printf("\n---------------------------------------\n");
    
    printf("\nDistribution: %d \n",head->data);


    leftDistribution(head);

    printf("left %d\n",pp);

    rightDistribution(head);
    printf("right %d\n",p);

    printf("\n---------------------------------------\n");
    
    printf("\nLevel (deepest node):\n");
    levels(head);
    printf("\n\n");


    return 0;

}
