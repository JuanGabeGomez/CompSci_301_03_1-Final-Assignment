#pragma once
#include <string>
#include <queue>

class People
{
  std::string name;
  int age;
  int height;
  int weight;
public:
  People(std::string name = std::string(), int age = 0, int height = 0, int weight = 0);
  ~People();
  void setName(std::string name = std::string());
  void setAge(int age = 0);
  void setHeight(int height = 0);
  void setWeight(int weight = 0);
  std::string getName();
  int getAge();
  int getHeight();
  int getWeight();
};

class Patient : public People
{
  int patientNum;
  int assignedDocID;
public:
  Patient();
  ~Patient();
  void setPatientNumber(int pnum = 0);
  void setAssignedDocID(int aDocID = 0);
  int getPatientNumber();
  int getAssignedDocID();
};

class Appointment
{
  int time;
  Patient pat;
  int day;
  int month;
  int year;
public:
  Appointment(int time = 0, Patient pat = Patient(), int day = 0, int month = 0, int year = 0)
  {
    this->time = time;
    this->pat = pat;
    this->day = day;
    this->month = month;
    this->year = year;
  }
  void setTime(int time = 0) { this->time = time; }
  void setPatient(Patient pat = Patient()) { this->pat = pat; }
  void setDay(int day = 0) { this->day = day; };
  void setMonth(int month = 0) { this->month = month; }
  void setYear(int year = 0) { this->year = year; }
  int getTime() { return time; }
  Patient getPatient() { return pat; }
  int getDay() { return day; }
  int getMonth() { return month; }
  int getYear() { return year; }
  bool operator==(Appointment a)
  {
    if (this->day == a.day && this->month == a.month && this->year == a.year && this->time == a.time && this->pat == a.pat)
      return true;
    return false;
  }
};

class Doctor : public People
{
  struct linkedAppointment
  {
    Appointment value;
    linkedAppointment* next;
  };
  struct PatientList
  {
    int patientID;
    PatientList* next;
  };
  int IDNumber;
  int AppSize;
  int PatSize;
  linkedAppointment* frontApp;
  PatientList* frontPat;
public:
  Doctor(std::string name = std::string(), int age = 0, int height = 0, int weight = 0, int ID = 0)
  {
    frontApp = nullptr;
    frontPat = nullptr;
    this->setName(name);
    this->setAge(age);
    this->setHeight(height);
    this->setWeight(weight);
    IDNumber = ID;
    AppSize = 0;
    PatSize = 0;
  }
  ~Doctor()
  {
    while (frontApp)
    {
      linkedAppointment* Apptemp = frontApp;
      frontApp = frontApp->next;
      delete Apptemp;
    }
    while (frontPat)
    {
      PatientList* Pattemp = frontPat;
      frontPat = frontPat->next;
      delete Pattemp;
    }
  }
  void addAppointment(Appointment a = Appointment())
  {
    linkedAppointment* newApp = new linkedAppointment;
    newApp->value = a;
    newApp->next = frontApp;
    frontApp = newApp;
    AppSize++;
  }
  void addPatient(int patientID = 0)
  {
    PatientList* newPat = new PatientList;
    newPat->patientID = patientID;
    newPat->next = frontPat;
    frontPat = newPat;
    PatSize++;
  }
  void removeAppointment(bool& found, Appointment a = Appointment())
  {
    linkedAppointment* previous = nullptr;
    int counter = 0;
    while (counter != AppSize && !found)
    {
      linkedAppointment* Apptemp = frontApp;
      if (Apptemp->value == a)
      {
        found = true;
        if (previous)
        {
          previous->next = Apptemp->next;
        }
        else
        {
          frontApp = Apptemp->next;
        }
        delete Apptemp;
      }
      previous = Apptemp;
      Apptemp = Apptemp->next;
      counter++;
    }
  }
  void removePatient(bool& found, int patientID = 0)
  {
    PatientList* previous = nullptr;
    int counter = 0;
    while (counter != PatSize && !found);
    {
      PatientList* Pattemp = frontPat;
      if (Pattemp->patientID == patientID)
      {
        found = true;
        if (previous)
        {
          previous->next = Pattemp->next;
        }
        else
        {
          frontPat = Pattemp->next;
        }
        delete Pattemp;
      }
      previous = Pattemp;
      Pattemp = Pattemp->next;
      counter++;
    }
  }
  std::queue<int> getpatientIDList()
  {
    std::queue<Appointment> temp;
    PatientList* Pattemp = frontPat;
    int counter = 0;
    while (counter != PatSize)
    {
      temp.push(Pattemp->patientID);
      Pattemp = Pattemp->next;
      counter++;
    }
  }
  std::queue<Appointment> getAppointmentList()
  {
    std::queue<Appointment> temp;
    linkedAppointment* Apptemp = frontApp;
    int counter = 0;
    while (counter != AppSize)
    {
      temp.push(Apptemp->value);
      Apptemp = Apptemp->next;
      counter++;
    }
  }
};