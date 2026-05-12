#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

class massive {
protected:
    vector<int> massive;
    int n;

public:
    void put_fill_massive() {
        cout << "Пожалуйста, введите кол-во элементов\n";
        cin >> n;
        cout << "Введите элементы массива\n";
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            massive.push_back(temp);
        }
        cout << "Массив успешно введен\n";
    }

    int get_len_massive() {
        return n;
    }

    bool get_yporadochen() {
        bool fl_sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (massive[i] < massive[i + 1]) {
                fl_sorted = false;
                break;
            }
        }
        return fl_sorted;
    }

    void print_massive() {
        for (int i = 0; i < n; i++) {
            cout << massive[i] << " ";
        }
    }

    void fill_from_vector(const vector<int>& vec) {
        massive = vec;
        n = vec.size();
    }
};

class massive_with_func : public massive {
private:
    bool is_prime(int number) {
        if (number < 2) return false;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    bool detect_only_easy() {
        for (int i = 0; i < n; i++) {
            if (!is_prime(massive[i])) {
                return false;
            }
        }
        return true;
    }
};

void inputMatrix(vector<vector<int>>& matrix, int& n, int& m) {
    cout << "Введите n - кол-во строк\n";
    cin >> n;
    cout << "Введите m - кол-во столбцов\n";
    cin >> m;

    matrix.resize(n, vector<int>(m));

    cout << "Введите элементы матрицы\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    massive_with_func mass1;
    int temp_n, temp_m;
    vector<vector<int>> matrix;

    inputMatrix(matrix, temp_n, temp_m);

    int count_only_prime_rows = 0;

    for (int i = 0; i < temp_n; i++) {
        massive_with_func current_row;
        current_row.fill_from_vector(matrix[i]);

        if (current_row.detect_only_easy()) {
            count_only_prime_rows++;
        }
    }

    cout << "Количество строк, содержащих только простые числа: " << count_only_prime_rows << endl;

    return 0;
}