#include "isExist.h"


#include "string"
#include "iostream"
int isExist(adressbooks * adbs, string name)
{
	for (int i = 0; i < adbs->P_Size; i++)
	{
		if (adbs->MaxPerson[i].P_Name == name)
		{
			return i; // get the location of the name
		}
	}
	return -1;
}


