#include <iostream>
#include <string>
bool isItzero(int num){
    return num==0;
}
int main(){
    using namespace std;
    string name;
    getline(cin, name); // to let spaces in the input. cin breaks when spaces are present.
    const string greeting = "* Hello " + name +" *";
    const string spaces(greeting.size(), ' ');
    const string second = "*" + spaces + "*";
    const string first(second.size(), '*');
    cout << first <<endl;
    cout << second << endl;
    cout << greeting << endl;
    cout << second << endl;
    cout << first << endl;
    cout << isItzero(0);
    return 0;
}
