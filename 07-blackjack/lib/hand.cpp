#include "../include/hand.h"

Hand::Hand()
{
  m_Cards.reserve(7);
}

Hand::~Hand()
{
  Clear();
}

void Hand::Add(Card* pCard)
{
  m_Cards.push_back(pCard);
}

void Hand::Clear()
{
  // itereate through vector, freeing all memory on the heap
  std::vector<Card*>::iterator iter = m_Cards.begin();
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
    delete * iter;
    *iter = nullptr;
  }
  // clear vector of pointers
  m_Cards.clear();
}

int Hand::GetTotal() const
{
  // return 0 if no cards in hand or if a first card has a value of 0
  if (m_Cards.empty() || m_Cards[0]->GetValue() == 0)
  {
    return 0;
  }

  // add up card values, treat each as 1
  int total = 0;
  std::vector<Card*>::const_iterator iter;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
    total += (*iter)->GetValue();
  }

  // determine if hand continues an ace
  bool containsAce = false;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
    if ((*iter)->GetValue() == Card::ACE)
      containsAce = true;
  }

  // if hand contains ace and total is low enough, treat ace as 11
  if (containsAce && total <= 11)
  {
    // add only 10 since we've already added 1 for the ace
    total += 10;
  }

  return total;
}
