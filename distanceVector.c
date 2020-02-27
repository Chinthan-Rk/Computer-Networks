#include<conio.h>
#include<stdio.h>
#define INF 999

struct routingTable
{
    int cost;
    int via;

}RT[10][10];


void readRouteTable(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Routing table for %c\n",'A'+i);

        for(int j=0;j<n;j++)
        {
            if(i==j)
            RT[i][j].cost=0;
            else
            {
                printf("%c ==> %c : ",('A'+i),('A'+j));
                scanf("%d",&RT[i][j].cost);
                
            }
           

            if(RT[i][j].cost != INF)
                RT[i][j].via = j;
            else
                RT[i][j].via=INF;
        }
    }
}

void buildRouteTable(int i,int n)
{
    int newCost=0;
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<n && j!=i;k++)
        {
            if(RT[i][j].cost != INF)
            {
                newCost = RT[i][j].cost + RT[j][k].cost;
                if(RT[i][k].cost > newCost)
                {
                    RT[i][k].cost = newCost;
                    RT[i][k].via = RT[i][j].via;
                }
            }
        }
    }
}

void dispRT(int n,int i)
{
    printf("Routing table for %c",'A'+i);
    printf("Destination\tCost\tVia\n");
    for(int j=0;j<n;j++)
    {
        printf("%c\t",'A'+j);
        printf("%d\t",RT[i][j].cost);
        printf("%c\t",RT[i][j].via);
        printf("\n");
    }
}

void findPath(int src,int dest)
{
    printf("%c",'A'+src);
    if(src!=dest)
    {
        findPath(RT[src][dest].via,dest);
    }
}

int main()
{
    
    printf("Enter the number of routers : ");
    int n,choice=1;
    scanf("%d",&n);

    printf("Enter the routing table : \n");
    readRouteTable(n);

    for(int i=0;i<n;i++)    
        buildRouteTable(i,n);

    for(int i=0;i<n;i++)
        dispRT(n,i);
    
    while(choice)
    {
        printf("Enter the source node : ");
        int src;
        scanf("%d",&src);
        printf("Enter the destination node : ");
        int dest;
        scanf("%d",&dest);

        findPath(src,dest);
        printf("Shortest Path from %c to %c = %d",'A'+src,'A'+dest,RT[src][dest]);

        printf("Continue ? = ");
        scanf("%d",&choice);
    }

    getch();
    return 0;
}