# Implémentation du Chiffrement de Vernam

Ce projet met en œuvre le chiffrement de Vernam pour encoder une chaîne de caractères en une image au format PGM. Il génère également la clé de déchiffrement, elle aussi sous forme d'image PGM.

## Prérequis

* Un compilateur C++ (par exemple, G++)
* L'utilitaire `make`

## Installation

1.  **Clonez le dépôt :**
    ```bash
    git clone <URL_DU_DEPOT_GIT>
    ```
2.  **Compilez le projet :**
    Naviguez jusqu'au répertoire du projet cloné et exécutez :
    ```bash
    make
    ```
    Cela créera les exécutables `encrypt` et `decrypt` dans le répertoire `bin/`.
    
## Utilisation

### Chiffrement

Pour chiffrer un message, utilisez l'exécutable `bin/encrypt` avec la syntaxe suivante :

```bash
bin/encrypt "Votre texte à chiffrer" chemin/vers/image_chiffree.pgm chemin/vers/image_cle.pgm
```
1. **Argument 1 :** La chaîne de caractères à chiffrer. Pensez à utiliser des guillemets si votre texte contient des espaces.
2. **Argument 2 :** Le chemin de destination pour l'image PGM chiffrée résultante.
3. **Argument 3 :** Le chemin de destination pour l'image PGM qui contiendra la clé de déchiffrement.

Ce programme convertit la chaîne de caractères fournie en une image PGM chiffrée. Il enregistre l'image résultante et la clé de déchiffrement (également une image PGM) aux emplacements spécifiés.

### Déchiffrement

Pour déchiffer un message, utiliser l'exécutable `bin/decrypt` avec la syntaxe suivante :

```bash
bin/encrypt chemin/vers/image_chiffree.pgm chemin/vers/image_cle.pgm
```

1. **Argument 1 :** Le chemin vers votre image PGM chiffrée.
2. **Argument 2 :** Le chemin vers l'image PGM contenant la clé de déchiffrement.

Le programme, à partir des deux images fournies en paramètres, décode la chaîne de caractères originale et l'affiche sur la sortie standard.