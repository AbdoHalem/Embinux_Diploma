#include "Integer.hpp"

int main(){
    // Test Parameterized Constructor
    cout << "Test Parameterized Constructor" << endl;
    Integer obj1(new int(5));
    cout << "obj1: " << obj1.Get_Value() << endl;
    // Test Default Constructor
    Integer obj2;
    // Test Copy Assignment operator
    cout << "Test Copy Assignment operator" << endl;
    obj2 = obj1;
    cout << "obj2: " << obj2.Get_Value() << endl;
    // Test Copy Constructor and Addition operator
    cout << "Test Copy Constructor and Addition operator" << endl;
    Integer obj3 = obj1 + obj2;
    cout << "obj3: " << obj3.Get_Value() << endl;
    obj3 = obj2 + 2;
    cout << "obj3 + 2: " << obj3.Get_Value() << endl;
    obj3 = 5 + obj2;
    cout << "3 + obj3: " << obj3.Get_Value() << endl;
    // Test Move Constructor and Subtraction operator
    cout << "Test Move Constructor and Subtraction operator" << endl;
    Integer obj4 = std::move(obj1 - obj2);
    cout << "obj4: " << obj4.Get_Value() << endl;
    obj4 = obj3 - 5;
    cout << "obj4: " << obj4.Get_Value() << endl;
    obj4 = 5 - obj2;
    cout << "obj4: " << obj4.Get_Value() << endl;
    // Test Move Assignment operator and Multiplication operator
    cout << "Test Move Assignment operator and Multiplication operator" << endl;
    Integer obj5;
    obj5 = std::move(obj1 * obj2);
    cout << "obj5: " << obj5.Get_Value() << endl;
    obj5 = obj1 * 3;
    cout << "obj5: " << obj5.Get_Value() << endl;
    obj5 = 5 * obj1;
    cout << "obj5: " << obj5.Get_Value() << endl;
    // Test Pre-increment Operator
    cout << "Test Pre-increment Operator" << endl;
    cout << "obj5: " << (++obj5).Get_Value() << endl;
    // Test Post-increment Operator
    cout << "Test Post-increment Operator" << endl;
    cout << "obj5: " << (obj5++).Get_Value() << endl;
    cout << "obj5: " << (obj5).Get_Value() << endl;
    // Test Bigger-than Operator
    cout << "Test Bigger-than Operator" << endl;
    cout << (obj5 > obj4) << endl;
    // Test Smaller-than Operator
    cout << "Test Smaller-than Operator" << endl;
    cout << (obj5 < obj3) << endl;
    // Test Non-equality Operator
    cout << "Test Non-equality Operator" << endl;
    cout << (obj5 != obj2) << endl;
    // Test Insertion Operator
    cout << "Test Insertion Operator" << endl;
    cout << obj5 << endl;
    // Test Extraction Operator
    cout << "Test Extraction Operator" << endl;
    cout << "Enter integer for obj4: ";
    cin >> obj4;
    cout << obj4 << endl;
    return 0;
}