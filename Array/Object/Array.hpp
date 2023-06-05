#ifndef class_Array_hpp
  #define class_Array_hpp
  #include <memory> // std::make_shared()
  #include <iostream> // std::ostream
  #include <sstream> // std::ostringstream
  #include <string> // std::string
  #include <cstring> // std::memcpy
  /**
   * @brief array of reconfigurable size
   * @tparam Type array item type
   * @tparam Size array length type
   */
  template <typename Type, typename Size>
    class Array
      {
        private:
        protected:
          /** @brief array starting point pointer */
          Type* _start;
          // std::shared_ptr<Type[]> _start;
          /** @brief array length */
          Size _length;
        public:
          /** @brief Construct a new Array object (not configured) */
          /** @brief Construct a new Array object (Configure a group of spaces, initialized as an array) */
          Array();
          /**
           * @brief Construct a new Array object (Configure a set of spaces, uninitialized)
           * @param length configured length
           */
          Array(Size length);
          /**
           * @brief Construct a new Array object (Configure a group of spaces, initialized as an array)
           * @param _start referenced starting point pointer
           * @param length referenced length
           * @param createCopy Create copy. If true, configure a new set of spaces and initialize them with the reference content, otherwise use the reference spaces and content directly.
           */
          Array(Type* _start, Size length, bool createCopy=true);
          /**
           * @brief Construct a new Array object (Configure a group of spaces, initialized as an array)
           * @param other referenced object
           * @param createCopy Create copy. If true, configure a new set of spaces and initialize them with the reference content, otherwise use the reference spaces and content directly.
           */
          Array(Array<Type, Size>& other, bool createCopy=true);
          /** @brief Destroy the Array object */
          ~Array();
          /**
           * @brief Reconfigure a group of spaces, initialized as an array
           * @param _start referenced starting point pointer
           * @param length referenced length
           * @param createCopy Create copy. If true, configure a new set of spaces and initialize them with the reference content, otherwise use the reference spaces and content directly.
           * @return Array<Type, Size>& *this
           */
          inline Array<Type, Size>& set_Array(Type* _start, Size length, bool createCopy=true);
          /**
           * @brief Reconfigure a group of spaces, initialized as an array
           * @param other referenced object
           * @param createCopy Create copy. If true, configure a new set of spaces and initialize them with the reference content, otherwise use the reference spaces and content directly.
           * @return Array<Type, Size>& *this
           */
          inline Array<Type, Size>& set_Array(Array<Type, Size>& other, bool createCopy=true);
          /**
           * @brief Get the Length object
           * @return const Size Length
           */
          inline Size get_Length();
          /**
           * @brief Set the Length object
           * @param length target size
           * @return Array<Type, Size>& *this
           */
          inline Array<Type, Size>& set_Length(Size length);
          /**
           * @brief Get the Length object
           * @return const Size Length
           */
          inline Size Length();
          /**
           * @brief Set and get the Length object
           * @param length target size
           * @return const Size Length
           */
          inline Size Length(Size length);
          /**
           * @brief Set the Item Content
           * @param index target index
           * @param data target data
           * @param reverse reverse index. If true, `_start+length-1-index`, otherwise `_start+index`
           * @return Type target item in array
           */
          inline Array<Type, Size>& set_ItemContent(Size index, Type data, bool reverse=false);
          /**
           * @brief Get the Item Content
           * @param index target index
           * @param reverse reverse index. If true, `_start+length-1-index`, otherwise `_start+index`
           * @return Type target item in array
           */
          inline Type get_ItemContent(Size index, bool reverse=false);
          /**
           * @brief Get the Item Address
           * @param index target index
           * @param reverse reverse index. If true, `_start+length-1-index`, otherwise `_start+index`
           * @return Type target item Address in array
           */
          inline Type* get_ItemAddress(Size index, bool reverse=false);
          Array<Type, Size> subArray(Size index, Size length, bool createCopy=true);
          Array<Type, Size> erase(Size index, Size length);
          Array<Type, Size> inserted(Size index, Type data);
          Array<Type, Size>& insert(Size index, Type data);
          Array<Type, Size>& replace(Size index, Size length, Type data);

          /**
           * @brief Get the Item Reference
           * @param index target index
           * @return Type& target item Reference in array
           */
          inline Type& operator[](Size index);

          // template <typename DataType, typename SizeType> friend inline std::ostream& operator<< (std::ostream& outStream, Array<DataType, SizeType>& array);
          std::string to_string() const;
          // const char* to_cstring() const;
      };
#endif //class_Array_hpp
#ifndef class_Array_cpp
  #include "Array.cpp"
#endif //class_Array_cpp