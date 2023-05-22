// #include <iostream>
#ifndef namespace_ArrayTool_hpp
  #include "ArrayTool.hpp"
#endif //namespace_ArrayTool_hpp
#ifndef namespace_ArrayTool_cpp
  #define namespace_ArrayTool_cpp
  // namespace ArrayTool::
  //   {
      template <typename DataType, typename LengthType> inline void ArrayTool::swap(DataType* data, LengthType first, LengthType second)
        { 
          DataType tmp = *(data+first);
          *(data+first) = *(data+second);
          *(data+second) = tmp;
        }

      // namespace Find::
      //   {
          template <typename DataType> bool ArrayTool::Find::Ascend (DataType first, DataType second) { return (first<second); }
          template <typename DataType> bool ArrayTool::Find::Descend(DataType first, DataType second) { return (first>second); }
          // (ArrayTool::Find::Ascend ) = [](DataType first, DataType second) -> bool { return (first<second); };
          // (ArrayTool::Find::Descend) = [](DataType first, DataType second) -> bool { return (first>second); };

          template <typename DataType> 
            inline DataType ArrayTool::Find::Base(DataType First, DataType Second, bool (*order)(DataType first, DataType second))
              { return (order(First, Second))?First:Second; }
          template <typename DataType> 
            inline DataType ArrayTool::Find::Base(DataType First, DataType Second, DataType Third, bool (*order)(DataType first, DataType second))
              { return ArrayTool::Find::Base(Find::Base(First, Second, order), Third, order); }
          template <typename DataType> 
            inline DataType ArrayTool::Find::Base(DataType First, DataType Second, DataType Third, DataType Fourth, bool (*order)(DataType first, DataType second))
              { return ArrayTool::Find::Base(Find::Base(First, Second, order), ArrayTool::Find::Base(Third, Fourth, order), order); }

          template <typename DataType, typename LengthType, typename ArgumentType> 
            DataType ArrayTool::Find::Index_Rule(DataType* data, LengthType length, ArgumentType argument, bool (*rule)(DataType datum, ArgumentType argument))
              { 
                LengthType index=0;
                for (; index<length; index++){
                  // std::cout<<rule(*(data+index), argument)<<", "<<(*rule)(*(data+index), argument)<<std::endl;
                  if (rule(*(data+index), argument)) 
                    break;
                }
                return index; 
              }
          template <typename DataType, typename LengthType> 
            inline DataType ArrayTool::Find::Index_Value(DataType* data, LengthType length, DataType argument)
              { 
                return ArrayTool::Find::Index_Rule<DataType, LengthType, DataType>(data, length, argument, [](DataType datum, DataType argument) -> bool {return datum==argument;}); 
              }
          
          template <typename DataType, typename LengthType>
            DataType ArrayTool::Find::Value_Iteration(DataType* data, LengthType length, bool (*order)(DataType first, DataType second))
            { 
              LengthType index=0;
              for (LengthType i=0; i<length; i++)
                index = ((order(*(data+index), *(data+i)))?(index):(i));
              return *(data+index); 
            }
          template <typename DataType, typename LengthType>
            DataType ArrayTool::Find::Value_Recursion_2Parts(DataType* data, LengthType length, bool (*order)(DataType first, DataType second))
              {
                if (length > 2) 
                  return Base
                    (
                      ArrayTool::Find::Value_Recursion_2Parts(data+0, length/2, order), 
                      ArrayTool::Find::Value_Recursion_2Parts(data+(length/2), (length/2)+((length%2>=1)?1:0), order), 
                      order
                    );
                else if (length == 2) 
                  return ArrayTool::Find::Base(*(data+0), *(data+1), order);
                return *(data+0);
              }
          template <typename DataType, typename LengthType>
            DataType ArrayTool::Find::Value_Recursion_3Parts(DataType* data, LengthType length, bool (*order)(DataType first, DataType second))
              {
                if (length > 3) 
                  return Base
                    (
                      ArrayTool::Find::Value_Recursion_3Parts(data+0, length/3, order), 
                      ArrayTool::Find::Value_Recursion_3Parts(data+(length*1/3), (length/3)+((length%3>=2)?1:0), order), 
                      ArrayTool::Find::Value_Recursion_3Parts(data+(length*2/3), (length/3)+((length%3>=1)?1:0), order), 
                      order
                    );
                else if (length == 3) 
                  return ArrayTool::Find::Base(*(data+0), *(data+1), *(data+2), order);
                else if (length == 2) 
                  return ArrayTool::Find::Base(*(data+0), *(data+1), order);
                return *(data+0);
              }
          

          // namespace Min::
          //   {
              template <typename Data> inline Data ArrayTool::Find::Min::Min(Data First, Data Second)
                { return ArrayTool::Find::Base(First, Second, ArrayTool::Find::Ascend); }
              template <typename Data> inline Data ArrayTool::Find::Min::Min(Data First, Data Second, Data Third)
                { return ArrayTool::Find::Base(First, Second, Third, ArrayTool::Find::Ascend); }
              template <typename Data> inline Data ArrayTool::Find::Min::Min(Data First, Data Second, Data Third, Data Fourth)
                { return ArrayTool::Find::Base(First, Second, Third, Fourth, ArrayTool::Find::Ascend); }
              template <typename DataType, typename LengthType> inline DataType ArrayTool::Find::Min::Value_Iteration(DataType* data, LengthType length)
                { return ArrayTool::Find::Value_Iteration(data, length, ArrayTool::Find::Ascend); }
              template <typename DataType, typename LengthType> inline DataType ArrayTool::Find::Min::Value_Recursion_2Parts(DataType* data, LengthType length)
                { return ArrayTool::Find::Value_Recursion_2Parts(data, length, ArrayTool::Find::Ascend); }
              template <typename DataType, typename LengthType> inline DataType ArrayTool::Find::Min::Value_Recursion_3Parts(DataType* data, LengthType length)
                { return ArrayTool::Find::Value_Recursion_3Parts(data, length, ArrayTool::Find::Ascend); }
              template <typename DataType, typename LengthType> inline LengthType ArrayTool::Find::Min::Index_Iteration(DataType* data, LengthType length)
                { return Index_Value(data, length, ArrayTool::Find::Min::Value_Iteration(data, length)); }
              template <typename DataType, typename LengthType> inline LengthType ArrayTool::Find::Min::Index_Recursion(DataType* data, LengthType length)
                { return Index_Value(data, length, ArrayTool::Find::Min::Value_Recursion_2Parts(data, length)); }
          //   }
          // namespace Max
          //   {
              template <typename Data> inline Data ArrayTool::Find::Max::Max(Data First, Data Second)
                { return ArrayTool::Find::Base(First, Second, ArrayTool::Find::Descend); }
              template <typename Data> inline Data ArrayTool::Find::Max::Max(Data First, Data Second, Data Third)
                { return ArrayTool::Find::Base(First, Second, Third, ArrayTool::Find::Descend); }
              template <typename Data> inline Data ArrayTool::Find::Max::Max(Data First, Data Second, Data Third, Data Fourth)
                { return ArrayTool::Find::Base(First, Second, Third, Fourth, ArrayTool::Find::Descend); }
              template <typename DataType, typename LengthType> inline DataType ArrayTool::Find::Max::Value_Iteration(DataType* data, LengthType length)
                { return ArrayTool::Find::Value_Iteration(data, length, ArrayTool::Find::Descend); }
              template <typename DataType, typename LengthType> inline DataType ArrayTool::Find::Max::Value_Recursion_2Parts(DataType* data, LengthType length)
                { return ArrayTool::Find::Value_Recursion_2Parts(data, length, ArrayTool::Find::Descend); }
              template <typename DataType, typename LengthType> inline DataType ArrayTool::Find::Max::Value_Recursion_3Parts(DataType* data, LengthType length)
                { return ArrayTool::Find::Value_Recursion_3Parts(data, length, ArrayTool::Find::Descend); }
              template <typename DataType, typename LengthType> inline LengthType ArrayTool::Find::Max::Index_Iteration(DataType* data, LengthType length)
                { return Find::Index_Value(data, length, ArrayTool::Find::Max::Value_Iteration(data, length)); }
              template <typename DataType, typename LengthType> inline LengthType ArrayTool::Find::Max::Index_Recursion(DataType* data, LengthType length)
                { return Find::Index_Value(data, length, ArrayTool::Find::Max::Value_Recursion_2Parts(data, length)); }
          //   }
      //   }
      // namespace Sort::
      //   {
          template <typename DataType, typename LengthType>
            DataType* ArrayTool::Sort::ShiftMinToFirst_Step_Iteration(DataType* data, LengthType length)
              {
                while (--length) if (ArrayTool::Find::Descend(*(data+length-1), *(data+length)))
                  ArrayTool::swap(data, length-1, length);
                return data;
              }
          template <typename DataType, typename LengthType>
            DataType* ArrayTool::Sort::ShiftMinToFirst_Step_Recursion(DataType* data, LengthType length)
              {
                // while (--length) if (ArrayTool::Find::Ascend(*(data+length-1), *(data+length)))
                if (ArrayTool::Find::Descend(*(data+length-2), *(data+length-1)))
                  ArrayTool::swap(data, length-2, length-1);
                if (length >2)
                  ArrayTool::Sort::ShiftMinToFirst_Step_Recursion(data, length-1);
                return data;
              }
          template <typename DataType, typename LengthType>
            DataType* ArrayTool::Sort::ShiftMinToFirst_Jump_Iteration(DataType* data, LengthType length)
              {
                LengthType index=ArrayTool::Find::Min::Index_Iteration(data, length);
                while (index--!=0) if (ArrayTool::Find::Descend(*(data+index), *(data+index+1)))
                  ArrayTool::swap(data, index, index+1);
                return data;
              }
          template <typename DataType, typename LengthType>
            DataType* ArrayTool::Sort::ShiftMinToFirst_Jump_Recursion(DataType* data, LengthType length)
              {
                ArrayTool::Sort::ShiftMinToFirst_Step_Recursion(data, ArrayTool::Find::Min::Index_Recursion(data, length)+1);
                return data;
              }
          template <typename DataType, typename LengthType>
            DataType* ArrayTool::Sort::SwapMinToFirst_Iteration(DataType* data, LengthType length)
              {
                ArrayTool::swap(data, ((LengthType)(0)), ArrayTool::Find::Min::Index_Iteration(data, length));
                return data;
              }
          template <typename DataType, typename LengthType>
            DataType* ArrayTool::Sort::SwapMinToFirst_Recursion(DataType* data, LengthType length)
              {
                ArrayTool::swap(data, ((LengthType)(0)), ArrayTool::Find::Min::Index_Recursion(data, length));
                return data;
              }
          // namespace Bubble::
          //   {
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Bubble::Ascend_Iteration(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      for (LengthType posi = 1; posi < length-round; posi++)
                        if (*(data+posi-1)>*(data+posi)) 
                          ArrayTool::swap(data, posi-1, posi);
                    return data;
                  }
              
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Bubble::Ascend_Iteration_Iteration(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      ArrayTool::Sort::ShiftMinToFirst_Step_Iteration(data+round, length-round);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Bubble::Ascend_Iteration_Recursion(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      ArrayTool::Sort::ShiftMinToFirst_Step_Recursion(data+round, length-round);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Bubble::Ascend_Recursion_Iteration(DataType* data, LengthType length)
                  {
                    ArrayTool::Sort::ShiftMinToFirst_Step_Iteration(data, length);
                    if (length >2)
                      ArrayTool::Sort::Bubble::Ascend_Recursion_Iteration(data+1, length-1);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Bubble::Ascend_Recursion_Recursion(DataType* data, LengthType length)
                  {
                    ArrayTool::Sort::ShiftMinToFirst_Step_Recursion(data, length);
                    if (length >2)
                      ArrayTool::Sort::Bubble::Ascend_Recursion_Recursion(data+1, length-1);
                    return data;
                  }
          //   }
          // namespace Insertion::
          //   {
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Insertion::Ascend_Iteration_Iteration(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      ArrayTool::Sort::ShiftMinToFirst_Jump_Iteration(data+round, length-round);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Insertion::Ascend_Iteration_Recursion(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      ArrayTool::Sort::ShiftMinToFirst_Jump_Recursion(data+round, length-round);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Insertion::Ascend_Recursion_Iteration(DataType* data, LengthType length)
                  {
                    ArrayTool::Sort::ShiftMinToFirst_Jump_Iteration(data, length);
                    if (length >2)
                      ArrayTool::Sort::Insertion::Ascend_Recursion_Iteration(data+1, length-1);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Insertion::Ascend_Recursion_Recursion(DataType* data, LengthType length)
                  {
                    ArrayTool::Sort::ShiftMinToFirst_Jump_Recursion(data, length);
                    if (length >2)
                      ArrayTool::Sort::Insertion::Ascend_Recursion_Recursion(data+1, length-1);
                    return data;
                  }
          //   }
          // namespace Selection::
          //   {
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Selection::Ascend_Iteration_Iteration(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      ArrayTool::Sort::SwapMinToFirst_Iteration(data+round, length-round);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Selection::Ascend_Iteration_Recursion(DataType* data, LengthType length)
                  {
                    for (LengthType round = 0; round < length-1; round++)
                      ArrayTool::Sort::SwapMinToFirst_Recursion(data+round, length-round);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Selection::Ascend_Recursion_Iteration(DataType* data, LengthType length)
                  {
                    ArrayTool::Sort::SwapMinToFirst_Iteration(data, length);
                    if (length >2)
                      ArrayTool::Sort::Selection::Ascend_Recursion_Iteration(data+1, length-1);
                    return data;
                  }
              template <typename DataType, typename LengthType> 
                DataType* ArrayTool::Sort::Selection::Ascend_Recursion_Recursion(DataType* data, LengthType length)
                  {
                    ArrayTool::Sort::SwapMinToFirst_Recursion(data, length);
                    if (length >2)
                      ArrayTool::Sort::Selection::Ascend_Recursion_Recursion(data+1, length-1);
                    return data;
                  }
          //   }
      //   }
  //   }
#endif //namespace_ArrayTool_cpp