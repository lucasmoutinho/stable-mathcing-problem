#include <list>
#include <iostream>

// Class Professor
class Professor{
private:

  // Has id, hab, job ans a list of preferences schools of the professor
  int id;
  int habilitation;
  std::list<int> preferences; 
  bool allocated;

public:
  Professor(int id, int habilitation, int preferences[5]);

  int getId();
  int getHabilitation();
  int getPreference();
  void removePreference(int school);
  std::list<int> getPreferencesList();
  bool isAllocated();
  void makeAllocation();
  void removeAllocation();

};

