#include <cstdlib>
#include <ctime>

namespace Random
  {
    inline void setRandom(unsigned long long int seed=static_cast<unsigned long long int>(std::time(NULL)))
      {std::srand(seed);}
    inline size_t getRandom(unsigned long long int min, unsigned long long int max)
      {return ((std::rand())%(max-min))+min;}
  }