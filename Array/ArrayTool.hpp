#ifndef namespace_ArrayTool_hpp
  #define namespace_ArrayTool_hpp
  namespace ArrayTool
    {
      template <typename DataType, typename LengthType> inline void swap(DataType* data, LengthType first, LengthType second);

      namespace Find
        {
          template <typename DataType> bool Ascend (DataType first, DataType second);
          template <typename DataType> bool Descend(DataType first, DataType second);

          template <typename DataType> inline DataType Base(DataType First, DataType Second, bool (*order)(DataType first, DataType second));
          template <typename DataType> inline DataType Base(DataType First, DataType Second, DataType Third, bool (*order)(DataType first, DataType second));
          template <typename DataType> inline DataType Base(DataType First, DataType Second, DataType Third, DataType Fourth, bool (*order)(DataType first, DataType second));

          template <typename DataType, typename LengthType, typename ArgumentType> 
            DataType Index_Rule(DataType* data, LengthType length, ArgumentType argument, bool (*rule)(DataType datum, ArgumentType argument));
          template <typename DataType, typename LengthType> 
            inline DataType Index_Value(DataType* data, LengthType length, DataType argument);
          
          template <typename DataType, typename LengthType>
            DataType Value_Iteration(DataType* data, LengthType length, bool (*order)(DataType first, DataType second));
          template <typename DataType, typename LengthType>
            DataType Value_Recursion_2Parts(DataType* data, LengthType length, bool (*order)(DataType first, DataType second));
          template <typename DataType, typename LengthType>
            DataType Value_Recursion_3Parts(DataType* data, LengthType length, bool (*order)(DataType first, DataType second));
          
          namespace Min
            {
              template <typename Data> inline Data Min(Data First, Data Second);
              template <typename Data> inline Data Min(Data First, Data Second, Data Third);
              template <typename Data> inline Data Min(Data First, Data Second, Data Third, Data Fourth);
              template <typename DataType, typename LengthType> inline LengthType Index_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline LengthType Index_Recursion(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline DataType Value_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline DataType Value_Recursion_2Parts(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline DataType Value_Recursion_3Parts(DataType* data, LengthType length);
            }
          namespace Max
            {
              template <typename Data> inline Data Max(Data First, Data Second);
              template <typename Data> inline Data Max(Data First, Data Second, Data Third);
              template <typename Data> inline Data Max(Data First, Data Second, Data Third, Data Fourth);
              template <typename DataType, typename LengthType> inline LengthType Index_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline LengthType Index_Recursion(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline DataType Value_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline DataType Value_Recursion_2Parts(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> inline DataType Value_Recursion_3Parts(DataType* data, LengthType length);
            }
        }
      namespace Sort
        {
          template <typename DataType, typename LengthType> DataType* ShiftMinToFirst_Step_Iteration(DataType* data, LengthType length);
          template <typename DataType, typename LengthType> DataType* ShiftMinToFirst_Step_Recursion(DataType* data, LengthType length);
          template <typename DataType, typename LengthType> DataType* ShiftMinToFirst_Jump_Iteration(DataType* data, LengthType length);
          template <typename DataType, typename LengthType> DataType* ShiftMinToFirst_Jump_Recursion(DataType* data, LengthType length);
          template <typename DataType, typename LengthType> DataType* SwapMinToFirst_Iteration(DataType* data, LengthType length);
          template <typename DataType, typename LengthType> DataType* SwapMinToFirst_Recursion(DataType* data, LengthType length);
          namespace Bubble
            {
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration_Recursion(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Recursion_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Recursion_Recursion(DataType* data, LengthType length);
            }
          namespace Insertion
            {
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration_Recursion(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Recursion_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Recursion_Recursion(DataType* data, LengthType length);
            }
          namespace Selection
            {
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Iteration_Recursion(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Recursion_Iteration(DataType* data, LengthType length);
              template <typename DataType, typename LengthType> DataType* Ascend_Recursion_Recursion(DataType* data, LengthType length);
            }
        }
    }
#endif //namespace_ArrayTool_hpp
#ifndef namespace_ArrayTool_cpp
  #include "ArrayTool.cpp"
#endif //namespace_ArrayTool_cpp