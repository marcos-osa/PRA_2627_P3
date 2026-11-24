bin/testTableEntry: testTableEntry-2.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry-2.cpp
bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp
clean:
	rm -rf *.o *.gch *.pch bin
