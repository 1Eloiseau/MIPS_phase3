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


# Choix de traduction


For the `instruction` datastructure, I chose to use a sum type (struct) since: ...




# Bugs connus/comportements aléatoires
* for `SLL` assembler I decided to accept negative offsets and to encode them into 2's complement.
* There was an issue for the `BGTZ` that I think is a bug blablablabla

