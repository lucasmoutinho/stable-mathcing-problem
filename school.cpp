#include "school.h"

using namespace std;

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
  this->prof.remove(professor);
}

std::list<int> School::getProfessors(){
  return this->prof;
}

bool School::isFull(){
  if(this->prof.size() > unsigned(this->jobs)){
    return true;
  }
  return false;
}

Professor *School::findProfessor(list<Professor> *professors, int id){
  list<Professor>::iterator jt = professors->begin();
  id--;
  advance(jt, id);
  return &(*jt);
}

Professor *School::findWorst(list<Professor> *professors, Professor* professor)
{
  int id;
  Professor* aux;
  Professor* worst = professor;
  for (list<int>::iterator it = this->prof.begin(); it != this->prof.end(); ++it)
  {
    id = (*it);
    aux = findProfessor(professors, id);
    if(aux->getHabilitation() != this->getHabilitation()){
      worst = aux;
    }
  }
  return worst;
}

void School::addProfessor(int professor){
  this->prof.push_back(professor);
}

void School::makeAllocation(Professor *professor, list<Professor> *professors){
  professor->makeAllocation();
  this->addProfessor(professor->getId());

  if(this->isFull()){
    Professor* worst = findWorst(professors, professor);
    worst->removePreference(this->getId());
    worst->removeAllocation();
    this->removeProfessor(worst->getId());
  }
}

void School::showProfessorsList(){
  cout << "E" << this->getId() << " ";
  for (list<int>::iterator it = this->prof.begin(); it != this->prof.end(); ++it)
  {
    cout << "P" << *it << " ";
  }
  cout << endl;
}