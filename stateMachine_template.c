/*
Paul Rickard - 20202: https://pauljohnrickard.com

Really basic state machine written in C:

While learning about state machines, I wrote this Switch Case based state machine.
It's not glorious, but it's intended use is a simple embeeded system, so it doesn't need to be.

State 0 cannot be used - don't do it.

*/



#include <stdio.h>


int state = 1; // populate this with the start state.
int nextState = 0;
int exitState = 0;
int entryState = 0;

// use this to transition between states
void transition(int thisNextState){

	//populate exitState
	exitState = state;

	//populate entryState
	entryState = thisNextState;

	// update states
	state = thisNextState;

}


int main() {

	while (1){


		//
		// State Switch case
		//
		switch (state){
		    case 1:
				printf("Case %d\n", state);
				transition(2);
				break;

		    case 2:
				printf("Case %d\n", state);
				transition(3);
				break;

		    default:
				printf("No State %d Exisits - Exit program", state);
				return 0;
		}


		//
		// exitState
		//
		switch (exitState){
		    case 0:
				break;

		    case 1:
				printf("Exit %d\n", exitState);
				break;

			case 2:
				printf("Exit %d\n", exitState);
				break;

		    default:
				printf("No Exit State %d Exists\n", state);
				break;
		}

		//wipe exit state
		exitState = 0;

		//
		// entryState
		//
		switch (entryState){
			case 0:
				break;

			case 1:
				printf("entry %d\n", entryState);
				break;

			case 2:
				printf("entry %d\n", entryState);
				break;

			default:
				printf("No Entry State %d Exists\n", state);
				break;
		}

		// wipe entry state
		entryState = 0;


	}
}
