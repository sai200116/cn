/*dijkstra*/
#include<stdio.h>
#include<limits.h>
#define max 10
int n,adj_mat[max][max];
struct node{
    int predecessor;
    int length;
    enum {permanent,tentative} label;
};
int shortestPath(int source,int des,int path[]){
    int i,j,min,k;
    struct node ele[n];
    for(i=0;i<n;i++){
            ele[i].predecessor=-1;
    ele[i].length=INT_MAX;
    ele[i].label=tentative;
}
ele[source].length=0;
ele[source].label=permanent;
k=source;
do{
        for(i=0;i<n;i++){
            if((adj_mat[k][i]!=0)&&(ele[i].label==tentative)){
                if(adj_mat[k][i]+ele[k].length<ele[i].length){
                    ele[i].predecessor=k;
ele[i].length=ele[k].length+adj_mat[k][i];
}
}
}
k=0;
min=INT_MAX;
for(i=0;i<n;i++){
if(ele[i].label==tentative&&ele[i].length<min){
min=ele[i].length;
k=i;
}
}
ele[k].label=permanent;
}while(k!=des);
i=0;
k=des;
do{
path[i++]=k;
k=ele[k].predecessor;
}while(k>=source);
printf("Distance :%d\n",ele[des].length);
return i;
}
int main(){
    printf("Enter number of nodes..:\n");
    scanf("%d",&n);
    printf("Enter graph in adjacency matrix form..:\n");
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&adj_mat[i][j]);
    }
    }
char source,des;
printf("Enter Source and Destination..:\n");
scanf(" %c %c",&source,&des);
int result=97;
if(source>='A'&&source<='Z'){
        result=65;
}
char ip1[20],ip2[20];
printf("Enter IP Address of source and destination..:\n");
scanf("%s %s",ip1,ip2);
int path[max];
int ans=shortestPath(source-result,des-result,path);
printf("The Shortest Path is..:");
for(int i=ans-1;i>=0;i--){
if(i==0){
printf("%c\n",path[i]+result);
continue;
}
printf("%c-->",path[i]+result);
}
printf("The forwarding tables are..:\n");
printf("Destination Address\t\tOutput Interface\n");
for(int i=ans-1;i>=0;i--){
printf("%s\t\t\t%c\n",ip2,path[i]+result);
}

return 0;
}
