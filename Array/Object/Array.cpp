#ifndef class_Array_hpp
  #include "Array.hpp"
#endif //class_Array_cpp
#ifndef class_Array_cpp
  #define class_Array_cpp
  template <typename DataType, typename LengthType> Array<DataType, LengthType>::Array() :DataPointer{nullptr}, DataLength{0} {}
  template <typename DataType, typename LengthType> Array<DataType, LengthType>::Array(LengthType Length) :DataPointer{new DataType[Length]}, DataLength{Length} {}
  template <typename DataType, typename LengthType> DataType Array<DataType, LengthType>::setItem(LengthType Index, DataType Data)
    {
      *(this->DataPointer+Index) = Data;
      return Data;
    }
  template <typename DataType, typename LengthType> DataType Array<DataType, LengthType>::getItemContent (LengthType Index)
    {
      return *(this->DataPointer+Index);
    }
  template <typename DataType, typename LengthType> DataType* Array<DataType, LengthType>::getItemAddress (LengthType Index)
    {
      return (this->DataPointer+Index);
    }
  template <typename DataType, typename LengthType> DataType* Array<DataType, LengthType>::operator[] (LengthType index)
    {
      return (this->DataPointer+index);
    }
  // template <typename DataType, typename LengthType> DataType Array<DataType, LengthType>::operator[] (LengthType index)
  //   {
  //     return *(this->DataPointer+index);
  //   }
  // template <typename DataType, typename LengthType> DataType* Array<DataType, LengthType>::operator() (LengthType index)
  //   {
  //     return (this->DataPointer+index);
  //   }
#endif //class_Array_cpp