#target: dependencies
#	rule to build
#

# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = determinant.o readMatrix.o lab1Main.o
SRCS = determinant.cpp readMatrix.cpp lab1Main.cpp
HEADERS = determinant.hpp readMatrix.hpp

lab1Main: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o lab1Main

#lab1Main.o: lab1Main.cpp ${HEADERS}
#	 ${CXX} ${CXXFLAGS} -c lab1Main.cpp

#determinant.o: determinant.hpp

#readMatrix.o: readMatrix.hpp

clean:  
	-rm *.o ${OBJS}
	-rm lab1Main
