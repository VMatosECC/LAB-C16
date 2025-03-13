// Chp16-Templates-Triplets.cpp 
#include <iostream>
using namespace std;

// Generic class template for a Triplet
template <typename T1, typename T2, typename T3>
class Triplet {
private:
    T1 first;
    T2 second;
    T3 third;

public:
    // Constructor
    Triplet(T1 a, T2 b, T3 c) : first(a), second(b), third(c) {}

    // Getters
    T1 getFirst()  const { return first; }
    T2 getSecond() const { return second; }
    T3 getThird()  const { return third; }

    // Setters
    void setFirst(T1 value)  { first = value; }
    void setSecond(T2 value) { second = value; }
    void setThird(T3 value)  { third = value; }

    // Display function
    void display() const {
        cout << "(" << first << ", " << second << ", " << third << ")" << endl;
    }
};

int main() {
    
    Triplet<string, int, double> item("apple", 12, 5.99);   //name-qty-price
    item.display();

    Triplet<int, int, int> point3d(1, 3, 5);                //point in the 3d space
    point3d.display();

    Triplet<int, int, int> rgb(0,0,255);                    //color
    rgb.display();

    //ECC geo-coordinates latitude, longitude, altitude
    Triplet<double, double, int> geoECC(33.885881,-118.330457,53); 
    geoECC.display();
}

