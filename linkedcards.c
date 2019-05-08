#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Why are we doing Magic the Gathering
char tagNames[100][16] = { "Elf", "Goblin", "Undead", "Giant" };

typedef struct MtgCardType
{
	char title [51];
	char spellType[15]; // "creature" "enchantment" "artifact" "instant" Sorcery" "Planeswalker" "land"
	
	int tags[5]; 
	int tagCount; 
	int power;
	int toughness;
	char manaCost[20]; 
	
	char rules[200];
	char flavorText[200];
	 
	struct MtgCardType * nextCard;

} MtgCardType;
/*
MtgCardType* loadCardList( ) //for now no parameter, later a file name

{
	// loop until all cards in the file have been read:
	 //* read data for one card
	 //* allocate memory to store that data
	 //* copy the data into that new structure
	 //* make sure the previous car in the list has "next" pointing to a new card
	 
	 
	 char line[100];
	 MtgCardType * newCardPtr = NULL;
	 MtgCardType * lastCardInList = NULL;
	 MtgCardType * firstCardInList = NULL;
	 
	 while (! feof(stdin) ) // user can create an end of file with ctrl + D
	{
		fgets(line, 100, stdin);
		newCardPtr = (MtgCardType *) malloc(sizeof(MtgCardType)); 

		strcpy( (*newCardPtr).title, line );
    
		if ( firstCardInList != NULL) 
	
       (*lastCardInList).nextCard = newCardPtr;
		}
		else
		{
			firstCardInList = newCardPtr;
			lastCardInList = newCardPtr;
		}
		
		(*newCardPtr).nextCard = NULL;
		lastCardInList = newCardPtr; 
		
		//(*lastCardInList).nextCard = NULL;
		//(*newCardPtr).nextCard = NULL; //alternate for line 62
	}
	return firstCardInList;
}
*/

MtgCardType* loadCardList( ) 

{
	 int y;
	 char line[100];
	 MtgCardType * newCardPtr = NULL;
	 MtgCardType * lastCardInList = NULL;
	 MtgCardType * firstCardInList = NULL;
	 
	 while (1)  // user can create an end of file with ctrl + D
	{
		newCardPtr = (MtgCardType *) malloc(sizeof(MtgCardType));
		
		
		
		
		printf("Card title:\n");
		fgets(line, 100, stdin);
		if (line[0] =='\n') break;
		y = strlen(line);
		line[y-1] = '\0';
		strcpy( (*newCardPtr).title, line );
		
		printf("Card type:\n");
		fgets(line, 100, stdin);
		if (line[0] =='\n') break;
		y = strlen(line);
		line[y-1] = '\0';
		strcpy( (*newCardPtr).spellType, line );
		
		printf("Card Toughness (noncreature: input 0, planewalker: # of loyalty counters):\n");
		fgets(line, 100, stdin);
		if (line[0] =='\n') break;
		
		(*newCardPtr).power = atoi(line);
		
		printf("Card Power (noncreature: input 0):\n");
		fgets(line, 100, stdin);
		if (line[0] =='\n') break;
		
		(*newCardPtr).toughness = atoi(line);
		
		printf("Mana Cost (ex: 6  BBR):\n");
		fgets(line, 100, stdin);
		if (line[0] =='\n') break;
		strcpy( (*newCardPtr).manaCost, line );
		
    
		
		(*newCardPtr).nextCard = NULL;
		
		if ( firstCardInList != NULL)  
		{
				(*lastCardInList).nextCard = newCardPtr; 
		}
		else
		{
			firstCardInList = newCardPtr; 
			lastCardInList = newCardPtr;
		}
					
		lastCardInList = newCardPtr; 
		printf("Another Card?  ( y / n)\n");
		fgets(line, 100, stdin);
		if (line[0] =='n') break;
		
		
	}
	return firstCardInList;
}

void printFirstCardInList(MtgCardType *listTop)
{
	//printf("%s\n", (*listTop).name );
	
	if (listTop != NULL) {
		printf("%s\n", listTop->title );
	} else {
		printf("*** Empty Card List ***\n");
	}
}

// second card in list

void printSecondCardInList(MtgCardType *listTop)
{
	//printf("%s\n", (*listTop).name );
	
	if (listTop != NULL) {
		printf("%s\n", listTop->nextCard->title ); 
	} else {
		printf("*** Empty Card List ***\n");
	}
}

// second card in list

void printThirdCardInList(MtgCardType *listTop)
{
	//printf("%s\n", (*listTop).name );
	
	if (listTop != NULL) {
		printf("%s\n", listTop->nextCard->nextCard->title ); 
	} else {
		printf("*** Empty Card List ***\n");
	}
}


void printCardList(MtgCardType *listTop)
{
	MtgCardType * tmpPtr = listTop;
	
	while(tmpPtr != NULL)
	{	
		printf("%s\n", tmpPtr->title);
	
		tmpPtr = tmpPtr->nextCard;
	}
		
		

}
void printfull(MtgCardType * tacocat)
{
	if (tacocat == NULL)
		{
			printf("empty list\n");
			exit(0);
		}
	printf("          Title            Type        Toughness   Power        Manacost\n");
	while(tacocat  != NULL)
		{
			printf("%15s %15s %10d %10d %15s", tacocat -> title, tacocat ->spellType, tacocat -> toughness , tacocat -> power , tacocat -> manaCost);
			tacocat = tacocat -> nextCard;
		}


}

int main(int argc, char* argv[])
{
	MtgCardType *topOfFirstList, *topOfSecondList;

		printf("Please enter a list of card titles\n");
		topOfFirstList = loadCardList(); 

		printf("Here is the list of cards:\n");
		printfull(topOfFirstList);
		

	return 0;
}
