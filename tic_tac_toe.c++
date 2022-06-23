#include <iostream>
#include <ctime>
#include <Windows.h>

void board(char arr[3][3]);

bool gameOver(char arr[3][3], int k);

void input(char (&arr)[3][3], char& symbol, int& num, bool b);


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    std::cout << "Чтобы сделать ход, нужно выбрать числа от 1-9!\n";
    std::cout << "крестик или нолик?\n";
    std::cout << "\tx - крестик\n" << "\t0 - нолик\n";
    char gamer1, gamer2;

    do
    {
        std::cin >> gamer1;
        if(gamer1 == 'x')
        {
            std::cout << "Вы выбрали крестик! Ходите первым.\n";
            gamer2 = '0';
        }
        else if(gamer1 == '0'){
            std::cout << "Вы выбрали нолик!. Я хожу первым.\n";
            gamer2 = 'x';
        }
        else
        {
            std::cout << "Неверный ввод! Попробуйте еще раз.\n";
        }
    }while (gamer1 != 'x' && gamer1 != '0');

    char arr2D[3][3]{0};
    int number;
    int countInput{1};
    bool b = (gamer1 == 'x') ? true: false;
    while (true)
    {
        if(b)
        { 
            Sleep(500);
            board(arr2D);
            if(countInput++ <= 9)
            { 
                Sleep(500);
                std::cout << "Ваш ход ";
                std::cin >> number;
                input(arr2D, gamer1, number, true);
                b = false;
                bool endGame = gameOver(arr2D, countInput);
                if(endGame == 1)
                {
                    std::cout <<"ПОБЕДA!!!\n";
                    board(arr2D);
                    exit(1);
                }
            }
            else
            {
                std::cout << "Ничья!\n";
                exit(1);
            }
        }
        else
        {
            if(countInput++ <= 9)
            {
                Sleep(500);
                std::cout << "Мой ход ";
                number = rand() % 9 + 1;
                input(arr2D, gamer2, number, false);
                std::cout << number << std::endl;
                b = true;
                bool endGame = gameOver(arr2D, countInput);
                if(endGame == 1)
                {
                    std::cout <<"ПОБЕДА!!!\n";
                    board(arr2D);
                    exit(1);
                }
            }
            else
            {
                std::cout << "Ничья!\n";
                board(arr2D);
                exit(1);
            }
        }
    }
    


    return 0;
}

void board(char arr[3][3])
{
    std::cout << "  _ " << " _ " << " _ " << " _ "  << std::endl;
    std::cout <<"| " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " |" << std::endl;
    std::cout << " _ " << " _ " << " _ " << " _ "  << std::endl;
    std::cout <<"| " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " |" << std::endl;
    std::cout << "  _ " << " _ " << " _ " << " _ "  << std::endl;
    std::cout <<"| " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " |" << std::endl;
    std::cout << std::endl;
}

bool gameOver(char arr[3][3], int k)
{
    if(k < 5)
        return false;
    else
    {    
        if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][0] != 0)
        {
            return 1;
        }
        else if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != 0)
        {
            return 1;
        }
        else if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][1] != 0)
        {
            return 1;
        }
        else if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] != 0)
        {
            return 1;
        }
        else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != 0)
        {
            return 1;
        }
        else if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != 0)
        {
            return 1;
        }
        else if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != 0)
        {
            return 1;
        }
        else if(arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != 0)
        {
            return 1;
        }
    }

    return false;
}

void input(char (&arr)[3][3], char& symbol, int& num, bool b)
{
    if(num < 1 || num > 9)
    {
        std::cout << "Неправильный ввод!\n";
    }
    else{ 

        if(num <= 3)
        {
            if(arr[0][num-1] == 'x' || arr[0][num-1] == '0')
            {
                if(b)
                    std::cin >> num;
                else{
                    num = rand() % 9 + 1;
                }
                return input(arr, symbol, num, b);
            }
            arr[0][num-1] = symbol;
        } 
        else if(num > 3 && num <= 6)
        {
            if(arr[1][(num-1) % 3] == 'x' || arr[1][(num-1) % 3] == '0')
            {
                if(b)
                    std::cin >> num;
                else{
                    num = rand() % 9 + 1;
                }
                return input(arr, symbol, num, b);
            }
            arr[1][(num-1) % 3] = symbol;                
        }   
        else
        {
            if(arr[2][(num-1) % 3] == 'x' || arr[2][(num-1) % 3] == '0')
            {
                if(b)
                    std::cin >> num;
                else{
                    num = rand() % 9 + 1;
                }
                return input(arr, symbol, num, b);
            }
            arr[2][(num-1) % 3] = symbol;
        }
    }
}