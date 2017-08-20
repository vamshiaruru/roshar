#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    double midterm, final;
    cin >> midterm >> final;
    int count = 0;
    double sum = 0;
    double x;
    vector<double> homework;
    while (cin >> x){
        homework.push_back(x);
    }
    int size = homework.size();
    sort(homework.begin(), homework.end());
    int median = size % 2 == 0 ? (homework[size/2] + homework[(size/2)+1])/2 
                                 : homework[size/2];

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * 
            final + 0.4 * median<< setprecision(prec) << endl;
    return 0;
}