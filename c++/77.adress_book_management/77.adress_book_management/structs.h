#ifndef __STRUCTS_H__
#define __STRUCTS_H__
#include "structs.h"
#include "iostream"
using namespace std;
#include "string"

#define MAX 1000

struct Person{

	string P_Name;
	int P_sex = 0;
	int P_age;
	string P_number;
	string P_address;
};

struct adressbooks
{
	struct Person MaxPerson[MAX];
	int P_Size = 0;  // this should be initialized
};
//struct Person;
//struct adressbooks adbs;

#endif