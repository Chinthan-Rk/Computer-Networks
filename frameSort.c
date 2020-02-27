#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct PACKET{
    int sequenceNumber;
    char message[10];
}PACKET1[10],PACKET2[10],temp;

void sendPackets(int nPack){

for(int i=0;i<nPack;i++)
    PACKET1[i].sequenceNumber = PACKET2[i].sequenceNumber = -1;

printf("Enter the message\n ");
for(int i=0;i<nPack;i++){
    PACKET1[i].sequenceNumber = i;
    printf("Message %d : ",(i+1));
    scanf("%s",PACKET1[i].message);
}

printf("Sending order \n");

int j=0;
while(j<nPack){
    
    int i = rand()%nPack;
    
    if(PACKET2[i].sequenceNumber==-1)
        PACKET2[i]= PACKET1[j++];
    
}
for(int i=0;i<nPack;i++){
printf("Message %d : %s\n",(i+1),PACKET2[i].message);
}

}

void recievePackets(int nPack){

for(int i=0;i<nPack;i++){
    //sorting 
    for(int j=0;j<nPack-i-1;j++){
        if(PACKET2[j].sequenceNumber > PACKET2[j+1].sequenceNumber)
        {
            temp = PACKET2[j];
            PACKET2[j]= PACKET2[j+1];
            PACKET2[j+1] = temp;

        }
    }
}

printf("Recieved Order ");
for(int i=0;i<nPack;i++){
printf("Message %d : %s\n",(i+1),PACKET2[i].message);
}
}

int main(){
    
    printf("Enter the number of packets : ");
    int numOfPackets;
    scanf("%d",&numOfPackets);

    sendPackets(numOfPackets);
    recievePackets(numOfPackets);
    
    getch();
    return 0;
}