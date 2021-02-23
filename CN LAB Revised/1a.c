#include<stdio.h>
#include<string.h>
void convertBinary(int c,char binary[10])//converting to binary
{
 int i;
 for(i=0;i<8;i++)
 {
 binary[i]='0';
 }
 binary[8]='\0';
 i=7;
 while(c)
 {
 binary[i--]=(c%2)+48;
 c=c/2;
 }
 return;
}
int main()
{
 char frames[25][25],bit[100]="",binary[100];
 int i,n,c;
 printf("Enter number of frames..:");
 scanf("%d",&n);
 for(i=0;i<n;)
 {
 printf("Enter %d frame : ",i+1);
 scanf("%s",frames[i]);
 if(strlen(frames[i])%8==0)
 {
 i++;
 }
 else
 {
 continue;
 }
 }
 for(i=0;i<n;i++)
 {
 c=(strlen(frames[i])/8)+1;//counting number of characters
 convertBinary(c,binary);
 strcat(bit,binary) ;//concating binary to res
 strcat(bit,frames[i]);//concating frame to res
 }
 printf("After performing the Character Count the result : %s",bit);//printing tranemitted frame
 return 0;
}
