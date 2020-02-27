#include<stdio.h>
#include<conio.h>
#define MAX 100

int noOfBits=0,data[MAX];
int registers[16];

void senderReadInput(){

    printf("Enter the number of bits in INPUT string : ");
    scanf("%d",&noOfBits);
    printf("Enter the INPUT string : ");
    
    for(int i=0;i<noOfBits+16;i++)
    {
            if(i >= noOfBits){
                data[i] = 0;
            }
            else
            {
            scanf("%d",&data[i]);
            }           
    }

}

void computeCRC()
{
int feedbackBit;


for(int i=0;i<noOfBits+16;i++){

feedbackBit = registers[15];

for(int j=15;j>0;j--)
registers[j] = registers[j-1];

registers[0] = data[i];

if(feedbackBit == 1)
{
    registers[12] = registers[12] ^ feedbackBit;
    registers[5] = registers[5] ^ feedbackBit;
    registers[0] = registers[0] ^ feedbackBit;
}

}



}

void recieverReadInput(){
    printf("Enter the number of bits : ");
    scanf("%d",&noOfBits);

    //printf("Enter the recieved message string : ");
    for(int i=0;i<noOfBits;i++)
    scanf("%d",&data[i]);

    
}

int checkError(){

    if(registers[12] == 0 && registers[0]==0 && registers[5]==0)
    return 0;
    
    return 1;
    
    
}

int main()
{
    
    senderReadInput(); //done

    //initialize the registers

    for(int i=0;i<16;i++)
    registers[i]=0;

    computeCRC();//done

for(int i=noOfBits,j=15;i<noOfBits+16;i++,j--) //adding remainder to dividend
    data[i] = registers[j];


for(int i=0;i<noOfBits+16;i++) //printing crc computed data string
printf("%d",data[i]);
    
    for(int i=0;i<16;i++) // reinit reg to 0
    registers[i]=0;

    recieverReadInput();

    computeCRC();

    if(!checkError())
    printf("NO ERROR");
    else
    {
        printf("ERROR");
    }
    



    getch();
    return 0;

}