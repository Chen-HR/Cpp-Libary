#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include "Process.hpp"

#ifndef Random_hpp
  #include "Random.hpp"
#endif //Random_hpp
#ifndef Random_cpp
  #define Random_cpp
  template <class Type, size_t* reorganization=Random::defult_reorganization_byte> Type Random::reorganization_byte(Type data) 
    {
      Type result=0;
      for (size_t byte = 0; byte < sizeof(data); byte++)
        {
          for (size_t index = 0; index < 8; index++)
            {
              result |= /*index_reshift*/(/*index_reshift*/(/*get_bit*/(data&/*index_shift*/(/*byte_shift*/(1ull<<(byte*8))<<index))>>index)<<*(reorganization+index));
            }
          // Log::log_data_number<unsigned long long int, 16, 0, '0', 16>("Process::reorganization_byte","data  ",data  );
          // Log::log_data_number<unsigned long long int, 16, 0, ' ', 16>("Process::reorganization_byte","result",result);
        }
      return result;
    }
  template <class Type> Type Random::reorganization_bytes(Type data)
    {
      Type result=0xffull&data;
      // Log::log_data_number<unsigned long long int, 16, 0, '0', 16>("Process::reorganization_bytes","data  ",data  );
      // Log::log_data_number<unsigned long long int, 16, 0, ' ', 16>("Process::reorganization_bytes","result",result);
      for (size_t byte = 1; byte < sizeof(data); byte++)
        {
          result |= (((data  &(0xffull<<(byte*8)))>>(byte*8))^((result&(0xffull<<((byte-1)*8)))>>((byte-1)*8)))<<(byte*8);
          // Log::log_data_number<unsigned long long int, 16, 0, '0', 16>("Process::reorganization_bytes","data  ",data  );
          // Log::log_data_number<unsigned long long int, 16, 0, ' ', 16>("Process::reorganization_bytes","result",result);
        }
      result ^= result>>((sizeof(data)-1)*8);
      // Log::log_data_number<unsigned long long int, 16, 0, '0', 16>("Process::reorganization_bytes","data  ",data  );
      // Log::log_data_number<unsigned long long int, 16, 0, ' ', 16>("Process::reorganization_bytes","result",result);
      return result;
    }
  template <class Type> inline Type Random::reorganization(Type data)
    {
      return Random::reorganization_bytes(Random::reorganization_byte(data));
    }
  /**
   * @brief Mixing `std::random_device{}()` with the current millisecond time `std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch() ).count()`
   */
  template <class SeedType> inline SeedType Random::seed_generator()
    {
      SeedType resule = 0;

      auto device = std::random_device{}();
      for(size_t index = 0; index <= sizeof(device)/sizeof(resule); index++, device>>=8*sizeof(resule)) 
        resule^=Random::reorganization(device);

      auto time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      for(size_t index = 0; index <= sizeof(time)/sizeof(resule); index++, time>>=8*sizeof(resule)) 
        resule^=Random::reorganization(time);

      return resule;
    }

  inline void Random::set()
    { std::srand(Random::seed_generator<unsigned int>()); }
  inline void Random::set(unsigned long long int seed)
    { std::srand(seed); }
  inline size_t Random::get_Integer()
    { return std::rand(); }
  inline size_t Random::get_Integer(unsigned long long int max)
    { return (std::rand())%(max); }
  inline size_t Random::get_Integer(unsigned long long int min, unsigned long long int max)
    { return ((std::rand())%(max-min))+min; }
  inline double Random::get()
    { return (double)(std::rand())/RAND_MAX; }
  
  Random::Std_cstdlib::Std_cstdlib()
    { std::srand(Random::seed_generator<unsigned int>()); }
  Random::Std_cstdlib::Std_cstdlib(unsigned int seed)
    { std::srand(seed); }
  Random::Std_cstdlib Random::Std_cstdlib::set()
    { std::srand(Random::seed_generator<unsigned int>()); return *this; }
  Random::Std_cstdlib Random::Std_cstdlib::set(unsigned int seed)
    { std::srand(seed); return *this; }
  unsigned int Random::Std_cstdlib::get_Integer()
    { return std::rand(); }
  unsigned int Random::Std_cstdlib::get_Integer(unsigned int max)
    { return (std::rand())%(max); }
  unsigned int Random::Std_cstdlib::get_Integer(unsigned int min, unsigned int max)
    { return ((std::rand())%(max-min))+min; }
  double Random::Std_cstdlib::get()
    { return (double)(std::rand())/RAND_MAX; }
  inline unsigned int Random::Std_cstdlib::operator()()
    { return this->get_Integer(); }

  template <class RandomEngine, class RandomValue> 
    Random::Std_mt19937<RandomEngine, RandomValue>::Std_mt19937()
      : main(Random::seed_generator<unsigned int>())
      { this->min=this->main.min(); this->max=this->main.max(); }
  template <class RandomEngine, class RandomValue> 
    Random::Std_mt19937<RandomEngine, RandomValue>::Std_mt19937(RandomValue seed)
      : main(seed)
      { this->min=this->main.min(); this->max=this->main.max(); }
  template <class RandomEngine, class RandomValue> 
    RandomValue Random::Std_mt19937<RandomEngine, RandomValue>::get_Integer() 
      { return this->main(); }
  template <class RandomEngine, class RandomValue> 
    RandomValue Random::Std_mt19937<RandomEngine, RandomValue>::get_Integer(RandomValue max) 
      { return (this->main())%(max); }
  template <class RandomEngine, class RandomValue> 
    RandomValue Random::Std_mt19937<RandomEngine, RandomValue>::get_Integer(RandomValue min, RandomValue max) 
      { return ((this->main())%(max-min))+min; }
  template <class RandomEngine, class RandomValue> 
    double Random::Std_mt19937<RandomEngine, RandomValue>::get() 
      { return (double)(this->main())/(this->main.max()); }
  template <class RandomEngine, class RandomValue> 
    inline RandomValue Random::Std_mt19937<RandomEngine, RandomValue>::operator()()
      { return this->get_Integer(); }
#endif //Random_cpp