/*
    1. If a calss doesnt have a default constructor, compiler creates one for us. But when you implement a parameterzied constructor, then compiler wont create default constructor anymore.
    2. You can request compiler to create defualt implementations of certain fucntions with a keyword = default  
    3. You can use this keyword only on those fucntions that can be synthesized by the compiler --> Destructors, copy construtors,  copy assignment operators etc 
    4. Keyword delete forces the compiler not to create any default implementations of the fucntions
    5. "delete" can be used on regular functions as well. --> Many applications/use cases
*/

class Integer{
private:
    int value_;
public:
    // default constructor
    /*
     Integer(){
        value_ = 0;
    }*/
    Integer() = default;   // default constructor
    Integer(int value){
        value_ = value;
    }
    // copy construtors by default
    // Integer(const Integer &) = default;
    Integer(const Integer &) = delete; // forces the compiler not to create
    void setValue(int value){
        value_ = value;
    }
    void setValue(float) = delete ; // forcing use not to pass float value

};

int main(){
    Integer i1;
    Integer i2(i1); // complains as there is no copy construtors, you cannot copy a object in this case.
    i1.setValue(10);
    i1.setValue(5.0); // forcing user not to pass float value
    return 0;
}