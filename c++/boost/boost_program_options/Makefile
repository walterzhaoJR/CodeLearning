boost_program_options:boost_program_options.o
	g++ -o boost_program_options boost_program_options.o -lboost_program_options

boost_program_options.o:boost_program_options.cpp
	g++ -c boost_program_options.cpp -I /home/boost_1_56_0/include/ -L /home/boost_1_56_0/lib/ 

clean:
	rm *.o boost_program_options 
