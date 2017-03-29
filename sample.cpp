#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
void norepran(int ran[],int run)
{


    int flag=0,c[10],i=0,j=0,s=0;
	   c[0] = ran[0];
 for ( i=1 ; i < run ; i++ )
 {
    flag=0;
	 for ( j=0 ; j < i ; j++ )
	   {
	     if (ran[j]==ran[i])
		{  flag=1;   break;  }
	    }
  if (flag==0)  c[s++]=ran[i];
  if(s==(run/2))       break;
}
for(i=0;i<(run/2);i++)
       ran[i]=c[i];
}
void random(int ran[],int n,int run)
{
    int i=0;

    for(i=0;i<run;i++)
	ran[i]=rand()%n;
	if((n==30)||(n==19)||(n==16))
	norepran(ran,run);


}
int choose(int n)
{
int q=0;
q=rand()%n;
return(q);
}
void fread(char ques11[][80],char ques12[][80],char ques21[][80],char ques22[][80],char ques23[][80],char fname[])
{
 FILE *fh;
 char fques[80],ch;
 int len=0,i=0,j=0,k=0,l=0,flag=0,m=0,n=0,o=0,b=0,de=0;
 fh=fopen(fname,"r");
 if(fh==NULL)
   printf("File can't open ");
 else
 {
   while(fgets(fques,79,fh)!=NULL)
   {
    len=strlen(fques);
    l=0,flag=0,b=0;

    for(i=0;i<(len-1);i++)

   {
       de=toascii(fques[i]);
       de-=3;
       ch=(char)de;


        if(ch=='_')
           l++;



    }
    for(i=0;i<len;i++)
    {

       de=toascii(fques[i]);
       de-=3;
       ch=(char)de;

     if(ch=='_')
     {
         if((l==2)&&(flag==0))
          { ques11[j++][b]='\0';  }
        else if((l==2)&&(flag==1))
          { ques12[k++][b]='\0';}
        else if((l==3)&&(flag==0))
            { ques21[m++][b]='\0'; }
        else if((l==3)&&(flag==1))
            { ques22[n++][b]='\0'; }
        else if((l==3)&&(flag==2))
            { ques23[o++][b]='\0'; }
            b=0;
     flag++;

     }

else
     {

    if(l==2)
       if(flag==0)
        { ques11[j][b++]=ch; }
       else
         {ques12[k][b++]=ch;}
     else if(l==3)
        if(flag==0)
         {ques21[m][b++]=ch;}
       else if(flag==1)
         {ques22[n][b++]=ch;}
       else if(flag==2)
         {ques23[o][b++]=ch;}
    }
}

   }
 }
 fclose(fh);

}
void check1(char dques[][80],char dans[][80],int ran[],int i,int &crct)
{
char gans[50];
printf("\t\t\t\t %s\n\n\t\t\t Answer: ",dques[ran[i]]);
gets(gans);
if(stricmp(dans[ran[i]],gans)==0)
   { printf("\n\nYOUR ANSWER IS: Correct"); crct++;}
else
  { printf("\n\nYOUR ANSWER IS: Wrong\n\n");   printf("CORRECT ANSWER IS: %s",dans[ran[i]]);
   }
}
void check2(char dques[][80],char dans1[][80],char dans2[][80],int ran[],int i,int &crct)
{
char gans[50];
printf("\t\t\t\t %s\n\n\t\t\t Answer: ",dques[ran[i]]);
gets(gans);
if((stricmp(dans1[ran[i]],gans)==0)||(stricmp(dans2[ran[i]],gans)==0))
{ printf("\n\nYOUR ANSWER IS: Correct"); crct++;}
else
{printf("\n\nYOUR ANSWER IS: Wrong\n\n"); printf("CORRECT ANSWER IS: %s (or) %s",dans1[ran[i]],dans2[ran[i]]); }


}
void level(int ranq[],char l11[][80],char l12[][80],char l21[][80],char l22[][80],char l23[][80],int ran[],int i,int &crct)
{
int qtype=0;
      if(ranq[i]==0)
       {
	qtype=choose(2);
	 if(qtype==0)
	     check1(l11,l12,ran,i,crct);
	 else
	     check1(l12,l11,ran,i,crct);
	}
	else if(ranq[i]==1)
	 {
	    qtype=choose(3);
	    if(qtype==0)
		check2(l21,l22,l23,ran,i,crct);
	    else if(qtype==1)
		check2(l22,l23,l21,ran,i,crct);
	    else
		check2(l23,l21,l22,ran,i,crct);
	 }
}
int main()
{
 time_t t;
 srand((unsigned) time(&t));
  int ran[40],i=0,ranq[20],lvl=0,crct=0;
    char l[6][100][80]; char zz ;
    char fname[4][30]={"easy.mvb","medium.mvb","hard.mvb"};



 random(ranq,2,10);

  printf("-------------------------------  ANAGRAM  ------------------------------------\n\n\n");
    printf("1.Easy\n2.Medium\n3.Hard\n");
    printf("Choose: ");
    scanf("%d",&lvl);

    system("cls");

    if(lvl==1)
       {  fread(l[0],l[1],l[2],l[3],l[4],fname[0]);
             random(ran,30,20);}
      else if(lvl==2)
       {  fread(l[0],l[1],l[2],l[3],l[4],fname[1]);
            random(ran,19,20);	}
       else if(lvl==3)
       {  fread(l[0],l[1],l[2],l[3],l[4],fname[2]);
        random(ran,16,20);}

      else  {printf("Invalid"); goto exit;}



    fflush(stdin);
    for(i=0;i<10;i++)
    {
    printf("-------------------------------  ANAGRAM  ------------------------------------\n\n\n");

      if(lvl==1)
       { printf("                                  EASY                                        \n\n\n");   printf("\t\t\t\t\t\t\t\tAnswered\n\n\t\t\t\t\t\t\t\t (%d / %d)\n",crct,i);	level(ranq,l[0],l[1],l[2],l[3],l[4],ran,i,crct);  }
      else if(lvl==2)
       { printf("                                  MEDIUM                                        \n\n\n"); printf("\t\t\t\t\t\t\t\tAnswered\n\n\t\t\t\t\t\t\t\t (%d / %d)\n",crct,i);	level(ranq,l[0],l[1],l[2],l[3],l[4],ran,i,crct);  }
       else if(lvl==3)
       { printf("                                  HARD                                        \n\n\n");   printf("\t\t\t\t\t\t\t\tAnswered\n\n\t\t\t\t\t\t\t\t (%d / %d)\n",crct,i); level(ranq,l[0],l[1],l[2],l[3],l[4],ran,i,crct);  }

      else  {printf("Invalid"); break;}
      scanf("%c",&zz);
      system("cls");
	  }
	  printf("-------------------------------  ANAGRAM   ------------------------------------\n\n\n");
	  printf("                           GAME   CREATED   BY                                 \n\n");
	  printf("                             VIGHNESHBALAJI M                                 \n\n\n");
	  printf("\t\t\t\t\t\t\t\tAnswered\n\n\t\t\t\t\t\t\t\t(%d / %d) \n",crct,i);
	  printf("                                Thank You                                          \n\n\n");
      printf("Please Sent Reviews And Comments To Vighneshbalaji@gmail.com\n");
	  scanf("%c",&zz);
      system("cls");

   exit:
return 0;
}
