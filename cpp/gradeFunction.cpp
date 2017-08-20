#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

double grade(double midterm, double final, double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double median(vector<double> vec){
    //for potentially large vectors this function is ineffeicient because entire
    //vector needs to be coopied into function argument. But this way of passing
    //the vector is necessary. If we use a reference, then the original vector
    //is changed, which is undesirable. If we use a const reference, then we 
    //can't sort it to get the median.
    int size = vec.size();
    if(size == 0){
        throw domain_error("Empty vector");
        //domain_error is used to show that the function's arguments are outside
        //the set of values the function can accept
    }
    sort(vec.begin(), vec.end());
    int mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}
istream& read_hw(istream& in, vector<double>& hw){
    //'&' mans we are passing a reference instead of the entire variable. Here
    //we need to pass a reference so that we can chane the vector.
    //Note that while passing non const references, we must always pass an 
    //Ivalue. Ivalue is a reference to a NONTEMPORARY object.
    if(in){
        double x;
        in.clear();
        //in.clear() removes the previous student's entries and resets any error
        //messages so that more input can be given. When clear is used with 
        //vectors, the vector is cleared and made empty
        while(in >> x){
            hw.push_back(x);
        }
        in.clear();
        //we have to do in.clear() again because we have to clear the stream of
        //any error states so that it can accept more input.
    }
    return in;
}
double grade(double midterm, double final, const vector<double>& hw){
    // very like Java, it isn't a problem if many functions have same names as 
    // long as they have different parameters, i.e function overloading is 
    // supported in C++
    if(hw.size() == 0){
        throw domain_error("Empty vector");
    }
    return grade(midterm, final, median(hw));
}
int main(){
    double midterm, final;
    cin >> midterm >> final;
    vector<double> homework;
    vector<double>& hw = homework;
    const vector<double>& chw = homework;
    read_hw(cin, hw);
    try{
        double final_grade = grade(midterm, final, chw);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3) << final_grade <<
                setprecision(prec) << endl;
    }
    catch(domain_error){
        cout << "You haven't entered any homework grades" << endl;
    }
    return 0;
}