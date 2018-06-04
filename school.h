#include <list>
#include <iostream>
#include "professor.h"

class School{
private:

  int id;
  int habilitation;
  int jobs;
  std::list<int> prof;

  Professor *findProfessor(std::list<Professor> *professors, int id);
  Professor *findWorst(std::list<Professor> *professors, Professor* professor);
  void removeProfessor(int professor);
  void addProfessor(int professor);

public:
  School(int id, int habilitation, int jobs);

  bool isFull();
  int getId();
  int getHabilitation();
  int getJobs();
  std::list<int> getProfessors();
  void makeAllocation(Professor *professor, std::list<Professor> *professors);
  void showProfessorsList();
};
