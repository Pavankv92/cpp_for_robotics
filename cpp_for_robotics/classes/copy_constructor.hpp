//
//  copy_constructor.hpp
//  cpp_for_robotics
//
//  Created by Pavan K V on 01.12.23.
//

#ifndef copy_constructor_hpp
#define copy_constructor_hpp

#include <stdio.h>

class Integer{
private:
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer &obj); // custom copy constructor
    int getValue() const;
    void setValue(int &value);
    ~Integer();
    
    

};

#endif /* copy_constructor_hpp */
