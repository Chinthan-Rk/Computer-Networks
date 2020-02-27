#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define BUCKETSIZE 1000
#define OUTRATE 200

struct PACKET{
    int arrivalTime;
    int weight;
}packets[10];

void readPackets(int n){

for(int i=0;i<n;i++){
    //printf("\nEnter the arrival time : ");
    //scanf("%d",&packets[i].arrivalTime);
    packets[i].arrivalTime = i;
    printf("\nEnter the weight : ");
    scanf("%d",&packets[i].weight);
}
}


void leakyBucket(int n){

int i,j=0,excess = BUCKETSIZE,totalPacketSizeInBucket=0;
int packetLoss =0;

for( i=0;i<30;i++){

if(packets[j].arrivalTime == i){
    if(packets[j].weight<=excess){
        
        excess -= packets[j].weight;
        totalPacketSizeInBucket+=packets[j].weight;

        printf("INSERTED :>> Time = %d :: Packet = %d\n",i+1,(j+1));
        printf("Bucket Size = %d\n\n",excess);
        j++;
    }
    else
    {
        printf("\nDISCARDED :>> Time = %d :: Packet = %d\n\n",i+1,j+1);
        packetLoss ++;
        j++;
    }    
}

if((i%5) == 0){
    
    if(totalPacketSizeInBucket >=OUTRATE){
        totalPacketSizeInBucket-= OUTRATE;
        excess += OUTRATE;
        printf("TRANSFERRED :>> Time = %d Size = 25Kb\n",i+1);
        printf("Bucket Size = %d\n\n",excess);
    }
    else if(totalPacketSizeInBucket < OUTRATE)
    {
        excess += totalPacketSizeInBucket;
        totalPacketSizeInBucket =0;
        printf("TRANSFERRED :>> Time = %d Size = 25Kb\n",i+1);
        printf("Bucket Size = %d\n\n",excess);
    }    
}
}

while(totalPacketSizeInBucket!=0){
    if(totalPacketSizeInBucket < OUTRATE){
        excess += totalPacketSizeInBucket;
        printf("TRANSFERRED :>> Time = %d Size = 25Kb\n",i++);
        printf("Bucket Size = %d\n\n",excess);
    }
    else{
        totalPacketSizeInBucket-= OUTRATE;
        excess += OUTRATE;
        printf("TRANSFERRED :>> Time = %d Size = 25Kb\n",i++);
        printf("Bucket Size = %d\n\n",excess);
    }
}

printf("\nBUCKET IS EMPTY !!");
printf("\nPACKET LOSS = %d",packetLoss);
}

int main()
{

printf("Enter the number of packets : ");
int nPack;
scanf("%d",&nPack);

readPackets(nPack);
leakyBucket(nPack);
    getch();
    return 0;
}