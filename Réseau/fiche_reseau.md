# Réseau  

## Général  
8 bits = 1 octet  
En héxadécimal deux symboles valent 1 octet  
Modèle OSI: Ah petite salope tu recraches la purée  
- Application  
- Présentation  
- Session  
- Transport  
- Réseau  
- Liaison  
- Physique  

10000000 = 128  
11000000 = 192  
11100000 = 224  
11110000 = 240  
11111000 = 248  
11111100 = 252  
11111110 = 254  
11111111 = 255  

## Couche physique  
Transmission numérique  
Transmission analogique (modems)  
Codes:  
NRZ: le plus simple. 1 correspond à un signal positif, 0 à un signal négatif  
NRZI: NRZ inversé. Transmission utilisé sur une ligne RS232, tensions +/- 12 V. Inconvénient de ces deux codes: détection et reconnaissance des longues lignes de 0 ou 1  
Manchester: (cours pas exo) 1 est codé par une variation en milieu de temps élémentaire de +V à -V, 0 par -V à +V (réseau ethernet)  
Manchester différentiel: bit 0 transition début temps élémentaire, bit 1 transition milieu temps élémentaire. Commence en bas (norme 802.5)  
Miller: bit 0 absence de transition pendant le temps élementaire, bit 1 transition au milieu du temps élémentaire. Si il y a plusieurs 0 transition au début de chaque temps élémentaire  

Valence: Nombre de valeurs que peut prendre l'état physique à un instant t. Un code numérique peut prendre +V ou -V donc la valence est de 2  
Moment élémentaire: durée élementaire pendant laquelle il faut emettre le signal physique sur le câble pour qu'il soit reconnaissable. En secondes noté Tm  
Vitesse de modulation: nombre de valeurs physiques émises par seconde. Noté Rm, s'exprime en bauds. Rm = 1 / Tm  
Débit binaire: nombre de valeurs physiques transmises par seconde. Noté D, en bit/s. D = Rm/k x log2(V) En vrai D = Rm x log2(V)  
Déformations du signal: affaiblissement, distorsions, bruits  
Temps de transmission: T en secondes entre le début et la fin. T = L/D où L représente la longueur du message en bits  

## Routage  
TCP/IP fonctionne en mode datagramme  
IP protocole réseau permettant l'acheminement des datas de bout en bout, de machine IP à machine IP  
Adresse IP divisée sur 32 bits (4 octets)  
Classes de sous-réseau:  
- Classe A: 255.0.0.0 (beaucoup de machines, peu de réseaux, grande ville) premier bit 0 Commence par 1  
- Classe B: 255.255.0.0 (moyen quoi) premiers bits 10 Commence par 128  
- Classe C: 255.255.255.0 (contraire...) premiers bits 110 Commence par 192  

Classes de sous-réseau différent des masques de sous-réseaux  
Adresse: 169.20.10.30  
Masque: 255.255.255.0  
La classe est B (169), l'adresse du réseau est 169.20.10.0  

La différence entre le masque et la classe permet de faire des sous-réseaux: 1 bit 2 sous-réseaux, 2 bits 4...  
Adresse de réseau: 202.12.45.0  
Pour créer 8 sous-réseaux, masque: par défaut 255.255.255.0, 8 vaut 3 bits donc codé 11100000 qui vaut 224 soit un masque 255.255.255.224  
Les adresses adressables sont répertoriées sur 5 bits soit 0 à 31. On enlève l'adresse du réseau et le broadcast. Il reste 30 adresses par sous-réseau  
Premier sous-réseau 1 à 30 dans l'intervalle 0 à 31, deuxième 33 à 62 intervalle 32 à 63...   
Notation simplifiée: 202.12.45.0/27 (le 27 indique que les 27 premiers bits du masque sont à 1 soit un masque 255.255.255.224)  

Adresse IP: 164.2.34.164  
Masque: 255.255.255.192  
X.X.X.10100100  
X.X.X.11000000 (2 bits donc 4 sous-réseaux)  
Sous-réseau: X.X.X.10000000 soit 164.2.34.128  
De réseau 0 à broadcast 63, de réseau 64 à broadcast 127, de 128 à broadcast 191 et réseau 192 à broadcast 255  
Adresses hôtes, plage 129 à 190  


