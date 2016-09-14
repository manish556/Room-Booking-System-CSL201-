all: sample

sample:	main.o	room_data.o	lab_data.o	lec_hall_data.o	node.o	LinkedList.o	ll_for_labs.o	ll_for_lec.o	ll_for_rooms.o	header.o
	g++ main.o	room_data.o	lab_data.o	lec_hall_data.o	node.o	LinkedList.o	ll_for_labs.o	ll_for_lec.o	ll_for_rooms.o	header.o -o sample

room_data.o:	room_data.cpp
	g++ -c room_data.cpp

lab_data.o:	lab_data.cpp
	g++ -c lab_data.cpp

lec_hall_data.o:	lec_hall_data.cpp
	g++ -c lec_hall_data.cpp

node.o:	node.cpp
	g++ -c node.cpp

LinkedList.o:	LinkedList.cpp
	g++ -c LinkedList.cpp

ll_for_labs.o:	ll_for_labs.cpp
	g++ -c ll_for_labs.cpp

ll_for_rooms.o:	ll_for_rooms.cpp
	g++ -c ll_for_rooms.cpp

ll_for_lec.o:	ll_for_lec.cpp
	g++ -c ll_for_lec.cpp

header.o:	header.cpp
	g++ -c header.cpp


clean:
	rm *o sample
