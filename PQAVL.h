#if !defined (PQAVL_H)
#define PQAVL_H

#include "AVLTree.h"

template < class T >
class PQAVL
{
	private:
		
		//AVL object
		AVLTree<T>* avl;
		
		bool allow_duplicates;
		bool duplicates_on_left;
	
	public:
	
		//Constructor/Deconstructor
		PQAVL(bool min_or_max, int(*compare_item)(T* item_1, T* item_2), int (*compare_key)(String* key, T* item));
		~PQAVL();
		
		//for convenience
		bool isEmpty();
		int size();
		
		/*
			Post: Inserts an item into the tree
		*/
		void insert(T* item);
		
		/*
			Post: Removes an Item from the tree
		*/
		T* remove();
};

template < class T >
PQAVL<T>::PQAVL(bool min_or_max, int(*compare_item)(T* item_1, T* item_2),int (*compare_key) (String* key, T* item))
{
	   allow_duplicates = true;
	   duplicates_on_left = true;
	   avl = new AVLTree<T>(min_or_max, allow_duplicates, duplicates_on_left, compare_item, compare_key);
}

template < class T >
PQAVL<T>::~PQAVL()
{
	avl->makeEmpty();
	delete avl;
}

template < class T >
bool PQAVL<T>::isEmpty()
{
	return (size() == 0);
}

template < class T >
int PQAVL<T>::size()
{
	return avl->size();
}

template < class T >
void PQAVL<T>::insert(T* item)
{
	avl->insert(item);
}

template < class T >
T* PQAVL<T>::remove()
{
	return avl->remove();
}

#endif