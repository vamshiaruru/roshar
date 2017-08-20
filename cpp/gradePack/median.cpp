//source file for median funciton
#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

double median(vector<double> vec){
    int size = vec.size();
    if(size == 0){
        throw domain_error("Empty vector");
    }
    sort(vec.begin(), vec.end());
    int mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}