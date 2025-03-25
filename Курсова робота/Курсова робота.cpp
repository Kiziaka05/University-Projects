#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>
#include <sstream>
#include <ctime>

using namespace std; 



string generateRandFacultet() {
    const int size = 10;
    string subjects[size] = { "IASA","FIOT","FPM","FBMI",
                          "FBT","IHF","XTF","FEA","FEL","PBF" };
    int index = rand() % 10;
    return subjects[index];

}
string generateRandLastName() {
    const int size = 20;
    string LastName[size] = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller",
        "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson",
        "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson" };
    int index = rand() % 20;
    return LastName[index];
}


// Структура для збереження даних студента
class StudentRecord {
public:
    string lastName;
    int score;
    string facultets;
    int PercentofVisitedLessons;

    // Конструктори
    StudentRecord(const string& name, int s, const string& facultet, int p)
        : lastName(name), score(s), facultets(facultet), PercentofVisitedLessons(p) {}
    StudentRecord()
        : lastName(""), score(0), facultets(""), PercentofVisitedLessons(0) {}

    friend std::ostream& operator<<(std::ostream& out, const StudentRecord& data) {
        out << "Student(" << data.lastName << " has average mark of " << data.score
            << ", facultet: " << data.facultets
            << ", percent of visited lessons: " << data.PercentofVisitedLessons << ")";
        return out;
    }
};

// Клас, що реалізує хеш-таблицю
class HashTable {
protected:
    // Внутрішній ланцюжок
    vector<list<StudentRecord>> table;
    // Розмір таблиці
    int TABLE_SIZE;
    //поточна кількість елементів
    int cursize;
    //фактор навантаженості
    const float LOAD_FACTOR = 0.75;
    // Функція хешування
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    // Конструктор з параметром
    HashTable() {
        TABLE_SIZE = 11; // Початковий розмір таблиці
        table.resize(TABLE_SIZE);
        cursize = 0;
    }
    
    // Деструктор
    ~HashTable() {
        cout << "HashTable is being destroyed" << endl;
    }

    //переміщення пам'яті у нову місце
    void resizeTable() {
        int newTableSize = TABLE_SIZE * 2;
        vector<list<StudentRecord>> newTable(newTableSize);

        for (const auto& bucket : table) {
            for (const auto& record : bucket) {
                int newIndex = hashFunction(record.lastName) % newTableSize;
                newTable[newIndex].push_back(record);
            }
        }

        table = std::move(newTable);
        TABLE_SIZE = newTableSize;
    }

