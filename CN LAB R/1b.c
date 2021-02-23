#include<stdio.h>
#include<string.h>
int main()
{
 int n,i,length,j,k,test=0,l,flag=0;
 printf("Enter Number Of Frames...:\n");
 scanf("%d",&n);
 char frames[25][25],buffer[10]="",dle[10],stx[10],etx[10],res[300]="";
 for(i=0;i<n;)
 {
 printf("Enter %d Frame : ",i+1);
 scanf("%s",frames[i]);
 if((strlen(frames[i])%8)!=0)//frame length should be multiple of 8
 {
 printf("Re-enter frames...:");
 continue;
 }
 i++;
 }
 do
 {
 printf("Enter dle...:");
 scanf("%s",dle);
 printf("Enter stx..:");
 scanf("%s",stx);
 printf("Enter etx..:");
 scanf("%s",etx);
 if(strlen(dle)==8&&strlen(stx)==8&&strlen(etx)==8)
 {
 flag=1;
 }
 }while(flag==0);
 for(i=0;i<n;i++)
 {
 test=0;
 l=0;
 strcat(res,dle);
 strcat(res,stx);
 length=strlen(frames[i])/8;
 for(j=0;j<length;j++)
 {
 for(k=test;k<=test+7;k++)
 {
 buffer[l++]=frames[i][k];
 }
 if(strcmp(buffer,dle)==0)//if flag appears in pattern
 {
 strcat(res,dle);//concat dle
 strcat(res,buffer);//concat buffer
 }
 else
 {
 strcat(res,buffer);//concat buffer
 }
 strcpy(buffer,"");//initializing buffer
 test+=8;
 l=00;
 }
 strcat(res,dle);
 strcat(res,etx);
 }
 printf("After Character Stuffing..:\n");
 printf("%s",res);
 return 0;
}
