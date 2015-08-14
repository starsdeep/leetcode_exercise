#include <sstream>
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

// The full name is boost::lexical_cast. We can avoid writing boost:: if we
// declare that we're using the namespace boost (just like we do with the
// namespace std), but having excessive using namespace declarations is often
// frowned upon.

int BoostGetInteger() {
    while (true) {
        string line;
        getline(cin, line);

        // lexical_cast handles invalid input by throwing an exception. We can use
        // a try-catch statement in order to determine whether the input was valid.
        try {
            // When we perform the conversion from string to data type, we have to
            // explicitly specify the resulting data type as a template argument.
            // Otherwise, the compiler has no way of figuring out what type we were
            // expecting.
            return boost::lexical_cast<int>(line);
        } catch (boost::bad_lexical_cast& ex) {
            cout << "Invalid integer. Retry: ";
        }
    }
}

int main() {
    /*
    while (true) {
        
        cout << "How old are you? ";
        int age = BoostGetInteger();
        cout << "Well, I'M " << (age + 1) << "." << endl;
    }*/
    vector<int> v(10);
    for(int i : v){
        cout << i << ' ';
    }

    return 0;
}

