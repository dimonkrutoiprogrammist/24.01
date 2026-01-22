#include <iostream>
using namespace std;

//Функция для удаления строки по указанному номеру
int** DeleteRows(int** matrix, int& rows, int cols, int position) {
    
    if (position < 0 || position >= rows) {
        cout << "Ошибка!" << endl;
        return matrix;
    }
    
    
    int** new_matrix = new int*[rows - 1];
    
  
    delete[] matrix[position];
    
    //копируем 
    int new_index = 0;
    for (int i = 0; i < rows; i++) {
        
        if (i != position) {
            new_matrix[new_index] = matrix[i];
            new_index++;
        }
    }
    
    // старый массив
    delete[] matrix;
    
  
    rows = rows - 1;
    
    //готовый массив
    return new_matrix;
}


int main() {
    setlocale(LC_ALL, "ru");
    
    int rows = 3; 
    int cols = 3;

 
    int** matrix = new int*[rows];

    //Цикл
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }

  
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

  
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

 
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    //Вывод
    cout << "Исходный массив" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    matrix = DeleteRows(matrix, rows, cols, 1); //Вызов функции

    //Вывод
    cout << "Итоговый массив" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    //очищаем память
    for(int i = 0; i < rows; i++){
        delete[] matrix[i]; 
    }
    delete[] matrix;

    return 0;
}
