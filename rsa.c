#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char text[20],dtext[20];
int p,q,n,phi,e,d,val[20];

int expo(int a,int b,int c)
{
    if(a==0)
    return 0;

    if(b==0)
    return 1;

    long y;
    if(b%2 == 0)
    {
        y=expo(a,b/2,c);
        y = (y*y) %c ;
    }
    else
    {
        y = a%c;
        y = (y*expo(a,b-1,c)%c)%c;
    }
    
    return (int) ((y+y)%c);

}

int encode(char ch)
{
    int temp;
     temp =expo(ch,e,n);
    return temp;
}

int decode(int ch)
{
    int temp =1;
     temp =expo(ch,d,n);
    return temp;
}


int prime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        return 0;
    }
    return 1;
}

int gcd(int a ,int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b= a%b;
        a=temp;
    }
    return a;
}



int main()
{
    printf("enter the string  : ");
    scanf("%s",text);

    do{
        p=rand()%100;
    }while(!prime(p));

    do{
        q=rand()%100;
    }while(!prime(q));

    n=p*q;
    phi = (p-1)*(q-1);

    do{
        e= rand()%phi;
    }while(gcd(e,phi) != 1);

    do{
        d=rand()%phi;
    }while((e*d)%phi != 1);

    int i;
    for( i=0;text[i]!='\0';i++)
        val[i] = encode(text[i]);
    
    val[i]=-999;

    printf("Encoded message : ");
    for(i=0;val[i]!= -999;i++)
    printf("%d  ",val[i]);

    //decode

    for(i=0;val[i] != -999;i++)
    {
       dtext[i] = decode(val[i]);
    }
    dtext[i]='\0';
    printf("The decoded value : %s" , dtext);





    getch();
    return 0;
}