
#include <iostream>
#include <vector>

// Fonction pour "heapify" un sous-arbre
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;        // Racine initialement considérée comme la plus grande
    int left = 2 * i + 1;   // Indice du fils gauche
    int right = 2 * i + 2;  // Indice du fils droit

    // Si le fils gauche est plus grand que la racine
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si le fils droit est plus grand que la racine
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si la racine n'est pas la plus grande
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Appliquer récursivement heapify sur le sous-arbre affecté
        heapify(arr, n, largest);
    }
}

// Fonction principale pour effectuer le tri par tas
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Construire un tas max (réorganiser le tableau)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraire les éléments un par un du tas
    for (int i = n - 1; i > 0; i--) {
        // Déplacer la racine actuelle à la fin
        std::swap(arr[0], arr[i]);

        // Réappliquer heapify sur le tas réduit
        heapify(arr, i, 0);
    }
}

// Fonction principale pour tester le code
int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    std::cout << "Tableau avant le tri : ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Tableau apres le tri : ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
