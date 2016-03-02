#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int exclam(int N){
	int result = 0;
	int i;
	for(i = N-1; i > 0; i--){
		result += i;
	}
	return result;
}

int main(int argc, char** argv){
	int nb;
	int i, j, nbParent;
	if(argc == 2){
		nb = atoi(argv[1]);
	}
	else{
		nb = 10;
	}

	for(nbParent = 2; nbParent < nb; nbParent++){
		int result = 0;
		for(i = 0; i < nbParent; i++){
			for(j = 0; j < nbParent-i; j++){
				if(i != j){
					result++;
				}
			}
		}
		printf("%d->%d, %d\n", nbParent, result, exclam(nbParent) + (nbParent/2));
	}
	return 0;
}
