#ifndef GENERATION
#define GENERATION

/*==================================== SPAWN INFORMATION*///
//#define SPAWN_RANDOM

#ifndef SPAWN_RANDOM
	#define SPAWN_SPREADING 10.0
#endif

#define RANDOM_PERIMETER 10

//#define USE_PARENT


/*==================================== EVOLUTION INFORMATION*/
#define EGALITARY

#ifndef EGALITARY_EVOLUTION
	#define FAVORITISM_EVOLUTION
#endif

/*==================================== CREATURE INFORMATION*/
#define CREATURE_SPEED_MULT 1.5
#define DIRECTION_DATA_MULT 1

#endif
