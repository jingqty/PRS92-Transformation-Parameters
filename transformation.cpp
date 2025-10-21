
//Translation
//deltaX  = 127.62195 meters 
//deltaY  = 67.24478 meters 
//deltaZ  = 47.04305 meters 

//Rotation (decimal)
//rotX = -0.0008521166667
//rotY =  0.001361919444      
//rotZ =  0.0004383055556

//Rotation (rad) *most sources requires conversion to rad*
//double rotX = -0.00001487224144;
//double rotY =  0.00002376997845;
//double rotZ =  0.000007649875074;

//scale = 1.06002

#include <iostream>
#include <limits>
#include <windows.h>

int main(){

    int choice;
    bool repeat = false;
    double x, y, z;

    //Translation
    double deltaX  = 127.62195;
    double deltaY  = 67.24478;  
    double deltaZ  = 47.04305;

    //Rotation (rad)
    double rotX = -0.00001487224144;
    double rotY =  0.00002376997845;
    double rotZ =  0.000007649875074;

    double scaleParameter = 1.00000106002;


//MATRICES
    double rotation[3][3] = {
        {    1,  rotZ,  -rotY},
        {-rotZ,     1,   rotX},
        { rotY, -rotX,      1}
    };

    double negativeRotation[3][3] = {
        {    1,  -rotZ,  rotY},
        {rotZ,     1,   -rotX},
        { -rotY, rotX,      1}
    };

    double translation[3][1] = {
        {deltaX},
        {deltaY},
        {deltaZ}
    };

    double temp_results[3][1] = {
        {0},
        {0},
        {0}
    }; 

    double coordinates[3][1] = {{x}, {y}, {z}};

while(true){
    do{
        std::cout << "Coordinate Transformation:" << std::endl;
        std::cout << "(1) from WGS84 to PRS92" << std::endl;
        std::cout << "(2) from PRS92 to WGS84" << std::endl;
        std::cout << "Enter Choice:";
        std::cin >> choice;

        switch (choice) {
        case 1:     //WGS84 to PRS92
        system("cls");

                std:: cout << "Enter WGS84 coordinates" << std::endl;
                std:: cout << "X-coordinate:";
                std:: cin >> x;
                std:: cout << "Y-coordinate:";
                std:: cin >> y;
                std:: cout << "Z-coordinate:";
                std:: cin >> z;

            coordinates[0][0] = x; //redeclare
            coordinates[1][0] = y;
            coordinates[2][0] = z;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                    temp_results[i][0] += rotation[i][j] * coordinates[j][0];
            }
        }
        
        for (int i = 0; i < 3; i++){
            std:: cout << std::fixed << translation[i][0] + scaleParameter * temp_results[i][0] << std::endl;
        }
        repeat = true;
            break;


        case 2: //PRS92 to WGS84

        system("cls");

                std:: cout << "Enter PRS92 coordinates" << std::endl;
                std:: cout << "X-coordinate:";
                std:: cin >> x;
                std:: cout << "Y-coordinate:";
                std:: cin >> y;
                std:: cout << "Z-coordinate:";
                std:: cin >> z;   

                coordinates[0][0] = x;
                coordinates[1][0] = y;
                coordinates[2][0] = z;
                
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                    temp_results[i][0] += negativeRotation[i][j] * coordinates[j][0];
            }
        }
        
        for (int i = 0; i < 3; i++){
            std:: cout << std::fixed << -translation[i][0] + scaleParameter * temp_results[i][0] << std::endl;
        }
        repeat = true;
            break;

        default:
        system("cls");
        std::cout << "Invalid Option" << std::endl;
            break;
        }

    }while(!repeat);

std::cout << "\nPress Enter To Return";   //Prevent exe file to close instantly    
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::cin.get();
system("cls");
};
    return 0;
}