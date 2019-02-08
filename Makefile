CC=g++
CFLAGS=-g -c

.PHONY: all
all: tm  

tm: main.o FileParser.o Turing_Machine.o Final_States.o States.o Transition.o Transition_Function.o Tape_Alphabet.o Input_Alphabet.o Tape.o Visible.o Crash.o Commands.o
	$(CC) -g -o tm main.o FileParser.o Turing_Machine.o Final_States.o States.o Transition.o Transition_Function.o Tape_Alphabet.o Input_Alphabet.o Tape.o Visible.o Crash.o Commands.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

FileParser.o: FileParser.cpp FileParser.h
	$(CC) $(CFLAGS) FileParser.cpp

TuringMachine.o: Turing_Machine.cpp Turing_Machine.h
	$(CC) $(CFLAGS) Turing_Machine.cpp

FinalStates.o: Final_States.cpp Final_States.h
	$(CC) $(CFLAGS) Final_States.cpp

States.o: States.cpp States.h
	$(CC) $(CFLAGS) States.cpp

Transition.o: Transition.cpp Transition.h
	$(CC) $(CFLAGS) Transition.cpp

TransitionFunction.o: Transition_Function.cpp Transition_Function.h
	$(CC) $(CFLAGS) Transition_Function.cpp

TapeAlphabet.o: Tape_Alphabet.cpp Tape_Alphabet.h
	$(CC) $(CFLAGS) Tape_Alphabet.cpp

InputAlphabet.o: Input_Alphabet.cpp Input_Alphabet.h
	$(CC) $(CFLAGS) Input_Alphabet.cpp

Tape.o: Tape.cpp Tape.h
	$(CC) $(CFLAGS) Tape.cpp

Visible.o: Visible.cpp Visible.h
	$(CC) $(CFLAGS) Visible.cpp

Crash.o: Crash.cpp Crash.h
	$(CC) $(CFLAGS) Crash.cpp

Commands.o: Commands.cpp Commands.h
	$(CC) $(CFLAGS) Commands.cpp

dist: clean
	-@mkdir Kenneth_Murry_Turing_Machine
	-@cp *.cpp *.h Makefile tm.* tmbad.* Kenneth_Murry_Turing_Machine
	-@cp -R TMProtoType Kenneth_Murry_Turing_Machine
	-@tar cvzf CptS322_Kenneth_Murry_Turing_Machine.tgz Kenneth_Murry_Turing_Machine
	-@rm -rf Kenneth_Murry_Turing_Machine

	@echo "                      "
	@echo "Fred's Delivery Services" 
	@echo "                      "
	@echo "        ____   Files packaged up and ready"
	@echo "       _|__|_  to be moved"
	@echo "        @..@  / "
	@echo "       (----)  "
	@echo "      ( >__< ) "
	@echo "      ^^ ~~ ^^ "
	@echo "                      "

#Test Rule that creates and runs one valid test.
#Start
.PHONY: test
valid: all 	
	for i in `seq 1`; \
	do \
		echo "\n------Valid Test In Progress------"; \
		./tm tm; \
	done
#End

#Test Rule that creates and runs one invalid test.
#Start
.PHONY: testbad
invalid: all 	
	for i in `seq 1`; \
	do \
		echo "\n------Invalid Test In Progress------"; \
		./tm tmbad; \
	done
#End


#Valgard rule
#Start
valgrind: all 
	valgrind --tool=memcheck --leak-check=full ./tm tm
#End

#A clean rule that removes all the generated files
#Start
.PHONY: clean
clean:
	-@rm -f *.o
	-@rm -f tm
	-@rm -f *.so
	
	@echo "                      "
	@echo "Fred's Cleaning Services " 
	@echo "                      "
	@echo "        ____   I hear you need some files"
	@echo "       _|__|_  to swim with the fishes"
	@echo "        @..@  / "
	@echo "       (----)  "
	@echo "      ( >__< ) "
	@echo "      ^^ ~~ ^^ "
	@echo "                      "
#End
	
