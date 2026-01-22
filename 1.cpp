#include <iostream>
using namespace std;

//Функция для добавления строки в конец
int** AddRows(int** matrix, int& rows, int cols){
    
    int** new_matrix = new int*[rows + 1]; 

    //Цикл
    for(int i = 0; i < rows; i++){
        new_matrix[i] = matrix[i];
    }

    new_matrix[rows] = new int[cols]; //Создание массива 

    for(int j = 0; j < cols; j++){
        new_matrix[rows][j] = 10; //Заполнениеи
    }

    delete[] matrix; 

    rows = rows + 1;

    return new_matrix; 
    //Возвращаем итоговый массив
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

    matrix = AddRows(matrix, rows, cols); //Вызов

    //Вывод 
    cout << "Итоговый массив" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // очищаем память
    for(int i = 0; i < rows; i++){
        delete[] matrix[i]; 
    }
    delete[] matrix; 

    return 0;
}
