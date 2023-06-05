#ifndef class_Array_hpp
  #include "Array.hpp"
#endif //class_Array_cpp
#ifndef class_Array_cpp
  #define class_Array_cpp
  #include <memory> // std::make_shared()
  #include <iostream> // std::ostream
  #include <sstream> // std::ostringstream
  #include <string> // std::string
  #include <cstring> // std::memcpy
  #define std_memcpy(dest, src) std::memcpy(dest, src, sizeof(src))
  #define std_memcpy_length(dest, src, length) std::memcpy((dest), (src), sizeof(decltype((src)))*length)
  template <typename Type, typename Size> Array<Type, Size>::Array() 
    :_start{nullptr}, _length{0} 
    {}
  template <typename Type, typename Size> Array<Type, Size>::Array(Size length) 
    // :_start{new Type[length]}, _length{length} 
    // : _start{std::make_shared<Type[]>(length)}, _length{length}
    {
      // try
      //   {
      //     this->_start = new Type[length];
      //   }
      // catch(const std::exception& exception)
      //   {
      //     std::cerr << exception.what() << std::endl;
      //   }
      // this->_length = length;
      // std::clog<<"Construct a new Array object (Configure a set of spaces, uninitialized)"<<std::endl;
      this->_length = length;
      try 
        {
          this->_start = new Type[length]; // Runtime_Error
        } 
      catch (const std::bad_alloc& error) 
        {
          std::cerr << error.what() << std::endl;
          // Handle memory allocation failure
        }
    }
  template <typename Type, typename Size> Array<Type, Size>::Array(Array<Type, Size>& other, bool createCopy) 
    {
      this->set_Array(other, createCopy);
    }
  template <typename Type, typename Size> Array<Type, Size>::Array(Type* _start, Size length, bool createCopy) 
    {
      this->set_Array(_start, length, createCopy);
    }
  template <typename Type, typename Size> Array<Type, Size>::~Array() 
    {
      // // std::clog << "try: delete this->_start" << std::endl;
      // try
      //   {
      //     delete[] this->_start;
      //     // std::clog << "try: success" << std::endl;
      //   }
      // catch(const std::exception& exception)
      //   {
      //     // std::clog << "try: fail: "  << exception.what() << std::endl;
      //   }
    }
  template <typename Type, typename Size> inline Array<Type, Size>& Array<Type, Size>::set_Array(Array<Type, Size>& other, bool createCopy)
    {
      // std::clog<<"this->_length: "<<this->_length<<std::endl;
      this->_length = other._length;
      // std::clog<<"this->_length: "<<this->_length<<std::endl;
      // std::clog<<"this->_start: "<<this->_start<<std::endl;
      if (createCopy)
        {
          this->_start = new Type[other._length];
          // this->_start = std::make_shared<Type[]>(other._length);
          std_memcpy_length(this->_start, other._start, other._length);
        }
      else this->_start = other._start;
      // std::clog<<"this->_start: "<<this->_start<<std::endl;
      return *this;
    }
  template <typename Type, typename Size> inline Array<Type, Size>& Array<Type, Size>::set_Array(Type* start, Size length, bool createCopy)
    {
      // std::clog<<"this->_length: "<<this->_length<<std::endl;
      this->_length = length;
      // std::clog<<"this->_length: "<<this->_length<<std::endl;
      // std::clog<<"this->_start: "<<this->_start<<std::endl;
      if (createCopy)
        {
          this->_start = new Type[length];
          // this->_start = std::make_shared<Type[]>(length);
          std_memcpy_length(this->_start, start, length);
        }
      else this->_start = _start;
      // std::clog<<"this->_start: "<<this->_start<<std::endl;
      return *this;
    }
  template <typename Type, typename Size> inline Size Array<Type, Size>::get_Length()
    { return this->_length; }
  template <typename Type, typename Size> inline Array<Type, Size>& Array<Type, Size>::set_Length(Size length)
    {
      Array<Type, Size> tmp(length);
      std_memcpy_length(tmp._start, this->_start, ((this->_length<tmp._length)?(this->_length):(tmp._length)));
      // this->set_Array(tmp);
      try { delete[] this->_start; }
      catch(const std::exception& exception) {}
      this->set_Array(tmp);
      return *this;
    }
  template <typename Type, typename Size> inline Size Array<Type, Size>::Length()
    { return this->get_Length(); }
  template <typename Type, typename Size> inline Size Array<Type, Size>::Length(Size length)
    { return this->set_Length(length)._length; }
  template <typename Type, typename Size> inline Array<Type, Size>& Array<Type, Size>::set_ItemContent(Size index, Type data, bool reverse)
    {
      if (index < 0 || index >= this->_length) throw std::out_of_range("Index out of bounds");
      *(this->_start+index) = data;
      return *(this);
    }
  template <typename Type, typename Size> inline Type Array<Type, Size>::get_ItemContent (Size index, bool reverse)
    {
      if (index < 0 || index >= this->_length) throw std::out_of_range("Index out of bounds");
      return *(this->_start+index);
    }
  template <typename Type, typename Size> inline Type* Array<Type, Size>::get_ItemAddress (Size index, bool reverse)
    {
      if (index < 0 || index >= this->_length) throw std::out_of_range("Index out of bounds");
      return (this->_start+index);
    }
  template <typename Type, typename Size> Array<Type, Size> Array<Type, Size>::subArray(Size index, Size length, bool createCopy)
    {
      if (index < 0 || index+length >= this->_length) throw std::out_of_range("Index out of bounds");
      Array<Type, Size> tmp(length);
      if (createCopy) 
        std_memcpy_length(tmp._start, this->_start+index, length);
        // for (Size i=0; i<length; i++) *(tmp._start+i) = *(this->_start+index+i);
      else tmp._start = this->_start+index;
      return tmp;
    }
  template <typename Type, typename Size> Array<Type, Size> Array<Type, Size>::erase(Size index, Size length)
    {
      if (index < 0 || index+length >= this->_length) throw std::out_of_range("Index out of bounds");
      Array<Type, Size> tmp(this->_length-length);
      std_memcpy_length(tmp._start, this->_start, index);
      std_memcpy_length(tmp._start+index, this->_start+index+length, this->_length-index-length);
      return tmp;
    }
  // template <typename Type, typename Size> Array<Type, Size> Array<Type, Size>::inserted(Size index, Type data)
  //   {
  //     const Size length = 1;
  //     if (index < 0 || index > this->_length) throw std::out_of_range("Index out of bounds");
  //     Array<Type, Size> tmp(this->_length+length);
  //     if (index!=0) std_memcpy_length(tmp._start, this->_start, index);
  //     std_memcpy_length(tmp._start+index, &data, length);
  //     if (index!=this->_length) std_memcpy_length(tmp._start+index+length, this->_start+index, this->_length-index);
  //     return tmp;
  //   }

  template <typename Type, typename Size> inline Type& Array<Type, Size>::operator[] (Size index)
    {
      if (index < 0 || index >= this->_length) throw std::out_of_range("Index out of bounds");
      return *(this->_start+index);
    }
  
  // template <typename Type, typename Size> inline std::ostream& operator<< (std::ostream& outStream, Array<Type, Size>& array)
  //   {
  //     outStream<<"[";
  //     for (size_t i=0; i<array.Length(); outStream<<array[i++])
  //       if (i) outStream<<", ";
  //     outStream<<"]";
  //     return outStream;
  //   }
  template <typename Type, typename Size> inline std::string Array<Type, Size>::to_string () const 
    {
      std::ostringstream buffer; buffer.clear();
      try
        {
          buffer<<"[";
          // std::clog<<"[";
          for (size_t i=0; i<this->_length; i++) 
            {
              // std::clog<<buffer.str()<<std::endl;
              if (i!=0) buffer<<", "; // Runtime_Error
              // if (i!=0) std::clog<<", ";
              buffer<<*(this->_start+i);
              // std::clog<<*(this->_start+i);
            }
          buffer<<"]";
          // std::clog<<"]";
        }
      catch(const std::exception& exception) { std::cerr << "Exception occurred during stream insertion: " << exception.what() << std::endl; }
      return buffer.str();
    }
  // template <typename Type, typename Size> inline const char* Array<Type, Size>::to_cstring () const 
  //   {
  //     return this->to_string().c_str();
  //   }

#endif //class_Array_cpp