
#ifndef Stream_In_hpp
  #define Stream_In_hpp
  namespace Stream_In
    {
      template <typename ReturnType> ReturnType stdcin();

      template <typename ReturnType> ReturnType stdcin(const char*, bool (*isInvalidValue)(ReturnType), char*, std::size_t);
    }
#endif //Stream_In_hpp
#ifndef Stream_In_cpp
  #include "Stream_In.cpp"
#endif //Stream_In_cpp