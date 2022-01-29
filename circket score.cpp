#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int GetPlayerToss(char player1[],char player2[],int oversToplay);
int batting(char battingplayer[],char bowlerplayer[],int oversToplay);
int main()
{
 int i,j,overs,noovers,player1Toss,player2Toss;
 char player1[50],player2[50];
 srand(time(NULL));
 printf("------------------------------WELCOME TO CRICKET GAME----------------------------\n");
 printf("Enter Player 1 Name:");
 fflush(stdin);
 gets(player1);
 printf("Enter Player 2 Name:");
 fflush(stdin);
 gets(player2);
 printf("Enter\n1 - Fixed Overs\n2 - play Until Out\n3 -How to Play?\n4 - exit: ");
 scanf("%d",&noovers);
   do{
  if(noovers==1)
  {
   printf("Enter No Of Overs: ");
   scanf("%d",&overs);
   player1Toss=GetPlayerToss(player1,player2,overs);
   
  }
  else if(noovers==2)
  {
   player1Toss=GetPlayerToss(player1,player2,0); 
  }
  else if(noovers==3)
  {
   printf("How To Play?\n");
   printf("Until a player Won the toss Follow the Output and give Whatever it asks you to give\n");
   printf("Then the player who won the toss choose either to Bat or to Bowl\n");
   printf("The player who won chose battting andbowling has to proceed by pressing enter key one by one\n");
   printf("Where System will generate Random number as runs for both players.player 1runs keeps on adding until his runs equals to player 2 runs\n");
   printf("Finally When Player 1 is Out.Till then his runs are his final score.The Same Process will be Conducted for player 2.\n");
   printf("Finally whoever is having Hightest Score is the Winner .\n\n");
   printf("For Example: Player 1Won the Toss And Chose Batting.Then When Player 1Press Enter Key,A score will be generated for player 1\n");
   printf("Suppose runs are 5 So Player 1 Score=5.Then Player 2 Also Presses Enter Key .Thenif he got a score will be generated for player 1\n ");
   printf("As Player 1 Score is not equal to player 2 score Then player 1 is not out and hi score will be 5 after 1st ball \n");
   printf("In 2nd ball player 1 got 3 runs and player 2 got 4.since again both are not equal.player 1 score=5+3=8\n");
   printf("If in the 3rd Ball player 2 also got 4 runs Then player 1  score is equal to player 2's Score Then player 1 is Out\n");
   printf("Then Final Score of player 1 is 8 runs.\n");
   printf("The Same Process is done for player 2.so Finaly who got more score is winner\n");
   printf("The Same process is done for 2.so Finaly who ever got more score is winner\n");
   }
   else
   {
   printf("--------------------------------------------Invalid Choice------------------------------------------\n");
   }
   	printf("Enter 1 - Fixed Overs\n2 -play Until Out\n3 - How to play?\n4 - Exist: ");
   	scanf("%d",&noovers);
     }while(noovers>=1 && noovers<=3);
    return(0);
    }
    
    int GetPlayerToss(char player1[],char player2[],int oversToplay)
    {
     int player1Choice,player2Choice,toss,player1Toss,batorbowlChoice,player2score,player1score;
         printf("%s Choose your choice either 1 for head or 2 for tail: ",player1);
     scanf("%d",&player1Choice);
     if(player1Choice==1)
    {
	 player2Choice=2;
	 printf("%s Choice is Tail\n",player2); 
	}
	else if(player1Choice==2)
	{
	  player2Choice=1;
	  printf("%s Choice is Head\n",player2);
	}
	else
	{
	 printf("----------------------------------------Invalid Chioce-------------------------------------------------\n");
	 return(0);
	}
	toss=rand()%2;
	toss=toss+1;
	if(toss==1)
	printf("Toss is Head\n");
	else
	printf("Toss is Tail\n");
	if(toss==player1Choice)
	{
	 player1Toss=1;
	 printf("player 1 %s Won the Toss\n",player1);
	 printf("Choose\n1 - Batting\n2 - Bowl: ");
	 scanf("%d",&batorbowlChoice);
	 if(batorbowlChoice==1)
	   {
	 	   printf("--------------%s is Going to bat Now------------------\n",player1);
	    player1score=batting(player1,player2,oversToplay);
	    printf("-----------------%s is Going to bat Now-------------------\n",player2);
	    player2score=batting(player2,player1,oversToplay);
	    printf("----------------Its Time for Results---------------------\n");
	   }
	   else
       {
	   printf("-----------------%s is Going to bat Now---------------------\n",player2);
	   player2score=batting(player2,player1,oversToplay);
	   printf("------------------%s is Going to bat Now---------------------\n",player1);
	   player1score=batting(player1,player2,oversToplay);
	   printf("------------------Its Time for Results----------------------\n");
	   } 
	}
    else if(toss==player2Choice)
   {
	player1Toss=2;
	printf("player2 %s Won the Toss\n",player2);
	printf("Choose\n1 - Batting\n2 - Bowl: ");
	scanf("%d",&batorbowlChoice);
	if(batorbowlChoice==1) 
	{
	 printf("------------------%s is Going to bat Now-----------------------\n",player2);
	 player2score=batting(player2,player1,oversToplay);
	 printf("------------------%s is Going to bat Now------------------------\n",player1);
	 player1score=batting(player1,player2,oversToplay);
	 printf("-------------------Its Time for Results-------------------------\n");
	}
   else
   {
   	printf("--------------------%s is Going to bat Now-------------------------\n",player1);
   	player1score=batting(player1,player2,oversToplay);
   	printf("--------------------%s is Going to bat Now--------------------------\n",player2);
   	player2score=batting(player2,player1,oversToplay);
   	printf("--------------------Its Time for Results----------------------------\n");
   }
  } 
   else
   {
   	printf("--------------------------------------Error----------------------------------------------\n");
   	return(0);
   }
   if(player1score==player2score)
   {
   	printf("Draw Match\nThanks For player the Game\n");
   }
   if(player1score>player2score)
   printf("%s Won the Match\nThanks For Playing the Game\n",player1);
   if(player1score<player2score)
   printf("%s Won the Match\nThanks For Playing the Game\n",player2);
   return (player1Toss);
  }
  
  int batting(char battingplayer[],char bowlingplayer[],int oversToplay)
  {
  	int i,j,battingScore,sum=0,bowlerScore,flag=1;
  	char c;
  	if(oversToplay>0)
  	{
      for(i=1;i<=oversToplay;i++)
      {
       for(j=1;j<=6;j++)
       {
       	printf("%d.%d ball\n",i,j);
       	printf("%s Press Enter to bowl :",bowlingplayer);
		fflush(stdin);
		scanf("%c",&c);
		fflush(stdin);
		bowlerscore=(int)rand()%7;//Generate from 0-6 where 0 means no ball
		printf("%s Press Enter Key to bat :",battingplayer);
		fflush(stdin);
		scanf("%c",&c);
		fflush(stdin);
		battingScore=rand()%7;//Generate 0-6 runs
		if(battingScore==bowlerScore) 
		{
		 flag=0;
		 printf("---------------------%s is Out-------------------\n",battingplayer);
		 printf("%s Total Score=%d\n",battingplayer,sum);
		 if(sum==0)
		        printf("----------------Hence Duck Out-------------------\n");
		break;
		}
		else
		{
		 printf("Got %d runs\n",battingScore);
		                if(battingScore==6)
		                printf("Sixerrrrrr Keep it up\n");
		                if(battingScore==4)
		            printf("Its aaFour Great Man\n");
		sum=sum+battingScore;
		printf("%s Score=%d\n",battingplayer,sum);
		}
	  } 
	  if(flag==0)
	  break;
	  }
	  
	  return(sum);
	  }
	    if(oversToplay==0)
	    {
	       while(flag)
	       {
	       	printf("%s Press Enter Key to bowl :",bowlingplayer);
	    fflush(stdin);
	    scanf("%c",&c);
	    fflush(stdin);
	    bowlerScore=(int)rand()%7;//Generate from 0-6 where 0 means no ball
	    printf("%c",&c);
	    fflush(stdin);
	    battingScore=rand()%7;//Generate 0-6 runs
	    if(battingScore==bowlerScore)
	    {
	     flag=0;
		 printf("-------------------%s is Out-------------------\n",battingplayer);
		 printf("%s Total Score=%d\n",battingplayer,sum);
		 if(sum==0)
		 printf("-------------Hehehe Duck Out--------------------\n");
		 break;
		}
		else
		{
		 printf("Got %d runs\n",battingScore);
		          if(battingScore==6)
				  printf("Sixerrrrrr Keep it Up\n");
			printf("Its a Four Great Man\n");
		sum+=battingScore;
		printf("%s Score=%d\n",battingplayer,sum);
	    }
		   }
		   return(sum);
		}
  }
