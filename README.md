Format du fichier .txt
La première rangée définie la résolution de l'écran:
-Window_res x
-Window_res y
La deuxième rangée définie les paramèmtre des Briques dans l'ordre suivant:
- Nombre de rangées de briques
- Nombre de colonnes de briques
- Largeur des briques en px
- Hauteur des briques en px
La troisième rangée définie les paramèmtre de la plateforme dans l'ordre suivant:
- Position initiale de la plateforme sur l'axe X (en px)
- Position initiale de la plateforme sur l'axe Y (en px)
- Largeur de la plateforme (en px)
- Hauteur de la plateforme  (en px)
La quatrième rangée définie les paramèmtre de la balle dans l'ordre suivant:
- Position initiale de la balle sur l'axe X (en px)
- Position initiale de la balle sur l'axe Y (en px)
- Rayon de la balle (en px)
- speed de la balle en X    (en px/tick)
- speed de la balle en Y    (en px/tick)

Les lignes qui suivent représentent les briques contenues dans l'interface utilisateur (Tableau 2D de caractères).
L'état de ces briques est donné par:
- 0: Absence de brique
- 1: Brique ayant 1 vie
- 2: Brique ayant 2 vies
- 3: Brique ayant 3 vies
- ...
- 8: Brique incassable (nombre infini de vies)
