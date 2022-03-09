#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Cars {carType
  enum {MAX_CHAR_LEN = 500};
  char name[MAX_CHAR_LEN] = {' '};
  double MPG;
  int Cylinders;
  double Displacement;
  double Horsepower;
  double Weight;
  double Acceleration;
  int Model;
  char Origin[30] = {' '};
  bool ValidEntry;
  Cars();
};

Cars::Cars(){
  MPG = 0;
  Cylinders = 0;
  Displacement = 0;
  Horsepower = 0;
  Weight = 0;
  Acceleration = 0;
  Model = 0;
  ValidEntry = false;
}

const int carAmount = 406;

void readCarz(Cars carType[carAmount], ifstream &carFile) {
  for(int index = 0; index < carAmount; index++){
  carFile.get(carType[index].name, Cars::MAX_CHAR_LEN, ';');
  carFile.ignore(100,';');
  carFile >> carType[index].MPG;
  carFile.ignore(100,';');
  carFile >> carType[index].Cylinders;
  carFile.ignore(100,';');
  carFile >> carType[index].Displacement;
  carFile.ignore(100,';');
  carFile >> carType[index].Horsepower;
  carFile.ignore(100,';');
  carFile >> carType[index].Weight;
  carFile.ignore(100,';');
  carFile >> carType[index].Acceleration;
  carFile.ignore(100,';');
  carFile >> carType[index].Model;
  carFile.ignore(100,';');
  carFile >> carType[index].Origin;
  carFile.ignore(100,'\n');
  carType[index].ValidEntry = !carFile.eof();
  }
}

void printCarz(Cars carType[carAmount], int carAmount){
  for(int index = 0; index < carAmount; index++){
    if(carType[index].ValidEntry == true){
    cout << "index " << index << "; ";
    cout << carType[index].name << ';';
    cout << carType[index].MPG << ';';
    cout << carType[index].Cylinders << ';';
    cout << carType[index].Displacement << ';';
    cout << carType[index].Horsepower << ';';
    cout << carType[index].Weight << ';';
    cout << carType[index].Acceleration << ';';
    cout << carType[index].Model << ';';
    cout << carType[index].Origin << ';' << endl;
    }
  }
}

void printOriginCar(Cars carType[carAmount], int carAmount){
  char Origin2[30];
  cout << "Pick an Origin, Japan, US, Europe." << endl;
    cin >> Origin2;

  for(int index = 0; index < carAmount; index++){
    if(strcmp(Origin2, carType[index].Origin) == 0){
      if(carType[index].ValidEntry != false){
        cout << carType[index].name << ';';
    cout << carType[index].MPG << ';';
    cout << carType[index].Cylinders << ';';
    cout << carType[index].Displacement << ';';
    cout << carType[index].Horsepower << ';';
    cout << carType[index].Weight << ';';
    cout << carType[index].Acceleration << ';';
    cout << carType[index].Model << ';';
    cout << carType[index].Origin << ';' << endl;
      }
  }
    }
  }

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

void delCar(Cars carType[carAmount], int carAmount){
  int index = 0;
  cout << "What car index do you want to delete?" << endl;
  cin >> index;
    if(carType[index].ValidEntry == true){
      carType[index].ValidEntry = false;
  }
  cout << "Car index: " << index << " has been deleted." << endl;
  printCarz(carType, carAmount);
  }

void addCar(Cars carType[carAmount], int carAmount){
  for(int index = 0; index < carAmount; index ++){
    if(carType[index].ValidEntry == false){
      int addC = index;
  //cin.ignore(100, '\n');
cout << "Enter name: ";
 cin >> carType[addC].name;
 carType[addC].MPG = readDouble("Enter MPG: ");
  carType[addC].Cylinders = readInt("Enter Cylinders: ");
  carType[addC].Displacement = readDouble("Enter Displacement: ");
  carType[addC].Horsepower = readDouble("Enter Horsepower: ");
  carType[addC].Weight = readDouble("Enter Weight: ");
  carType[addC].Acceleration = readDouble("Enter Acceleration: ");
  carType[addC].Model = readInt("Enter Model: ");
  cout << "Enter Origin: ";
  cin >> carType[addC].Origin;
  carType[addC].ValidEntry = true;
 cout << "Car added." << endl;
  printCarz(carType, carAmount);
      break;
    }
  }
}
void carMenu(Cars carType[carAmount], int carAmount){
  int option = 0;
  while(option != 5){
  cout << "Welcome to my car dealership." << endl;
  cout << "Pick an option." << endl;
  cout << "1. Print cars" << endl;
  cout << "2. Print Origin cars" << endl;
  cout << "3. Delete car" << endl;
  cout << "4. Add car" << endl;
  cout << "5. Quit" << endl;
  cin >> option;
  while(option < 1 && option > 5){
  cout << "Pick an option." << endl;
  cout << "1. Print cars" << endl;
  cout << "2. Print Origin cars" << endl;
  cout << "3. Delete car" << endl;
  cout << "4. Add car" << endl;
  cout << "5. Quit" << endl;
  cin >> option;
  }
  if(option == 1){
    printCarz(carType, carAmount);
  }
  if(option == 2){
    printOriginCar(carType, carAmount);
  }
  if(option == 3){
    delCar(carType, carAmount);
  }
  if(option == 4){
    addCar(carType, carAmount);
  }
    }
    }

int main(){
  ifstream carFile("cars.txt");
  Cars carType[carAmount];
  readCarz(carType, carFile);
  carMenu(carType, carAmount);
  return 0;
}