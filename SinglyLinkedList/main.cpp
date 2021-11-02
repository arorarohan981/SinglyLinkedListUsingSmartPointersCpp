//
//  main.cpp
//  SinglyLinkedList
//
//  Created by Rohan Arora on 31/10/21.
//

#include <iostream>
#include "SinglyLinkedList.hpp"

int main(int argc, const char * argv[]) {
    mylib::List<std::string> stringList;
    std::cout<<std::boolalpha;
    stringList.append("R");
    stringList.append("o");
    stringList.append("h");
    stringList.append("a");
    stringList.append("n");
    stringList.print();
    std::cout<<"Removed n : "<<stringList.remove("n")<<std::endl;
    stringList.print();
    std::cout<<"Remove Element at Position 1 "<<stringList.remove(1)<<std::endl;
    stringList.print();
    std::cout<<"Found J "<<stringList.search("J")<<std::endl;
//    std::cout<<"Remove Element at Pos 2 : "<<integerList.remove(2)<<std::endl;
//    integerList.print();
    stringList.resetList();
    try{
    stringList.print();
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}

