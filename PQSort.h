#if !defined (PQSORT_H)
#define PQSORT_H

#include "PQAVL.h"

template < class T >
class PQSort
{
	private:
	
		/*
			Pre: N/A
			Post: Sorts the array
		*/
		static void _pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item));
		
	public:
		
		/*
			Pre:  The array needs more that one element
			Post: A sorted array is returned
		*/
		static T** pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item));
};

template < class T >
void PQSort<T>::_pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item))
{
	PQAVL<T>* pq_avl = new PQAVL<T>(min_or_max, compare_item, compare_key);
	
	for(int i = 0; i < num_items; i++)
	{
		T* itm = items[i];
		pq_avl->insert(itm);
	}
	
	int pq_size = pq_avl->size();
	
	for(int i = 0; i < pq_size; i++)
	{
		items[i] = pq_avl->remove();
	}
}

template < class T >
T** PQSort<T>::pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two),int (*compare_key) (String* key, T* item) )
{
	T** new_sorted = new T*[num_items];
	
	for(int i = 0; i < num_items; i++)
	{
		new_sorted[i] = items[i];
	}
	
	_pqSort(new_sorted, num_items, min_or_max, compare_item, compare_key);
	
	return new_sorted;
	
}
#endif