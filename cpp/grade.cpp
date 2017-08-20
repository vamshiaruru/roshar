#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main(){
    double midterm, final;
    cin >> midterm >> final;
    int count = 0;
    double sum = 0;
    double x;
    while (cin >> x){
        ++count;
        sum += x;
    }
    streamsize prec = cout.precision(); //to determine the current precision the stream is using (we use ionmanip because it defines streamsize type)
    //ios header lets us setprecision
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << setprecision(prec) << endl;
    return 0;
}