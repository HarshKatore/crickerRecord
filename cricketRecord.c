 #include<stdio.h>
#include<string.h>

struct cricketer
{
	int wickets,category,number_of_odis_played,t20,age;
	char name[25];
	char country[50];
	float batting_score;
};

void getdata(struct cricketer player[],int); //get data of a player
void putdata(struct cricketer player[],int); //display all players
void dis_batsman_of_par_country(struct cricketer[],int); //number of batsman of particular country
void dis_bat_high_avg_score(struct cricketer[],int); //batsman with highest batting score
void display_bowler_of_par_country(struct cricketer[],int); //number of bowlers of particular country
void dis_bow_max_wicket(struct cricketer[],int); //bowler with maximum wickets taken
void display_particular_player(struct cricketer[],int); //get particular player's info

int main()
{ 
	int N;
	printf("Enter the no of cricket players\n");
	scanf("%d",&N);
  if(N==0){
    printf("NO RECORD");
  }
	struct cricketer player[100];
	int choice;
	do
	{
		printf("\n==============Menu=============");
		printf("\nEnter 1 to input player: ");
		printf("\nEnter 2 to display all players: ");
		printf("\nEnter 3 to display batsman of a particular country: ");
		printf("\nEnter 4 to display batsman with highest average batting score: ");
		printf("\nEnter 5 to display bowler of a particular country: ");
		printf("\nEnter 6 to display bowler with maximum wicket: ");
		printf("\nEnter 7 to display details of particular player: ");
		printf("\nEnter 8 to exit: ");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
    if(choice>8){
      printf("wrong choice. Enter correct choice:");
    }
		switch(choice)
		{
			case 1:
				getdata(player,N);
			break;
			case 2:
				putdata(player,N);
			break;
			case 3:
				dis_batsman_of_par_country(player,N);
			break;
			case 4:
				dis_bat_high_avg_score(player,N);
			break;
			case 5:
				display_bowler_of_par_country(player,N);
			break;
			case 6:
				dis_bow_max_wicket(player,N);
			break;
			case 7:
				display_particular_player(player,N);
			break;
		}
	}while(choice!=8);
}

void getdata(struct cricketer player[],int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		printf("\nEnter Name of a Player : \n");
		scanf("%s",player[i].name);
		printf("Enter Country to which the player belongs : \n");
		scanf("%s",player[i].country);
		printf("Enter Age of the Player : \n");
		scanf("%d",&player[i].age);
		printf("Enter Batting Score : \n");
		scanf("%f",&player[i].batting_score);
		printf("Enter Wickets taken by a player : \n");
		scanf("%d",&player[i].wickets);
		printf("Enter Category of player 1. for Batsman 2. Bowler 3. wicket keeper 4.all-rounder: \n");
		scanf("%d",&player[i].category);
		printf("Enter number of ODI's played by player : \n");
		scanf("%d",&player[i].number_of_odis_played);
		printf("Enter number of t20's played by player : \n");
		scanf("%d",&player[i].t20);
	}
}

void putdata(struct cricketer player[],int s)
{
	int i;
	printf("\nNAME\tAGE\tCOUNTRY\tBATTING SCORE\tWICKETS\tCATEGORY\tNUMBER OF ODI's PLAYED\tT20 played\n");
	for(i=0;i<s;i++)
	{
			printf("\n Name of a Player :%s \n",player[i].name);
	
		printf(" Country to which the player belongs : %s\n",player[i].country);
		
		printf(" Age of the Player :%d \n",player[i].age);
		
		printf(" Batting Score :%d \n",player[i].batting_score);
	
		printf(" Wickets taken by a player :%d \n",player[i].wickets);
	
		printf("Enter Category of player 1. for Batsman 2. Bowler 3. wicket keeper 4.all-rounder: %d \n",player[i].category);
		
		printf("Enter number of ODI's played by player :%d \n",player[i].number_of_odis_played);
		
		printf("Enter number of t20's played by player : %d \n",player[i].t20);
		
	}
}

void dis_batsman_of_par_country(struct cricketer player[],int s)
{
	int n,i,count=0;
	char c[50];
	printf("Enter country's name: ");
	scanf("%s",c);
		printf("These are the names of batsman belonging to a particular country : %s\n",c);
	for(i=0;i<s;i++)
	{
		n = strcmp(c,player[i].country);
		if(n==0 && player[i].category==1)
		{
			printf("\t%s \n",player[i].name);
			count++;
		}
	}
	
	printf("\nNo of batsman from particular country %s = %d",c,count);
	//printf("These are the names of batsman belonging to a particular country");
}

void dis_bat_high_avg_score(struct cricketer player[],int s)
{
	int i, m=0;
	float max;
	max=player[0].batting_score;
	for(i=0;i<s;i++)
	{
		if(player[i].batting_score > max)
		{
			max=player[i].batting_score;
                        m=i;
		}
		
	}
	printf("\nName of the Player with Highest Score : %s",player[m].name);
}

void display_bowler_of_par_country(struct cricketer player[],int s)
{
	int n,i,count=0;
	char c[50];
	printf("Enter country's name: ");
	scanf("%s",c);
		printf("These are the names of bowler belonging to a particular country : %s\n",c);
	for(i=0;i<s;i++)
	{
		n= strcmp(c,player[i].country);
		if(n==0 && player[i].category==2)
		{
			printf("\t%s \n",player[i].name);
			count++;
		}
		
	}
	printf("\nNo of bowlers from particular country %s = %d",c,count);
	//printf("These are the names of bowler belonging to a particular country : %s",player[i].name);
}

void dis_bow_max_wicket(struct cricketer player[],int s)
{
	int i;
	float max;
	max=player[0].wickets;
	for(i=0;i<s;i++)
	{
		if(player[i].category==2 && player[i].wickets>max)
		{
			max=player[i].wickets;
		}
		printf("The bowler that has taken maximum number of wickets is %s",player[i].name);
	}
	//printf("The bowler that has taken maximum number of wickets is %s",player[i].name);
}

void display_particular_player(struct cricketer player[],int s)
{
	int m,i;
	char n[25];
	printf("Enter name a the player you want information of:");
	scanf("%s",n);
	for(i=0;i<s;i++)
	{
		m= strcmp(n,player[i].name);
		if(m==0)
		{
		printf("\n Name of a Player :%s \n",player[i].name);
	
		printf(" Country to which the player belongs : %s\n",player[i].country);
		
		printf(" Age of the Player :%d \n",player[i].age);
		
		printf(" Batting Score :%d \n",player[i].batting_score);
	
		printf(" Wickets taken by a player :%d \n",player[i].wickets);
	
		printf("Enter Category of player 1. for Batsman 2. Bowler 3. wicket keeper 4.all-rounder: %d \n",player[i].category);
		
		printf("Enter number of ODI's played by player :%d \n",player[i].number_of_odis_played);
		
		printf("Enter number of t20's played by player : %d \n",player[i].t20);
		}
	}
}