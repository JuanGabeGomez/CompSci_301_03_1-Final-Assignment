#include "People.h"
#include "AssociativeArray.h"
#include <iostream>

using namespace std;

int main()
{
  AssociativeArray<int, Patient> patientList;
  AssociativeArray<int, Doctor> doctorList;
  char answer;
  do
  {
    cout << "What would you like to do?\n"
      << "A. Print out list of patients\n"
      << "B. Search for a patient in database\n"
      << "C. Link patient to doctor\n"
      << "D. Unlink patient to doctor\n"
      << "E. See list of doctors\n"
      << "F. Print out list of patients assigned to a doctor\n"
      << "G. Add appointment"
      << "H. Print table of appointments\n"
      << "Q. Quit\n";
    switch (answer)
    {
    case 'A':
      break;
    case 'B':
      break;
    case 'C':
      break;
    case 'D':
      break;
    case 'E':
      break;
    case 'F':
      break;
    case 'G':
      break;
    case 'H':
      break;
    case 'Q':
      break;
    }
  } while (answer != 'Q');
  return 0;
}