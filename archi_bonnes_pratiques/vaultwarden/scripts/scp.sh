#!/bin/bash

# Chemin de la base de données et du fichier de sauvegarde
#DB_PATH="/chemin/vers/ma_base_de_donnees.db"
#BACKUP_PATH="/chemin/vers/sauvegardes/ma_base_de_donnees_backup_$(date +%Y%m%d%H%M%S).db"

# Exécuter la sauvegarde
#sqlite3 $DB_PATH ".backup $BACKUP_PATH"

# Message de confirmation
#echo "Sauvegarde terminée : $BACKUP_PATH"

FILENAME="test.txt"

echo "Faut qu'ici ce soit concluant" > $FILENAME

scp -P 50983 ./$FILENAME vaultwarden@146.59.239.49:/home/vaultwarden/backups

rm $FILENAME

