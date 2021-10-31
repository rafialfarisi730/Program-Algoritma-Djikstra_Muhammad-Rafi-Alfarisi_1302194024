#include <iostream>
using namespace std;
#define INF 999

// program utama
int main() {
    cout << "Nama  : Muhammad Rafi Alfarisi" << endl;
    cout << "NIM   : 1302194024" << endl;
    cout << "Kelas : SE-43-03" << endl;
    cout << endl;

    // inisalisasi variable
    int i, j, source, target, start, minimum, m, update, ver, min_weight;
    cout << "-----------PROGRAM ALGORITMA DIJKSTRA-----------" << endl;
    // masukkan jumlah vertex yang diinginkan
    cout << "Masukkan Jumlah Vertex yang diinginkan : ";
    cin >> ver; ver++;
    // inisialisasi matriks bobot, buffer, visited dll
    int weight[ver][ver], buff[ver], path[ver], prev[ver], visited[ver]={0};
    // inisalisasi nilai awal bobot, buffer, dll
    for(i = 1; i < ver; i++) {
        buff[i] = INF;
        prev[i] = -1;
        path[i] = 0;
        for(int j = 1;j < ver; j++) {
            weight[i][j] = INF;
        }
    }
    // memasukkan nilai bobot
    for(i = 1;i < ver; i++) {
        for(j = i+1; j < ver; j++)
        {
            cout << "Masukkan bobot " << i << " ke " << j << " : ";
            cin >> weight[i][j];
            weight [j][i] = weight[i][j];
        }
        cout << endl;
    }
    // masukkan vertex awal dan tujuan
    cout << "Masukkan Vertex Awal : ";
    cin >> source;
    cout << "Masukkan Vertex Tujuan : ";
    cin >> target;

    start = source;
    visited[start]=1;
    buff[start] = 0;
    // proses mencari bobot terkecil
    while(visited[target] == 0) {
        minimum = INF;
        m = 0;
        for(i=1;i< ver;i++) {
            update = buff[start] + weight[start][i];
            // cek vertex yang sudah dikunjungi
            if(update < buff[i] && visited[i]==0) {
                buff[i] = update;
                prev[i] = start;
            }
            if(minimum > buff[i] && visited[i]==0) {
                minimum = buff[i];
                m = i;
            }
        }
        start = m;
        visited[start] = 1;
    }
    // bobot terkecil
    min_weight = buff[target];
    // mulai backtracking
    start = target;
    j = 0;
    // mencari vertex yang dikunjungi
    while(start != -1) {
        path[j] = start;
        start = prev[start];
        j++;
    }
    // menampilkan bobot terkecil yang dilalui
    cout << "Bobot terkecil yang dilalui adalah " << min_weight << endl;
    // menampilkan vertex yang dikunjungi
    cout << "Jalur yang ditempuh adalah : ";
    for (int i = ver-1; i >= 0; i--) {
        if (path[i] != 0) {
            cout << path[i] << " ";
        }
    }
    cout << endl;
}
