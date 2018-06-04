#include "school.h"

School::School(int id, int habilitation, int jobs){
  this->id = id;
  this->habilitation = habilitation;
  this->jobs = jobs;
}

int School::getId(){
  return this->id;
}

int School::getHabilitation(){
  return this->habilitation;
}

int School::getJobs(){
  return this->jobs;
}

void School::removeProfessor(int professor){
  this->professors.remove(professor);
}

std::list<int> School::getProfessors(){
  return this->professors;
}

bool School::isFull(){
  if(this->professors.size() > unsigned(this->jobs)){
    return true;
  }
  return false;
}

void School::makeAllocation(Professor professor){
}