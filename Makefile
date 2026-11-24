bin/testTableEntry: testTableEntry-2.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry-2.cpp

clean:
	rm -rf *.o *.gch *.pch bin
