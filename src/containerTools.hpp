#ifndef CONTAINERTOOLS_HPP
#define CONTAINERTOOLS_HPP

#include <iostream> //used for printing
#include <random>   //used to generate random numbers for array
#include <array>

class ContainerTools{
public:
    template<typename T>
    static void print(const T & Storage){
        std::cout << "[ ";
        for(auto & x : Storage){
            std::cout << x << " ";
        }
        std::cout << "]\n";
    }

    template<typename T, size_t N>
    static std::array<T, N> randomArray(const T & min, const T & max){
        
        std::array<T, N> ar;
        T diff = max - min;

        for(auto & i : ar){
            T r = (T(rand())%diff)+min;
        }
        return ar;
    }
    template<typename T, size_t N>
    static std::array<float, N> randomArray(const float & min, const float & max){
        
        std::array<float, N> ar;
        float diff = max - min;

        for(auto & i : ar){
            i = fmod(float(rand()),diff)+min;
        }
        return ar;
    }
};

#endif