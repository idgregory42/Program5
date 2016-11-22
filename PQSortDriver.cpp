#if !defined (NULL)
#define NULL 0
#endif

#include "PQSort.h"

#include "2110/CSC2110/CD.h"
using CSC2110::CD;
#include "2110/CSC2110/Text.h"
using CSC2110::String;
#include "2110/CSC2110/ListArray.h"
using CSC2110::ListArray;
#include "2110/CSC2110/ListArrayIterator.h"
using CSC2110::ListArrayIterator;

void removeCDS(ListArray<CD>* list);

int main()
{
	ListArray<CD>* cds = CD::readCDs("cds.txt");
	bool min = true;
	
	int size = cds->size();
	String* s = s->i_to_a(size);
	s->displayString();
	
	CD** cd_array = new CD*[size];
	
	
	ListArrayIterator<CD>* iter = cds->iterator();
	int count = 0;
	while(iter->hasNext())
	{
		CD* cd = iter->next();
		cd_array[count] = cd;
		count++;
		//cd->displayCD();
	}
	delete iter;
	
	
	
	CD** cd_s = PQSort<CD>::pqSort(cd_array, size, min, &CD::compare_items, &CD::compare_keys);
	String* _min = new String("\n\nMin : \n\n");
	_min->displayString();
	for(int i = 0; i < 5; i++)
	{
		CD* cd = cd_s[i];
		cd->displayCD();
	}
	
	min = false;
	cd_s = PQSort<CD>::pqSort(cd_array, size, min, &CD::compare_items, &CD::compare_keys);
	
	String* _max = new String("\n\nNow max : \n\n");
	_max->displayString();
	
	for(int i = 0; i < 5; i++)
	{
		CD* cd = cd_s[i];
		cd->displayCD();
	}
	
	removeCDS(cds);
	
	delete cds;
	delete[] cd_array;
	delete[] cd_s;
	delete s;
	delete cd_array;
	delete cd_s;
	delete _max;
	delete _min;
	return 0;
}

void removeCDS(ListArray<CD>* list)
{
	ListArrayIterator<CD>* iter = list->iterator();
	while(iter->hasNext())
	{
		CD* c = iter->next();
		delete c;
		c = NULL;
	}
	delete iter;
}