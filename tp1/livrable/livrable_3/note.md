# Livrable 3

Une seule image bruitée de référence (`get_noise(10,2)`) est dupliquée en 3 copies pour que les 3 filtres s'appliquent sur exactement le même bruit (comparaison équitable). Le `2` correspond à un bruit **salt & pepper** (pixels isolés aberrants), pas gaussien.
`blur_median(5,0)` et `blur_box(5)` utilisent la même fenêtre (5) pour comparer les méthodes à paramètre égal. `blur_anisotropic(100)` n'est pas comparable directement : son paramètre est une force de diffusion, pas une taille de fenêtre.

| Image | variance | variance_noise |
|---|---:|---:|
| bruitée | 4750.42 | 1937.38 |
| blur_median(5,0) | 3401.53 | 4.84 |
| blur_box(5) | 2769.05 | 7.94 |
| blur_anisotropic(100) | 3789.08 | 675.90 |

(`variance_noise` = bruit résiduel estimé ; plus c'est bas, mieux le bruit est filtré.)

**Constat** : `blur_median` et `blur_box` éliminent quasi tout le bruit résiduel, `blur_anisotropic` beaucoup moins (675 même à amplitude 100). Raison probable : le bruit salt & pepper est impulsionnel (valeurs isolées très contrastées), exactement ce que le filtre médian est conçu pour éliminer. Le filtre anisotrope, lui, lisse en préservant les contours — il interprète les pixels de bruit isolés comme de petits contours à garder plutôt que comme du bruit, d'où sa faible efficacité ici. Sur un bruit gaussien (`noise(10,0)`) plutôt que salt & pepper, l'anisotrope serait sans doute bien plus compétitif puisque c'est le type de bruit pour lequel il est pensé.
