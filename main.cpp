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
void showProfessors(list<Professor> professors);

void showProfessors(list<Professor> *professors){
  for (std::list<Professor>::iterator it = professors->begin(); it != professors->end(); ++it)
  {
    cout << "ID: " << it->getId() << " || ";
    cout << "Habilitation: " << it->getHabilitation() << " || ";
    cout << "Preferences: ";
    list<int> preferences = it->getPreferencesList();
    for (std::list<int>::iterator jt = preferences.begin(); jt != preferences.end(); ++jt){
      cout << *jt << " ";
    }
    cout << endl << endl;
  }
}

int getNumber(string word){
  string aux;
  string aux2;
  string aux3;
  int decimal = 0;
  int centesimal = 0;
  int result = 0;
  if(word[0] == '('){
    if(word[3] == ','){
      aux = word[2];
      istringstream(aux) >> result;
    }
    else if (word[4] == ','){
      aux2 = word[2];
      aux = word[3];
      istringstream(aux) >> result;
      istringstream(aux2) >> decimal;
      decimal *= 10;
      result = result + decimal;
    }
    else{
      aux3 = word[2];
      aux2 = word[3];
      aux = word[4];
      istringstream(aux) >> result;
      istringstream(aux2) >> decimal;
      istringstream(aux3) >> centesimal;
      decimal *= 10;
      centesimal *= 100;
      result = result + decimal + centesimal;
    }
  }
  else{
    if(word[2] == ',' || word[2] == ')'){
      aux = word[1];
      istringstream(aux) >> result;
    }
    else if(word[1] == ')'){
      aux = word[0];
      istringstream(aux) >> result;
    }
    else{
      aux2 = word[1];
      aux = word[2];
      istringstream(aux) >> result;
      istringstream(aux2) >> decimal;
      decimal *= 10;
      result = result + decimal;
    }
  }
  return result;
}

void separateNumber(string word, int *id, int *habilitation, int *job){
  string aux;
  string aux2;
  int decimal = 0;
  int result = 0;
  int j = 0;
  if(word[3] == ')'){
    aux = word[2];
  }
  else{
    aux2 = word[2];
    aux = word[3];
    istringstream(aux) >> result;
    istringstream(aux2) >> decimal;
    decimal *= 10;
    result = result + decimal;
    j = 1;
  }
  result >> *id;
  *habilitation = (int)word[6+j];
  *job = (int)word[10+j];
}

bool readFile(list<Professor> *professors, list<School> *schools){
  string line;
  string aux1, aux2, aux3, aux4, aux5, aux6, aux7;
  int preferences[5];
  int habilitation;
  int jobs;
  int id;

  ifstream fp("entradaProj3TAG.txt");
  if (fp.is_open()){
    while (!fp.eof()){
      getline(fp, line); /*pega uma linha inteira do .txt*/
      stringstream is(line);
      if(line[0] == '('){
        if(line[1] == 'P'){
          is >> aux1 >> aux2 >> aux3 >> aux4 >> aux5 >> aux6 >> aux7;
          id = getNumber(aux1);
          habilitation = getNumber(aux2);
          preferences[0] = getNumber(aux3);
          preferences[1] = getNumber(aux4);
          preferences[2] = getNumber(aux5);
          preferences[3] = getNumber(aux6);
          preferences[4] = getNumber(aux7);
          // cout << id << habilitation << preferences[0] << preferences[1] << preferences[2] << preferences[3] << preferences[4] << endl;
          Professor prof = Professor(id, habilitation, preferences);
          professors->push_back(prof);
          cout << professors->size() << endl;
        }
        else{
          is >> aux1;
          separateNumber(aux1,&id, &habilitation, &jobs);
          School sch = School(id, habilitation, jobs);
          schools->push_back(sch);
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

  if(readFile(&professors, &schools)){
    showProfessors(&professors);
  }
  return 0;
}
