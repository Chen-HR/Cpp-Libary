#include <iostream>
#include <cstdlib>
#include <ctime>

template <class Type> inline void exchange(Type* a,Type* b)
  { Type c = *a; *a = *b, *b = c; }
/**
 * @brief array of pointer to use
 * @tparam Type array contain type
 * @tparam Size array length type
 */
template <class Type, class Size> struct Array
  { 
    Type* start; Size length; 
    Array(Size _length)
      {
        this->start = new Type[_length];
        this->length = _length;
      }
    Array(Type* _start, Size _length)
      {
        this->start = _start;
        this->length = _length;
      }
  };
template <class Type, class Size> std::ostream& operator<< (std::ostream& outStream, Array<Type, Size>& array)
  {
    outStream<<"[";
    for (size_t i=0; i<array.length; i++)
      {
        if (i) outStream<<", ";
        outStream<<*(array.start+i);
      }
    outStream<<"]";
    return outStream;
  }
/**
 * @brief Set random element to a array (Does not include setting random seed) (`std::srand(std::time(nullptr));`)
 * @tparam Type array contain type
 * @tparam Size array length type
 * @param array modified target
 */
template <class Type, class Size> inline void setRandomElement_Array(Array<Type, Size>& array)
  { for (size_t i=0; i<array.length; i++) *(array.start+i) = (std::rand()^std::rand())%100; }
/**
 * @brief Cut Partition
 * @tparam Type array contain type
 * @tparam Size array length type
 * @param array modified target
 * @param pivot initial pivot position
 * @return end pivot position
 */
template <class Type, class Size> Size split_Array(Array<Type, Size>& array, Size pivot=0)
  {
    // Normalized pivot position
    for (; pivot!=0; pivot--) exchange((array.start+pivot), (array.start+pivot-1));
    /**
     * @brief main action: Continue to move all values greater than the pivot value to the back, and finally move the pivot to the front of the first value greater than the pivot value
     * @param i The position retainer of pivot, and elements greater than this position are greater than pivot value
     * @param j Forward explorer, will exchange value with The position retainer of pivot when explored element is greater than pivot value
     */
    for (size_t i, j=i=array.length-1; j<=i && i*j!=0; )
      {
        // The explorer moves The position retainer of pivot forward
        for (; *(array.start+j)>*(array.start+pivot) && i==j && j>0; i=--j) ;
        // The explorer moves to a position greater than the pivot value
        for (; *(array.start+j)<=*(array.start+pivot) && j>0; j--) ;
        // Exchange the value of the explored position to The position retainer of pivot
        if (*(array.start+j)>*(array.start+pivot) && j>0) 
          exchange((array.start+j), (array.start+i)), i--, j--;
        // Explore to the end
        if (j==0) 
          exchange((array.start+pivot), (array.start+i)), pivot = i;
      }
    return pivot;
  }
/**
 * @brief quick sort a Array<Type, Size>
 * @tparam Type array contain type
 * @tparam Size array length type
 * @param array modified target
 */
template <class Type, class Size> void quickSort_Array(Array<Type, Size>& array)
  {
    // Get segmentation
    Size pivotIndex = split_Array(array);
    // If less than or equal to the pivot value the part length is greater than 1
    if (pivotIndex>1)
      {
        Array<Type, Size> front(array.start, pivotIndex);
        quickSort_Array(front);
      }
    // If the length of the part greater than the pivot value is greater than 1
    if (array.length-pivotIndex-1>1)
      {
        Array<Type, Size> rear(array.start+pivotIndex+1, array.length-pivotIndex-1);
        quickSort_Array(rear);
      }
  }
/**
 * @brief find order from a Array<Type, Size>
 * @tparam Type array contain type
 * @tparam Size array length type
 * @param array find target
 * @param order order of array
 * @return element values in the specified order
 */
template <class Type, class Size> Type findOrder_Array(Array<Type, Size>& array, Size order)
  {
    // Create a copy
    Array<Type, Size> _array(array.length);
    for (Size i=0; i<_array.length; i++) *(_array.start+i) = *(array.start+i);
    // Get segmentation
    Size pivotIndex = split_Array(_array);
    // If the target is before the split point
    if (pivotIndex>order)
      {
        Array<Type, Size> front(_array.start, pivotIndex);
        return findOrder_Array(front, order);
      }
    // If the target is after the split point
    else if (pivotIndex<order)
      {
        Array<Type, Size> rear(_array.start+pivotIndex+1, _array.length-pivotIndex-1);
        return findOrder_Array(rear, order-pivotIndex-1);
      }
    // If the split point is the target
    return *(_array.start+pivotIndex);
  }
/**
 * @brief find middle element from a Array<Type, Size>
 * @tparam Type array contain type
 * @tparam Size array length type
 * @param array find target
 * @return middle element values from array
 */
template <class Type, class Size> Type findMiddle_Array(Array<Type, Size>& array)
  {
    // Create a copy
    Array<Type, Size> _array(array.length);
    for (Size i=0; i<_array.length; i++) *(_array.start+i) = *(array.start+i);
    Size order = _array.length>>1;
    // Get segmentation
    Size pivotIndex = split_Array(_array);
    // If the target is before the split point
    if (pivotIndex>order)
      {
        Array<Type, Size> front(_array.start, pivotIndex);
        return findOrder_Array(front, order);
      }
    // If the target is after the split point
    else if (pivotIndex<order)
      {
        Array<Type, Size> rear(_array.start+pivotIndex+1, _array.length-pivotIndex-1);
        return findOrder_Array(rear, order-pivotIndex-1);
      }
    // If the split point is the target
    return *(_array.start+pivotIndex);
  }
