#include <iostream>

using namespace std;

bool check(int input){
    if (input % 1234 == 0 || input % 123456 == 0 || input %1234567 == 0){
        return true;
    }
    for(int i = 1; i < 11; i++){
        if(input > 123456*i){
            if((input - 123456*i)%1234 == 0){
                return true;
            }
        }
        else{
            break;
        }
    }
    return false;
}

int main()
{
    int input;
    cin >> input;
    if (input % 1234 == 0 || input % 123456 == 0 || input %1234567 == 0){
        cout << "YES" << endl;
        return 0;
    }
    if(input < 1234 || (input > 1234 && input < 123456)){
        cout << "NO" << endl;
        return 0;
    }
    if(input > 123456 && input < 1234567){
        if(check(input)){
            cout << "YES" << endl;
            return 0;
        }else{
            cout << "NO" << endl; 
            return 0;
        }
    }
    else{
        for(int i = 1; i < 1000; i++){
            if(input > 1234567*i){
                if(check(input - 1234567*i)){
                    cout << "YES" << endl;
                    return 0;
                }
                else{
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else{
                break;
            }
        }
        cout << "NO" << endl;
        return 0;
    }
}
