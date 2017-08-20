#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "student_info.h"

using namespace std;

double grade(const student_info& s){
    return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw){
    if(hw.size() == 0){
        throw domain_error("Empty vector");
    }
    return grade(midterm, final, median(hw));
}