/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <student name>
* @course: Data Structures (CSCI 2320)
*
* @file main.cpp
* @brief Driver program for Linked List Lab
-----------------------------------------------------------------------
*/ 
#include<iostream>
#include <string>
#include "LinkedList.h"

/*
TODO:
Add your comment header here
Display the welcome message to cout at the beginning of main:

Display the following message to cout at the end of the main:
"Goodbye!"
*/

int main()
{
    LinkedList<int> myIntList1;
    LinkedList<std::string> myStringList1;

    std::cout << std::endl
              << "Test some integer lists..." << std::endl;
    // Add some elements to the list of integers
    myIntList1.push_back(10);
    myIntList1.push_back(20);
    myIntList1.push_back(30);
    myIntList1.push_front(5);
    std::cout << "Integer list 1: ";
    myIntList1.print();

    // Print the front and back element of the list
    std::cout << "Front element: " << myIntList1.front() << std::endl;
    std::cout << "Back element: " << myIntList1.back() << std::endl;

    // Pop elements from the list
    std::cout << "Pop front: " << myIntList1.front() << std::endl;
    myIntList1.pop_front();
    std::cout << "Integer list 1: ";
    myIntList1.print();
    std::cout << "Pop front: " << myIntList1.front() << std::endl;
    myIntList1.pop_front();
    std::cout << "Integer list 1: ";
    myIntList1.print();
    std::cout << "Length of list 1 is " << myIntList1.size() << std::endl;

    // Check if the list is empty
    if (myIntList1.empty())
    {
        std::cout << "List 1 is empty" << std::endl;
    }
    else
    {
        std::cout << "List 1 is not empty" << std::endl;
    }

    std::cout << "Pop back: " << myIntList1.back() << std::endl;
    myIntList1.pop_back();
    std::cout << "Pop back: " << myIntList1.back() << std::endl;
    myIntList1.pop_back();
    std::cout << "Integer list 1:" << myIntList1.toString() << ":" << std::endl;

    // Check if the list is empty
    if (myIntList1.empty())
    {
        std::cout << "List 1 is empty" << std::endl;
    }
    else
    {
        std::cout << "List 1 is not empty" << std::endl;
    }

    // Create a new list by copying an old one
    myIntList1.push_back(10);
    myIntList1.push_back(20);
    myIntList1.push_back(30);
    std::cout << "Integer list 1: ";
    myIntList1.print();

    LinkedList<int> myIntList2 = myIntList1;
    std::cout << "Copy integer list 1 to integer list 2." << std::endl;
    myIntList2 = myIntList1;
    std::cout << "Integer list 2: ";
    myIntList2.print();

    std::cout << "Pop 2 elements of the front of integer list 2." << std::endl;
    myIntList1.pop_front();
    myIntList1.pop_front();
    std::cout << "Integer list 1:" << myIntList1.toString() << ":" << std::endl;
    std::cout << "Integer list 2:" << myIntList2.toString() << ":" << std::endl;

    std::cout << "Integer list 2 via std cout: "
              << myIntList2 << ":" << std::endl;

    std::cout << std::endl
              << "Test some exceptions..." << std::endl;
    myIntList1.pop_back();

    if (myIntList1.empty())
    {
        std::cout << "List 1 is empty" << std::endl;
    }
    else
    {
        std::cout << "List 1 is not empty" << std::endl;
    }

    try
    {
       // use 2 statements to avoid awkward buffering issue on Windows
        std::cout << "Front element: ";
        std::cout << myIntList1.front() << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // use 2 statements to avoid awkward buffering issue on Windows
        std::cout << "Back element: ";
        std::cout << myIntList1.back() << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Try our list on strings
    std::cout << std::endl
              << "Test some string lists..." << std::endl;
    myStringList1.push_front("spam?");
    myStringList1.push_front("some");
    myStringList1.push_front("have");
    myStringList1.push_front("Please, may I");
    std::cout << "String list 1: " << myStringList1 << std::endl;

    // Try inserting elements
    std::cout << "\nTry inserting an element at position 3" << std::endl;
    std::cout << "String list 1 has length " << myStringList1.size() 
              << std::endl;
    try
    {
        myStringList1.insert(3, "more");
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "String list 1: " << myStringList1 << std::endl;

    std::cout << "\nTry inserting an element at the beginning" << std::endl;
    try
    {
        myStringList1.insert(0, "Sir!  Sir! ");
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "String list 1: " << myStringList1 << std::endl;

    std::cout << "\nTry inserting an element at the end" << std::endl;
    try
    {
        myStringList1.insert(myStringList1.size(), "I love spam!");
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "String list 1: " << myStringList1 << std::endl;

    // Try inserting an element out of range
    std::cout << "\nTry inserting an element out of range" 
              << std::endl;
    std::cout << "String list 1 has length " << myStringList1.size()
              << std::endl;
    try
    {
        myStringList1.insert(myStringList1.size() + 10, "even more");
        std::cout << "Unexpected success trying to insert out of range" 
                  << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        std::cout << "Expected failure trying to insert out of range"
                  << std::endl;
    }
    std::cout << "\nRemove the first and last element and print result"
              << std::endl;    
    myStringList1.pop_back();
    myStringList1.pop_front();
    std::cout << "String list 1: " << myStringList1 << std::endl;

    return 0;
}
