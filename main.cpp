/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) make sure it compiles & runs without errors.
 
 7) use your knowledge of casting to remove any conversion warnings. 

 8) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!




*/

struct A {};

struct HeapA
{
    HeapA() : ptr(new A){}
    ~HeapA()
    {
        delete ptr;
    }
    A* ptr = nullptr;  
};

#include <iostream>

struct FloatType;
struct DoubleType;
struct IntType;

struct FloatType
{   
    FloatType(float passedValue) : value(new float(passedValue)){}
    ~FloatType()
    {
       delete value;  
    }
    float* value = nullptr;

    FloatType& add(float value);
    FloatType& subtract(float value);
    FloatType& multiply(float value);
    FloatType& divide(float value);

    FloatType& add(FloatType& ft);
    FloatType& subtract(FloatType& ft);
    FloatType& multiply(FloatType& ft);
    FloatType& divide(FloatType& ft);

    FloatType& add(DoubleType& dt);
    FloatType& subtract(DoubleType& dt);
    FloatType& multiply(DoubleType& dt);
    FloatType& divide(DoubleType& dt);

    FloatType& add(IntType& it);
    FloatType& subtract(IntType& it);
    FloatType& multiply(IntType& it);
    FloatType& divide(IntType& it);

};


FloatType& FloatType::add(float passedValue)
{
    *value += passedValue;
    return *this;
}

FloatType& FloatType::subtract(float passedValue)
{
    *value -= passedValue;
    return *this;
}

FloatType& FloatType::multiply(float passedValue)
{
    *value *= passedValue;
    return *this;
}

FloatType& FloatType::divide(float passedValue)
{
    if(passedValue == 0.0f)
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
    }
    *value /= passedValue;
    return *this;
}

struct DoubleType
{
    DoubleType(double passedValue) : value(new double(passedValue)){}
    ~DoubleType()
    {
        delete value;
    }
    double* value = nullptr;

    DoubleType& add(double passedValue);
    DoubleType& subtract(double passedValue);
    DoubleType& multiply(double passedValue);
    DoubleType& divide(double passedValue);

    DoubleType& add(FloatType& ft);
    DoubleType& subtract(FloatType& ft);
    DoubleType& multiply(FloatType& ft);
    DoubleType& divide(FloatType& ft);

    DoubleType& add(DoubleType& dt);
    DoubleType& subtract(DoubleType& dt);
    DoubleType& multiply(DoubleType& dt);
    DoubleType& divide(DoubleType& dt);

    DoubleType& add(IntType& it);
    DoubleType& subtract(IntType& it);
    DoubleType& multiply(IntType& it);
    DoubleType& divide(IntType& it);
};

DoubleType& DoubleType::add(double passedValue)
{
    *value += passedValue;
    return *this;
}
DoubleType& DoubleType::subtract(double passedValue)
{
    *value -= passedValue;
    return *this;
}
DoubleType& DoubleType::multiply(double passedValue)
{
    *value *= passedValue;
    return *this;
}
DoubleType& DoubleType::divide(double passedValue)
{
    if(passedValue == 0.000)
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
    }
    *value /= passedValue;
    return *this;
}

struct IntType
{
    IntType(int passedValue) : value(new int(passedValue)){}
    ~IntType()
    {
        delete value;
    }
    int* value = nullptr;

    IntType& add(int passedValue);
    IntType& subtract(int passedValue);
    IntType& multiply(int passedValue);
    IntType& divide(int passedValue);

    IntType& add(FloatType& ft);
    IntType& subtract(FloatType& ft);
    IntType& multiply(FloatType& ft);
    IntType& divide(FloatType& ft);

    IntType& add(DoubleType& dt);
    IntType& subtract(DoubleType& dt);
    IntType& multiply(DoubleType& dt);
    IntType& divide(DoubleType& dt);

    IntType& add(IntType& it);
    IntType& subtract(IntType& it);
    IntType& multiply(IntType& it);
    IntType& divide(IntType& it);

};

IntType& IntType::add(int passedValue)
{
    *value += passedValue;
    return *this;
}

IntType& IntType::subtract(int passedValue)
{
    *value -= passedValue;
    return *this;
}

IntType& IntType::multiply(int passedValue)
{
    *value *= passedValue;
    return *this;
}

IntType& IntType::divide(int passedValue)
{
    if(passedValue == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" <<  std::endl;
        return *this;
    }
    *value /= passedValue;
    return *this;
}

FloatType& FloatType::add(FloatType& ft)
{
    return add(*ft.value);
}

FloatType& FloatType::subtract(FloatType& ft)
{
    return subtract(*ft.value);
}

FloatType& FloatType::multiply(FloatType& ft)
{
    return multiply(*ft.value);
}

FloatType& FloatType::divide(FloatType& ft)
{
    return divide(*ft.value);
}

FloatType& FloatType::add(DoubleType& dt)
{
    return add(*dt.value);
}

FloatType& FloatType::subtract(DoubleType& dt)
{
    return subtract(*dt.value);
}

FloatType& FloatType::multiply(DoubleType& dt)
{
    return multiply(*dt.value);
}

FloatType& FloatType::divide(DoubleType& dt)
{
    return divide(*dt.value);
}

FloatType& FloatType::add(IntType& it)
{
    return add(*it.value);
}

FloatType& FloatType::subtract(IntType& it)
{
    return subtract(*it.value);
}

FloatType& FloatType::multiply(IntType& it)
{
    return multiply(*it.value);
}

FloatType& FloatType::divide(IntType& it)
{
    return divide(*it.value);
}

DoubleType& DoubleType::add(FloatType& ft)
{
    return add(*ft.value);
}

DoubleType& DoubleType::subtract(FloatType& ft)
{
    return subtract(*ft.value);
}

DoubleType& DoubleType::multiply(FloatType& ft)
{
    return multiply(*ft.value);
}

DoubleType& DoubleType::divide(FloatType& ft)
{
    return divide(*ft.value);
}

DoubleType& DoubleType::add(DoubleType& dt)
{
    return add(*dt.value);
}

DoubleType& DoubleType::subtract(DoubleType& dt)
{
    return subtract(*dt.value);
}

DoubleType& DoubleType::multiply(DoubleType& dt)
{
    return multiply(*dt.value);
}

DoubleType& DoubleType::divide(DoubleType& dt)
{
    return divide(*dt.value);
}

DoubleType& DoubleType::add(IntType& it)
{
    return add(*it.value);
}

DoubleType& DoubleType::subtract(IntType& it)
{
    return subtract(*it.value);
}

DoubleType& DoubleType::multiply(IntType& it)
{
    return multiply(*it.value);
}

DoubleType& DoubleType::divide(IntType& it)
{
    return divide(*it.value);
}

IntType& IntType::add(FloatType& ft)
{
    return add(*ft.value);
}

IntType& IntType::subtract(FloatType& ft)
{
    return subtract(*ft.value);
}

IntType& IntType::multiply(FloatType& ft)
{
    return multiply(*ft.value);
}

IntType& IntType::divide(FloatType& ft)
{
    return divide(*ft.value);
}

IntType& IntType::add(DoubleType& dt)
{
    return add(*dt.value);
}

IntType& IntType::subtract(DoubleType& dt)
{
    return subtract(*dt.value);
}

IntType& IntType::multiply(DoubleType& dt)
{
    return multiply(*dt.value);
}

IntType& IntType::divide(DoubleType& dt)
{
    return divide(*dt.value);
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.0f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (*(it.multiply(1000).divide(2).subtract(10).add(100)).value) << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (*dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}


