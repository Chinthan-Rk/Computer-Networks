#include<conio.h>
#include<stdio.h>
#include<math.h>
#define MAX 50

int data[MAX],hammingSequence[MAX];

int parityBitCount(int n)
{
    int r=0;
    while(pow(2,r)<(n+r+1))
    r++;

    return r;
}

void generateHammingSequence(int pCount,int noOfDataBits)
{
    int i = 0,k=0;
   for(int j=1;j<=pCount+noOfDataBits;j++)
   {
       if(j == pow(2,k))
       {
           hammingSequence[j] = 0;
           k++;

       }
       else
       {
           hammingSequence[j] = data[i++];
       }
   }
}

int setParityBits(int pCount,int noOfDataBits)
{
    int parityBit=1,errorSum=0;

    while(parityBit < pow(2,pCount))
    {
        int i = parityBit;
        int oneCount =0;

        while(i <= pCount+noOfDataBits)
        {
            for(int j=0;j<parityBit;j++)
            {
                if(hammingSequence[i+j] == 1)
                    oneCount++;
            }
            i += 2*parityBit;

            if(oneCount%2 == 0)
            {
                hammingSequence[parityBit] = 0;
            }
            else
            {
                hammingSequence[parityBit]=1;
                errorSum += parityBit;
            }

        }
            parityBit = parityBit *2;

    }
    return errorSum;
}

int checkError(int ePos,int pCount)
{
    for(int i=1;i<pow(2,pCount);i = i*2)
    {
        if(ePos == i)
        return 1;
    }
    return 0;
}

int main()
{

    int noOfDataBits;
    printf("Enter the number of databits");
    scanf("%d",&noOfDataBits);

    printf("Enter the data : ");
    for(int i=1;i<=noOfDataBits;i++)
    {
        scanf("%d",&data[i]);
    }

    int pCount = parityBitCount(noOfDataBits);

    generateHammingSequence(pCount,noOfDataBits);
    setParityBits(pCount,noOfDataBits);

    printf("Hamming code for the data : ");

    for(int i=1;i<=noOfDataBits+pCount;i++)
    printf("%d  ",hammingSequence[i]);

    printf("Enter the data recieved : ");
    for(int i=1;i<=noOfDataBits+pCount;i++)
    {
        scanf("%d",&hammingSequence[i]);
    }

    int errorPosition = 0;
    errorPosition = setParityBits(pCount,noOfDataBits);

    if(errorPosition != 0)
    {
        if(checkError(errorPosition,pCount))
        {
            printf("Only parity bit is corrupted , data is correct");
        }
        else
        {
            printf("Data is corrupted at %d",errorPosition);
            hammingSequence[errorPosition] = !(hammingSequence[errorPosition]);
            printf("Corrected 1 bit, new sequence = ");
            for(int i=1;i<=pCount+noOfDataBits;i++)
            printf("%d ",hammingSequence[i]);
        }

    }
    else
    {
        printf("There is no error in the recieved data ");
    }

    getch();
    return 0;
}
