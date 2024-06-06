#include "HangmanGame.h" // подключение заголовочных файлов 
#include "DisplayInformation.h"

using namespace std; // подключение пространства имен std

int main() { // главная функция в которой выполняется весь код
    HangmanGame game("words.txt"); // создание объекта HangmanGame 
    // а также передача имени файла где хранятся слова

    time_t startTime = time(nullptr); // инициализация переменных
    int numberOfAttempts = 0;

    game.displayGreetingOutput(); // вывод приветственного сообщения

    while (!game.isGameOver()) { // главный цикл игры

        game.displaySecretWord(); // вывод на экран слова со скрытыми буквами 
        game.displayMistakes(); // вывод на экран информации об ошибочном вводе игрока

        numberOfAttempts++;

        char guess; // игрок вводит букву, которую он считает правильной
        cout << "Letter: ";
        cin >> guess;
        cout << endl;

        if (game.guessLetterAndDisplayHangman(guess)) { // проверка введенной буквы и вывод результата
            cout << "Congratulations, you guessed the word: " << game.getEncryptedWord() << endl;
            break;
        }
    }

    if (game.getAttempts() == 6) { // вывод сообщения о завершении игры и результатах.
        cout << "Game over. You didn't guess the word. The word you guessed was: " << game.getEncryptedWord() << endl;
    }

    time_t endTime = time(nullptr); 
    int elapsedTime = static_cast<int>(endTime - startTime); 
    cout << "Time: " << elapsedTime << " seconds" << endl; // вывод времени, проведенного в игру, и другой информации об игре
    game.displayMistakes(); // вывод всех ошибок
    cout << "Number of attempts: " << numberOfAttempts << endl; // количество попыток чтобы угадать слово

    return 0;
}