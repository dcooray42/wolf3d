# wolf3d

Troisième projet de la branche graphique en parallèle de RTv1 de l'école 42.

Pour ce projet, il faut recoder un labyrinthe grâce à la méthode raycasting grâce au fichier de description de scène passé en paramètre.

Voici les bonus qui sont gérés par ce programme :
* Texture sur les murs, sol et ciel
* Musique
* Passage secret
* Surprise

## Pour commencer

Ces instructions vous aideront à avoir une copie du projet et de pouvoir le faire marcher sur votre ordinateur.

### Prérequis

**Attention: A partir de maintenant, toutes les étapes (téléchargement, installation/compilation, exécution) seront à effectuer sur un terminal.**

#### Système d'exploitation

```
macOS Sierra
```

#### Téléchargement

Ce que vous devez faire pour télécharger les fichiers sources afin de pouvoir les compiler par la suite

```
git clone https://github.com/dcooray42/wolf3d.git [nom du PATH/dossier]
```

### Installation

Se placer dans le dossier dans lequel vous avez fait la copie des fichiers sources du projet puis rentrer la commande suivante

```
make
```

Plusieurs fichiers .o auront fait leur apparitions dans le dossier que vous avez cloné ainsi que le binaire

```
wolf3d
```

### Suppression

Pour supprimer les fichiers objets .o généré lors de la création du programme

```
make clean
```

Pour supprimer les fichiers objets .o et le programme

```
make fclean
```

Pour tout supprimer puis recompiler le programme

```
make re
```

## Faire des tests

Une fois que le programme a été créé, vous n'avez plus qu'à rentrer en ligne de commande le nom du programme + le fichier 
de description de scène.

### Utilisation du programme

Ligne de commande

```
./wolf3d [PATH/fichier de description de scène]
```

### Commandes

Ces commandes ont été attribuées dans un environnement où les claviers étaient en QWERTY. Pour une meilleure expérience, 
veuillez changer par avance la configuration de votre clavier.

| Touche |      Action      |
| ------ |:---------------- |
| W      | Avancer          |
| S      | Reculer          |
| A      | Tourner à gauche |
| D      | Tourner à droite |
| Q      | Strafe à gauche  |
| E      | Strafe à droite  |
| Shift  | Courir           |
| Ctrl   | Marcher          |
| ESC    | Quitter          |

#### Exemple
![alt text](https://raw.githubusercontent.com/dcooray42/wolf3d/master/photo/wolf3d.jpeg)

## Compiler avec
* Minilibx - Librairie graphique
* FMOD - Bibliothèque multiplateforme de gestion du son

## Licence
* Minilibx - License BSD: Copyright Olivier Crouzet - 2014
* FMOD - End User Licence Agreement (EULA)

## Note
125/100

## Auteur

* **Dimitri Cooray** - [Lien vers github](https://github.com/dcooray42)
