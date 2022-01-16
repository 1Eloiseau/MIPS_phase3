---
title: CS351@ Esisar -- MIPS Emulator Developer Documentation
subtitle: Step 2, 2021-2022 
author: Boulin Martin
papersize: a4
geometry: margin=1.5cm
fontsize: 12pt
lang: fr
---
# Infos principales
* Pour lancer : make && ./emul-mips in1.s in1.hex in1.state
* Les labels sont gérés


# Structure du code
**mettre ici le tableau csv**
* Les 35 registres sont toujours dans cet ordre : R0 - ... - R31 - PC - HI - LO
* La mémoire est un tableau de 1000 char. Cette décision a été prise pour avoir la place de stocker les instructions et les données. Nous avons choisi des char pour avoir un accès à chaque octet individuellement, bien que la plupart du temps nous accédons à une adresse multiple de 4. De plus, cela nous permet de gérer plus simplement le stockage gros-boutiste.
* Pour la gestion des labels :
  * le fichier est lue une première fois pour créer un tableau de correspondance numLigne<->label
  * Le numéro de ligne du fichier.s est différent du numéro d'instruction. Le commentaires, lignes vides, labels, ne comptent pas comme instructions.
* Pour le mode non-interactif :
  1. La ligne est lue par lireLigneFichier
  2. Elle est "nettoyée" par formatterLigne() qui renvoit un int (3 valeurs possibles)
  3. S'il vaut 0, la ligne est un commentaire ou vide, on va à l'étape 5
     S'il vaut 1, la ligne est une instruction
     S'il vaut -1, la ligne est un label
  4. La ligne est traduite puis écrite dans le .hex
  5. On passe à la ligne suivante
* (Eloi)
  * toutes mes variables locales de *fonction(var)* s'appellent l_var
  * les index ayant besoin de noms clairs s'appellent i_var
  * camelCase pour le nommage des variables et fonctions
  * accollades : 
    if(condition) {
	    instructions;
    }
## Fichiers
* lectureEcriture.c
  * formaterLigne(char* ligne)
    * l'instruction ou le label est formaté : supprime les commentaires, espaces, tabulations
    * ex : " 	ADD    $3  ,    $2,  $1 # commentaire  " devient "ADD $3,$2,$1" terminé par \0
    * renvoie 0 si la ligne est une instruction, 1 si label(ligne renvoyé avec le ":"), -1 si vide/commentaire (ligne n'est pas modifié dans ce cas) 
  * int lireFichier(FILE * fichier, char*** tabLignes)
    * lit le fichier et enregistre chaque ligne dans le tableau de lignes
    * renvoie le nombre de lignes lues
  * void ecrireLigneFichier(FILE * fichier, char donnees[])
    * ecrit une ligne dans le fichier (avec un /n)
  
* main.c
  * 

# Choix de traduction


For the `instruction` datastructure, I chose to use a sum type (struct) since: ...




# Bugs connus/comportements aléatoires
* for `SLL` assembler I decided to accept negative offsets and to encode them into 2's complement.
* There was an issue for the `BGTZ` that I think is a bug blablablabla

