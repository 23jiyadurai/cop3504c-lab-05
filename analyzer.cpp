#include "StringData.h"
#include <iostream>

int linearSearch(std::vector<std::string> data, std::string element);
int binarySearch(std::vector<std::string> data, std::string element);

int main(){
    std::vector<std::string> data = getStringData();
    long long begin = systemTimeNanoseconds();
    int index = linearSearch(data, "not_here");
    long long timeTaken = systemTimeNanoseconds() - begin;
    std::cout << "Linear search found \"not_here\" at index " << index << " in " << timeTaken << " nanoseconds." << std::endl;
    begin = systemTimeNanoseconds();
    index = binarySearch(data, "not_here");
    timeTaken = systemTimeNanoseconds() - begin;
    std::cout << "Binary search found \"not_here\" at index " << index << " in " << timeTaken << " nanoseconds." << std::endl;
    begin = systemTimeNanoseconds();
    index = linearSearch(data, "mzzzz");
    timeTaken = systemTimeNanoseconds() - begin;
    std::cout << "Linear search found \"mzzzz\" at index " << index << " in " << timeTaken << " nanoseconds." << std::endl;
    begin = systemTimeNanoseconds();
    index = binarySearch(data, "mzzzz");
    timeTaken = systemTimeNanoseconds() - begin;
    std::cout << "Binary search found \"mzzzz\" at index " << index << " in " << timeTaken << " nanoseconds." << std::endl;
    begin = systemTimeNanoseconds();
    index = linearSearch(data, "aaaaa");
    timeTaken = systemTimeNanoseconds() - begin;
    std::cout << "Linear search found \"aaaaa\" at index " << index << " in " << timeTaken << " nanoseconds." << std::endl;
    begin = systemTimeNanoseconds();
    index = binarySearch(data, "aaaaa");
    timeTaken = systemTimeNanoseconds() - begin;
    std::cout << "Binary search found \"aaaaa\" at index " << index << " in " << timeTaken << " nanoseconds." << std::endl;

}

int linearSearch(std::vector<std::string> data, std::string element){
    for (int i = 0; i < data.size(); i++){
        if (data[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> data, std::string element){
    int left = 0;
    int right = (int)data.size();
    while (left < right){
        int middle = (left + right) / 2;
        if (data[middle] < element){
            left = middle + 1;
        }
        else if (data[middle] > element){
            right = middle;
        }
        else {
            return middle;
        }
    }
    return -1;
}