#ifndef GENERATION
#define GENERATION

/*==================================== Manual Control of Creatures*/
//#define MANUAL_CREATURE

#ifndef MANUAL_CREATURE
	/*==================================== If launching for tests*/
	//#define TEST_PROBA
#endif

#ifndef TEST_PROBA
	/*==================================== If print the generation num*/
	#define PRINT_GEN
#else
	//#define TOUCH_OBJECTIVE
	#ifndef TOUCH_OBJECTIVE
		#define NB_GEN_MAX 500
	#endif
#endif

/*==================================== SPAWN INFORMATION*/
//#define SPAWN_RANDOM

#ifndef SPAWN_RANDOM
	#define SPAWN_SPREADING 10.0
#endif

#define RANDOM_PERIMETER 10

//#define USE_PARENT


/*==================================== EVOLUTION INFORMATION*/
#define EGALITARY_EVOLUTION

#ifndef EGALITARY_EVOLUTION
	#define FAVORITISM_EVOLUTION
#endif

/*==================================== CREATURE INFORMATION*/
#define CREATURE_SPEED_MULT 1.5
#define DIRECTION_DATA_MULT 1

#endif
