#include <stdio.h>
#include <stdlib.h>

int adj[20][20];
int q[20],f=-1,r=-1,indeg[20],i,vertices,topsrt[20];

int add(int n)
{
	if(r==19)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1)
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

int del()
{
	if(f==-1 || f>r)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		int a=q[f++];
		return(a);
	}
}

int indegree(int n)
{
	int incnt;
	incnt=0;
	for(i=0;i<vertices;i++)
	{
		if(adj[i][n]==1)
		{
			incnt++;
		}
	}
	return(incnt);
}

int isEmpty()
{
	if(f>r || f==-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void create_graph()
{
	int count, maximum_edges, origin_vertex, destination_vertex;
	printf("Enter number of vertices:\t");
	scanf("%d", &vertices);
	maximum_edges = vertices * (vertices - 1);
	for(count = 1; count <= maximum_edges; count++)
	{
		printf("Enter Edge [%d] co-ordinates (-1 -1 to quit)\n", count);
		printf("Enter Origin Vertex:\t");
		scanf("%d", &origin_vertex);
		printf("Enter Destination Vertex:\t");
		scanf("%d", &destination_vertex);
		if((origin_vertex == -1) && (destination_vertex == -1))
		{
			break;
		}
		if(origin_vertex >= vertices || destination_vertex >= vertices || origin_vertex < 0 || destination_vertex < 0)
		{printf("Edge Co-ordinates are Invalid\n");
		count--;}
		else
			adj[origin_vertex][destination_vertex] = 1;
}
}

int main()
{
	create_graph();
	printf("Vertices:%d\n",vertices);
	int i;
	for(i=0;i<vertices;i++)
	{
		indeg[i]=indegree(i);
		printf("AAAAAAAAA%d %d\n",i,indeg[i]);
		if(indeg[i]==0)
		{
			printf("YYYYYYYYYYYY%d %d\n",i,indeg[i]);
			add(i);
		}
	}
	int count,k;
	count=0;
	while(!isEmpty() && count<vertices)
	{
		k=del();
		printf("BBXBBBBB%d\n",k);
		topsrt[++count]=k;
		for(i=0;i<vertices;i++)
		{
			if(adj[k][i]==1)
			{
				adj[k][i]=0;
				indeg[i]-=1;
				if(indeg[i]==0)
				{
					add(i);
				}
			}
		}
	}
	if(count < vertices)
	{
		printf("Graph is Cyclic. Therefore, Topological Ordering Not Possible\n");
		exit(1);
	}
	printf("Topological Order of Vertices\n");
	for(i = 1; i <= count; i++)
	{
		printf("%3d", topsrt[i]);
	}
	printf("\n");
	return 0;
	
}