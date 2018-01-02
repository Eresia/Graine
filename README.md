# Graine - Partie Intelligence Artificielle

Projet de génération procédurale de créature devant apprendre à survivre dans un monde inconnu.

Ce projet est divisé en deux parties :
- La partie génération des créatures, se basant sur les arbres phylogénétiques pour générer procéduralement des créatures de différentes espèces et les faire évoluer
- La partie intelligence artificielle des créatures qui a pour but l'apprentissage de la survie et se basant sur la fusion d'un réseau de neuronne et d'algorithmes génétiques.

Ce dépot est axé sur la partie Intelligence Artificielle

Lien vers notre chaine Youtube pour observer l'avancement du projet :
[Graine](https://www.youtube.com/channel/UCm7d0uD_0_0Cycn0mbER40A)

Lien vers la documentation du projet :
[Documentation](http://graine.lepesant.me)

##Installation d'Allegro

Notre projet utilise la librairie graphique Allegro. Voici les instructions d'installations :

### Les dépendances :
```shell
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev cmake build-essential make libxcursor-dev cmake g++ freeglut3-dev libxcursor-dev libpng12-dev libjpeg-dev libfreetype6-dev libgtk2.0-dev libasound2-dev libpulse-dev libopenal-dev libflac-dev libdumb1-dev libvorbis-dev libphysfs-dev
```
### La librairie en elle même
```shell
git clone https://github.com/liballeg/allegro5.git
cd allegro
git checkout 5.0
mkdir build
cd build
cmake ..
make
sudo make install
```
### Enfin les extensions nécessaires :
```shell
sudo apt-get install liballegro-ttf5.0 liballegro-image5.0
```

## Compilation & Exécution
Mettez vous dans le dossier du projet et faites
```shell
make
```
Il suffit ensuite d'éxécuter test.out
