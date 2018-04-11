#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//a linked list node
struct node
{
	int data;
	struct node*next;
};
void push(struct node**head_ref,int data)
{


	struct node*newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("incorrect input");
	}
	else
	{
	
	newNode->data=data;
	newNode->next=*head_ref;
*head_ref=newNode;
//return newNode;
}
}
//inserting after a new node
void afterinsert(struct node*second,int data)
{
	if(second==NULL)
	{
		printf("wrong entry");
	}
	else
	{
		struct node* new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=second->next;
		second->next=new;
	}
}
//inserting at the end
void end(struct node*head,int value)
{
	struct node*p,*q;
	p=malloc(sizeof(struct node));
	q=malloc(sizeof(struct node));
	p->data=value;
	p->next=NULL;
	q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
}
//deleting a node
void deleteNode(struct node**head,int key)
{
	struct node*temp=*head,*prev;
	if(temp!=NULL&&temp->data==key)
	{
		*head=temp->next;
		free(temp);
		return;
	}
	//searching for key in likned list
	while(temp!=NULL&& temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	return;
		prev->next=temp->next;
	
	free(temp);
}
//deleting a node at specific position
void delpos(struct node**head,int pos)
{
	int i;
	if(*head==NULL)
	return ;
	struct node*temp=*head;
	if(pos==0)
	{
		*head=temp->next;
		free(temp);
		return ;
	}
	for( i=0;temp!=NULL&&i<pos-1;i++)
	temp=temp->next;
	if(temp==NULL||temp->next==NULL)
	return ;
	struct node*next=temp->next->next;
	free(temp->next);
	temp->next=next;
}
//count of nodes
static int getcount(struct node*head)
{
	struct node*temp=head;
	int c=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}
//searching a node
int search(struct node*head,int x)
{
	struct node*temp=head;
    int flag=0;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
		flag=1;
			return flag;
	}
		temp=temp->next;
	
	}
		return flag;
}
//swap nodes in a linked list without swpping data
void swapnode(struct node*head,int x,int y)
{
	if(x==y)
	{
		return ;
	}
	struct node*prevx=NULL;struct node*currx=head;
	while(currx&&currx->data!=x)
	{
		prevx=currx;
		currx=currx->next;
	}
	struct node*prevy=NULL;struct node*curry=head;
	while(curry&&curry->data!=y)
	{
		prevy=curry;
		curry=curry->next;
	}
	if(currx==NULL||curry==NULL)
	{
		return ;
	}
	if(prevx!=NULL)
	prevx->next=curry;
	else
	head=curry;
	if(prevy!=NULL)
	prevy->next=currx;
	else
	head=currx;
	struct node*temp=curry->next;
	curry->next=currx->next;
	currx->next=temp;
}
//get nth Node in link list
int getnode(struct node*head,int index)
{
	struct node*current=head;
	int c=0;
	while(current!=NULL)
	{
	
	if(c==index)
	{
		return (current->data);
	}
	c++;
	current=current->next;
}
}
// get nth node from last
void printNthFromLast(struct node* head, int n)
{
    int len = 0, i;
    struct node *temp = head;
 
    // 1) count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
 
    // check if value of n is not more than length of the linked list
    if (len < n)
      return;
 
    temp = head;
 
    // 2) get the (n-len+1)th node from the begining
    for (i = 1; i < len-n+1; i++)
       temp = temp->next;
 
    printf ("%d", temp->data);
 
    return;
}
void main()
{
	struct node* head=NULL;
	struct node*second=NULL;
	struct node*third=NULL;
	//allocating 3 node in the heap
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=second;
	second->data=2;
    second->next=third;
	third->data=3;
	third->next=NULL;
	//push(30);
push(&head,30);
afterinsert(second,40);
end(head,50);
deleteNode(&head,40);
delpos(&head,3);
printlist(head);
int m=getcount(head);
printf("numbr of nodes are :%d",m);
printf("\n");
int d=search(head,21);
printf("%d",d);
printf("\n");
swapnode(head,1,50);
int p=getnode(head,2);
printNthFromLast(head,2);
printlist(head);
printf("%d",p);
getch();
}


int printlist(struct node*n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n=n->next;
	}
	return 0;
}
