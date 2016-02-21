#include "main.hpp"

using namespace std;
using namespace this_thread;

int main(int argc, char** argv){

    Network network = Network(25);;
    if(argc > 1){
        network = Network(atoi(argv[1]));
    }

    int nb;

    do{
        cin >> nb;
        if(nb != -1){
            network.stimulate(nb, 1);
        }
        sleep_for(chrono::milliseconds(200));
        cout << network.to_string() << endl;
    }while(nb != -1);
    return 0;
}
