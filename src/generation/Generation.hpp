#ifndef GENERATION
#define GENERATION

/*==================================== Manual Control of Creatures*/
//#define MANUAL_CREATURE

#ifndef MANUAL_CREATURE
	/*==================================== Basic generation*/
	#define NB_CREA 5
	#define NB_CREA_MAX 12
	#define TURN_MAX 100
	/*==================================== If launching for tests*/
	//#define TEST_PROBA
#endif

#ifndef TEST_PROBA
	/*==================================== If print the generation num*/
	#define PRINT_GEN
#else
	#define TOUCH_OBJECTIVE
	#ifndef TOUCH_OBJECTIVE
		#define NB_GEN_MAX 1500
	#endif
#endif

/*==================================== Define NeuralNetwork parameters*/
#define BRAIN_INPUT 2
#define BRAIN_OUTPUT 3
#define BRAIN_HIDDEN_LAYER 1
#define BRAIN_NEURON_PER_LAYER 3

/*==================================== SPAWN INFORMATION*/
//#define SPAWN_RANDOM

#ifndef SPAWN_RANDOM
	#define SPAWN_SPREADING 12.0
#endif

#define RANDOM_PERIMETER 10

//#define USE_PARENT


/*==================================== EVOLUTION INFORMATION*/
#define EGALITARY_EVOLUTION

#ifndef EGALITARY_EVOLUTION
	#define FAVORITISM_EVOLUTION
#endif

/*==================================== CREATURE INFORMATION*/
#define CREATURE_SPEED_MULT 1
#define DIRECTION_DATA_MULT 1

#endif
