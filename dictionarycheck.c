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
	int manaCost; / colorless
  
	char rules[200];
	char flavorText[200];
	 
	struct MtgCardType * nextCard;

} MtgCardType;
/*
MtgCardType* loadCardList( ) 

{	 
	 
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
		
		(*lastCardInList).nextCard = newCardPtr; //this should give us a new card at the end of the list
		
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


MtgCardType* loadCardList(char fname[] )

{
	 
	 char line[100];
	 MtgCardType * newCardPtr = NULL;
	 MtgCardType * lastCardInList = NULL;
	 MtgCardType * firstCardInList = NULL;
	 
	 FILE *input = fopen (fname , "r");
	 
	 while ( fgets(line, 100, input) )
	 {	
		
		

		newCardPtr = (MtgCardType *) malloc(sizeof(MtgCardType));
		strcpy( (*newCardPtr).title, line ); // astericks in front of a pointer value means the thing pointed to. In this case, MtgCardType structure.
		(*newCardPtr).nextCard = NULL;
		
		if ( firstCardInList != NULL)  
		{
				
				lastCardInList-> nextCard = newCardPtr; 		//writes new card 
				lastCardInList = newCardPtr;
		}		
		else
		{
			firstCardInList = newCardPtr;
			lastCardInList = newCardPtr;
		}
					
		
		
		
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


// printCardList
//prints an entire card list, given pointer to top of the list
void printCardList(MtgCardType *listTop)
{
	MtgCardType * tmpPtr = listTop;
	
	while(tmpPtr != NULL)
	{	
	//print current card
	//make temp point to self
		printf("%s\n", tmpPtr->title);
	
		tmpPtr = tmpPtr->nextCard;
	}
		
		

}

char *prunesearchword( char z[])
{
	
	int i,k;
		
	for (i=6 ; i > 0 ; i--)
		{						
			for (k=0; k<99 ; k++)
			z[k] = z[k+1];
		}
	return z;
}

MtgCardType * searchlist(char keyword[] , MtgCardType *org )
{
/*
	int len = strlen(keyword),orange;
	MtgCardType *revised = NULL;
	MtgCardType * temp = org;
	MtgCardType * leadingedge;
	
	
		
	while(temp -> nextCard != NULL)
	{
		orange = strncmp(keyword,temp-> title,len-1);
		if (0 == orange)
			{
				
				if (revised == NULL)
					{	
						printf("tacocat\n");
						revised = temp;
						printf("tacocat\n");
						revised -> nextCard = NULL;
						
					}
				else
					{
						printf("tacocat\n");
						strcpy(leadingedge -> nextCard -> title , temp -> title);
						leadingedge = leadingedge -> nextCard;
						printf("tacocat\n");
						
													
					}
				
			}
		
		temp = temp -> nextCard;
		
	}
	
	return revised;
	*/
}


int main(int argc, char* argv[])
{
	MtgCardType *topOfFirstList, *topOfSecondList ;
	
		FILE *test = fopen(argv[1] , "r");
		if (test == NULL)
			{
				printf("NO FILE FOUND\n");
				
				exit(0);
			}
			
		int inloop =1;
		char h[100];
		
		topOfFirstList = loadCardList(argv[1]); 
		 
		MtgCardType * lastCardInList = NULL;
		lastCardInList = topOfFirstList;
		while (lastCardInList -> nextCard != NULL)
			lastCardInList = lastCardInList -> nextCard;
		while (inloop)
			{
				MtgCardType * temp = NULL;
				temp = (MtgCardType *) malloc(sizeof(MtgCardType));
				printf("Please enter words\n");
				fgets(h, 100 ,stdin);
				if (h[0] ==':')
					{
						if ((h[1] == 'q') && (h[2] == 'u') && (h[3] ==  'i') && (h[4] == 't')) 
							exit(0);
						if ((h[1] == 'l') && (h[2] == 'i') && (h[3] ==  's') && (h[4] == 't'))
							{
								
								if (h[5] != '\n' )
									{
										//h = prunesearchword( h );
										strcpy(h , prunesearchword( h ));		
										
										topOfSecondList = searchlist( h , topOfFirstList);
										
										if (topOfSecondList == NULL)
											{
												printf("NO WORDS FOUND\n");
				
												
											}
											
										else
											printCardList(topOfSecondList);
									}
								else 
									{
										inloop=0;
										printf("Here is the first list of words\n");
										printCardList(topOfFirstList);
									}
							}
				
				
				
					}
				else 
				{
				strcpy( temp -> title, h );
				lastCardInList-> nextCard = temp;  
				lastCardInList = temp;	
				}		
				
			}

		
		
	
	return 0;
}
