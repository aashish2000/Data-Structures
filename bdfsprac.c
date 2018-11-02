#include <stdio.h>

int vis[20], a[20][20], q[20], s[20],top=0,f=-1,r=-1;

int enq(int n)
{
	if(r==19)
	{
		return(0);
	}
	else
	{
		if(r==-1)
		{
			q[++r]=n;
			f++;
		}
		else
		{
			q[++r]=n;
		}
		return(1);
	}
}

int deq()
{
	if(f==-1 || f>r)
	{
		return(0);
	}
	else
	{
		int k;
		k=q[f++];
		return(k);
	}
}


int bfs(int v,int n)
{
	int p;
	enq(v);
	vis[v]=1;
	p=deq();
	int i;
	if(p!=0)
	{
		printf("%d ",p);
	}
	while(p!=0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[p][i]==1 && vis[i]==0)
			{
				enq(i);
				vis[i]=1;
				
			}
		}
		p=deq();
		if(p!=0)
		{
			printf("%d ",p);
		}
	}
	for (i = 1; i <=n; ++i)
	{
		if(vis[i]==0)
		{
			bfs(i,n);
		}
	}

}


int push(int n)
{
	if(top==19)
	{
		return(0);
	}
	else
	{
		s[++top]=n;
		return(1);
	}
}

int pop()
{
	if(top==-1)
	{
		return(0);
	}
	else
	{
		int k;
		k=s[top--];
		return(k);
	}
}



int dfs(int v,int n)
{
	int p;
	push(v);
	vis[v]=1;
	p=pop();
	int i;
	if(p!=0)
	{
		printf("%d ",p);
	}
	while(p!=0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[p][i]==1 && vis[i]==0)
			{
				push(i);
				vis[i]=1;
				
			}
		}
		p=pop();
		if(p!=0)
		{
			printf("%d ",p);
		}
	}
	for (i = 1; i <=n; ++i)
	{
		if(vis[i]==0)
		{
			dfs(i,n);
		}
	}

}

void main()
{
	int n,i,s,ch,j;
	char c,dummy;
	printf("No of Vertices: ");
	scanf("%d",&n);
	printf("Adjacency Matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("THE ADJACENCY MATRIX IS\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}

	do
	{
		for(i=1;i<=n;i++)
		vis[i]=0;
		printf("\nMENU");
		printf("\n1.B.F.S");
		printf("\n2.D.F.S");
		printf("\nChoice: ");
		scanf("%d",&ch);
		printf("\nENTER THE SOURCE VERTEX :");
		scanf("%d",&s);

		switch(ch)
		{
			case 1:{bfs(s,n);
			break;}
			case 2:
			{
			dfs(s,n);
			break;
		}
		}
		printf("\nDO U WANT TO CONTINUE(Y/N) ? ");
		scanf("%c",&dummy);
		scanf("%c",&c);
	}while((c=='y')||(c=='Y'));
}