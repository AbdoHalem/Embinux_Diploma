#include "Integer.hpp"

/* Operators Overloading */
/* Copy Assignment Operator */
Integer& Integer::operator= (const Integer &other) {
    if(other.ptr_){
        this->ptr_ = new int(*(other.ptr_));
    }
    else{
        this->ptr_ = other.ptr_;
    }
    return *this;
}

/* Move Assignment Operator */
Integer& Integer::operator= (Integer &&other) noexcept {
    if(other.ptr_){
        this->ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    return *this;
}

/* Addition Operator */
Integer Integer::operator+ (const Integer &other) const {
    if(other.ptr_ && this->ptr_){
        return Integer(new int(*(this->ptr_) + *(other.ptr_)));
    }
    else if(other.ptr_){
        return Integer(new int(*(other.ptr_)));
    }
    else if(this->ptr_){
        return Integer(new int(*(this->ptr_)));
    }
    else{
        cout << "Both are null pointers!" << endl;
        return Integer(nullptr);
    }
}
// obj + 5
Integer Integer::operator+ (int value) const {
    if(this->ptr_){
        return Integer(new int(*(this->ptr_) + value));
    }
    else{       // this->ptr_ == nullptr
        return Integer(new int(value));
    }
}
// 5 + obj
Integer operator+ (int value, const Integer &other) {
    if(other.ptr_){
        return Integer(new int(*(other.ptr_) + value));
    }
    else{       // this->ptr_ == nullptr
        return Integer(new int(value));
    }
}

/* Subtraction Operator */
Integer  Integer::operator- (const Integer &other) const {
    if(other.ptr_ && this->ptr_){
        return Integer(new int(*(this->ptr_) - *(other.ptr_)));
    }
    else if(other.ptr_){
        return Integer(new int(0 - *(other.ptr_)));
    }
    else if(this->ptr_){
        return Integer(new int(*(this->ptr_)));
    }
    else{
        cout << "Both are null pointers!" << endl;
        return Integer(nullptr);
    }
}
// obj - 5
Integer Integer::operator- (int value) const {
    if(this->ptr_){
        return Integer(new int(*(this->ptr_) - value));
    }
    else{       // this->ptr_ == nullptr
        return Integer(new int(-value));
    }
}     
// 5 - obj
Integer operator- (int value, const Integer &integer) {
    if(integer.ptr_){
        return Integer(new int(*(integer.ptr_) - value));
    }
    else{       // this->ptr_ == nullptr
        return Integer(new int(-value));
    }
} 

/* Multiplication Operator */
Integer Integer::operator* (const Integer &other) const {
    if(other.ptr_ && this->ptr_){
        return Integer(new int(*(this->ptr_) * *(other.ptr_)));
    }
    else{
        cout << "Multiblying null pointer !" << endl;
        return Integer(nullptr);
    }
}

// obj * 5
Integer Integer::operator* (int value) const {
    if(this->ptr_){
        return Integer(new int(*(this->ptr_) * value));
    }
    else{       // this->ptr_ == nullptr
        return Integer(new int(0));
    }
}     
// 5 * obj
Integer operator* (int value, const Integer &integer) {
    if(integer.ptr_){
        return Integer(new int(*(integer.ptr_) * value));
    }
    else{       // this->ptr_ == nullptr
        return Integer(new int(0));
    }
}

/* Pre-increment Operator */
Integer& Integer::operator++ (){
    if(this->ptr_){
        ++(*(this->ptr_));
    }
    return *this;
}

/* Post-increment Operator */
Integer Integer::operator++ (int){
    if(this->ptr_){
        Integer temp = *this;
        ++(*(this->ptr_));
        return temp;
    }
    return *this;
}

/* Pre-decrement Operator */
Integer& Integer::operator-- (){
    if(this->ptr_){
        --(*(this->ptr_));
    }
    return *this;
}

/* Post-decrement Operator */
Integer Integer::operator-- (int){
    if(this->ptr_){
        Integer temp = *this;
        --(*(this->ptr_));
        return temp;
    }
    return *this;
}

/* Smaller-than Operator */
bool Integer::operator< (const Integer &other) const {
    if(this->ptr_ && other.ptr_){
        return (*(this->ptr_) < *(other.ptr_));
    }
    else if (this->ptr_){return false;}
    else if (other.ptr_){return true;}
    else{return false;}
}
/* Bigger-than Operator */
bool Integer::operator> (const Integer &other) const {
    if(this->ptr_ && other.ptr_){
        return (*(this->ptr_) > *(other.ptr_));
    }
    else if (this->ptr_){return true;}
    else if (other.ptr_){return false;}
    else{return false;}
}

/* Non-equality Operator */
bool Integer::operator!= (const Integer &other) const {
    if(this->ptr_ && other.ptr_){
        return (*(this->ptr_) != *(other.ptr_));
    }
    else if (this->ptr_ || other.ptr_){return true;}
    else{return false;}
}

/* Extraction Operator */
std::istream& operator>> (std::istream &input, const Integer &integer) {
    if(integer.ptr_){
        input >> *(integer.ptr_);
    }
    return input;
}

/* Insertion Operator */
std::ostream& operator<< (std::ostream &output, const Integer &integer) {
    if(integer.ptr_){
        output << *(integer.ptr_);
    }else{output << "nullptr";}
    return output;
}