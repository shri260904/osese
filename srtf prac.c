#include<stdio.h>
struct process{
int at,bt,rt,ct,pid;
};

void sortAT(struct process p[],int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(p[j].at>p[j+1].at){
            struct process temp=p[j];
            p[j]=p[j+1];
            p[j+1]=p[j];
        }
    }

}
}

int main(){
struct process p[10];
int i,n,wt[10],tat[10],current=0,complete=0;
printf("enter the no of processes: ");
scanf("%d", &n);
for (i=0;i<n;i++){
        p[i].pid= i+1;
    printf("enter the at for P%d", i+1);
    scanf("%d", &p[i].at);
     printf("enter the bt for P%d", i+1);
    scanf("%d", &p[i].bt);
    p[i].rt=p[i].bt;
}

sortAT(p,n);
//gantt chart
while(complete<n){
    int shortest=-1;
    int min=9999;
    for(i=0;i<n;i++){
        if(p[i].at<=current && p[i].rt<min && p[i].rt>0){
            min=p[i].rt;
            shortest=i;
        }

    }
    if(shortest==-1){
            current++;
        }
        else{
            p[shortest].rt--;
            current++;
            printf("| p%d ", p[shortest].pid);

        }
        if(p[shortest].rt==0){
            complete++;
            p[shortest].ct=current;
        }
 }
 float awt=0,atat=0;

 printf(" \nPid\t at\t bt\t ct\t tat\t wt\t\n");
 for(i=0;i<n;i++){
        tat[i]=p[i].ct-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    printf(" %d\t %d\t %d\t %d\t %d\t %d\t\n", p[i].pid,p[i].at, p[i].bt, p[i].ct, tat[i], wt[i]);
  awt+=wt[i];
  atat+=tat[i];
 }
 printf("awt= %f\natat= %f\n", awt/n,atat/n);
return 0;
}
