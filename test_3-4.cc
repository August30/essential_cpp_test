#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

class even_elem 
{
public:
    bool operator()(int elem)
    {
        return elem % 2 == 0 ? true : false;
    }
};

int main()
{
    vector<int> input;
    istream_iterator<int> in(cin), eos;

    cout<< "11111111111"<< endl;

    copy(in, eos, back_inserter(input));

    cout << "222222" << endl;
    vector<int>::iterator division = stable_partition(input.begin(), input.end(), even_elem());

    ofstream even_file("even.txt"), odd_file("odd.txt");

    ostream_iterator<int> even_iter(even_file, " "), odd_iter(odd_file, "\n");

    copy(input.begin(), division, even_iter);
    copy(division, input.end(), odd_iter);
    
    return 0;
}