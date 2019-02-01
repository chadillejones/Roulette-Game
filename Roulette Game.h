//Roulette babyyy

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>

void showInstructions();
float getBetAmount();
void makeBet(int *choice,int *singleno,int *oddeven,int *triple);
int spinWheel();
float figureWinnings(int singleno,int oddeven,int triple,int slot,float bet,int choice);

int main()
{
	float bet=0,result=0,total=0,stotal=0;
	int choice=39,singleno=50,oddeven=50,triple=50,slot=90, quit=0;
	
	showInstructions();
	do
	{
		bet=getBetAmount();
		makeBet(&choice,&singleno,&oddeven,&triple);
		slot=spinWheel();
		puts("You rolled number..............");
		printf("\n%d\n",slot);
		result=figureWinnings(singleno,oddeven,triple,slot,bet,choice);
		printf("\nYou won $%.2f",result);
		printf("\nYou lost $%.2f",fabs(result-bet));
		total=total+result;
		stotal=stotal+fabs(result-bet);
		puts("\nDo you want to continue. Enter 1 to continue. Enter 2 to end game.");
		scanf("%d",&quit);
	}
	while(quit!=2);
	printf("You total earnings is $%.2f ",total-stotal);
	if(total-stotal<0)
	{
		printf("\nUnfortunately you have a net loss.\nPlease pay $%.2f at the counter near the main entrance.\nHave a nice day",fabs(total-stotal));
	}
	else
	{
		printf("\nFantastic you came out big.\nYou can collect your reward of $%.2f at the counter near the main entrance.\nHave a nice day",total-stotal);
	}
	return 0;
}
void showInstructions()
{
	printf("Welcome to the best Roulette Game this side of town.\nReady to win BIG?");
	printf("\n\nMy name is Chad and I am here to tell you the rules of this game.\nRead carefully!");
	printf("\n\nThere are 36 options to bet on. \nBet on single numbers for a whopping 36 TIMES your bet amount");
	puts("Bet on either odd or even numbers for 2 times your bet amount");
	puts("Bet on the ranges 1-12,13-24 or 25-36 for 3 times your bet amount");
	puts("Please note that the odd even bet and the triple range bet does not include 0 as a winnable number");
	puts("Now lets play!!!");
}
float getBetAmount()
{
	float bet;
	puts("How much money are you placing on your bet.");
	scanf("%f",&bet);
	return bet;
}
void makeBet(int *choice,int *singleno,int *oddeven,int *triple)
{
	puts("\nWhat type of bet are you placing your money on. Select the number that corresponds with the bet type");
	puts("Single number.......................1");
	puts("Odds or Evens.......................2");
	puts("Triple Range........................3");
	scanf("%d",&*choice);
	while(*choice<=0||*choice>=4)
	{
		printf("Please enter a valid bet type from 1-3\n");
		puts("Single number.......................1");
		puts("Odds or Evens.......................2");
		puts("Triple Range........................3");
		scanf("%d",&*choice);
	}
	if(*choice==1)
	{
		puts("You have selected the single number for a chance to win 36 times your bet!");
		puts("Please enter the number of your choosing from 0-36");
		scanf("%d",&*singleno);
		while(*singleno<=-1||*singleno>=37)
		{
			puts("Please enter a valid number between 0-36");
			scanf("%d",&*singleno);
		}
	}
	if(*choice==2)
	{
		puts("You have selected the Odds and Evens for a chance to win 2 times your bet!");
		puts("Please enter the number type you are bettinng on");
		puts("Odds.........1");
		puts("Evens........2");
		scanf("%d",&*oddeven);
		while(*oddeven<=0||*oddeven>=3)
		{
			puts("Please enter a valid number 1 or 2");
			puts("Odds.........1");
			puts("Evens........2");
			scanf("%d",&*oddeven);
		}
	}
	if(*choice==3)
	{
		puts("You have selected the Triple Range for a chance to win 3 times your bet!");
		puts("Please enter the range you are betting on");
		puts("Range 1-12..........1");
		puts("Range 13-24.........2");
		puts("Range 25-36.........3");
		scanf("%d",&*triple);
		while(*triple<=0||*triple>=4)
		{
			puts("Please enter a valid number  from 1, 2 or 3");
			puts("Range 1-12..........1");
			puts("Range 13-24.........2");
			puts("Range 25-36.........3");
		}
	}
}
int spinWheel()
{	
	int slot;
	srand(time(0));
	int num;
	
	slot=num=(rand()%(35))+1;
	return slot;
}
float figureWinnings(int singleno,int oddeven,int triple,int slot,float bet,int choice)
{
	float win=0;
	
	
	if(choice==1)
	{
	if(singleno==slot)
	{
		puts("Congratulations. You have won on the Single Number selection. You are a grand prize winner");
		win=bet*36;
	}
	else
	{
		puts("Drats. Better luck next time");
	}
	}
	else
	{
		
		
	}
	if(choice==2)
	{
	if(oddeven==1)
	{
		if(slot%2!=0&&slot!=0)
		{
			puts("Congratulations. You have won on the Odds or Even selections.");
			win=bet*2;
		}
		else
		{
			puts("Drats. Better luck next time");
		}
	}
	else
	{
		if(slot%2==0&&slot!=0)
		{
			puts("Congratulations. You have won on the Odds or Even selections.");
			win=bet*2;
		}
		else
		{
			puts("Drats. Better luck next time");
		}	
	}
	}
	else
	{
	}
	
	
	if(choice==3)
	{
	if(triple==1)
	{
		if(slot<=0||slot>=13)
		{
			puts("Drats. Better luck next time");
		}
		else
		{
			puts("Congratulations. You have won on the Triple selection.");
			win=bet*3;
		}
	}
	if(triple==2)
	{
		if(slot<=12||slot>=25)
		{
			puts("Drats. Better luck next time");
		}
		else
		{
			puts("Congratulations. You have won on the Triple selection.");
			win=bet*3;
		}
	}
	if(triple==3)
	{
		if(slot<=24||slot>=37)
		{
			puts("Drats. Better luck next time");
		}
		else
		{
			puts("Congratulations. You have won on the Triple selection.");
			win=bet*3;
		}
	}
	}
	else 
	{
	}
	return win;
}

