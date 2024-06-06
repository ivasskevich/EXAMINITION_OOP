#include "HangmanGame.h"

HangmanGame::HangmanGame(const string& filename) : attempts(0), guessedLetters("") { 
    // конструктор класса HangmanGame, который инициализирует пол€ этого класса
    srand(time(0));
    encryptedWord = loadRandomWordFromFile(filename);
    secretWord = decryptWord(encryptedWord);
}

int HangmanGame::countWordsInFile(const string& filename) {
    // метод дл€ подсчета количества слов в указанном файле
    // ќткрываетс€ файл, считываютс€ строки, и дл€ каждой строки увеличиваетс€ счетчик
    ifstream file(filename);
    int count = 0;
    string word;

    if (!file.is_open()) {
        cout << "Error when uploading a file" << endl;
        exit(0);
    }

    while (getline(file, word)) {
        count++;
    }

    file.close();
    return count;
}

string HangmanGame::loadRandomWordFromFile(const string& filename) {
    // метод дл€ загрузки случайного слова из файла. ¬ызываетс€ метод countWordsInFile 
    // дл€ определени€ количества слов в файле, затем выбираетс€ случайный индекс
    // и это слово считываетс€ из файла
    int wordCount = countWordsInFile(filename);
    ifstream file(filename);
    string word;
    int randomIndex = rand() % wordCount;

    if (!file.is_open()) {
        cout << "Error when uploading a file" << endl;
        exit(0);
    }

    for (int i = 0; i < randomIndex; i++) {
        getline(file, word);
    }

    file.close();
    return word;
}

string HangmanGame::decryptWord(const string& encryptedWord) {
    // метод дл€ расшифровки слова. —оздаетс€ копи€ зашифрованного слова
    // и дл€ каждого символа, €вл€ющегос€ буквой, устанавливаетс€ символ '_'
    string decryptedWord = encryptedWord;
    for (int i = 0; i < decryptedWord.length(); i++) {
        if (isalpha(decryptedWord[i])) {
            decryptedWord[i] = '_';
        }
    }
    return decryptedWord;
}

bool HangmanGame::guessLetter(char guess) {
    // метод дл€ угадывани€ буквы. ѕровер€етс€ каждый символ зашифрованного слова, 
    // и если он совпадает с угаданной буквой, то соответствующий символ в секретном слове 
    // замен€етс€ на угаданную букву
    bool found = false;
    for (int i = 0; i < encryptedWord.length(); ++i) {
        if (isalpha(encryptedWord[i]) && encryptedWord[i] == guess) {
            secretWord[i] = guess;
            found = true;
        }
    }
    return found;
}

bool HangmanGame::isGameOver() {
    // метод дл€ проверки завершени€ игры. ¬озвращает true, если количество попыток (attempts) равно 6
    return (attempts == 6);
}

bool HangmanGame::guessLetterAndDisplayHangman(char guess) {
    // метод дл€ угадывани€ буквы и отображени€ состо€ни€ "виселицы"
    // если буква не угадана, она добавл€етс€ к списку угаданных букв
    // увеличиваетс€ количество попыток и вызываетс€ метод отображени€ "виселицы"
    if (!guessLetter(guess)) {
        guessedLetters += guess;
        attempts++;
        displayHangman(attempts);
    }
    return secretWord == encryptedWord;
}

void HangmanGame::displayGreetingOutput() { // метод дл€ вывода приветственного сообщени€
    cout << "Welcome to the game 'Hangman'!" << endl;
    cout << "You have 6 tries to guess the word" << endl;
    cout << "The words related to the names of cities" << endl;
}

void HangmanGame::displaySecretWord() { // метод дл€ вывода секретного слова
    cout << "Word: " << secretWord << endl;
}

void HangmanGame::displayMistakes() { // метод дл€ вывода информации о допущенных ошибках
    cout << "Mistakes (" << attempts << "): " << guessedLetters << endl;
}

void HangmanGame::displayHangman(int attempts) {
    // метод дл€ вывода состо€ни€ "виселицы" в зависимости от количества попыток
    switch (attempts) {
    case 1: cout << "        O" << endl; break;
    case 2: cout << "        O" << endl;
            cout << "        |" << endl; break;
    case 3: cout << "        O" << endl;
            cout << "       /|" << endl; break;
    case 4: cout << "        O" << endl;
            cout << "       /|\\" << endl; break;
    case 5: cout << "        O" << endl;
            cout << "       /|\\" << endl;
            cout << "       /" << endl; break;
    case 6: cout << "        O" << endl;
            cout << "       /|\\" << endl;
            cout << "       / \\" << endl; break;
    }
}

string HangmanGame::getEncryptedWord() { // метод дл€ получени€ зашифрованного слова
    return encryptedWord;
}

int HangmanGame::getAttempts() { // метод дл€ получени€ количества попыток
    return attempts;
}