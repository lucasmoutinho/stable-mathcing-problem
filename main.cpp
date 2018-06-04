#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale>
#include "school.h"

using namespace std;

bool readFile(list<Professor> professors, list<School> schools);
int getNumber(string word);
void separateNumber(string word, int *id, int *habilitation, int *job);
void showProfessors(list<Professor> professor);

void showProfessors(list<Professor> professor){
  for (list<Professor>::iterator it = professor.begin(); it != professor.end(); it++)
  {
    cout << it->getId();
    cout << it->getHabilitation() << endl;
  }
}

int getNumber(string word){
  string aux;
  int result;
  if(word[0] == '('){
    if(word[3] == ','){
      aux = word[2];
    }
    else{
      aux = word[2] + word[3];
    }
  }
  else{
    if(word[2] == ','){
      aux = word[1];
    }
    else{
      aux = word[1] + word[2];
    }
  }
  istringstream convert(aux);
  convert >> result;
  return result;
}

void separateNumber(string word, int *id, int *habilitation, int *job){
  string aux;
  int j = 0;
  if(word[3] == ')'){
    aux = word[2];
  }
  else{
    aux = word[2] + word[3];
    j = 1;
  }
  istringstream convert(aux);
  convert >> *id;
  *habilitation = (int)word[6+j];
  *job = (int)word[10+j];
}

bool readFile(list<Professor> professors, list<School> schools){
  string line;
  string aux1, aux2, aux3, aux4, aux5, aux6, aux7;
  int preferences[5];
  int habilitation;
  int jobs;
  int id;

  ifstream fp("entradaProj3TAG.txt");
  if (fp.is_open()){
    while (getline(fp, line)){
      if(line[0] == '('){
        if(line[1] == 'P'){
          fp >> aux1 >> aux2 >> aux3 >> aux4 >> aux5 >> aux6 >> aux7;
          id = getNumber(aux1);
          habilitation = getNumber(aux2);
          preferences[0] = getNumber(aux3);
          preferences[1] = getNumber(aux4);
          preferences[2] = getNumber(aux5);
          preferences[3] = getNumber(aux6);
          preferences[4] = getNumber(aux7);
          Professor prof = Professor(id, habilitation, preferences);
          professors.push_back(prof);
        }
        else{
          fp >> aux1;
          separateNumber(aux1,&id, &habilitation, &jobs);
          School sch = School(id, habilitation, jobs);
          schools.push_back(sch);
        }
      }
    }
    fp.close();
    return true;
  }
  else{
    cout << "Unable to read the file" << endl;
  }
  return false;
}

int main(){
  list<Professor> professors;
  list<School> schools;

  if(readFile(professors, schools)){
    showProfessors(professors);
  }
  return 0;
}
