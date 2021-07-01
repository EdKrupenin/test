#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <utility>
#include <vector>

/// Функция для печати координат в консоли
/// \param coordinates Вектор с координатами х и у
void printCoordinates(std::vector<std::pair<double,double>> &coordinates){
    for (int j = 0; j < coordinates.size(); ++j) {
        std::cout << "x = " << coordinates[j].first << " y = " << coordinates[j].second << std::endl;
    }
}

/// Функция получения координат из файла
/// \param file ссылка на файл с координатами
/// \param doubleCoordinates ссылка на вектор который надо заполнить
void getCoordinates(std::ifstream &file, std::vector< std::pair<double, double>> &doubleCoordinates){
    std::regex regular ("(.*?);(.*)");  //Регулярное выражение для поиска координат разделенных ;
    std::regex dot (",");               //Регулярное выражение для унификиции разделителя
    std::cmatch result;                      //Результат поиска с помощью регулярного выражения
    std::string s;                           //Строка для считывания из файла
    while(!file.eof()){
        file>>s;
        std::regex_search(s.c_str(), result, regular);
        doubleCoordinates.push_back(std::make_pair(atof(std::regex_replace
                                                   (result[1].str().c_str(),dot,".").c_str()),
                                                   atof(std::regex_replace
                                                   (result[2].str().c_str(),dot,".").c_str())));
    }
}

int main() {
    setlocale(LC_NUMERIC, "C");
    std::vector< std::pair<double, double>> doubleCoordinates; //Вектор из коррдинат х, у
    std::ifstream file;
    try{
        file.open("C:\\Project\\test\\STC\\file.txt"); // Открытие файла
        file.exceptions ( std::ifstream::failbit);
        getCoordinates(file,doubleCoordinates);
        printCoordinates(doubleCoordinates);
        file.close();
    }
    catch (const std::ifstream::failure& e) {
        std::cout << "Exception opening/reading file";
    }
    return 0;
}