    //загрузити дані з файлу
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open the file." << endl;
            return;
        }
        string lastName, facultet;
        int score, percent;
        while (file >> lastName >> score >> facultet >> percent) {
            insertRecord(lastName, score, facultet, percent,0);
        }
        file.close();
    }

    // Функція вставки запису
    virtual void insertRecord(const string& lastName, int score, const string& facultet, int percentVisited,bool test) {
        if (static_cast<float>(cursize) / TABLE_SIZE >= LOAD_FACTOR) {
            resizeTable();
        }
        int index = hashFunction(lastName);
        StudentRecord newRecord(lastName, score, facultet, percentVisited);

        // Перевірка наявності запису з таким ключем
        for (auto& record : table[index]) {
            if (record.lastName == lastName&& record.facultets==facultet) {
               
               
                int choice;
                if (test) {//параметр для перевірки чи цей виклик тестувальний
                    
                    table[index].push_back(newRecord);
                    cout << "New record added." << endl;
                    cursize++;
                    return;
                }
                else {
                    // Якщо запис знайдено, ви можете запитати користувача, який з цих записів зберегти
                    cout << "A record with the same last name already exists:" << endl;
                    cout << "1. Update the existing record" << endl;
                    cout << "2. Add as a new record" << endl;
                    cout << "3. Keep the old record" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (choice == 1) {
                        // Оновлення існуючого запису
                        updateScore("students.txt", lastName, score, facultet, percentVisited);
                        return;
                    }
                    if (choice == 2) {
                        // Додавання нового запису
                        table[index].push_back(newRecord);
                        cout << "New record added." << endl;
                        cursize++;
                        return;
                    }
                    if (choice == 3) {
                        return;
                    }
                }   
            }
        }
        // Якщо запис не знайдено, додаємо новий запис
        table[index].push_back(newRecord);
        cout << "New record added." << endl;
        cursize++;
    }

    // Функція пошуку запису за прізвищем
    virtual void findRecords(const string& lastName) {
        int index = hashFunction(lastName);
        bool found = false;
        for (const auto& record : table[index]) {
            if (record.lastName == lastName) {
                cout << "Score for " << record.lastName << ": " << record.score
                    << ", facultet: " << record.facultets
                    << ", percent of visited lessons: " << record.PercentofVisitedLessons << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No record found for " << lastName << endl;
        }
    }

    // Оновлення даних студента за прізвищем та факультетом
    void updateScore(const string& filename, const string& lastName, int newScore, const string& facultet, int newPercent) {
        int index = hashFunction(lastName);
        bool foundRecord = false;

        // Пошук запису в хеш-таблиці
        for (auto& record : table[index]) {
            if (record.lastName == lastName && record.facultets == facultet) {
                foundRecord = true;
                record.score = newScore;
                record.PercentofVisitedLessons = newPercent;
                break;
            }
        }

        if (!foundRecord) {
            cout << "Record for " << lastName << " with faculty " << facultet << " not found." << endl;
            return;
        }

        // Оновлення оцінки в файлі
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open the file." << endl;
            return;
        }

        vector<string> lines;
        string line;
        while (getline(file, line)) {
            string currentLastName, currentFacultet;
            int currentScore, currentPercent;
            istringstream iss(line);
            if (!(iss >> currentLastName >> currentScore >> currentFacultet >> currentPercent)) {
                cerr << "Invalid data format in file." << endl;
                return;
            }
            if (currentLastName == lastName && currentFacultet == facultet) {
                currentScore = newScore;
                currentPercent = newPercent;
            }
            lines.push_back(currentLastName + " " + to_string(currentScore) + " " + currentFacultet + " " + to_string(currentPercent));
        }
        file.close();

        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "Could not open the file for writing." << endl;
            return;
        }
        for (const string& updatedLine : lines) {
            outFile << updatedLine << endl;
        }
        outFile.close();
        cout << "Record for " << lastName << " updated in " << filename << endl;
    }

    // Функція збереження даних у файл
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open the file for writing." << endl;
            return;
        }

        for (const auto& bucket : table) {
            for (const auto& record : bucket) {
                file << record.lastName << " " << record.score << " " << record.facultets << " " << record.PercentofVisitedLessons << endl;
            }
        }
        file.close();
    }

    //отримати всі записи
    vector<StudentRecord> getAllRecords() {
        vector<StudentRecord> allRecords;
        for (const auto& chain : table) {
            for (const auto& record : chain) {
                allRecords.push_back(record);
            }
        }
        return allRecords;
    }

    // Функція видалення запису за фамілією
    void deleteRecord(const string& lastName, const string& facultets) {
        int index = hashFunction(lastName);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->lastName == lastName&& it->facultets == facultets) {
                chain.erase(it);
                cout << "Record for " << lastName << " deleted." << endl;
                cursize--;
                return;
                
            }
        }
        cout << "No record found for " << lastName << endl;
    }

    //поточна кількість елементів
    int Hashsize() const{
        return cursize;
    }

    //розмір хеш-таблиці
    int size() const {
        return TABLE_SIZE;
    }

    //Чи існує запис за даним ім'ям та факультетом
    bool recordExists(const string& lastName, const string& facultet) {
        int index = hashFunction(lastName);
        for (const auto& record : table[index]) {
            if (record.lastName == lastName && record.facultets == facultet) {
                return true;
            }
        }
        return false;
    }

    //очищення всієї хеш-таблиці
    void clearTable() {
        for (auto& bucket : table) {
            bucket.clear(); // Видаляє всі записи з поточного списку
        }
    }
};


//клас хеш-таблиці з подвійним хешуванням для тестування
class DoubleHashTable {

    vector<StudentRecord> table;
    int TABLE_SIZE;
    int cursize;
    const float LOAD_FACTOR = 0.6;
    //1 хеш-функція
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }
    //2 хеш-функція
    int secondHashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return 1 + (hash % (TABLE_SIZE - 1));
    }

    void resizeTable() {
        int newTableSize = TABLE_SIZE * 2;
        cout << "Resizing table to new size: " << newTableSize << endl;
        vector<StudentRecord> newTable(newTableSize);

        for (const auto& record : table) {
            if (!record.lastName.empty()) {
                int index = hashFunction(record.lastName) % newTableSize;
                int stepSize = secondHashFunction(record.lastName);
                while (!newTable[index].lastName.empty()) {
                    index = (index + stepSize) % newTableSize;
                }
                newTable[index] = record;
            }
        }
        table = move(newTable);
        TABLE_SIZE = newTableSize;
    }

