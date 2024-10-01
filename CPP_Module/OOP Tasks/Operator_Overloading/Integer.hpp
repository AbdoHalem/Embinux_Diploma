#ifndef __INTEGER__H__
#define __INTEGER__H__

#include <iostream>

using namespace std;

class Integer
{
private:
    int *ptr_;
public:
    /* Default Constructor */
    explicit Integer() : ptr_(nullptr) {}
    /* Parameterized Constructor */
    explicit Integer(int *p) : ptr_(p) {}
    /* Copy Constructor */
    Integer(const Integer& other) {
        if(other.ptr_){
            this->ptr_ = new int(*(other.ptr_));
        }
        else{
            this->ptr_ = nullptr;
        }
    }
    /* Move Constructor */
    Integer(Integer &&other) noexcept{
        if(other.ptr_){
            this->ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        else{   // other.ptr_ == nullptr
            this->ptr_ = nullptr;
        }
    }
    /* Destructor */
    ~Integer(){
        delete ptr_;     // Delete allocated memory
    }

    /* Setters */
    void Set_Value(int num){
        *(this->ptr_) = num;
    }
    /* Getters */
    int Get_Value() const {
        if(this->ptr_){
            return *(this->ptr_);
        }
        else{
            cout << "Null Pointer:  ";
            return (int)NULL;
        }
    }

    /* Operators Overloading */
    /* Copy Assignment Operator */
    Integer& operator= (const Integer &other);
    /* Move Assignment Operator */
    Integer& operator= (Integer &&other) noexcept ;
    /* Addition Operator */
    Integer operator+ (const Integer &other) const ;
    Integer operator+ (int value) const ;       // obj + 5
    friend Integer operator+ (int value, const Integer &other) ;       // 5 + obj
    /* Subtraction Operator */
    Integer operator- (const Integer &other) const ;
    Integer operator- (int value) const ;       // obj - 5
    friend Integer operator- (int value, const Integer &integer) ;     // 5 - obj
    /* Multiplication Operator */
    Integer operator* (const Integer &other) const ;
    Integer operator* (int value) const ;       // obj * 5
    friend Integer operator* (int value, const Integer &integer) ;     // 5 * obj
    /* Pre-increment Operator */
    Integer& operator++ () ;
    /* Post-increment Operator */
    Integer operator++ (int) ;
    /* Pre-decrement Operator */
    Integer& operator-- ();
    /* Post-decrement Operator */
    Integer operator-- (int);
    /* Smaller-than Operator */
    bool operator< (const Integer &other) const ;
    /* Bigger-than Operator */
    bool operator> (const Integer &other) const ;
    /* Non-equality Operator */
    bool operator!= (const Integer &other) const ;
    /* Insertion Operator */
    friend std::istream& operator>> (std::istream &input, const Integer &integer) ;
    /* Extraction Operator */
    friend std::ostream& operator<< (std::ostream &output, const Integer &integer) ;
};



#endif  //!__INTEGER__H__