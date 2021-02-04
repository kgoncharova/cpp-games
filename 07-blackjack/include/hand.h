#ifndef HAND_H_
#define HAND_H_
#include <vector>
#include "card.h"

class Hand
{
protected:
  std::vector<Card*> m_Cards;
public:
  Hand();
  virtual ~Hand();

  // adds a card to the hand
  void Add(Card* pCard);

  // clears hand of all cards
  void Clear();

  // gets hand total value, intelligently treats aces as 1 or 11
  int GetTotal() const;
};

#endif
