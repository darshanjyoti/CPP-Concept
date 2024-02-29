
#include <iostream>
#include <thread>

void task1()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Task 1 executing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void task2()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Task 2 executing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

int main()
{
    
    // Create thread for task1
    std::thread t1(task1);

    // Create thread for task2
    std::thread t2(task2);

    // Main thread waits for t1 and t2 to finish
    t1.join();
    t2.join();

    std::cout << "All tasks completed" << std::endl;
    
    return 0;
}
