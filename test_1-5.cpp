#include <iostream>
#include <string>
using namespace std;

int main() {
    string user_name;

    cout << "please enter your name:";
    cin  >> user_name;

    switch (user_name.size())
    {
    case 0:
        cout << "ah, the user with no name."
             << "well, ok, hi , user with no name\n";
        break;
    case 1:
        cout << "a 1-character name? hmm, have you read kafka?:"
             << "hello," << user_name << endl;
             break;
    default:
        cout << "hello," << user_name
             << "--happy to make your acquaintance!\n";
        break;
    }
    return 0;
}