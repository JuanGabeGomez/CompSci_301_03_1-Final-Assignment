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
  void setTime(int time = 0) { this->time = time; }
  void setPatient(Patient pat = Patient());
  void setDay(int day = 0);
  void setMonth(int month = 0);
  void setYear(int year = 0);
  int getTime();
  Patient getPatient();
  int getDay();
  int getMonth();
  int getYear();
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
public:
  Doctor(std::string name = std::string(), int age = 0, int height = 0, int weight = 0, int ID = 0);
  ~Doctor();
  void addAppointment();
  void addPatient(int patientID = 0);
  void removeAppointment();
  void removePatient(int patientID = 0);
  std::queue<int> getpatientIDList();
  std::queue<Appointment> getAppointmentList();
};