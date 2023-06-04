// #include <algorithm>
#include "Random.hpp"
// #include "Log.hpp"

#define for_index(count) for(int index = 0; index < count; index++)

int main()
  {
    // unsigned long long longlong=0x7094B05E800C69B1ull; // 0x7094b05e800c69b1 -> 12160434660043930778
    // Log::log("Random::reorganization_byte()", Random::reorganization_byte(longlong, Random::defult_reorganization_byte));

    // unsigned long long longlong=0x7094B05E800C69B1ull; // 0x7094b05e800c69b1 -> 6786566242029590767
    // Log::log("Random::reorganization_bytes()", Random::reorganization_bytes(longlong));

    // unsigned long long longlong=0x7094B05E800C69B1ull; // 0x7094b05e800c69b1 -> 0xa8c28ae502443c9a -> 0xe54d8f05e0e2a67f
    // Log::log_data_number<unsigned long long int, 16, 0, '0', 16>("", "Random::reorganization_byte(Random::reorganization_bytes())", Random::reorganization(longlong));
    
    for_index(20) Log::log("Random::seed_generator()", Random::seed_generator<unsigned int>());

    // Random::set();
    // for_index(20) Log::log("Random::get", Random::get());
    // for_index(20) Log::log("Random::get_Integer()", Random::get_Integer());
    // for_index(20) Log::log("Random::get_Integer(10)", Random::get_Integer(10));
    // for_index(20) Log::log("Random::get_Integer(10, 20)", Random::get_Integer(10, 20));

    // Random::Std_cstdlib_15 engine_15(0);
    // for_index(20) Log::log("Random::Std_cstdlib_15::get", engine_15.get());
    // for_index(20) Log::log("Random::Std_cstdlib_15::get_Integer()", engine_15.get_Integer());
    // for_index(20) Log::log("Random::Std_cstdlib_15::get_Integer(10)", engine_15.get_Integer(10));
    // for_index(20) Log::log("Random::Std_cstdlib_15::get_Integer(10, 20)", engine_15.get_Integer(10, 20));
    // for_index(20) Log::log("Random::Std_cstdlib_15()", engine_15());

    // Random::Std_cstdlib_15 engine_15_1(0), engine_15_2(0);
    // Log::log("engine_15_1", engine_15_1());
    // Log::log("engine_15_1", engine_15_1());
    // Log::log("engine_15_2", engine_15_2());
    // Log::log("engine_15_2", engine_15_2());

    // Random::Std_mt19937_32 engine_32;
    // for_index(20) Log::log("Random::Std_mt19937_32::get", engine_32.get());
    // for_index(20) Log::log("Random::Std_mt19937_32::get_Integer()", engine_32.get_Integer());
    // for_index(20) Log::log("Random::Std_mt19937_32::get_Integer(10)", engine_32.get_Integer(10));
    // for_index(20) Log::log("Random::Std_mt19937_32::get_Integer(10, 20)", engine_32.get_Integer(10, 20));
    // for_index(20) Log::log("Random::Std_mt19937_32()", engine_32());
    
    // Random::Std_mt19937_32 engine_32_1(0), engine_32_2(0);
    // Log::log("engine_32_1", engine_32_1());
    // Log::log("engine_32_1", engine_32_1());
    // Log::log("engine_32_2", engine_32_2());
    // Log::log("engine_32_2", engine_32_2());

    // Random::Std_mt19937_64 engine_64;
    // for_index(20) Log::log("Random::Std_mt19937_64::get", engine_64.get());
    // for_index(20) Log::log("Random::Std_mt19937_64::get_Integer()", engine_64.get_Integer());
    // for_index(20) Log::log("Random::Std_mt19937_64::get_Integer(10)", engine_64.get_Integer(10));
    // for_index(20) Log::log("Random::Std_mt19937_64::get_Integer(10, 20)", engine_64.get_Integer(10, 20));
    // for_index(20) Log::log("Random::Std_mt19937_64()", engine_64());

    // Random::Std_mt19937_64 engine_64_1(0), engine_64_2(0);
    // Log::log("engine_64_1", engine_64_1());
    // Log::log("engine_64_1", engine_64_1());
    // Log::log("engine_64_2", engine_64_2());
    // Log::log("engine_64_2", engine_64_2());

    // uncreate about `std::random_device`
    // std::random_device random_device;
    // for_index(20) Log::log("std::random_device{}()", std::random_device{}());
    // for_index(20) Log::log("std::random_device()", random_device());
  }