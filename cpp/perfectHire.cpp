#include <iostream>
using namespace std;

int main()
{
    int n, p, x;
    cin >> n >> p >> x;
    int A[n];
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    int maxScore = 0;
    int maxId = 0;
    for(int i = 1; i <= n; i++){
        cout << p ;
        int score = p * A[i];
        // cout << "\t" << score << "\t" << maxScore << "\t" << A[i] << endl;
        if(score > maxScore){
            maxScore = score;
            maxId = i;
        }
        p = p - x;
        cout << p << endl;
    }
    cout << maxId << endl;
    return 0;
}
