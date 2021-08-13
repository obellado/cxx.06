#include <iostream>

class Base {
    public:
        virtual ~Base( void ){}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};


Base*   generate( void ){

    int r = rand();
    r = r % 3;
    switch (r) {
        case 0:
            std::cout << "\033[34m" << "(A created)" << "\033[0m" << std::endl;
            return (new A());
        case 1:
            std::cout << "\033[34m" << "(B created)" << "\033[0m" << std::endl;
            return (new B());
        default:
            std::cout << "\033[34m" << "(C created)" << "\033[0m" << std::endl;
            return (new C());
    }
}

void    identify(Base * p){

    A * t = dynamic_cast<A*>(p);
    if (t != NULL) {
       std::cout << "\033[1m\033[35m"  << "This is A class!" << "\033[0m" << std::endl;
       return ;
    }
    else
        std::cerr << "Hmm.. Not an A... " << '\n';

    B * t2 = dynamic_cast<B*>(p);
    if (t2 != NULL) {
        std::cout << "\033[1m\033[35m" << "This is B class!" << "\033[0m" << std::endl;
       return ;
    }
    else
        std::cerr << "Definitely not a B... " << '\n';

    C * t3 = dynamic_cast<C*>(p);
    if (t3 != NULL) {
       std::cout << "\033[1m\033[35m" << "This is C class!" << "\033[0m" << std::endl;
       return ;
    }
    else
        std::cerr << "Not an C... " << '\n';
}

void    identify(Base & p){
    try
    {
       A & t = dynamic_cast<A&>(p);
       std::cout << "\033[1m\033[35m"  << "This is A class!" << "\033[0m" << std::endl;
       return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hmm.. Not an A... " << '\n';
    }
    try
    {
       B & t = dynamic_cast<B&>(p);
       std::cout << "\033[1m\033[35m" << "This is B class!" << "\033[0m" << std::endl;
       return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Definitely not a B... " << '\n';
    }
    try
    {
       C & t = dynamic_cast<C&>(p);
       std::cout << "\033[1m\033[35m" << "This is C class!" << "\033[0m" << std::endl;
       return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Not an C... " << '\n';
    }
}

int main( void ){

    srand(time(NULL));

    std::cout << std::endl << "\033[1m\033[31m" << "By pointer:" << "\033[0m" << std::endl << std::endl;

    Base *cl = generate();

    identify(cl);
    delete cl;
    cl = generate();
    identify(cl);
    delete cl;
    cl = generate();
    identify(cl);
    delete cl;
    cl = generate();
    identify(cl);
    delete cl;
    cl = generate();
    identify(cl);
    delete cl;
    cl = generate();
    identify(cl);
    delete cl;

    std::cout << std::endl << "\033[1m\033[31m" << "By reference:" << "\033[0m" << std::endl << std::endl;

    cl = generate();
    identify(*cl);
    delete cl;
    cl = generate();
    identify(*cl);
    delete cl;
    cl = generate();
    identify(*cl);
    delete cl;
    cl = generate();
    identify(*cl);
    delete cl;
    cl = generate();
    identify(*cl);
    delete cl;
    cl = generate();
    identify(*cl);
    delete cl;

    return (0);
}