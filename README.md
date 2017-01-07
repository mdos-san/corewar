# Vm *Corewar* Quick start
Apres avoir cloner le repo aller dans le dossier *mdos-san*:

    $> git clone https://github.com/mdos-san/corewar
    $> cd corewar/mdos-san

Pour compiler la vm il suffit de faire un faire un:

    $> make
    
La vm etant encore en **beta**, elle prend **forcément** 3 parametres qui sont les champions,
le visualiseur est activé par **defaut (pas de -n)**, voici un example d'utilisation:

    $> ./corewar ../ressources/test.cor ../ressources/fluttershy.cor ../ressources/bee_gees.cor
    
La vm n'etant pas finie, le vainqueur de la partie n'est pas afficher a la fin.

Les commandes asm gerée sont ( **opcode**. *commande*):

1. **live**
2. **ld**
3. **st**
4. **add**
6. **and**
8. **xor**
9. **zjmp**
10. **ldi**
11. **sti**
12. **fork**

Quelque soucis sont encore présent avec le **carry**, des tests seront fait lors de la prochaine version pour s'assurer de son bon fonctionnement.

Pour connaitre les prochaines **features**, rendez-vous sur la page [Projects](https://github.com/mdos-san/corewar/projects) du repo.
