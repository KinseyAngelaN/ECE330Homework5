// Fig. 8.13: fig08_13.cpp
// Selection sort with pass-by-reference. This program puts values into an 
// array, sorts them into ascending order and prints the resulting array.
#include <iostream> 
#include <iomanip>
using namespace std;
template <class T>
void selectionSort( int * const, const int ); // prototype
template <class T>
void swap( int * const, int * const ); // prototype

int main()
{
   const int arraySize = 10;
   const int a[ arraySize ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
   const float b[arraySize] = {52.29, 30.721, 61.96, 29.2, 19.44, 96.19, 57.35, 94.43, 86.24, 88.72};

   cout << "Data items in original order (integer array)\n";

   for ( int i = 0; i < arraySize; ++i )
      cout << setw( 4 ) << a[ i ];

   selectionSort(a, arraySize); // sort the array

   cout << "\nData items in ascending order (integer array)\n";

   for ( int j = 0; j < arraySize; ++j )
      cout << setw( 4 ) << a[ j ];

   cout << endl;

   cout << "Data items in original order (float array)\n";

   for ( int i = 0; i < arraySize; ++i )
      cout << setw( 4 ) << b[ i ];

   selectionSort(b, arraySize); // sort the array

   cout << "\nData items in ascending order (float array)\n";

   for ( int j = 0; j < arraySize; ++j )
      cout << setw( 4 ) << b[ j ];

   cout << endl;
} // end main

// function to sort an array

template <class T>
void selectionSort( T * const array, const int size )
{
   int smallest; // index of smallest element

   // loop over size - 1 elements
   for ( int i = 0; i < size - 1; ++i )
   {
      smallest = i; // first index of remaining array

      // loop to find index of smallest element
      for ( int index = i + 1; index < size; ++index )

         if ( array[ index ] < array[ smallest ] )
            smallest = index;

      swap( &array[ i ], &array[ smallest ] );
   } // end if
} // end function selectionSort

// swap values at memory locations to which
// element1Ptr and element2Ptr point
template <class T>
void swap( T * const element1Ptr, T * const element2Ptr )
{
   T hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
} // end function swap

