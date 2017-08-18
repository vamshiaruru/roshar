#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    using namespace std;
    string x;
    vector<string> v;
    while(cin >> x && x != "9999"){
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        cout << v[i] + "  ";
    }
    cout << endl;
    int size = v.size();
    int i=0;
    int count = 0;
    while(i < size){
        count = 0;
        string curr = v[i];
        cout << curr + " :";
        if(i == size -1){
            cout << count << endl;
            break;
        }
        string next = v[i+1];
        int j = 0;
        for(j = i; j < size; j++){
            next = v[j];
            if(curr == next){
                count++;
            }
            else{
                break;
            }
        }
        i = i + j;
        cout << count << endl;
    }
    return 0;
}