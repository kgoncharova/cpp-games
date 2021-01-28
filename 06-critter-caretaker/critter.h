#ifndef CRITTER_H_
#define CRITTER_H_
#include <iostream>

class Critter
{
private:
  int m_Hunger;
  int m_Boredom;
  int GetMood() const;
  void PassTime(int time = 1);
public:
  Critter(int hunger = 0, int boredom = 0);
  void Talk();
  void Eat(int food = 4);
  void Play(int fun = 4);
};

#endif
