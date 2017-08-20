#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

int main(){
    int i;
    for(i = 0;i < 100; i++){
        cout << i << setw(50) << i*i << endl;
        // here setw(50) filled 50 blank characters
        // similarly setfill()
    }
    return 0;
}