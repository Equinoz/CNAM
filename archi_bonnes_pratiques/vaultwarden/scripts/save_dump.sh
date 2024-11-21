#!/bin/bash

# Identifiants du serveur de destination
NAME="vaultwarden"
IP="146.59.239.49"
PORT=50983
TARGET_PATH="/home/vaultwarden/backups"

# Chemin de la base de données et du fichier de sauvegarde
DB_PATH="./db.squilte"???
BACKUP_PATH="./backup_vaultwarden_$(date +%Y%m%d%H%M%S).db"

# Exécuter la sauvegarde
sqlite3 $DB_PATH ".backup $BACKUP_PATH"

# Envoi du fichier de backup au serveur de secours via SSH
scp -P $PORT $BACKUP_PATH $NAME@$IP:$TARGET_PATH

# Suppression du fichier de backup, inutile ici
#rm $BACKUP_PATH

