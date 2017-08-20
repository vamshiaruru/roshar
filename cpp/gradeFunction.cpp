#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

double median(vector<double> vec){
    int size = vec.size();
    if(size == 0){
        throw domain_error("Empty vector");
        //domain_error is used to show that the function's arguments are outside the set of values the function can accept
    }
    mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}