# Livrable 4

Deux conversions RGB → niveaux de gris : `rgb2gray` (moyenne arithmétique 0.33R+0.33G+0.33B) et `rgb2grayw` (moyenne pondérée 0.299R+0.587G+0.114B, norme ITU-R BT.601 qui suit la sensibilité de l'œil humain).

| | mean | variance |
|---|---:|---:|
| gray_mean (arithmétique) | 126.46 | 1801.75 |
| gray_weighted (pondérée) | 123.54 | 2277.68 |

Différence entre les deux images : écart moyen de 5.37 niveaux (sur 255), écart max de 18.

**Comparaison / préférence** : je préfère **rgb2grayw (moyenne pondérée)**.
- L'œil humain est bien plus sensible au vert qu'au rouge ou au bleu ; la moyenne arithmétique traite les 3 canaux à égalité, ce qui ne correspond pas à la perception réelle de la luminosité.
- La version pondérée a une variance plus élevée (2277 vs 1801) : elle conserve davantage de contraste/détails, l'image "a plus de punch" visuellement.
- C'est la formule standard (luma, utilisée en TV/vidéo) pour une bonne raison : elle donne un rendu en niveaux de gris plus fidèle à ce qu'on perçoit naturellement d'une image couleur.

La moyenne arithmétique reste plus simple à calculer et "neutre" (pas de justification perceptuelle), mais au prix d'un rendu légèrement plus plat.
