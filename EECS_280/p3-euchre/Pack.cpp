// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "Pack.h"
#include <array>
#include <string>

// EFFECTS: Initializes the Pack to be in the following standard order:
  //          the cards of the lowest suit arranged from lowest rank to
  //          highest rank, followed by the cards of the next lowest suit
  //          in order from lowest to highest rank, and so on.
  // NOTE: The standard order is the same as that in pack.in.
  // NOTE: Do NOT use pack.in in your implementation of this function
  Pack::Pack(){
      reset();
      int cardIndex = 0;
      for (int i = 0; i < NUM_SUITS; i++){
          for (int j = 7; j < NUM_RANKS; j++){
              Card c1(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
              cards[cardIndex] = c1;
              cardIndex++;
          }
      }
  }

  // REQUIRES: pack_input contains a representation of a Pack in the
  //           format required by the project specificationc
  // MODIFIES: pack_input
  // EFFECTS: Initializes Pack by reading from pack_input.
  Pack::Pack(std::istream& pack_input){
      reset();
      std::string cardRank;
      std::string cardSuit;
      std::string junk;
      for (int i = 0; i < PACK_SIZE; i++){
          pack_input >> cardRank >> junk >> cardSuit;
          Card c1(cardRank, cardSuit);
          cards[i] = c1;
      }
  }

  // REQUIRES: cards remain in the Pack
  // EFFECTS: Returns the next card in the pack and increments the next index
  Card Pack::deal_one(){
      Card c1; 
      c1 = cards[next];
      next++;
      return c1;
  }

  // EFFECTS: Resets next index to first card in the Pack
  void Pack::reset(){
      next = 0;
  }

  // EFFECTS: Shuffles the Pack and resets the next index. This
  //          performs an in shuffle seven times. See
  //          https://en.wikipedia.org/wiki/In_shuffle.
  void Pack::shuffle(){
      for (int k = 0; k < 7; k++){
          std::array<Card, PACK_SIZE / 2> stack1;
          std::array<Card, PACK_SIZE / 2> stack2;
          for (int i = 0; i < 12; i++){
              stack1[i] = cards[i];
          }
          for (int i = 0; i < 12; i++){
              stack2[i] = cards[i + 12];
          }
          for (int i = 0; i < 24; i += 2){
              cards[i] = stack2[i / 2];
              cards[i + 1] = stack1[i / 2];
          }
      }
      reset();
  }

  // EFFECTS: returns true if there are no more cards left in the pack
  bool Pack::empty() const{
      return (next == 24);
  }