/*crc*/
#include<stdio.h>
#include<string.h>
void Cyclic_Redundancy_Check(char [],char []);
void delete_element(char [],int);
int main()
{
    char dateword[100],polynomial[20]="";
    int choice,flag=0;
    printf("Enter Dateword..:\n");
    scanf("%s",dateword);
    printf("Enter your choice...:\n");
    printf("1 : CRC12\n");
    printf("2 : CRC16\n");
    printf("3 : CRC CCITT\n");
    printf("4 : user choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : strcpy(polynomial,"1100000001111");
                 break;
        case 2 : strcpy(polynomial,"11000000000000101");
                 break;
        case 3 : strcpy(polynomial,"10001000000100001");
                 break;
        case 4 : printf("Enter Polynomial..:\n");
                 while(flag==0)
                 {
                    scanf("%s",polynomial);
                        if(polynomial[0]=='1'&&polynomial[strlen(polynomial)-1]=='1')
                        {
                            break;
                        }
                    printf("Re-enter Ploynomial..:\n");
                    flag=0;
                }
                break;
    }
    Cyclic_Redundancy_Check(dateword,polynomial);
    return 0;
}
void Cyclic_Redundancy_Check(char dateword[],char polynomial[])
{
    int length1,length2,i,j,operand1,operand2,result,k,t=0;
    char temp1[20],temp2[200];
    length1=strlen(polynomial);
    strcpy(temp2,dateword);
    length2=strlen(dateword);
    for(i=0,j=length2;i<length1-1;i++)
    {
        temp2[j++]='0';
    }
    temp2[j]='\0';
    for(i=0;i<length1;i++)
    {
        temp1[i]=temp2[i];
    }
    temp1[i]='\0';
    for(i=strlen(temp1);i<=strlen(temp2);i++)
    {
        if(temp1[0]=='1')
        {
            for(j=0;j<strlen(temp1);j++)
            {
                operand1=temp1[j]-48;
                operand2=polynomial[j]-48;
                result=operand1^operand2;
                temp1[j]=result+48;
            }
        }
        else
        {
            operand2=0;
            for(j=0;j<strlen(temp1);j++)
            {
                operand1=temp1[j]-48;
                result=operand1^operand2;
                temp1[j]=result+48;
            }
        }
        k=strlen(temp1);
        temp1[k++]=temp2[i];
        temp1[k]='\0';
        delete_element(temp1,0);
    }
    printf("Remainder..:%s\n",temp1);
    strcat(dateword,temp1);
    printf("Transmitted Bit..:%s\n",dateword);
    return;
}
void delete_element(char str[],int index)
{
    int i;
    for(i=index;i<strlen(str);i++)
    {
        str[i]=str[i+1];
    }
    str[i]='\0';
    return;
}
