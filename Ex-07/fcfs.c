#include<stdio.h>
#include<string.h>
 
int main(){
	int n,i;
	printf("How many processes?:");
	scanf("%d",&n);
	char name[n][20];
	int btime[n];
	for(int i=0;i<n;i++){
		printf("Enter Name:");
		scanf("%s",name[i]);

		printf("Enter Burst Time:");
		scanf("%d",&btime[i]);
	}
/*
	int ct[n],cta=0;
	for(int i=0;i<n;i++){
		cta+=btime[i];
		ct[i]=cta;
	}*/
	int tat[n],temp=0;
	for(int i=0;i<n;i++){
		tat[i]=temp+btime[i];
		temp=tat[i];
	}

	int bt=0;
	int bta=0;
	printf("process\t waiting time\t turn around time\n");
	for(int i=0;i<n;i++){
		printf("%s\t\t %d\t\t %d\n",name[i],bt,tat[i]);
		bt+=btime[i];
		bta+=bt;
	}
	printf("The average waiting time: %d\n", bta/n);
}
