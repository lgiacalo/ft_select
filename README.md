# ft_select

Le but de ft-select est de répertorier tous les arguments passés à votre programme en colonnes dont la taille dépend de la taille de votre fenêtre de terminal (comme ls le fera).

Ensuite, vous, l'utilisateur, pouvez progresser dans cette liste avec des touches fléchées (le mouvement étant représenté par un changement visuel tel qu'expliqué sur le sujet), sélectionnez un ou plusieurs éléments avec barre d'espace et supprimez de cette liste un ou plusieurs éléments avec suppression / backspace.

Toutes les modifications visuelles et la plupart de la mise en œuvre sont basées sur termcaps.

À la fin, vous devez quitter correctement le programme avec la touche d'échappement ou envoyer une liste des éléments sélectionnés au shell dans le format décrit par le sujet.

Cela permet d'utiliser ft_select comme un moyen facile et convivial de sélectionner des éléments entre autres et de passer leur liste à toute autre commande dans le shell (par exemple, rm ft_select * .c).

NORME LIBFT !!!! A CAUSE DE PRINTF
