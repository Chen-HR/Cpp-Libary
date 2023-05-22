#ifndef class_Array_hpp
  #define class_Array_hpp
  /**
   * @brief 
   * 
   * @tparam DataType 
   * @tparam LengthType 
   */
  template <typename DataType, typename LengthType>
    class Array
      {
        private:
        protected:
          DataType* DataPointer;
          LengthType DataLength;
        public:
          Array();
          Array(LengthType Length);
          DataType  setItem(LengthType Index, DataType Data);
          DataType  getItemContent(LengthType Index);
          DataType* getItemAddress(LengthType Index);
          DataType* operator[](LengthType Index);
          // DataType  operator[](LengthType Index);
          // DataType* operator()(LengthType Index);
      };
#endif //class_Array_hpp
#ifndef class_Array_cpp
  #include "Array.cpp"
#endif //class_Array_cpp