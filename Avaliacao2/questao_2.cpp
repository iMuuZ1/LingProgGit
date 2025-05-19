
#include <iostream>

#include <vector>



int main() {



    int num;

    int cols = 4;

    int rows = 2;

   

 // Declara uma matrix rows x cols



    std::vector<int> vector(array, array + sizeof(array) / sizeof(int));
        std::vector<std::vector<int>> matrix = {
        {20, 10, 50},
        {40, 30, 60},
        {70, 80, 90}
    };

    // Print vector elements
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << "Element " << i << ": " << vector[i] << std::endl;
    }





    return 0;

}