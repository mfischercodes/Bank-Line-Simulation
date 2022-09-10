//bhtest

#include <iostream>
#include "BinaryHeap.h"
#include "Event.h"


using namespace std;

int main(){
    // cout << "hello2" << endl;
    BinaryHeap<Event>* testing = new BinaryHeap<Event>();
    Event e1('A', 4);
    Event e2('A', 3);
    Event e3('A', 1);
    Event e4('A', 5);
    Event e5('A', 6);
    Event e6('A', 0);

    cout << "----insert testing----" << endl;
    
    // cout << testing->isEmpty() << endl;

    testing->insert(e1);
    testing->insert(e2);
    testing->insert(e3);
    testing->insert(e4);
    testing->insert(e5);
    testing->printBinaryHeap();

    cout << "---need to double---" << endl;

    testing->insert(e6);

    testing->printBinaryHeap();

    // cout << "----remove testing----" << endl;


    // testing->remove(); // 1
    // testing->remove(); // 3
    // testing->remove(); // 4
    // testing->remove(); // 5 
    // EMPTY NOW
    
    // cout << testing->retrieve() << endl; // will throw error as is empty


    delete testing;
    return 0;
}