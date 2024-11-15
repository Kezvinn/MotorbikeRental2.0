#include "./Functions/Functions.h"
#include <bits/stdc++.h>

#include "./System/system.h"
#include "./User/Member.h"
#include "./User/Admin.h"
#include "./Request/request.h"
using namespace std;

int main(){
    System system;
    system.init();
    system.mainMenu();
    // vector<int> vec = {10,20,20,20,30,30,20,20,10};
    // sort(vec.begin(), vec.end());
    // auto it = unique(vec.begin(), vec.end());

    // vec.resize(distance(vec.begin(), it));
    
    // for (it = vec.begin(); it!=vec.end(); ++it)
    //     cout << ' ' << *it;

    // Request rqst_1("RQ859", "M123", "M133", "B223", "12/12/2024", "20/12/2024", 56, "Pending");
    // Request rqst_2("RQ859", "M123", "M133", "B223", "12/12/2024", "20/12/2024", 56, "Pending");
    
    // if (rqst_1 == rqst_2){
    //     cout << "Equal" << endl;
    // } else {
    //     cout << "Not Equal" << endl;
    // }
    
    // int rows = 3;
    // int cols = 4;
    // std::vector<std::string> matrix(rows * cols);

    // // Populate the matrix
    // matrix[0 * cols + 0] = "A1";
    // matrix[0 * cols + 1] = "A2";
    // matrix[0 * cols + 2] = "A3";
    // matrix[0 * cols + 3] = "A4";

    // matrix[1 * cols + 0] = "B1";
    // matrix[1 * cols + 1] = "B2";
    // matrix[1 * cols + 2] = "B3";
    // matrix[1 * cols + 3] = "B4";

    // matrix[2 * cols + 0] = "C1";
    // matrix[2 * cols + 1] = "C2";
    // matrix[2 * cols + 2] = "C3";
    // matrix[2 * cols + 3] = "C4";

    // // Access the elements and print the matrix
    // for (int row = 0; row < rows; ++row) {
    //     for (int col = 0; col < cols; ++col) {
    //         std::cout << matrix[row * cols + col] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // readFile("Data/Requests.txt");
    return 0;
}

