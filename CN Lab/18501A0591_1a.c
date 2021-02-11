/*character count*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    printf("Enter Number of frames..:\n");
    scanf("%d",&n);
    char frames[25][25],binary[10][10]={"","00000001","00000010","00000011","00000100","00000101","00000110","00000111"},bit[100]="";
    int i,c;
    printf("Enter Frames..:\n");
    for(i=0;i<n;)
    {
        scanf("%s",frames[i]);
        if(strlen(frames[i])%8==0)
        {
            i++;
        }
        else
        {
            printf("Re-enter frame..:\n");
        }
    }
    for(i=0;i<n;i++)
    {
        c=(strlen(frames[i])/8)+1;
        strcat(bit,binary[c]);
        strcat(bit,frames[i]);
    }
    printf("Result...:\n%s",bit);
    return 0;
}
