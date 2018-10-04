#include <iostream>

using namespace std;

int matrix[1000][1000], n, m, found=0;

int busqueda(int x, int y){
    if(matrix[x][y] == 1){
        matrix[x][y] = 2;
        found = 1;
        return 1;
    }
    else {
        if(matrix[x][y] == 2 || matrix[x][y] == -1 || found) return 0;
        matrix[x][y] = 2;
        cout << x << ' ' << y << endl;
        int rooms = 1;
        if(y+1 < m) rooms += busqueda(x, y+1);
        if(x-1 >= 0) rooms += busqueda(x-1, y);
        if(y-1 >= 0) rooms += busqueda(x, y-1);
        if(x+1 < n) rooms += busqueda(x+1, y);
        return rooms;
    }
}

int main() {
    int x_start, y_start, x_blue, y_blue;
    cin >> n >> m;
    cin >> x_blue >> y_blue;
    cin >> x_start >> y_start;

    matrix[x_blue][y_blue]++;
    cout << busqueda(x_start, y_start);

    return 0;
}
