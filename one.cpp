#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void shuffel(char cards[60][6])
{
	
	for (int i = 60-1;i > 0;i--)
	{
		int j = rand() % (i + 1);
		char temp[6];
		strcpy(temp, cards[i]);
		strcpy(cards[i], cards [j] );
		strcpy(cards[j], temp);
	}
}
void player_move(char player[4][6],char cards[60][6], char ground_card[2][6])
{
	printf("\n %s\n",ground_card[1]);
	printf(" do you want this card ??? if yes enter 1,if no 0, if basra 2\n");
	int num1;
	scanf("%d", &num1);
	

	if (num1 == 1 && strcmp(ground_card[1], " "))     //will enter  if ground_card[1]!=" "
	{
		printf("choose the card that you want to chang\n");
		int num2;
		scanf("%d", &num2);
		char temp[6];
		

		strcpy(temp, ground_card[1]);
		strcpy(ground_card[1], player[num2]);
		strcpy(player[num2] , temp);

		
	}
	for (int i = 0;i < 4;i++)
	{
		printf("%s\t", player[i]);
	}

	if (num1 == 2 && strcmp(ground_card[1], " "))//////////////////////////////////////////////////////while loop kepera we albasra
	{
		printf("\nchoose num of card to basra\n");
		int num4;
		scanf("%d", &num4);


	}



	int num;
	if (num1 == 0)      
	{
		for (int i = 1; i > 60;i++)
		{
			if (strcmp(cards[i], "xx") != 0)
			{
				num = i;
				break;
			}
		}
		printf("\n%s\n", cards[num]);
		printf("if you want this card press 1 if not 0\n");
		int num3;
		scanf("%d", &num3);
		if (num3 == 1)
		{
			printf("choose the card that you want to change\n");
			int num2;
			scanf("%d", &num2);

			strcpy(ground_card[0], ground_card[1]);
			
			strcpy(ground_card[1], player[num2]);
			strcpy(player[num2], cards[num]);
			strcpy(cards[num], "xx");
			
		}
		if (num3 == 0) /// rest of the functions
		{
			strcpy(ground_card[0], ground_card[1]);
			strcpy(ground_card[1], cards[num]);
			strcpy(cards[num], "xx");
		}
	} 




}
 
int main()
{
	char cards[60][6] = { "1","1","1","1","2","2","2","2","3","3","3","3","4","4","4","4","5","5","5","5","6","6","6","6",
	 "7", "7", "7", "7", "8", "8", "8", "8", "9", "9", "9", "9", "10", "10", "10", "10", "-1", "sd", "sd","sd", "s", "s", "+20" ,
	 "+20", "+20", "+20", "basra", "basra", "5wh", "5wh", "5wh", "5wh", "harmy", "5od", "kd", "kd" };

	shuffel(cards);

	for (int i = 0;i < 60;i++)
	{
		printf("%s\t", cards[i]);
	}
	printf("\n\n");
	char player[4][6];
	srand(time(0));
	int used[60] = { 0 };


	char ground_card[2][6];
	strcpy(ground_card[0]," ");
	strcpy(ground_card[1], cards[0]);
	strcpy(cards[0], "xx");
	printf("First card %s\n", ground_card[1]);
	used[0] = 1;


	for (int i = 0;i < 4;i++)  // assign 4 num
	{
		int c;
		do
		{
			c = rand() % 60; //pick random
		} while (used[c]);   //repet if it's taken

		strcpy(player[i], cards[c]);
		used[c] = 1;
		strcpy(cards[c], "xx");
		printf("%s\t", player[i]);


	}
	printf("\n\n");
	for (int i = 0;i < 60;i++)
	{
		printf("%s\t", cards[i]);
	}
	printf("\n\n");
	printf(" first two crads to see :)");
	printf("\n\n");

	printf("%s\t%s", player[0], player[1]);
	/*int num;
	for (int i = 0; i > 60;i++)
	{
		if (strcmp(cards[i], "xx") != 0)
		{
			num = i;
			break;
		}
	}*/
	player_move(player,cards, ground_card);

}