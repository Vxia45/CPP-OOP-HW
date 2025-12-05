# Library Management System

## Описание

Проектът **„Система за управление на библиотека"** представлява C++ система, която моделира работата на библиотека чрез взаимосвързани класове. Системата позволява управление на книги, членове и заеми на книги.

Проектът демонстрира прилагането на основни обектно-ориентирани концепции в C++:
- конструктори, деструктори и правилото на петте (Rule of 5);
- капсулация и достъп чрез getters и setters;
- композиция на класове;
- статични членове и методи;
- валидация на данни и обработка на изключения;
- работа със STL контейнери (`vector`, `string`);
- move семантика и копиращи операции.

---

## Структура на проекта

```
cpp-oop-hw/
├── Author.h
├── Book.h
├── Member.h
├── Loan.h
├── Library.h
├── main.cpp
├── .gitattributes
└── README.md
```

---

## Компилация и изпълнение

Отворете терминал в директорията на проекта и изпълнете:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o library main.cpp
```

След това стартирайте програмата:

```bash
./library
```

---

## Примерен изход

```
=== Library ===
Total books: 3
Books:
 - "Pod igoto" by Ivan Vazov (born 1850), Year: 1894, ISBN: ISBN-001, Price: 25.500000 leva
 - "Nema zemya" by Ivan Vazov (born 1850), Year: 1900, ISBN: ISBN-002, Price: 18.900000 leva
 - "Staroplaninski legendi" by Yordan Yovkov (born 1880), Year: 1927, ISBN: ISBN-003, Price: 15.000000 leva

Total members: 2
Members:

Member: Andrey Tinchev,
Member ID: M001,
Joined: 2025

Member: Petar Petrov,
Member ID: M002,
Joined: 2023

Active loans: 0
Total books in memory: 6

=== Book Loans ===

Loan created.

=== Book Availability ===
Available ISBN-001? false
Available ISBN-002? true
Available ISBN-003? true

=== Book Returns ===
Available ISBN-001? true

=== Find By Author ===
"Pod igoto" by Ivan Vazov (born 1850), Year: 1894, ISBN: ISBN-001, Price: 25.500000 leva
"Nema zemya" by Ivan Vazov (born 1850), Year: 1900, ISBN: ISBN-002, Price: 18.900000 leva

=== Testing Rule of 5 ===
Copied book: "Pod igoto" by Ivan Vazov (born 1850), Year: 1894, ISBN: ISBN-001, Price: 25.500000 leva
Moved book: "Staroplaninski legendi" by Yordan Yovkov (born 1880), Year: 1927, ISBN: ISBN-003, Price: 15.000000 leva

=== Final Result ===
=== Library ===
Total books: 3
Books:
 - "Pod igoto" by Ivan Vazov (born 1850), Year: 1894, ISBN: ISBN-001, Price: 25.500000 leva
 - "Nema zemya" by Ivan Vazov (born 1850), Year: 1900, ISBN: ISBN-002, Price: 18.900000 leva
 - "Staroplaninski legendi" by Yordan Yovkov (born 1880), Year: 1927, ISBN: ISBN-003, Price: 15.000000 leva

Total members: 2
Members:

Member: Andrey Tinchev,
Member ID: M001,
Joined: 2025

Member: Petar Petrov,
Member ID: M002,
Joined: 2023

Active loans: 0
Total books in memory: 8

