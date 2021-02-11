/*character stuffing*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,length,j,k,test=0,l,flag=0;
    printf("Enter Number Of Frames...:\n");
    scanf("%d",&n);
    char frames[25][25],buffer[10]="",dle[10],stx[10],etx[10],res[300]="";
    printf("Enter Number Of Frames...:\n");
    for(i=0;i<n;)
    {
        scanf("%s",frames[i]);
        if((strlen(frames[i])%8)!=0)
        {
            printf("Re-enter frames...:\n");
            continue;
        }
        i++;
    }
    do
    {
        printf("Enter dle...:\n");
        scanf("%s",dle);
        printf("Enter stx..:\n");
        scanf("%s",stx);
        printf("Enter etx..:\n");
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
            if(strcmp(buffer,dle)==0)
            {
                strcat(res,dle);
                strcat(res,buffer);
            }
            else
            {
                strcat(res,buffer);
            }
            strcpy(buffer,"");
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
