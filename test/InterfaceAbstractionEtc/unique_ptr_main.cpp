/**
 *
 * File: main.cpp
 * Created Date: Tu Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Tue Mar 14 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include <iostream>
#include <string>
#include <bits/unique_ptr.h>
/*
void * smartPointer()
{
//    std::unique_ptr<std::string> a(new std::string("A"));
    return static_cast<void*>(new std::string("A"));
}

int main ()
{
//    std::unique_ptr<std::string> s = smartPointer();
//    std::unique_ptr<std::string> a = std::move(s);
//    std::cout << *s << std::endl;
//    std::cout << *a << std::endl;

 void* ptr = smartPointer();

  // Cast the pointer back to the original type


  std::unique_ptr<std::string> my_class_ptr(static_cast<std::string>(smartPointer()));

  // Use the object
  delete my_class_ptr;

  return 0;
}


//class A {
//public:
//    A() { std::cout << "A()" << std::endl; }
//    ~A() { std::cout << "~A()" << std::endl; }
//};
//
//void * function()
//{
//    return &(A::A);
//}*/

class MyClass {
public:
  MyClass() {
    std::cout << "MyClass created." << std::endl;
  }
};

// Declare the extern "C" function
extern "C" void* create_my_class() {
  return static_cast<void*>(new MyClass());
}

int main() {
  // Call the extern "C" function
  void* ptr = create_my_class();

  // Cast the pointer back to the original type
  std::unique_ptr<MyClass> my_class_ptr(static_cast<MyClass*>(ptr));
//  std::move(my_class_ptr)
  // Use the object
//  delete my_class_ptr;

  return 0;
}