=== Validations ===
Error: Invalid birth year
Error:Year must be between 1450 and 2025
```

---

## Класове

### Клас `Author`

Представя автор на книга с основни характеристики.

**Членове:**
- `string name` — име на автора
- `int birthYear` — година на раждане

**Методи:**
- `Author()` — конструктор по подразбиране
- `Author(const string& name, int birthYear)` — параметризиран конструктор с валидация (1850-2025)
- `getName()` — връща името на автора
- `getBirthYear()` — връща годината на раждане
- `setBirthYear(int year)` — задава година с валидация
- `to_string()` — текстово представяне на автора

---

### Клас `Book`

Представя книга с пълна информация и имплементира правилото на петте (Rule of 5).

**Членове:**
- `string title` — заглавие
- `Author author` — автор (композиция)
- `int year` — година на издаване
- `double price` — цена
- `string isbn` — ISBN номер
- `static int totalBooks` — статичен брояч на всички книги в паметта

**Методи:**
- `Book()` — конструктор по подразбиране
- `Book(const string& title, const Author& author, int year, double price, const string& isbn)` — параметризиран конструктор
- Copy constructor и copy assignment operator
- Move constructor и move assignment operator
- `~Book()` — деструктор
- Getters за всички полета
- `setYear(int y)` и `setPrice(double p)` — setters с валидация
- `to_string()` — текстово представяне
- `static getTotalBooks()` — връща броя на всички книги в паметта

**Валидации:**
- Година на издаване: 1450-2025
- Цена: неотрицателна

---

### Клас `Member`

Представя член на библиотеката.

**Членове:**
- `string name` — име
- `string memberId` — уникален идентификатор
- `int yearJoined` — година на присъединяване

**Методи:**
- `Member()` — конструктор по подразбиране
- `Member(const string& name, const string& memberId, int yearJoined)` — параметризиран конструктор
- Getters за всички полета
- `to_string()` — текстово представяне

**Валидации:**
- Member ID не може да бъде празен
- Година на присъединяване: 1900-2025

---

### Клас `Loan`

Представя заем на книга от член.

**Членове:**
- `string isbn` — ISBN на заетата книга
- `string memberId` — ID на членa
- `string startDate` — начална дата
- `string dueDate` — крайна дата
- `bool returned` — статус на връщане

**Методи:**
- `Loan()` — конструктор по подразбиране
- `Loan(const string& isbn, const string& memberId, const string& startDate, const string& dueDate)` — параметризиран конструктор
- Getters за всички полета
- `markReturned()` — маркира книгата като върната
- `isOverdue(const string& today)` — проверява дали заемът е просрочен
- `to_string()` — текстово представяне

**Валидация:**
- Крайната дата трябва да е след или равна на началната дата

---

### Клас `Library`

Главен клас, който управлява цялата библиотечна система.

**Членове:**
- `vector<Book> books` — колекция от книги
- `vector<Member> members` — колекция от членове
- `vector<Loan> loans` — колекция от заеми

**Методи:**
- `addBook(const Book& b)` — добавя книга
- `hasBook(const string& isbn)` — проверява дали книгата съществува
- `isBookAvailable(const string& isbn)` — проверява дали книгата е налична за заемане
- `addMember(const Member& m)` — добавя член
- `hasMember(const string& memberId)` — проверява дали членът съществува
- `loanBook(const string& isbn, const string& memberId, const string& start, const string& due)` — създава заем
- `returnBook(const string& isbn, const string& memberId)` — маркира книга като върната
- `findByAuthor(const string& authorName)` — търси книги по име на автор (частично съвпадение)
- `to_string()` — пълно текстово представяне на библиотеката

---

## Образователни цели

Проектът има за цел да демонстрира:
- разделение между декларация (`.h`) и използване (`.cpp`);
- правилото на петте (Rule of 5) с copy/move конструктори и оператори за присвояване;
- композиция на класове (`Book` съдържа `Author`);
- използване на статични членове за проследяване на обекти;
- валидация на входни данни с изключения;
- работа със STL контейнери (`vector`);
- const-коректност на методите;
- управление на ресурси и памет.

---

## Функционалности

-Управление на книги (добавяне, проверка на наличност)  
-Управление на членове (регистрация, проверка)  
-Система за заемане и връщане на книги  
-Търсене на книги по автор  
-Статистика за активни заеми  
-Статичен брояч за общ брой книги в паметта  
-Пълна валидация на данни  
-Обработка на грешки чрез изключения  

---

## Екранна снимка
  ![Екранна снимка на кода](imgs/image.png)

---

## Автор
- **Име:** Андрей Тинчев
- **Номер:** 22401
- **Курс:** Обектно-ориентирано програмиране (C++)  
- **Дата:** 04.12.2025

