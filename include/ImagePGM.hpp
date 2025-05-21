#ifndef IMAGE_PGM_HPP
#define IMAGE_PGM_HPP

#include "Image.hpp"

class ImagePGM : public Image {
    private:
        octet* _data;

    public:

        /* Constructeurs et desctructeurs */
        /**
         * 
         * @brief Constructeur par défaut.
         *  
         * @note Initialise la largeur et la hauteur à 0
         * et data a nullptr.
         * 
         */
        ImagePGM();

        /**
         * 
         * @brief Constructeur à 2 paramêtres.
         * 
         * @param width Largeur de l'image.
         * @param height Hauteur de l'image.
         * 
         * @note Initialise la largeur et la hauteur
         * aux valeurs des paramêtres
         * 
         */
        ImagePGM(size_t width, size_t height);

        /**
         * 
         * @brief Constructeur à 3 paramêtres.
         * 
         * @param width Largeur de l'image.
         * @param height Hauteur de l'image.
         * @param data Niveau de gris.
         * 
         * @note Initialise la largeur et la hauteur
         * et de niveaux de gris aux valeurs des paramêtres
         * 
         */
        ImagePGM(size_t width, size_t height, octet* data);

        /**
         * 
         * @brief Constructeur mono-paramêtre.
         * 
         * @param other Objet ImagePGM.
         * 
         * @note Initialise l'objet aux attributs
         * de other.
         * 
         */
        ImagePGM(const ImagePGM& other);

        /**
         * 
         * @brief Destructeur.
         * 
         * @note Libère l'espace mémoire occupé.
         * par data.
         * 
         */
        ~ImagePGM();


        /* Getters */
        /**
         * 
         * @brief Accesseur sur la moyenne.
         * @return unsigned char.
         * 
         * @note Retourne la moyenne des niveaux de gris
         * de l'image.
         * 
         */
        octet average() const;

        /**
         * 
         * @brief Accesseur sur l'histogramme.
         * 
         * @return Liste de valeur flottantes.
         * 
         * @note Retourne l'histogramme de l'image.
         * 
         */
        float* histo() const;

        /**
         * 
         * @brief Accesseur sur l'histogramme.
         * 
         * @return Liste de valeurs flottantes.
         * 
         * @note Retourne la distribution de probabilité de l'image.
         * 
         */
        float* ddp() const;


        /* Comparaison */
        /**
         * 
         * @brief Accesseur sur l'histogramme.
         * 
         * @param other Objet ImagePGM.
         * @return Valeur flottante.
         * 
         * @note Calcul l'erreur moyenne entre les deux images à
         * conditions qu'elles soient de même taille.
         * 
         */
        float mse(const ImagePGM& other) const;

        /**
         * 
         * @brief Accesseur sur l'histogramme.
         * 
         * @param other Objet ImagePGM.
         * @return Valeur flottante.
         * 
         * @note Calcul le psnr entre les deux images a conditions qu'elles soient
         * de même taille.
         * 
         */
        float psnr(const ImagePGM& otehr) const;

        /**
         * 
         * @brief Accesseur sur l'histogramme.
         * 
         * @param other Objet ImagePGM.
         * @return Valeur flottante.
         * 
         * @note Calcul la distance de Battacharryya entre
         * les 2 distributions des images.
         * 
         */
        float bhattacharyyaDist(const ImagePGM& other) const;

        /**
         * 
         * @brief Accesseur sur l'histogramme
         * 
         * @param other Objet ImagePGM
         * @return Valeur flottante
         * 
         * @note Calcul la distance du chi-2 entre
         * les 2 distributions des images.
         * 
         */
        float chi2(const ImagePGM& other) const;

        /**
         * 
         * @brief Accesseur sur l'histogramme
         * 
         * @param other Objet ImagePGM
         * @return Valeur flottante
         * 
         * @note Calcul la divergence de Kullback-Leibler entre
         * les 2 distributions des images.
         * 
         */
        float hellingerDist(const ImagePGM& other) const;


        float jensenShannonDiv(const ImagePGM& other) const;


        /* Setters */
        /**
         * 
         * @brief Setters sur la taille.
         * 
         * @param width Nouvelle largeur.
         * @param height Nouvelle hauteur.
         * 
         * @note Redimensionne l'image à la largeur et 
         * longeur passées en paramêtres
         * 
         */
        void resize(size_t width, size_t height) override;

        /**
         * 
         * @brief Méthode de segmentation.
         * 
         * @param block_size Taille des blocs
         * 
         * @note Segmente l'image en blocs de tailles
         * block_size.
         * 
         */
        void segment(size_t block_size) override;

        /**
         * 
         * @brief Méthode de génération de mosaïques.
         * 
         * @param block_size Taille des blocs
         * @param lib_path Chemin d'accès à la base d'image. 
         * @param lib_size Nombre d'image souhaitée pour la 
         * génération.
         * 
         * @note Génère une image mosaic de blocs de taille block_size
         * à partir de lib_size images contenues dans le dossier lib_path.
         * 
         */
        void mosaic(size_t block_size, const char* lib_path, size_t lib_size, int mode) override;

        
        /* Opérateurs */
        /**
         * 
         * @brief Opérateur d'égalité.
         * 
         * @param other Objet ImagePGM.
         * @return Reference d'ImagePGM.
         * 
         * @note Copie l'objet en paramêtres dans l'objet courant
         * et retourne la référence de celui-ci.
         * 
         */
        ImagePGM& operator= (const ImagePGM& other);

        /**
         * 
         * @brief Opérateur d'accès constant.
         * 
         * @param i Indice de ligne.
         * @return Adresse d'unsigned char.
         * 
         * @note Retourne un pointeur vers le premier
         * élément de la ligne i.
         * 
         */
        octet* operator[] (size_t i);


        /* Méthodes de chiffrements */
        /**
         * 
         * @brief Méthode de permutation.
         * 
         * @param block_size Taille des blocs.
         * @return Liste de permutations
         * 
         * @note Permute les blocs de taille block_size
         * qui composent l'image.
         * 
         */
        size_t* swap(size_t block_size) override;

        /**
         * 
         * @brief Méthode de trie.
         * 
         * @param block_size Taille des blocs.
         * 
         * @note Remet les blocs en ordre les blocs
         * à l'aide de la liste des permutations.
         * 
         */
        void sort(size_t block_size, size_t* key) override;

        /**
         *
         * @brief Méthode de chiffrement
         * 
         * @param key_path chaine de caractère constante.
         * 
         * @note Chiffre l'image et la stocke dans key_path
         * 
         */
        void vernamEncrypt(const char* key_path) override;

        /**
         * 
         * @brief Méthode du déchiffrement de Vernam.
         * 
         * @param key_path chaine de caractère constante.
         * 
         * @note Déchiffre l'image stockée a key_path.
         * 
         */
        void vernamDecrypt(const char* key_path) override;

        /* Lecture et écriture  */

        /**
         * 
         * @brief Méthode de lecture d'image.
         * 
         * @param path Chemin d'accès à l'image.
         * 
         * @note Ouvre et lit l'image se trouvant
         * à path.
         * 
         */
        bool read(const char* path) override;

        /**
         * 
         * @brief Méthode d'écriture d'image.
         * 
         * @param path Chemin d'accès à l'image.
         * 
         * @note Ouvre et ou créé un fichier se trouvant à
         * path et écrit les donnée de l'image à l'intérieur.
         * 
         */
        bool write(const char* path, const char* comment) override;
};

#endif // IMAGE_PGM_HPP