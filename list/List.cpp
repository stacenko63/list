#include "List.h"
#include <iostream>
#include <windows.h>

using namespace std;
int CheckTypeInt()
{
    char per[100]{ 0 };
    gets_s(per);
    while (strlen(per) == 0)
    {
        printf("Введено некорректное значение. Повторите попытку: ");
        gets_s(per);
    }
    for (int i = 0; i < strlen(per); i++)
    {
        if (int(per[i]) == 45 && i == 0) i++;
        if (int(per[i]) < 48 || int(per[i]) > 57)
        {
            printf("Введено некорректное значение. Повторите попытку: ");
            gets_s(per);
            while (strlen(per) == 0)
            {
                printf("Введено некорректное значение. Повторите попытку: ");
                gets_s(per);
            }
            i = -1;
        }
    }
    int result = atoi(per);
    return result;
}
void AddEl(List& list)
{
    int key, index, menu = 1;
    do
    {
        system("cls");
        char value[10];
        printf("Введите элемент, который хотите добавить: ");
        key = CheckTypeInt();
        printf("Введите значение ключа: ");
        gets_s(value);
        printf("1 - Добавить элемент в начало списка\n");
        printf("2 - Добавить элемент в конец списка\n");
        printf("3 - Добавить элемент по индексу\n");
        printf("0 - Вернуться в главное меню\n");
        printf("Введите ваш выбор: ");
        menu = CheckTypeInt();
        while (menu < 0 || menu > 3)
        {
            printf("Такого пункта нет в меню. Повторите попытку: ");
            menu = CheckTypeInt();
        }
        try
        {
            if (menu == 0) break;
            if (menu == 1) list.AddBegin(key, value);
            else if (menu == 2) list.AddEnd(key, value);
            else if (menu == 3)
            {
                printf("Введите индекс элемента, который хотите добавить: ");
                index = CheckTypeInt();
                list.AddIndex(key, value, index);
            }
            printf("Элемент успешно добавлен в список!\n");
            printf("1 - Добавить элемент снова\n");
            printf("0 - Вернуться в главное меню\n");
            printf("Введите ваш выбор: ");
            menu = CheckTypeInt();
            while (menu < 0 || menu > 1)
            {
                printf("Такого пункта нет в меню. Повторите попытку: ");
                menu = CheckTypeInt();
            }
        }
        catch (char* exception)
        {
            printf("\nОшибка: %s\n", exception);
        }
    } while (menu != 0);
}
void DelEl(List& list)
{
    int key, index, menu = 1;
    do
    {
        system("cls");
        printf("1 - Удалить элемент из начала списка\n");
        printf("2 - Удалить элемент из конца списка\n");
        printf("3 - Удалить элемент по индексу\n");
        printf("4 - Удалить элемент по значению\n");
        printf("0 - Вернуться в главное меню\n");
        printf("Введите ваш выбор: ");
        menu = CheckTypeInt();
        while (menu < 0 || menu > 4)
        {
            printf("Такого пункта нет в меню. Повторите попытку: ");
            menu = CheckTypeInt();
        }
        try
        {
            if (menu == 0) break;
            if (menu == 1) list.DelBegin();
            else if (menu == 2) list.DelEnd();
            else if (menu == 3)
            {
                printf("Введите индекс элемента, который хотите удалить: ");
                index = CheckTypeInt();
                list.DelIndex(index);
            }
            else if (menu == 4)
            {
                printf("Введите элемент, который хотите удалить из списка: ");
                key = CheckTypeInt();
                list.DelKey(key);
            }
            printf("Элемент успешно удален из списка!\n");
            printf("1 - Удалить элемент снова\n");
            printf("0 - Вернуться в главное меню");
            printf("Введите ваш выбор: ");
            menu = CheckTypeInt();
            while (menu < 0 || menu > 1)
            {
                printf("Такого пункта нет в меню. Повторите попытку: ");
                menu = CheckTypeInt();
            }
        }
        catch (char* exception)
        {
            printf("\nОшибка: %s\n", exception);
        }
    } while (menu != 0);
}
int main()
{
    setlocale(LC_ALL, "RUS");
    int menu = 1;
    List list;
    do
    {
        system("cls");
        printf("Полученный список: \n");
        list.Print();
        printf("\n1 - Добавить элемент в список\n");
        printf("2 - Удалить элемент из список\n");
        printf("3 - Очистить список\n");
        printf("4 - Узнать размер списка\n");
        printf("5 - Получить элемент списка по индексу\n");
        printf("6 - Получить элемент списка по ключу\n");
        printf("7 - Изменить элемент списка по индексу\n");
        printf("8 - Изменить элемент списка по ключу\n");
        printf("0 - Выйти\n");
        printf("Введите ваш выбор: ");
        menu = CheckTypeInt();
        while (menu < 0 || menu > 8)
        {
            printf("Такого пункта нет в меню. Повторите попытку: ");
            menu = CheckTypeInt();
        }
        try
        {
            if (menu == 1) AddEl(list);
            else if (menu == 2) DelEl(list);
            else if (menu == 3) list.Clear();
            else if (menu == 4) cout << list.GetSize();
            else if (menu == 5)
            {
                int index;
                printf("Введите индекс: ");
                index = CheckTypeInt();
                list.GetElementIndex(index);
            }
            else if (menu == 6)
            {
                int key;
                printf("Введите ключ: ");
                key = CheckTypeInt();
                list.GetElementKey(key);
            }
            else if (menu == 7)
            {
                int index, key;
                char value[10];
                printf("Заведите индекс: ");
                index = CheckTypeInt();
                printf("Введите новый ключ: ");
                key = CheckTypeInt();
                printf("Введите новое значение ключа: ");
                gets_s(value);
                list.SetElementIndex(key, value, index);
            }
            else if (menu == 8)
            {
                int key, newkey;
                char value[10];
                printf("Введите ключ ключ: ");
                key = CheckTypeInt();
                printf("Введите новый ключ: ");
                newkey = CheckTypeInt();
                printf("Введите новое значение ключа: ");
                gets_s(value);
                list.SetElementKey(key, newkey, value);
            }
        }
        catch (const char* exception)
        {
            printf("\nОшибка: %s\n", exception);
            Sleep(1000);
        }
    } while (menu != 0);
}
