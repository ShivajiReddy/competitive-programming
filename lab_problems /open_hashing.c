#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node* next;
};
typedef struct node NODE;
typedef struct node* NODEPTR;
int opcount;
NODEPTR iniatizeLL(NODEPTR head)
{
	head = (NODEPTR)malloc(sizeof(NODE));
	head->val=0;
	head->next=NULL;
	return head;
}

NODEPTR insertIntoList(NODEPTR head,int val)
{
	NODEPTR temp=(NODEPTR)malloc(sizeof(NODE));
	temp->val=val;
	temp->next=NULL;
	NODEPTR t=head;
	head->val++;
	while(t->next!=NULL)
		t=t->next;
	t->next=temp;
	return head;
}

int getSum(int n)
{
	int sum=0,rem;
	while(n!=0)
	{
		opcount++;
		rem=n%10;
		sum=sum+rem;
		n=n/10;
	}
	return sum;
}

void printll(NODEPTR head)
{
	printf("Bucket size:%d\n",head->val);
	head=head->next;
	while(head!=NULL)
		{printf("%d -> ",head->val);
		head=head->next;}
	printf("\n");
}

int checkIfInBucket(NODEPTR bucket,int ele)
{
	opcount++;
	if(bucket->val==0)
		return 0;
	bucket=bucket->next;
	while(bucket!=NULL)
	{
		opcount++;
		if(ele==bucket->val)
			return 1;
		bucket=bucket->next;
	}
	return 0;
}

int main()
{

	int n,i,j;
	NODEPTR buckets[10];
	opcount=0;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the integer elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Dividing them into 10 buckets!\n");
	int sumOfDigits=0,bucketNo;


	for(i=0;i<10;i++)
	{
		buckets[i]=iniatizeLL(buckets[i]);
	}

	for(i=0;i<n;i++)
	{
		sumOfDigits=getSum(a[i]);
		bucketNo=sumOfDigits%10;
		buckets[bucketNo] = insertIntoList(buckets[bucketNo],a[i]);
	}

	printf("Printing the contents of the bucket:\n");
	for(i=0;i<10;i++)
	{
		printf("Bucket %d\n",i);
		printll(buckets[i]);
	}


	int choice,ele;
	while(1)
	{
		printf("Do you want to look for an element? 1 or 0\n");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("Enter the element:\n");
			scanf("%d",&ele);
			opcount=0;
			sumOfDigits=getSum(ele);
			bucketNo=sumOfDigits%10;
			if(checkIfInBucket(buckets[bucketNo],ele))
				{printf("Element found in the bucket: %d\n",bucketNo);
				printf("SUCCESSFUL SEARCH\nOPCOUNT:%d\n",opcount);}
			else
				{printf("The element not found!\n");
				printf("UNSUCCESSFUL SEARCH\nOPCOUNT:%d\n",opcount);}
		}
		else
		{
			break;
		}

	}


}