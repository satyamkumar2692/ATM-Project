#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
void func(int x,int bal,char s[],int ibal,int t,int q,int w,int z,char u[]){
      int a,o,b;
      int c,d,e,f,g;
if(x==1)
      {
      printf("1.Balance Checking\n2.Cash withdrawal\n3.Cash Deposition\n4.Print E-receipt\n5.Exit\n\nPlease proceed with your choice:");
      scanf("%d",&o);

      if(o==1){printf("The account balance in Rs : %d \n",bal,ibal);
             printf("Would you like to have another ATM transaction?(1/0):\n");
             scanf("%d",&a);
             if(a==1){func(1,bal,s,ibal,t,q,w,z,u);}
             else if(a==0){printf("Thanks for using our ATM services\n");
                                  return 0;}}
      else if(o==2){
            printf("Insert the amount to be withdrawal\n");
            printf("Note:Only 100,500 and 2000 notes are available at the moment\n");
            scanf("%d",&b);
            if(b%100==0){printf("You can collect your cash\nYour current balance is %d \n",bal-b);
                  bal=bal-b;t++;
                        printf("Would you like to have another ATM transaction?(1/0):\n");
            scanf("%d",&c);
             if(c==1){func(1,bal,s,ibal,t,q,w,z,u);}
             else if(c==0){printf("Thanks for using our ATM services\n");
                                  return 0;}
            }
            else if (b%100!=0){printf("You are requested to insert the amount in multiples of 100\n");
            printf("Would you like to have another ATM transaction?(1/0):\n");
            scanf("%d",&d);
             if(d==1){func(1,bal,s,ibal,t,q,w,z,u);}
             else if(d==0){printf("Thanks for using our ATM services\n");
                                  return 0;}
                                }
                     }
            else if(o==3){
                  printf("Enter the amount to be deposited\n");
                  scanf("%d",&e);
            bal =bal+e;t++;
            printf("The balance is %d\n",bal);

                  printf("Would you like to have another ATM transaction?(1/0):\n");
            scanf("%d",&f);
             if(f==1){func(1,bal,s,ibal,t,q,w,z,u);}
             else if(f==0){printf("Thanks for using our ATM services\n");
                                  return 0;}
      }
      else if(o==4){printf("\nTime of transaction:");puts(u);
                  printf("Date of transaction:%d/%d/%d\n",q,w,z);
            printf("Card number:");puts(s);
            printf("Initial balance:%d\n",ibal);
            printf("Final balance:%d\n",bal);
            printf("Number of transactions:%d\n",t);
            if(ibal>bal)printf("Net Amount debited:%d\n\n",ibal-bal);
            else if(bal>ibal)printf("Net amount credited:%d\n\n",bal-ibal);
             printf("Would you like to have another ATM transaction?(1/0):\n");
            scanf("%d",&g);
             if(g==1){func(1,bal,s,ibal,t,q,w,z,u);}
             else if(g==0){printf("Thanks for using our ATM services\n");
                                  return 0;}
      }
       else if(o==5){
            printf("Thanks for using our ATM services\n");
                                  return 0;
       }
}
else if(x==0){printf("Wrong password!!\n");}
return ;
}

int main()
{
    int pin=2022;
    int p;
    int bal=2000,t=0;
    printf("Please insert your card or Enter your card number\n");
    int ibal=bal;//initial balance
    char s[17];
    int arr[16];
    int q,w,z,v;
    int AMEX=0,MAST=0,VISA=0;
    time_t currentTime;
    time(&currentTime);
    struct tm *myTime=localtime(&currentTime);
    //printf("%i/%i/%i\n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900);
    q=myTime->tm_mday;
    w=myTime->tm_mon+1;
    z=myTime->tm_year+1900;
    char u[50];

strcpy(u,ctime(&currentTime));

    gets(s);
    int i=0,sum=0,sum1=0;
    while(s[i]!='\0'){
      arr[i]=s[i]-48;
      i++;
    }

  for(int j=i-2;j>=0;j-=2){
      arr[j]=2*arr[j];
      if(arr[j]>9)arr[j]=arr[j]-9;
      sum=sum+arr[j];
  }
     for(int j=i-1;j>=0;j-=2){sum1=sum1+arr[j];}
     if((sum+sum1)%10==0){
            if(i==15 && s[0]==3+48&& ( s[1]==7+48 || s[1]==4+48)){printf("\nWelcome to AMEX ATM services\n\n");AMEX++;}
       else if(i==16 && s[0]==5+48 && ( s[1]==1+48 || s[1]==2+48 ||s[1]==3+48 ||s[1]==4+48 || s[1]==5+48)){printf("\nWelcome to MASTERCARD ATM services \n\n");MAST++;}
       else if((i==13 || i==16) && (s[0]==4+48)){printf("\nWelcome to VISA ATM services \n\n");VISA++;}
     }
     else{ printf("INVALID card number\n");
     return 0;
     }

if(AMEX==1){
printf("Enter CVV\n");
scanf("%d",&v);
if(v>=1000 && v<=9999){printf("CVV verified\n");}
else {printf("Invalid CVV  \n");return 0;}}

if(MAST==1){
printf("Enter CVV\n");
scanf("%d",&v);
if(v>=100 && v<=999){printf("CVV verified\n");}
else {printf("Invalid CVV  \n");return 0;}}

if(VISA==1){
printf("Enter CVV\n");
scanf("%d",&v);
if(v>=100 && v<=999){printf("CVV verified\n");}
else {printf("Invalid CVV  \n");return 0;}}

    printf("Enter your password \n");
    scanf("%d",&p);

    if(p==pin){printf("Password matched successfully!\n\n");
          func(1,bal,s,ibal,t,q,w,z,u);}
      else if(p!=pin){func(0,bal,s,ibal,t,q,w,z,u);}

    return 0;
}