public:
   
    DoubleHashTable() {
        TABLE_SIZE = 11;
        table.resize(TABLE_SIZE);
        cursize = 0;
    }

    void insertRecord(const string& lastName, int score, const string& facultet, int percentVisited) {
        if (static_cast<float>(cursize) / TABLE_SIZE >= LOAD_FACTOR) {
            resizeTable();
        }
        int index = hashFunction(lastName);
        int stepSize = secondHashFunction(lastName);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int newIndex = (index + i * stepSize) % TABLE_SIZE;
            if (table[newIndex].lastName.empty()) {
                table[newIndex] = StudentRecord(lastName, score, facultet, percentVisited);
                cout << "New record added." << endl;
                cursize++;
                return;
            }
        }

        cout << "Table is full, cannot add new record." << endl;
    }

    void findRecords(const string& lastName) {
        int index = hashFunction(lastName);
        int stepSize = secondHashFunction(lastName);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int newIndex = (index + i * stepSize) % TABLE_SIZE;
            if (table[newIndex].lastName == lastName) {
                cout << "Score for " << table[newIndex].lastName << ": " << table[newIndex].score
                    << ", facultet: " << table[newIndex].facultets
                    << ", percent of visited lessons: " << table[newIndex].PercentofVisitedLessons << endl;
                return;
            }
        }
        cout << "No record found for " << lastName << endl;
    }

    void deleteRecord(const string& lastName) {
        int index = hashFunction(lastName);
        int stepSize = secondHashFunction(lastName);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int newIndex = (index + i * stepSize) % TABLE_SIZE;
            if (table[newIndex].lastName == lastName) {
                cout << "Deleting record at index." << endl;
                table[newIndex] = StudentRecord(); 
                cursize--;
                return;
            }
        }
        cout << "No record found for " << lastName << " to delete." << endl;
    }
    int size() const {
        return TABLE_SIZE;
    }
    int Hashsize() const {
        return cursize;
    }
};

//функція для порівняння часу операцій хеш-таблиць
void compareHashTables() {
    const int numRecords = 500;
    HashTable testht;
    DoubleHashTable testdht;
    int deletesize = numRecords / 2;
    srand(time(0));

    clock_t myStart1 = clock();
    for (int i = 0; i < numRecords; ++i) {
        string lastName = generateRandLastName();
        string facultet = generateRandFacultet();
        int score = rand() % 101;
        int percentVisited = rand() % 101;
        testht.insertRecord(lastName, score, facultet, percentVisited,1);  
    }
    for (int i = 0; i < numRecords*2; ++i) {
        string lastName = generateRandLastName();
        testht.findRecords(lastName);
    }
    for (int i = 0; i < deletesize; ++i) {
        string lastName = generateRandLastName();
        string facultet = generateRandFacultet();
        testht.deleteRecord(lastName,facultet);
    }
    clock_t myEnd1 = clock();
    float myTime1 = (float(myEnd1 - myStart1)) / CLOCKS_PER_SEC;
   
    clock_t myStart2 = clock();
    for (int i = 0; i < numRecords*2; ++i) {
        string lastName = generateRandLastName();
        string facultet = generateRandFacultet();
        int score = rand() % 101;
        int percentVisited = rand() % 101;
        testdht.insertRecord(lastName, score, facultet, percentVisited);
    }

    for (int i = 0; i < numRecords; ++i) {
        string lastName = generateRandLastName();
        testdht.findRecords(lastName);
    }
    
    for (int i = 0; i < deletesize; ++i) {
        string lastName = generateRandLastName();
        testdht.deleteRecord(lastName);
    }
    clock_t myEnd2 = clock();
    float myTime2 = (float(myEnd2 - myStart2)) / CLOCKS_PER_SEC;
    cout << endl << endl << endl;
    cout << "Time taken for inserting records and finding results in HashTable with chaining: " <<myTime1 <<" microseconds" << endl;
    cout << "Records amount in HashTable with chaining: "<<testht.Hashsize()<<". Size of HashTable with chaining: " << testht.size() << endl;
    cout << "Time taken for inserting records and finding records in HashTable with double hash: " << myTime2 << " microseconds" << endl;
    cout << "Records amount in DoubleHashTable: " << testdht.Hashsize() << ". Size of DoubleHashTable: " << testdht.size() << endl;

}


