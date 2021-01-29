#include "critter.h"

Critter::Critter(int hunger, int boredom)
    : m_Hunger(hunger), m_Boredom(boredom) {}

inline int Critter::GetMood() const
{
  return (m_Hunger + m_Boredom);
}

int Critter::getHunger() const
{
  return m_Hunger;
}

int Critter::getBoredom() const
{
  return m_Boredom;
}

void Critter::PassTime(int time)
{
  m_Hunger += time;
  m_Boredom += time;
}

void Critter::Talk()
{
  std::cout << "I'm a critter and I feel ";

  int mood = GetMood();
  if (mood > 15)
    std::cout << "mad.\n";
  else if (mood > 10)
    std::cout << "frustrated.\n";
  else if (mood > 5)
    std::cout << "okay.\n";
  else
    std::cout << "happy.\n";
  ShowHungerBoredum();
  PassTime();
}

void Critter::Eat(int food)
{
  std::cout << "Brruppp.\n";
  m_Hunger -= food;
  if (m_Hunger < 0)
    m_Hunger = 0;
  ShowHungerBoredum();
  PassTime();
}

void Critter::Play(int fun)
{
  std::cout << "Wheee!\n";
  m_Boredom -= fun;
  if (m_Boredom < 0)
    m_Boredom = 0;
  ShowHungerBoredum();
  PassTime();
}

void Critter::ShowHungerBoredum()
{
  if ((m_Hunger <= 4) && (m_Boredom <= 4))
  {
    std::cout << "I'm full and I'm not bored. \n";
  }
  else if ((m_Hunger <= 4) && (m_Boredom > 4 && m_Boredom <= 10))
  {
    std::cout << "I'm full, but I'm bored.\n";
  }
  else if ((m_Hunger <= 4) && (m_Boredom >= 10))
  {
    std::cout << "I'm full, but I'm very bored. \n";
  }
  else if ((m_Boredom <= 4) && (m_Hunger > 4 && m_Hunger < 10))
  {
    std::cout << "I'm hungry, but I'm not bored. \n";
  }
  else if ((m_Boredom > 4 && m_Boredom < 10) && (m_Hunger > 4 && m_Hunger < 10))
  {
    std::cout << "I'm hungry and I'm bored. \n";
  }
  else if ((m_Boredom >= 10) && (m_Hunger > 4 && m_Hunger < 10))
  {
    std::cout << "I'm hungry, but I'm very bored. \n";
  }
  else if ((m_Hunger >= 10) && (m_Boredom <= 4))
  {
    std::cout << "I'm very hungry, but I'm not bored. \n";
  }
  else if ((m_Hunger >= 10) && (m_Boredom > 4 && m_Boredom < 10))
  {
    std::cout << "I'm very hungry, and I'm bored. \n";
  }
  else if ((m_Hunger >= 10) && (m_Boredom >= 10))
  {
    std::cout << "I'm very hungry, and I'm very bored! \n";
  }
}

void Critter::DisplayLevels()
{
  std::cout << "\nCritter Hunger Level: " << getHunger() << ".\n";
  std::cout << "Critter Boredum Level: " << getBoredom() << ".\n";
}
