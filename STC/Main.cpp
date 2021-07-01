#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <utility>
#include <vector>
#include <string.h>

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
    file.close();
}

/// Поменять координаты x,y местами
/// \param coordinate одно из значений вектора
void swap(std::pair<double,double> &coordinate){
    double tmp = coordinate.first;
    coordinate.first = coordinate.second;
    coordinate.second = tmp;
}

/// Запрос на инверсию координат
/// \param doubleCoordinates
void swapQuestions(std::vector< std::pair<double, double>> &doubleCoordinates){
    int answer;
    std::cout << "Do you want swap X and Y ? Press 1. Not - press 0" <<std::endl;
    std::cin>>answer;
    if(answer == 1){
        for (int i = 0; i < doubleCoordinates.size() ; ++i) {
            swap(doubleCoordinates[i]);
            //doubleCoordinates[i].swap(doubleCoordinates[i+1]); Поменять соседние пары х у местами !!! следить за i+1 и
            // не выйти за границы массива
        }
    }
}

/// Функция записи в бинарный файл
/// \param tab ссылка на экземпляр файла
void writeBin(std::fstream &tab){
    /*
        binFile.open("C:\\Project\\test\\STC\\binFile.bin", std::ios::binary);
        for (int i = 0; i < doubleCoordinates.size() ; ++i) {
            binFile<<doubleCoordinates[i].first<<";"<<doubleCoordinates[i].second<<"\n";
        }
        binFile.close();
    */
    std::string sout;
    for(size_t i = 0; i < doubleCoordinates.size(); i++)
    {
        size_t size = sizeof(doubleCoordinates[i])+sizeof(";")+sizeof("\n");
        // пишем в файл длину строки:
        tab.write( (char *)&size, sizeof(size) );
        sout = std::to_string(doubleCoordinates[i].first) + ';' + std::to_string(doubleCoordinates[i].second) + '\n';
        // теперь саму строку:
        tab.write( sout.c_str(), size );
    }
    tab.close();
}

/// Функция чтения координат из бинарного файла
/// \param file сслыка на файл
/// \param doubleCoordinatesBin сслыка на вектор с координатами
void readBin(std::ifstream &file,std::vector< std::pair<double, double>> &doubleCoordinatesBin){
    std::string s;
    int size = 0;
    file.seekg (0, std::ios::end);
    size = file.tellg();
    std::cout << "file length : " << size << " bytes" << std::endl;
    file.seekg (0, std::ios::beg);

    while ( size > 0 )
    {
        size_t size_len;
        // читаем длину очередной строки:
        file.read( (char *)&size_len, sizeof(size) );
        // читаем саму строку:
        file>>s;
        std::cout  << s <<std::endl ;
        size-=sizeof(s);
        std::regex regular ("(.*?);(.*)");  //Регулярное выражение для поиска координат разделенных ;
        std::cmatch result;                      //Результат поиска с помощью регулярного выражения
        std::regex_search(s.c_str(), result, regular);
        doubleCoordinatesBin.push_back(std::make_pair(atof(result[1].str().c_str()),
                                                      atof(result[2].str().c_str())));
    }
    file.close();
}

int main() {
    setlocale(LC_NUMERIC, "C");
    std::vector< std::pair<double, double>> doubleCoordinates; //Вектор из коррдинат х, у
    std::vector< std::pair<double, double>> doubleCoordinatesBin; //Вектор из коррдинат х, у
    std::ifstream file;
    std::ofstream binFile;
    try{
        file.open("C:\\Project\\test\\STC\\file.txt"); // Открытие файла
        file.exceptions ( std::ifstream::failbit);
        getCoordinates(file,doubleCoordinates);
        printCoordinates(doubleCoordinates);
        swapQuestions(doubleCoordinates);
        printCoordinates(doubleCoordinates);

        std::fstream tab("C:\\Project\\test\\STC\\binFile.bin", std::ios::binary | std::ios::out);
        writeBin(tab);

        file.open("C:\\Project\\test\\STC\\binFile.bin", std::ios::binary| std::ios::in );
        readBin(file,doubleCoordinatesBin);

        printCoordinates(doubleCoordinatesBin);

        doubleCoordinatesBin.clear();
        doubleCoordinates.clear();
    }
    catch (const std::ifstream::failure& e) {
        std::cout << "Exception opening/reading file";
    }
    return 0;
}