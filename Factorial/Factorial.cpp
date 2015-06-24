// Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

struct node
{
	int value;
	node *next,*pre;
}*head1 = NULL, *end1 = NULL, *head2 = NULL, *end2 = NULL;

int carry = 0; int d=1;
void insert1(int x)
{
	node *temp;
	end1 = NULL;
	head1 = end1;
	if (x==0)
	{
		int t = x % 10;
		temp = new node;
		temp->value = t;
		end1 = temp;
		temp->pre = NULL;
		temp->next = NULL;
		head1 = temp;

	}
	for (; x >0; x /= 10)
	{
		int t = x % 10;
		temp = new node;
		temp->value = t;
		
		if (end1==NULL)
		{
			end1 = temp;
			temp->pre = NULL;
				temp->next = NULL;
				head1 = temp;
		}
		else
		{
			temp->pre = head1;
			temp->pre->next = temp;
			head1 = temp;
			head1->next = NULL;
		}
		
		
	}
}
void insert2(int x)
{
	node *temp;
	end2 = NULL;
	head2 = end2;
	if (x == 0)
	{
		int t = x % 10;
		temp = new node;
		temp->value = t;
		end2 = temp;
		temp->pre = NULL;
		temp->next = NULL;
		head2 = temp;

	}
	for (; x > 0; x /= 10)
	{
		int t = x % 10;
		temp = new node;
		temp->value = t;

		if (end2 == NULL)
		{
			end2 = temp;
			temp->pre = NULL;
			temp->next = NULL;
			head2 = temp;
		}
		else
		{
			temp->pre = head2;
			temp->pre->next = temp;
			head2 = temp;
			head2->next = NULL;
		}


	}
}

void add1(int x,int i)
{
	node *temp;
	temp = end1;
	for (int j = 0; j < i;j++)
	{
		temp = temp->next;
	}
	if (x == 0)
	{
		head1->value = head1->value + carry;
		carry = 0;
		temp = new node;
		temp->value = 0;
		head1->next = temp;
		temp->pre = head1;
		temp->next = NULL;
		head1 = temp;
	}
	for (; x > 0; x /= 10)
	{
		int t = x % 10;
		if (temp == head1)
		{
			if (head1->value + t +carry > 9)
			{
				head1->value = head1->value + t + carry - 10;
				carry = 1;

			}
			else
			{
				head1->value = head1->value + t + carry;
				carry = 0;
			}
			temp = new node;
			temp->value = 0;
			head1->next = temp;
			temp->pre = head1;
			temp->next = NULL;
			head1 = temp;
		}
		else
		{
			if (temp->value + t + carry > 9)
			{
				temp->value = temp->value + t + carry - 10;
				carry = 1;

			}
			else
			{
				temp->value = temp->value + t + carry;
				carry = 0;
			}
			temp = temp->next;

		}
	}

}
void copy2()
{
	node *temp,*temp2;
	temp = end1;
	insert2(temp->value);
	temp = temp->next;
	for (;temp!=NULL;)
	{
		temp2 = new node;
		temp2->value = temp->value;
		temp2->pre = head2;
		head2->next = temp2;
		temp2->next = NULL;
		head2 = temp2;

		temp = temp->next;
	}
	
}
void multiply(int x)
{
	node *temp;
	copy2();
	insert1(0);
	temp = end2;
	for (int i=0;temp!=NULL;i++)
	{
		add1(temp->value*x, i);
		temp = temp->next;
	}

}
void pri()
{
	node *t;
	t = head1;
	while (t->value==0)
	{
		t = t->pre;
	}
	while (t!=NULL)
	{
		printf("%d", t->value);
		t = t->pre;
	}
	printf("\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	int num1,num2;
	printf("Enter First Number");
	scanf_s("%d", &num1);

	printf("Enter second Number");
	scanf_s("%d", &num2);
	insert1(num1);
	insert2(0);
	multiply(num2);
	pri();
	return 0;
}

