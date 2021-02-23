#include<stdio.h>
#include<string.h>
int main()
{
 int n,i,c=0,j,k=0;
 printf("Enter Number Of Frames..:");
 scanf("%d",&n);
 char frames[25][25],bit[100]="",delimeter[10]="01111110";
 for(i=0;i<n;i++)
 {
 printf("Enter %d frame : ",i+1);
 scanf("%s",frames[i]);
 }
 for(i=0;i<n;i++)
 {
 c=0;//count of consecutive 1’s
 strcat(bit,delimeter);
 k=strlen(bit);
 for(j=0;j<strlen(frames[i]);j++)
 {
 if(frames[i][j]=='0')
 {
 c=0;
 bit[k++]='0';
 }
 else
 {
 if(frames[i][j]=='1')
 {
 bit[k++]='1';
 c++;
 }
 if(c==5)//if consecutive 1’s count is 5 then stuff a zero
 {
 bit[k++]='0';
 c=0;
 }
 }
 }
 }
 strcat(bit,delimeter);
 printf("After Bit Stuffing ..:");
 printf("%s",bit);
 return 0;
}
