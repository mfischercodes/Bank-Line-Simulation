/* 
 * BankSimApp.cpp
 * 
 * Author: Michael Fischer 301310859
 *
 * Last Modification: March 27 2022
 *
 */  

#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include "Event.h"
#include "Queue.h"

#include <iostream>
#include <string>       // stoi
#include <iomanip>      // setw

#include "EmptyDataCollectionException.h"

using namespace std;

void processArrival(Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, 
                    Queue<Event>* bankLine, bool* tellerAvailable, int currentTime){

    cout << "Processing an arrival event at time:"<< setw(6) <<  arrivalEvent.getTime() << endl;

    eventPriorityQueue->dequeue();

    if (bankLine->isEmpty() && *tellerAvailable){
        int departureTime = currentTime + arrivalEvent.getLength();
        Event newDepartureEvent('D', departureTime);
        eventPriorityQueue->enqueue(newDepartureEvent);
        *tellerAvailable = false;
    } 
    else
        bankLine->enqueue(arrivalEvent);
        
}

void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, 
                      Queue<Event>* bankLine, bool* tellerAvailable, int currentTime, float* totalWaitTime){

    cout << "Processing a departure event at time: " << setw(4) << departureEvent.getTime() << endl;

    eventPriorityQueue->dequeue();

    if (!bankLine->isEmpty()){
        Event customer = bankLine->peek();
        bankLine->dequeue();
        int departureTime = currentTime + customer.getLength();

        // time until you are seen - time arrived
        *totalWaitTime += currentTime - customer.getTime();

        Event newDepartureEvent('D', departureTime);
        eventPriorityQueue->enqueue(newDepartureEvent);
    } 
    else
        *tellerAvailable = true;

}

void simulate(){
    cout << "Simulation Begins" << endl;

    string aLine = "";
    string delimiter = " ";
    size_t pos;
    int arrival = 0;
    int length = 0;
    int currentTime = 0;
    int totalCustomers = 0;
    float totalWaitTime = 0.0;

    Queue<Event>* bankLine = new Queue<Event>();
    PriorityQueue<Event>* eventPriorityQueue = new PriorityQueue<Event>();

    bool tellerAvailable = true;

    // Create and add all arrival events to event priority queue
    while ( getline (cin,aLine) ){
        // Get next arrival time a and transacation time t from file
        pos = aLine.find(delimiter);
        arrival = stoi(aLine.substr(0, pos));
        aLine.erase(0, pos + delimiter.length());
        length = stoi(aLine);
        Event newArrivalEvent('A', arrival, length);
        eventPriorityQueue->enqueue(newArrivalEvent);
        totalCustomers ++;
    }

    // Go through all customers in priority order of when they arrived
    while (!eventPriorityQueue->isEmpty()){
        Event newEvent = eventPriorityQueue->peek();
        currentTime = newEvent.getTime();

        if (newEvent.isArrival()){
            processArrival(newEvent, eventPriorityQueue, bankLine, &tellerAvailable, currentTime);
        } else {
            processDeparture(newEvent, eventPriorityQueue, bankLine, &tellerAvailable, currentTime, &totalWaitTime);
        }
        
    }

    cout << "Simulation Ends" << endl << endl;

    cout << "Final Statistics:  " << endl << endl;
    cout << "\tTotal number of people processed: " << totalCustomers << endl;
    cout << "\tAverage amount of time spent waiting: " << totalWaitTime / totalCustomers << endl;


    delete bankLine;
    delete eventPriorityQueue;

}

int main(){
    simulate();
    return 0;    
}

