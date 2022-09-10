all: bsim

bsim: BankSimApp.o Event.o EmptyDataCollectionException.o
	g++ -Wall -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp

binaryheaptest: bhtest.o  Event.o EmptyDataCollectionException.o
	g++ -Wall -o binaryheaptest bhtest.o Event.o EmptyDataCollectionException.o

bhtest.o: bhtest.cpp
	g++ -Wall -c bhtest.cpp

BinaryHeap.o: BinaryHeap.cpp
	g++ -Wall -c BinaryHeap.cpp

Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp

pq: pqtest.o Event.o EmptyDataCollectionException.o
	g++ -Wall -o pq pqtest.o Event.o EmptyDataCollectionException.o

pqtest.o: pqtest.cpp
	g++ -Wall -c pqtest.cpp

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ -Wall -c PriorityQueue.cpp

queue: qtest.o EmptyDataCollectionException.o
	g++ -Wall -o queue qtest.o EmptyDataCollectionException.o

qtest.o: qtest.cpp
	g++ -Wall -c qtest.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f pq *.o binaryheaptest *.o queue *.o bsim *.o

	