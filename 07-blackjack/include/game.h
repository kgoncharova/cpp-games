#ifndef GAME_H_
#define GAME_H_
#include "deck.h"
#include "house.h"
#include "player.h"

class Game
{
private:
  Deck m_Deck;
  House m_House;
  std::vector<Player> m_Players;
public:
  Game(const std::vector<std::string>& names);

  ~Game();

  // plays the game of blackjack
  void Play();
};

#endif
