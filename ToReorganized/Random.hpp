#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#ifndef Random_hpp
  #define Random_hpp
  namespace Random
    {
      size_t defult_reorganization_byte[8] = {4, 0, 6, 2, 7, 3, 5, 1};
      template <class Type, size_t* reorganization=defult_reorganization_byte> Type reorganization_byte(Type data);
      template <class Type> Type reorganization_bytes(Type data);
      template <class Type> inline Type reorganization(Type data);
      template <class RandomValue> inline RandomValue seed_generator();

      inline void set();
      inline void set(unsigned long long int seed);
      inline size_t get_Integer();
      inline size_t get_Integer(unsigned long long int max);
      inline size_t get_Integer(unsigned long long int min, unsigned long long int max);
      inline double get();
      /**
       * @brief using `std::srand()` and `std::rand()`
       */
      class Std_cstdlib
        {
          private:
          protected:
          public:
            static const unsigned int min = 0;
            static const unsigned int max = RAND_MAX;
            Std_cstdlib();
            Std_cstdlib(unsigned int seed);
            Std_cstdlib set();
            Std_cstdlib set(unsigned int seed);
            static unsigned int get_Integer();
            static unsigned int get_Integer(unsigned int max);
            static unsigned int get_Integer(unsigned int min, unsigned int max);
            static double get();
            inline unsigned int operator()();
        };
      typedef Std_cstdlib Std_cstdlib_15;
      
      template <class RandomEngine = std::mt19937, class RandomValue = std::mt19937::result_type> class Std_mt19937
        {
          private:
          protected:
          public:
            RandomEngine main;
            RandomValue min;
            RandomValue max;
            Std_mt19937();
            Std_mt19937(RandomValue seed);
            Std_mt19937<RandomEngine, RandomValue> set();
            Std_mt19937<RandomEngine, RandomValue> set(RandomValue seed);
            RandomValue get_Integer();
            RandomValue get_Integer(RandomValue max);
            RandomValue get_Integer(RandomValue min, RandomValue max);
            double get();
            inline RandomValue operator()();
        };
      typedef Std_mt19937<std::mt19937, unsigned int> Std_mt19937_32;
      typedef Std_mt19937<std::mt19937_64, unsigned long long> Std_mt19937_64;

      typedef Std_cstdlib_15 Random_15;
      typedef Std_mt19937_32 Random_32;
      typedef Std_mt19937_64 Random_64;
    }
#endif //Random_hpp
#ifndef Random_cpp
  #include "Random.cpp"
#endif //Random_cpp