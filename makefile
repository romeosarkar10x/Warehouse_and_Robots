CC=g++
FLAGS=-std=c++20 -Wall -Wextra -Wpedantic -Wconversion -Wno-unused-variable -Wno-unused-parameter

OBJECTS=\
algorithm.o \
csv.o \
dim2.o \
hash.o \
interval.o \
item.o \
log.o \
order.o \
packing_station.o \
record.o \
robot.o \
timestamp.o \
warehouse.o



a.exe: main.cpp $(patsubst %.o,objects/%.o,$(OBJECTS))
	$(CC) $^ -o $@

objects/algorithm.o: sources/algorithm.cpp
	$(CC) -c $^ -o $@

objects/csv.o: sources/csv.cpp
	$(CC) -c $^ -o $@

objects/dim2.o: sources/dim2.cpp
	$(CC) -c $^ -o $@

objects/hash.o: sources/hash.cpp
	$(CC) -c $^ -o $@

objects/interval.o: sources/interval.cpp
	$(CC) -c $^ -o $@

objects/item.o: sources/item.cpp
	$(CC) -c $^ -o $@

objects/log.o: sources/log.cpp
	$(CC) -c $^ -o $@

objects/order.o: sources/order.cpp
	$(CC) -c $^ -o $@

objects/packing_station.o: sources/packing_station.cpp
	$(CC) -c $^ -o $@

objects/record.o: sources/record.cpp
	$(CC) -c $^ -o $@

objects/robot.o: sources/robot.cpp
	$(CC) -c $^ -o $@

objects/timestamp.o: sources/timestamp.cpp
	$(CC) -c $^ -o $@

objects/warehouse.o: sources/warehouse.cpp
	$(CC) -c $^ -o $@





.PHONY: clean

# for windows
clean:
	del /f objects\*.o