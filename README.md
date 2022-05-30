# Projet co Strategie capteurs

ce dépôt git contient toutes les stratégies créer dans le cadre du projet collectif de polytech tours

## Utilisation
Chaque branche est nommée selon le nom d'un capteur 
chaque branche contient :
 - un main de test du capteur 
 - Le driver du capteur 
 - ses différentes stratégies de mesure 

## ajout d'un capteur sur une sonde 

Pour ajouter un capteur dans un système, il faut mettre dans le dossier projet de la sonde:
 - Le driver du capteur 
 - ses différentes stratégies de mesure

## Stratégie de mesure 

Une stratégie de mesure est un résumé de comment un capteur mesure une grandeur physique. une stratégie possède quatre méthodes:
- getMesure
- wakeUp
- lowPower
- init
