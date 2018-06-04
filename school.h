#include <list>
#include <iostream>
#include "professor.h"

class School{
private:
  int id;
  int habilitation;
  int jobs;
  std::list<int> professors;

  bool isFull();

public:
  School(int id, int habilitation, int jobs);

  int getId();
  int getHabilitation();
  int getJobs();
  void removeProfessor(int professor);
  std::list<int> getProfessors();
  
  void makeAllocation(Professor professor);
};
