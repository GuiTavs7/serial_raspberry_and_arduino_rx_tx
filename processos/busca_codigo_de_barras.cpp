#include <iostream>
#include <vector>

int main() {
    std::vector<long> pedido = {131974, 131974, 131394, 131974, 131974, 132799, 132611, 132611, 132751};
    std::vector<float> largura = {0.81, 0.86, 0.87, 0.93, 0.96, 0.96, 1, 1, 1.01};
    std::vector<float> altura = {1.35, 1.25, 1.2, 1.35, 1.25, 2.4, 2.49, 2.49, 2.6};

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        long codigo;
        std::cout << "Digite um código de barras válido: ";
        std::cin >> codigo;

        bool encontrado = false;
        for (size_t i = 0; i < pedido.size(); i++) {
            if (pedido[i] == codigo) {
                std::cout << "Codigo de barras encontrado: " << pedido[i] << std::endl;
                std::cout << "Altura: " << altura[i] << std::endl;
                std::cout << "Largura: " << largura[i] << std::endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            std::cout << "Código de barras não encontrado." << std::endl;
        }

        std::cout << "Deseja digitar mais um código? (S/N): ";
        std::cin >> continuar;
    }

    std::cout << "Programa encerrado." << std::endl;

    return 0;
}