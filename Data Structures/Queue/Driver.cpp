/*****************************************************************************/
/*!
@file   Driver.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   7/3/2016
@brief  a sample driver to test the functionality of the Queue
*/
/*****************************************************************************/
#include "Queue.h"
#include <chrono>

#define STRESS 0

void Test0()
{
    //Enqueue/Dequeue
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Enqueue/Dequeue" << std::endl << std::endl;
    DataStructures::Queue<int> q(10);
    for (int i = 1; i <= 10; i++)
        q.Enqueue(i);
    q.DumpQueue();
    std::cout << "Starting Dequeue" << std::endl << std::endl;
    for (int i = 1; i <= 10; i++) {
        q.Dequeue();
        q.DumpQueue();
    }
    std::cout << std::endl;
}

void Test1()
{
    //Top/Bottom
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Top" << std::endl << std::endl;
    DataStructures::Queue<int> q(10);
    for (int i = 1; i <= 10; i++)
        q.Enqueue(i);
    q.DumpQueue();
    std::cout << "Top: " << q.Top() << std::endl;
    std::cout << "Bottom: " << q.Bottom() << std::endl << std::endl;
    q.Dequeue();
    q.DumpQueue();
    std::cout << "Top: " << q.Top() << std::endl;
    std::cout << "Bottom: " << q.Bottom() << std::endl << std::endl;
    q.Dequeue();
    q.DumpQueue();
    std::cout << "Top: " << q.Top() << std::endl;
    std::cout << "Bottom: " << q.Bottom() << std::endl << std::endl;
    std::cout << std::endl;
}

void Test2()
{
    //Grow
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Grow" << std::endl << std::endl;
    DataStructures::Queue<int> q(10);
    for (int i = 1; i <= 10; i++)
        q.Enqueue(i);
    q.DumpQueue();
    for (int i = 1; i <= 10; i++)
        q.Enqueue(i);
    q.DumpQueue();
    std::cout << std::endl;
}

void Test3()
{
    //Copy Constructor
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Copy Constructor" << std::endl;
    DataStructures::Queue<int> q(20);
    for (int i = 1; i <= 10; i++)
        q.Enqueue(i);
    std::cout << "Q1 :";  q.DumpQueue();
    std::cout << " Size: " << q.Size() << std::endl << std::endl;

    DataStructures::Queue<int> q2(q); //explicit call
    std::cout << "Q2 :";  q2.DumpQueue();
    std::cout << " Size: " << q2.Size() << std::endl << std::endl;
}

void Test4()
{
    //Assignment Operator
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Assignment Operator" << std::endl;
    DataStructures::Queue<int> q(10);
    for (int i = 1; i <= 10; i++)
        q.Enqueue(i);
    std::cout << "Q1 :"; q.DumpQueue();
    std::cout << " Size: " << q.Size() << std::endl << std::endl;

    DataStructures::Queue<int> q2(10);
    for (int i = 10; i <= 20; i++)
        q2.Enqueue(i);
    std::cout << "Q2 :"; q2.DumpQueue();
    std::cout << " Size: " << q2.Size() << std::endl << std::endl;

    std::cout << "Assigning Queue 2 to Queue" << std::endl;
    q2 = q;
    std::cout << "Q2 :"; q2.DumpQueue();
    std::cout <<  " Size: " << q2.Size() << std::endl << std::endl;

    DataStructures::Queue<int> q3(20);
    for (int i = 1; i <= 20; i++)
        q3.Enqueue(i);
    std::cout << "Q3 :"; q3.DumpQueue();
    std::cout << " Size: " << q3.Size() << std::endl << std::endl;

    std::cout << "Assigning Queue 2 to Queue 3" << std::endl;
    q2 = q3;
    std::cout << "Q2 :"; q2.DumpQueue();
    std::cout << " Size: " << q2.Size() << std::endl << std::endl;

    std::cout << "Assigning Queue 3 to Queue" << std::endl;
    q3 = q;
    std::cout << "Q3 :"; q3.DumpQueue();
    std::cout << " Size: " << q3.Size() << std::endl << std::endl;   
}

void Test5()
{
    //Empty Queue, Strings
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Empty Queue" << std::endl;
    DataStructures::Queue<std::string> q(1);
    std::cout << "Q1 :"; q.DumpQueue();
    q.Dequeue();
    q.Enqueue("Hello");
    q.Enqueue("World");
    q.Enqueue("Foo");
    q.Enqueue("Bar");
    q.DumpQueue();
}

void Test6()
{
    //Stress Enqueue
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Stress with Grow" << std::endl;
    DataStructures::Queue<int> q(1);
    for (int i = 1; i <= 100000; i++)
        q.Enqueue(i);
    std::cout << "Q1 :"; q.DumpQueue();
}

void Test7()
{
    //Stress Enqueue, No Grow
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Stress without Grow" << std::endl;
    DataStructures::Queue<int> q(100000);
    for (int i = 1; i <= 100000; i++)
        q.Enqueue(i);
    std::cout << "Q1 :"; q.DumpQueue();
}

int main()
{
    Test0(); //Enqueue / Dequeue
    Test1(); //Top
    Test2(); //Grow
    Test3(); //Copy Constructor
    Test4(); //Assignment Operator
    Test5(); //Empty Queue

#if STRESS
    auto t1 = std::chrono::high_resolution_clock::now();
    Test6(); //Stress Enqueue Grow
    auto t2 = std::chrono::high_resolution_clock::now();
    auto diff = t2 - t1;

    auto t3 = std::chrono::high_resolution_clock::now();
    Test7(); //Stress Enqueue No Grow
    auto t4 = std::chrono::high_resolution_clock::now();
    auto diff2 = t4 - t3;

    std::cout << std::endl;
    std::cout << "Time With Grow: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
        << " milliseconds\n" << std::endl;

    std::cout << "Time Without Grow: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
        << " milliseconds\n" << std::endl;
#endif
    return 0;
}