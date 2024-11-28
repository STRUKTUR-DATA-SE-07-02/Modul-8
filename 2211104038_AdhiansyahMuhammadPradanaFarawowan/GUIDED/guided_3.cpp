#include <iostream>

const int MAX = 5;
int front = 0;
int back = 0;
std::string teller_queue[5];

bool is_full()
{
    if (back == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_empty()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(std::string data)
{
    if (is_full())
    {
        std::cout << "Queue is full!" << '\n';
    }
    else
    {
        if (is_empty())
        {
            teller_queue[0] = data;
            front++;
            back++;
        }
        else
        {
            teller_queue[back] = data; back++;
        }
    }
}

void dequeue()
{
    if (is_empty())
    {
        std::cout << "Queue is empty!" << '\n';
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            teller_queue[i] = teller_queue[i + 1];
        }
        back--;
    }
}

int count_queue_elements()
{
    return back;
}

void clear_queue()
{
    if (is_empty())
    {
        std::cout << "Queue is empty!" << '\n';
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            teller_queue[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void display_queue()
{
    std::cout << "Persons in waiting:" << '\n';
    for (int i = 0; i < MAX; i++)
    {
        if (teller_queue[i] != "")
        {
            std::cout << i + 1 << ". " << teller_queue[i] <<

                '\n';
        }
        else
        {
            std::cout << i + 1 << ". " << "[]" << '\n';
        }
    }
}

int main()
{
    enqueue("Lelouch Lamperouge");
    enqueue("Suzaku Kururugi");
    enqueue("C. C.");

    display_queue();
    std::cout << "Numbers waiting = " << count_queue_elements() << '\n';

    dequeue();
    display_queue();
    std::cout << "Numbers waiting = " << count_queue_elements() << '\n';

    clear_queue();
    display_queue();
    std::cout << "Numbers waiting = " << count_queue_elements() << '\n';

    return 0;
}