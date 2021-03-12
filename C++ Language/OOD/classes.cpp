#include <iostream> // using IO functions
#include <string>   // using string
using namespace std;

class Circle
{
private:
    double radius; // Data member (Variable)
    string color;  // Data member (Variable)

public:
    // Constructor with default values for data members
    Circle(double r = 1.0, string c = "red")
    {
        radius = r;
        color = c;
    }
    // (or) constructor's member intializer list
    //Circle(double r = 1.0, string c = "res") : radius(r), color(c) {}
    // destructor manully created here actually it will be
    // automatically by system itself as ~Circle(){}which does nothing
    //Destructor is called implicitly when an object is destroyed.
    ~Circle() { cout << "destroyed" << endl; }
    //default copy constructor would look like
    Circle(const Circle &rhs)
    {
        this->radius = rhs.radius; // u can change data member using this
        //this pointer or u can use data member directly in class
        // but sometimes to avoid same name confusions this usage preferred
        color = rhs.color;
    }
    //default copy assignement operator would look like
    Circle &operator=(const Circle &rhs)
    {
        this->radius = rhs.radius;
        this->color = rhs.color;
        return *this;
    }
    double getRadius() const
    { // Member function (Getter)
        //Step 2: radius = 0;
        return radius;
    }

    string getColor()
    { // Member function (Getter)
        return color;
    }

    double getArea()
    { // Member function
        return radius * radius * 3.1416;
    }
    // Setter for color
    void setColor(string c)
    {
        // this is a pointer created automatically to this object class
        this->color = c;
    }

    // Setter for radius
    void setRadius(double r)
    {
        radius = r;
    }
}; // need to end the class declaration with a semi-colon

// Test driver function
int main()
{
    // Construct a Circle instance
    Circle c1(1.2, "blue");
    cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()
         << " Color=" << c1.getColor() << endl;
    // changing the radius and color instantiated
    c1.setColor("changedblue");
    c1.setRadius(2.1);
    cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()
         << " Color=" << c1.getColor() << endl;
    // Construct another Circle instance
    Circle c2(3.4); // default color
    cout << "Radius=" << c2.getRadius() << " Area=" << c2.getArea()
         << " Color=" << c2.getColor() << endl;

    // Construct a Circle instance using default no-arg constructor
    Circle c3; // default radius and color
    cout << "Radius=" << c3.getRadius() << " Area=" << c3.getArea()
         << " Color=" << c3.getColor() << endl;
    // seting a color
    c3.setColor("white");
    cout << "Radius=" << c3.getRadius() << " Area=" << c3.getArea()
         << " Color=" << c3.getColor() << endl;
    // invoking copy constructor
    Circle c5(c1);
    cout << "Radius=" << c5.getRadius() << " Area=" << c5.getArea()
         << " Color=" << c5.getColor() << endl;
    Circle c6(5.6, "orange"), c7;
    cout << "Radius=" << c6.getRadius() << " Area=" << c6.getArea()
         << " Color=" << c6.getColor() << endl;
    // Radius=5.6 Area=98.5206 Color=orange
    cout << "Radius=" << c7.getRadius() << " Area=" << c7.getArea()
         << " Color=" << c7.getColor() << endl;
    // Radius=1 Area=3.1416 Color=red (default constructor)

    c7 = c6; // memberwise copy assignment ,invokes copy assignment operator
    cout << "Radius=" << c7.getRadius() << " Area=" << c7.getArea()
         << " Color=" << c7.getColor() << endl;
    // Radius=5.6 Area=98.5206 Color=orange
    Circle c8 = c6; // Invoke the copy constructor, NOT copy assignment operator
                    // Same as Circle c8(c6)
    return 0;
}
/*
Radius=1.2 Area=4.5239 Color=blue
Radius=2.1 Area=13.8545 Color=changedblue
Radius=3.4 Area=36.3169 Color=red
Radius=1 Area=3.1416 Color=red
Radius=1 Area=3.1416 Color=white
// step 2:After intialising radius in the getter function radius as 0
Radius=0 Area=0 Color=blue
Radius=0 Area=0 Color=changedblue
Radius=0 Area=0 Color=red
Radius=0 Area=0 Color=red
Radius=0 Area=0 Color=white
// so use const getter function so that nothing can be intialised 
in getters
//after c5 is getting copy of c3
Radius=1.2 Area=4.5239 Color=blue
Radius=2.1 Area=13.8545 Color=changedblue
Radius=3.4 Area=36.3169 Color=red
Radius=1 Area=3.1416 Color=red
Radius=1 Area=3.1416 Color=white
Radius=1 Area=3.1416 Color=white
// when copy constructor written by user without any member intializers
// usually copy constructor will be written automatically by compiler
Radius=1.2 Area=4.5239 Color=blue
Radius=2.1 Area=13.8545 Color=changedblue
Radius=3.4 Area=36.3169 Color=red
Radius=1 Area=3.1416 Color=red
Radius=1 Area=3.1416 Color=white
Radius=6.95286e-310 Area=0 Color= // garbage values are copied
// after manually writting destructor with prints destroyed when a 
object is destroyed:
Radius=1.2 Area=4.5239 Color=blue
Radius=2.1 Area=13.8545 Color=changedblue
Radius=3.4 Area=36.3169 Color=red
Radius=1 Area=3.1416 Color=red
Radius=1 Area=3.1416 Color=white
Radius=2.1 Area=13.8545 Color=changedblue
destroyed
destroyed
destroyed
destroyed
*/