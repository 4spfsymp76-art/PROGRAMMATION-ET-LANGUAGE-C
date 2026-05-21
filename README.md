# PROGRAMMATION ET LANGUAGE C

 MBOUNGOU Nollan
 MOUGOULA Marc-Antoine
Mahmody NAJIB
KITISSOU Joris

## Commandes utilisées

### Vérification Docker
docker --version

### Test Docker
docker run hello-world

### Lancement Nginx
docker run -d -p 8080:80 nginx

### Voir les conteneurs
docker ps

### Voir les logs
docker logs <id>

### Entrer dans le conteneur
docker exec -it <id> bash

### Lancement DVWA
docker run -d -p 8081:80 vulnerables/web-dvwa

## Résultat

- Docker fonctionne correctement
- Nginx est accessible
- DVWA fonctionne
