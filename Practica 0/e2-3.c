#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * NOTE: suits
 * 0 = swords
 * 1 = gold
 * 2 = cups
 * 3 = clubs
 */

typedef struct _card {
  unsigned int suit;
  unsigned int number;
} card;

card chance (card arr[], int length) {
  int rando = rand() % length;
  
  return arr[rando];
}

int main (void) {
  srand((unsigned int)time(NULL));
  
  card deck[48];
  card randomCard;
  int i, curSuit = 0;
  
  for (i = 0; i < 48; i++) {
    if (i % 12 == 0) 
      curSuit++;
    
    deck[i].suit = curSuit;
    deck[i].number = (int)(i % 12) + 1;
  }
  
  randomCard = chance(deck, 48);
  
  printf("Your random card is the %d of %d.\n", randomCard.number, randomCard.suit);
  
  return 0;
}