int main() {
    // Створення об'єкта хеш-таблиці 
    HashTable ht;
    // Завантаження даних з файлу
    ht.loadFromFile("students.txt");

    //Головне меню
    char choice;
    do {
        system("cls");
        cout << "Menu:\n";
        cout << "1. Find student record\n";
        cout << "2. Add new student record\n";
        cout << "3. Update student record\n";
        cout << "4. Show all records\n";
        cout << "5. Delete student record\n";
        cout << "6. Clear all records\n";
        cout << "7. Compare HashTables\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case '1': {
            // Пошук запису за прізвищем
            string searchLastName;
            cout <<endl<<"Enter last name of the student to search: ";
            cin >> searchLastName;
            ht.findRecords(searchLastName);
            break;
        }

        case '2': {
            // Додавання нового запису
            string lastName, facultet;
            int score, percent;
            cout <<endl<< "Enter last name of the student: ";
            cin >> lastName;
            cout << "Enter facultet of the student: ";
            cin >> facultet;
            while (true) {
                cout << "Enter score of the student: ";
                if (cin >> score) {
                    break;
                }
                else {
                    cout << "Invalid input! Please enter an integer value for new score." << endl;
                    cin.clear(); // очищаємо стан потоку
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропускаємо некоректне введення
                }
            }
            // Перевірка правильності вводу рercent
            while (true) {
                cout << "Enter new percent of visited lessons: ";
                if (cin >> percent) {
                    break;
                }
                else {
                    cout << "Invalid input! Please enter an integer value for new percent of visited lessons." << endl;
                    cin.clear(); // очищаємо стан потоку
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропускаємо некоректне введення
                }
            }

            ht.insertRecord(lastName, score, facultet, percent,0);
            ht.saveToFile("students.txt");  // Збереження після додавання запису
            break;
        }

        case '3': {
            // Оновлення запису студента
            string lastName, Facultet;
            int newScore, newPercent;
            cout<<endl << "Enter last name of the student: ";
            cin >> lastName;
            cout << "Enter facultet of the student: ";
            cin >> Facultet;


            if (!ht.recordExists(lastName, Facultet)) {
                cout << "There is not records with last name " << lastName << " and from facultet " << Facultet;
                break;
            }
            

            while (true) {
                cout << "Enter new score of the student: ";
                if (cin >> newScore) {
                    break;
                }
                else {
                    cout << "Invalid input! Please enter an integer value for new score." << endl;
                    cin.clear(); // очищаємо стан потоку
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропускаємо некоректне введення
                }
            }
            // Перевірка правильності вводу newPercent
            while (true) {
                cout << "Enter new percent of visited lessons: ";
                if (cin >> newPercent) {
                    break;
                }
                else {
                    cout << "Invalid input! Please enter an integer value for new percent of visited lessons." << endl;
                    cin.clear(); // очищаємо стан потоку
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропускаємо некоректне введення
                }
            }

            ht.updateScore("students.txt", lastName, newScore, Facultet, newPercent);
            break;
        }

        case '4': {
            // Виведення всіх записів
            vector<StudentRecord> allRecords = ht.getAllRecords();
            int s = allRecords.size();
            if (s == 0) {
                cout << "Hash table is empty"<<endl;
            }
            int i = 1;
            cout << "There are " << ht.Hashsize()<<" students records :\n";
            for (const auto& record : allRecords) {
                
                cout <<i<<" "<< record << endl;
                i++;
            }
            break;
           
        }

        case '5': {
            // Видалення запису за прізвищем та факультетом
            string lastName,facultets;
            cout <<endl<< "Enter last name of the student to delete: ";
            cin >> lastName;
            cout << "Enter facultet of the student to delete: ";
            cin >>facultets;
            ht.deleteRecord(lastName,facultets);
            ht.saveToFile("students.txt");  // Збереження після видалення запису
            break;
        }

        case '6': {
            //очищення всієї хеш-таблиці
            ht.clearTable();
            cout << "Hashtable cleaned\n";
            break;
        }
        case '7': {
            //порівняння хеш-таблиць
            compareHashTables();
            break;
        }
        case '8': {
            //вихід
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();

    } while (choice != '8');
    // Збереження змінених даних у файл
    ht.saveToFile("students.txt");
    return 0;
}