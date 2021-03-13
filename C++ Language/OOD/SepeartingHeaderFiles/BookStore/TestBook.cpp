#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    /* // Declare and construct an instance of Author
    Author peter("Peter Jones", "peter@somewhere.com", 'm');
    peter.print(); // Peter Jones (m) at peter@somewhere.com

    // Declare and construct an instance of Book
    Book cppDummy("C++ for Dummies", peter, 19.99);
    cppDummy.setQtyInStock(88);
    cppDummy.print();
    // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    cout << cppDummy.getQtyInStock() << endl;        // 88
    cout << cppDummy.getPrice() << endl;             // 19.99
    cout << cppDummy.getAuthor().getName() << endl;  // "Peter Jones"
    cout << cppDummy.getAuthor().getEmail() << endl; // "peter@somewhere.com"
    cout << cppDummy.getAuthorName() << endl;        // "Peter Jones"

    Book moreCpp("More C++ for Dummies", peter, -19.99);
    // price should be positive! Set to 0
    cout << moreCpp.getPrice() << endl; // 0*/
    // Declare and construct an instance of Author
    Author peter("Peter Jones", "peter@somewhere.com", 'm');
    peter.print(); // Peter Jones (m) at peter@somewhere.com

    // Declare and construct an instance of Book
    Book cppDummy("C++ for Dummies", peter, 19.99);
    cppDummy.print();
    // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    peter.setEmail("peter@xyz.com");
    peter.print(); // Peter Jones (m) at peter@xyz.com
    cppDummy.print();
    // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    cppDummy.getAuthor().setEmail("peter@abc.com");
    cppDummy.print();
    // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
}
/*
friday@ubuntu:~/Temp$ g++ -c Author.cpp
friday@ubuntu:~/Temp$ g++ -c Book.cpp
friday@ubuntu:~/Temp$ g++ TestBook.cpp Author.cpp Book.cpp
friday@ubuntu:~/Temp$ ./a.out
Peter Jones (m) at peter@somewhere.com
'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
88
19.99
Peter Jones
peter@somewhere.com
Peter Jones
price should be positive! Set to 0
0
//step 2:
friday@ubuntu:~/Temp$ g++ -c Author.cpp
friday@ubuntu:~/Temp$ g++ -c Book.cpp
friday@ubuntu:~/Temp$ g++ TestBook.cpp Author.cpp Book.cpp
friday@ubuntu:~/Temp$ ./a.out
Peter Jones (m) at peter@somewhere.com
'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
Peter Jones (m) at peter@xyz.com
'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
*/