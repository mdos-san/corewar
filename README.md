# Vm corewar Quick start
Apres avoir cloner le repo, aller sur la branche dev puis aller dans le dossier mdos-san:

    $> git clone https://github.com/mdos-san/corewar
    $> cd corewar
    $> git checkout dev
    $> cd mdos-san

Pour compiler la vm il suffit de faire un faire un:

    $> make
    
La vm etant encore en beta, elle prend forcement 3 parametres qui sont les champions,
le visualiseur est activé par defaut (pas de -n), voici un example d'utilisation:

    $> ./corewar ../ressources/test.cor ../ressources/fluttershy.cor ../ressources/bee_gees.cor
