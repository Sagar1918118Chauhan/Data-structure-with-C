 /*1.Creating
   2.Traverse
         >Forward
         >Reverse
   3.Inserting
           >At beg
		   >At end
		   >At any specific location
	4.Deletion
	      >from beg
		  >from end
		  >from any specific location       
 
    5.Searching
 
 */
#include<stdio.h>
#include<stdlib.h>

struct nodeSLL
{    
    int data;
    struct nodeSLL *next;
};

struct nodeSLL *head=NULL;


void creationSLL();

void displayForward();

void DisplayReverse(struct nodeSLL *head);
 void insertatfirst();
 void insertatend();
void insertatspecificlocation();
void deleteatfirst();
void deleteatend();
void deleteatspecificlocation();
int main()
{    
     creationSLL();
     printf("\n\n");
     printf("Forward manner to display linked list=\n");
     displayForward();
     printf("\n\nReversed manner to display linked list=\n");
    DisplayReverse(head);
       insertatfirst();
       printf("\n\n");
     displayForward();
       insertatend();
        printf("\n\n");
     displayForward();
       insertatspecificlocation();
        printf("\n\n");
    displayForward();
    printf("\n\nDelete item from  beg=\n");
       deleteatfirst();
       printf("\n\n");
     displayForward();
     printf("\n\nDelete item from end=\n");
      deleteatend();
        printf("\n\n");
     displayForward();
     printf("\n\nDelete item from any location=\n");
      deleteatspecificlocation();
       printf("\n\n");
     displayForward();
       return 0;
}

void creationSLL()
{
    struct nodeSLL *newnode,*endnode;
    int item;
    char ch;
    do{
        printf("Enter the data=");
        scanf("%d",&item);
        newnode=(struct nodeSLL *)malloc(sizeof(struct nodeSLL));
        newnode->data=item;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
            endnode=newnode;
        }
        else
        {
            endnode->next=newnode;
            newnode->next=NULL;
            endnode=newnode;
        }
        printf("\nDo you want to add more node? ");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}

void displayForward()
{
    struct nodeSLL *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->\t",temp->data);
        temp=temp->next;
    }
}
void DisplayReverse(struct nodeSLL *head)
{    
    
	if (head == NULL) {
        return;
    }
    DisplayReverse(head->next);
    printf("%d\t", head->data);
}

void insertatfirst()
{
    int item;
    printf("\nEnter the data to be inserted at the beginning=");
    scanf("%d",&item);
    struct nodeSLL *newnode;
    newnode=(struct nodeSLL *)malloc(sizeof(struct nodeSLL));
    newnode->data=item;
    newnode->next=head;
    head=newnode;
}

void insertatend()
{
    int item;
    printf("\nEnter the data to be inserted at the end=");
    scanf("%d",&item);
    struct nodeSLL *newnode,*temp;
    newnode=(struct nodeSLL *)malloc(sizeof(struct nodeSLL));
    newnode->data=item;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertatspecificlocation()
{
    int item,pos,i;
    printf("\nEnter the data to be inserted at a specific location=");
    scanf("%d",&item);
    printf("\nEnter the position=");
    scanf("%d",&pos);
    struct nodeSLL *newnode,*temp;
    newnode=(struct nodeSLL *)malloc(sizeof(struct nodeSLL));
    newnode->data=item;
    temp=head;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deleteatfirst()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct nodeSLL *temp=head;
    head=temp->next;
    free(temp);
}

void deleteatend()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct nodeSLL *temp1=head, *temp2=NULL;
    if(temp1->next==NULL)
    {
        head=NULL;
        free(temp1);
        return;
    }
    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next=NULL;
    free(temp1);
}

void deleteatspecificlocation()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    int pos,i ;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    struct nodeSLL *temp1=head, *temp2=NULL;
    if(pos==1)
    {
        head=temp1->next;
        free(temp1);
        return;
    }
   for(i=1;i<pos && temp1!=NULL;i++)
    {
        temp2=temp1;
        temp1=temp1->next;
         
    }
    if(temp1==NULL)
    {
        printf("Invalid position\n");
        return;
    }
    temp2->next=temp1->next;
    free(temp1);
}

 