Trame ethernet:  
Valeurs numériques données  en **héxadécimal!**  
Entête trame: adresse MAC destination 6 **octets** - adresse MAC source 6 **octets** - type 2 **octets**  

Entête paquet: version IP 4 **bits** - longueur en-tête 4 **bits** - type service 8 **bits** - longueur paquet IP en octets 16 **bits** - identification datagramme actuel 16 **bits** - flags 4 **bits** dernier inutilisé - déplacement 12 **bits** - TTL time-to-live 8 **bits** - protocole 8 **bits** - checksum 16 **bits** - IP source 32 **bits** - IP destination 32 **bits** - options 32 **bits** - champ de données 32 **bits**  
Version IP 4 = IPV4, 6 = IPV6, 5 = datagrame mode  
Flags: premier bit réservé 0, DF don't fragment deuxième si la fragmentation est autorisée, MF more fragments troisième si 1 c'est pas le dernier  
Protocole: 01 ICMP, 02 IGMP, 06 TCP, 17 UDP  
Dans une trame IP, le déplacement est à multiplier par 8 pour connaître où on en est dans la trame à recevoir. Déplacement = 0 veut dire que c'est le premier fragment  
Si il y a un seul fragment, pas d'options  

Entête segment: port source 2 **octets** en héxa - port destination 2 **octets** en héxa - numéro de séquence 4 **octets** - acquittement 4 **octets** - autre trucs 4 **octets** - fenêtre d'acquittement 4 **octets**  
Les numéros de séquence et d'acquittement permettent de détecter les pertes éventuelles, retransmettre et réordonner au besoin  
La fenêtre d'anticipation est le nombre d'octets pouvant être émis sans avoir à attendre d'acquittement  

## Spanning tree  
Détection de boucles dans un réseau local (utilisant des switchs). Dans le cas où il y a deux switchs, une trame sera reçue sur un switch par le biais du LAN d'origine et par le biais de l'autre LAN, étant passé par l'autre switch. Cela crée des boucles infinies  
Il est nécéssaire de supprimer les boucles en bloquant certaines connexions entre switchs. On se sert d'un graph qui doit recouvrir le réseau de façon à permettre d'accéder à chaque switch de façon unique. Pour se faire on utilise un protocole avec des trames "Bridge Protocole Data Unit"  
Trame BPDU: 4 champs dont: racine sur 6 **octets** (adresse MAC) - distance sur 4 **octets** - MAC du pont émetteur 6 **octets** - numéro port émetteur 2 **octets**  
BPDU1 = (R1, D1, E1, P1)  
BPDU2 = (R2, D2, E2, P2)  
BPDU1 est meilleure que BPDU2 si:  
- R1 < R2 ||  
- R1 == R2 && D1 < D2 ||  
- R1 == R2 && D1 == D2 && E1 < E2 ||  
- R1 == R2 && D1 == D2 && E1 == E2 && P1 < P2  

Tout pont suppose qu'il est la racine (envoie 0 de distance donc et son numéro pour la racine, identique à son numéro à lui)  
A la reception d'une trame BPDU on choisi la meilleure et on crée une nouvelle configuration: cette nouvelle trame est considérée comme la nouvelle racine et la trame du port mise à jour. Si la trame BPDU se situe entre la trame du port et la racine, le port correspondant est bloqué  
Trames du switch numéro 15 (qui pense être la racine):  
- 1	15	0	15	F  
- 2	15	0	15	F  

Réception de la trame 13	0	13	1  
Trames mises à jour:  
- 1	13	0	13	R  
- 2	13	1	15	F  

La trame étant meilleure, le switch en déduit que sur son port 1 il a accès à la racine et la met à jour en conséquence, puis sur son port 2 ajoute les informations de racines et de distance  
Réception de la trame 13	0	13	2  
Trames mises à jour:  
- 1	13	0	13	R  
- 2	13	1	15	B  

La nouvelle trame est moins bonne que la racine, mais meilleure que celle du port 2: ce port est bloqué  
**Attention!** Les tables sont affichées Port Racine Coût Emmetteur, les trames Racine, Distance, Emetteur, Port. Il faut faire passer le port de la fin de la trame au début pour faire correspondre aux tables   

