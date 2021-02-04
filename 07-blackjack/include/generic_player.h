#ifndef GENERIC_PLAYER_H_
#define GENERIC_PLAYER_H_
#include <iostream>
#include "hand.h"

class GenericPlayer : public Hand
{
private:
  friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
protected:
  std::string m_Name;
public:
  GenericPlayer(const std::string& name = "");
  virtual ~GenericPlayer();

  // indicates whether or not generic player wants to keep hitting
  virtual bool IsHitting() const = 0;

  // returns whether generic player has busted - has a total greater than 21
  bool IsBusted() const;

  // announces that the generic player busts
  void Bust() const;
};

#endif
