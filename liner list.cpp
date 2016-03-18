#include<iostream>
#include<cstdlib>
#include<cstdio>
#define NUM 10000
#define OK 1
#define ERROR 0
using namespace std;
typedef struct LNode
{
	int data;
	LNode *next;
}LNode,*LinkList;

int Create(LinkList &L,int n)
{
	LNode *p,*r;
	int i,d;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	i=0;
	r=L;
	while (i<n)
	{
		scanf("%d",&d);
		p=(LNode*)malloc(sizeof(LNode));
		p->data=d;
		r->next=p;
		r=r->next;
		++i;
	}
	return OK;
}

int Find(LinkList L,int k,int &e)
{
	int i=0;
	LNode *p;
	p=L;
	while (p&&i<k)
	{
		p=p->next;
		i++;
	}
	if (p)
	{
		e=p->data;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

int Insert(LinkList&L,int k,int e)
{
    int i=0;
    LNode *p ,*r;
    p=L;
    while (p&&i<k-1)
    {
        p=p->next;
        i++;
    }
    if (!p) return ERROR;
    r=(LNode*)malloc(sizeof(LNode));
    r->next=p->next;
    p->next=r;
    r->data=e;
    return OK;
}

int Delete(LinkList&L,int k,int &e)
{
	LNode *p,*r;
	int i;
	p=L;
	i=1;
	while (p->next&&i<k)
	{
		i++;
		p=p->next;
	}
	if (!p->next) return ERROR;
	else
	{
		r=p->next;
		p->next=r->next;
		e=r->data;
		free(r);
		return OK;
	}
}

int Sort(LinkList &L,int l,int r)
{
	int i,temp,sta,end;
	LNode *p;

	i=1;
	sta=l;
	end=r;
	while (sta<end)
	{
		i=1;
		p=L->next;
		while (i<sta)
		{
			++i;
			p=p->next;
		}
		while (i<=end)
		{
			++i;
			if ((p->data)>(p->next->data))
			{
				temp=p->data;
				p->data=p->next->data;
				p->next->data=temp;
			}
			p=p->next;
		}
		end--;
	}
	return OK;
}
int main()
{
	LinkList L;
	LNode *p;
	int n,x,y,ans,i,e;
	scanf("%d",&n);
	Create(L,n);
	//scanf("%d",&x);//   find  here
	//if (Find(L,x,ans))  cout << ans << endl;
	//else cout << "ERROR" << endl;
	/*Sort(L,1,n);
	p=L->next;
	for (i=1;i<=n;++i)
	{
		cout << p->data << " ";
		p=p->next;
	}*/       // sort here
	/*scanf("%d",&y);
	if (Delete(L,y,e))
	{
		p=L->next;
		n=n-1;
		for (i=1;i<=n;++i)
		{
			cout << p->data << " ";
			p=p->next;
		}
		cout << endl;
		cout << e << endl;
	}*/  // delete here
	int pos;
	scanf("%d%d",&pos,&x);
	if (Insert(L,pos,x))
    {
        p=L->next;
        ++n;
        for (i=1;i<=n;++i)
        {
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
    }
	return 0;
}
