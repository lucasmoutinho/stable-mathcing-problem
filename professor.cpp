#include "professor.h"

Professor::Professor(int id, int habilitation, int preferences[5]){
  this->id = id;
  this->habilitation = habilitation;
  
  for(int i = 0; i < 5; i++)
  {
    this->preferences.push_back(preferences[i]);
  }
  
  this->allocated = false;
}

int Professor::getId()
{
  return this->id;
}

int Professor::getHabilitation()
{
  return this->habilitation;
}

int Professor::getPreference(){
  return this->preferences.front();
}

void Professor::removePreference(int school){
  this->preferences.remove(school);
}

std::list<int> Professor::getPreferencesList(){
  return this->preferences;
}

bool Professor::isAllocated(){
  return this->allocated;
}

void Professor::makeAllocation(){
  this->allocated = true;
}

void Professor::removeAllocation(){
  this->allocated = false;
}