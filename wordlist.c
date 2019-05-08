#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Why are we doing Magic the Gathering
char tagNames[100][16] = { "Elf", "Goblin", "Undead", "Giant" };

typedef struct MtgCardType
{
	char title [51]; 
	char spellType[15]; // "Creature" "Enchantment" "Artifact" "Instant" Sorcery" "Planeswalker" "Swamps which are the most fun land"
	
	int tags[5]; 
	int tagCount; 
	int power;
	int toughness;
	int manaCost; // colorless
	
	char rules[200];
	char flavorText[200];
	 
	struct MtgCardType * nextCard;

} MtgCardType;

MtgCardType* loadCardList( )
{
	 char line[100];
	 MtgCardType * newCardPtr = NULL;
	 MtgCardType * lastCardInList = NULL;
	 MtgCardType * firstCardInList = NULL;
	 
	 while (1) // ctrl + D end file
	{
		fgets(line, 100, stdin);
		if (line[0] =='\n') break;
	
		newCardPtr = (MtgCardType *) malloc(sizeof(MtgCardType)); 
		strcpy( (*newCardPtr).title, line ); 
		(*newCardPtr).nextCard = NULL;
		
		if ( firstCardInList != NULL)  
		{
			newCardPtr -> nextCard = firstCardInList;
			firstCardInList = newCardPtr; 
		}		
		else
		{
			firstCardInList = newCardPtr; 
			lastCardInList = newCardPtr;
		}
	}
	return firstCardInList;
}
// Check top then lists cards

void printFirstCardInList(MtgCardType *listTop)
{	
	if (listTop != NULL) {
		printf("%s\n", listTop->title );
	} else {
		printf("*** Empty Card List ***\n");
	}
}

void printSecondCardInList(MtgCardType *listTop)
{
	if (listTop != NULL) {
		printf("%s\n", listTop->nextCard->title );
	} else {
		printf("*** Empty Card List ***\n");
	}
}

void printThirdCardInList(MtgCardType *listTop)
{
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
//print card
		printf("%s\n", tmpPtr->title);
	
		tmpPtr = tmpPtr->nextCard;
	}	
}

int main(int argc, char* argv[])
{
	MtgCardType *topOfFirstList, *topOfSecondList;

		printf("Please enter a list of card titles\n");
		topOfFirstList = loadCardList();
		printf("--------------------------------------------------------------\n");
		printf("Please enter a second list\n");
		topOfSecondList = loadCardList();
		
		printf("--------------------------------------------------------------\n");
		printf("Here is the first card in your first list...\n");
		printFirstCardInList(topOfFirstList);
		
		printf("--------------------------------------------------------------\n");
		printf("Here is the first card in your second list...\n");
		printFirstCardInList(topOfSecondList);
		
		printf("--------------------------------------------------------------\n");
		printf("Here is the second card in your second list...\n");
		printSecondCardInList(topOfSecondList);
		
		printf("--------------------------------------------------------------\n");
		printf("Here is the first list of cards...\n");
		printCardList(topOfFirstList);
		
		printf("==============================================================\n");
		printf("Here is the second list of cards...\n");
		printCardList(topOfSecondList);
		
	return 0;
}
