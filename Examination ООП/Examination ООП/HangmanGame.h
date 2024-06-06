#pragma once // директива, обеспечивающая защиту от двойного включения заголовочного файла 
//это означает что этот файл будет включен только один раз в состав проекта

#include "DisplayInformation.h" // Подключение абстактного класса HangmanGame наследник класса DisplayInformation
#include <iostream> // подключение библиотеки для работы с потоками ввода/вывода
#include <ctime> // подключение библиотеки для работы с временем
#include <string> // подключение библиотеки для работы со строками
#include <fstream> // подключение библиотеки для работы с файлами ввода/вывода

using namespace std; // Использование пространства имен std для того чтобы постоянно не писать std:: 

class HangmanGame : public DisplayInformation { // Объявление класса HangmanGame, который наследует функционал из класса DisplayInformation
private: // раздел, где указываются приватные члены класса
    string encryptedWord; // строка для хранения зашифрованного слова
    string secretWord; // строка для хранения секретного слова
    int attempts; // целое число для отслеживания количества попыток игрока
    string guessedLetters; // Строка для хранения угаданных букв

public: // раздел, где указываются публичные члены класса, которые будут доступны извне
    HangmanGame(const string& filename); // конструктор класса, который принимает имя файла для загрузки слов для игры
    int countWordsInFile(const string& filename); // метод для подсчета количества слов в файле
    string loadRandomWordFromFile(const string& filename); // метод для загрузки случайного слова из файла
    string decryptWord(const string& encryptedWord); // Метод для расшифровки слова.
    bool guessLetter(char guess); // метод для угадывания буквы
    bool isGameOver(); // метод для проверки завершения игры
    bool guessLetterAndDisplayHangman(char guess); // метод для угадывания буквы и отображения состояния игры
    void displayGreetingOutput(); // метод для вывода приветственного сообщения
    void displaySecretWord(); // метод для вывода секретного слова
    void displayMistakes(); // метод для вывода информации о ошибках игрока
    void displayHangman(int attempts); // метод для вывода состояния виселицы
    string getEncryptedWord(); // метод для получения зашифрованного слова
    int getAttempts(); // метод для получения количества попыток
};