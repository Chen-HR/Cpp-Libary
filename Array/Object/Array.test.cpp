#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

int main(int argc, const char** argv)
  {
    size_t Length=8;

    Array<size_t, size_t> array(Length);
    for (size_t i=0; i<Length; i++) array[i] = i;
    std::cout<<"array: "<<array.to_string()<<std::endl;

    Array<size_t, size_t> copy(array);
    std::cout<<"copy: "<<copy.to_string()<<std::endl;

    std::cout<<std::endl;
    
    std::cout<<"array: "<<array.Length(Length<<1)<<": "<<array.to_string()<<std::endl;
    std::cout<<"copy: "<<copy.Length(Length>>1)<<": "<<copy.to_string()<<std::endl;

    std::cout<<std::endl;

    Array<char, size_t> string_number(17); string_number[16] = '\0';
    for (size_t i=0; i<10; i++) string_number[   i] = '0'+i;
    for (size_t i=0; i< 6; i++) string_number[10+i] = 'a'+i;
    std::cout<<"string_number: "<<string_number.to_string()<<std::endl;
    std::cout<<"string_number: "<<string_number.get_ItemAddress(0)<<std::endl;

    Array<char, size_t> string_alpha(27); string_alpha[26] = '\0';
    for (size_t i=0; i<26; i++) string_alpha[i] = 'a'+i;
    std::cout<<"string_alpha: "<<string_alpha.to_string()<<std::endl;
    std::cout<<"string_alpha: "<<string_alpha.get_ItemAddress(0)<<std::endl;

    std::srand(std::time(nullptr));
    Array<char, size_t> string_random(65); string_random[64] = '\0';
    for (size_t i=0; i<64; i++) string_random[i] = string_number[std::rand()%16];
    std::cout<<"string_random: "<<string_random.to_string()<<std::endl;
    std::cout<<"string_random: "<<string_random.get_ItemAddress(0)<<std::endl;

    std::cout<<std::endl;

    std::cout<<"string_number: "<<string_number.to_string()<<std::endl;
    Array<char, size_t> string_number_subArray_0_16(string_number.subArray(0, 16)); // string_number_subArray_0_16.set_ItemContent(0, '\0', true);
    std::cout<<"string_number.subArray(0, 16): "<<string_number_subArray_0_16.get_ItemAddress(0)<<": "<<string_number_subArray_0_16.to_string()<<std::endl;
    Array<char, size_t> string_number_subArray_4__8(string_number.subArray(4,  8)); // string_number_subArray_4__8.set_ItemContent(0, '\0', true);
    std::cout<<"string_number.subArray(4,  8): "<<string_number_subArray_4__8.get_ItemAddress(0)<<": "<<string_number_subArray_4__8.to_string()<<std::endl;

    std::cout<<std::endl;

    std::cout<<"string_number: "<<string_number.to_string()<<std::endl;
    Array<char, size_t> string_number_erase_0_16(string_number.erase(0, 16));
    Array<char, size_t> string_number_erase_4__8(string_number.erase(4,  8));
    std::cout<<"string_number.erase(0, 16): "<<string_number_erase_0_16.to_string()<<std::endl;
    std::cout<<"string_number.erase(4,  8): "<<string_number_erase_4__8.to_string()<<std::endl;

    // std::cout<<std::endl;

    // std::cout<<"string_number: "<<string_number.to_string()<<std::endl;
    // std::cout<<"string_number.inserted( 0, 'z'): "<<string_number.inserted( 0, 'z').to_string()<<std::endl;
    // std::cout<<"string_number.inserted( 8, 'z'): "<<string_number.inserted( 8, 'z').to_string()<<std::endl;
    // std::cout<<"string_number.inserted(16, 'z'): "<<string_number.inserted(16, 'z').to_string()<<std::endl;
  }