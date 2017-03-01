# Vm *Corewar* Quick start

Quick start:

    $> git clone https://github.com/mdos-san/corewar && cd corewar
    $> make

Options:

    -dump [nb]      ## Dump de la memoire au cycle [nb] conforme au sujet
    -d [nb]         ## Dump de la memoire au cycle [nb] conforme a la vm de zaz
    -n [nb] player  ## Set numero du joueur suivant a [nb]
    -v              ## Active le visualiseur ncurse
    -verbose        ## Similaire a l'option -v 16 de la vm de zaz

Examples:

    $> ./corewar _cor/fluttershy.cor _cor/helltrain.cor
    $> ./corewar -v _cor/fluttershy.cor _cor/helltrain.cor
    $> ./corewar -dump 15000 _cor/fluttershy.cor _cor/helltrain.cor
    $> ./corewar -v -n 42 _cor/fluttershy.cor -n -3 _cor/helltrain.cor -n 21 _cor/turtle.cor _cor/bee_gees.cor
    $> ./corewar -verbose _cor/fluttershy.cor _cor/helltrain.cor

Utilisation des scripts de tests:

    $> bash dump_inspect        # Verifie si les dumps memoire sont correct
    $> bash verbose_inspect     # Verifie si le verbose est correct (hard)

Pour connaitre les prochaines **features**, rendez-vous sur la page [Projects](https://github.com/mdos-san/corewar/projects) du repo.
