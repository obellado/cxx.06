#include <iostream>

typedef struct Data{
    int a;
    std::string s1;
    std::string s2;
}       Data;

uintptr_t   serialize(Data *ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}

int main( int argc, char** argv ){

    if (argc == 4){
        Data * data = new Data();
        data->a = std::atoi(argv[1]);
        data->s1 = argv[2];
        data->s2 = argv[3];

        uintptr_t d = serialize(data);

        std::cout << "Data address : " << data << std::endl;
        std::cout << "Serialize    : " << d << std::endl;
        std::cout << "Deserialize  : " << deserialize(d) << std::endl;
        std::cout << "Deserialize  : " << deserialize(d)->a << std::endl;
        std::cout << "Deserialize  : " << deserialize(d)->s1 << std::endl;
        std::cout << "Deserialize  : " << deserialize(d)->s2 << std::endl;
        delete data;
        return (0);
    }
    return (1);
}