/*bit stuffing*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,c=0,j,k=0;
    printf("Enter Number Of Frames..:\n");
    scanf("%d",&n);
    char frames[25][25],bit[100]="",delimeter[10]="01111110";
    printf("Enter Frames..:\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",frames[i]);
    }
    for(i=0;i<n;i++)
    {
        c=0;
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
                if(c==5)
                {
                    bit[k++]='0';
                    c=0;
                }
            }
        }
    }
    strcat(bit,delimeter);
    printf("After Bit Stuffing ..:\n");
    printf("%s",bit);
    return 0;
}
