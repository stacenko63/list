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
        printf("������� ������������ ��������. ��������� �������: ");
        gets_s(per);
    }
    for (int i = 0; i < strlen(per); i++)
    {
        if (int(per[i]) == 45 && i == 0) i++;
        if (int(per[i]) < 48 || int(per[i]) > 57)
        {
            printf("������� ������������ ��������. ��������� �������: ");
            gets_s(per);
            while (strlen(per) == 0)
            {
                printf("������� ������������ ��������. ��������� �������: ");
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
        printf("������� �������, ������� ������ ��������: ");
        key = CheckTypeInt();
        printf("������� �������� �����: ");
        gets_s(value);
        printf("1 - �������� ������� � ������ ������\n");
        printf("2 - �������� ������� � ����� ������\n");
        printf("3 - �������� ������� �� �������\n");
        printf("0 - ��������� � ������� ����\n");
        printf("������� ��� �����: ");
        menu = CheckTypeInt();
        while (menu < 0 || menu > 3)
        {
            printf("������ ������ ��� � ����. ��������� �������: ");
            menu = CheckTypeInt();
        }
        try
        {
            if (menu == 0) break;
            if (menu == 1) list.AddBegin(key, value);
            else if (menu == 2) list.AddEnd(key, value);
            else if (menu == 3)
            {
                printf("������� ������ ��������, ������� ������ ��������: ");
                index = CheckTypeInt();
                list.AddIndex(key, value, index);
            }
            printf("������� ������� �������� � ������!\n");
            printf("1 - �������� ������� �����\n");
            printf("0 - ��������� � ������� ����\n");
            printf("������� ��� �����: ");
            menu = CheckTypeInt();
            while (menu < 0 || menu > 1)
            {
                printf("������ ������ ��� � ����. ��������� �������: ");
                menu = CheckTypeInt();
            }
        }
        catch (char* exception)
        {
            printf("\n������: %s\n", exception);
        }
    } while (menu != 0);
}
void DelEl(List& list)
{
    int key, index, menu = 1;
    do
    {
        system("cls");
        printf("1 - ������� ������� �� ������ ������\n");
        printf("2 - ������� ������� �� ����� ������\n");
        printf("3 - ������� ������� �� �������\n");
        printf("4 - ������� ������� �� ��������\n");
        printf("0 - ��������� � ������� ����\n");
        printf("������� ��� �����: ");
        menu = CheckTypeInt();
        while (menu < 0 || menu > 4)
        {
            printf("������ ������ ��� � ����. ��������� �������: ");
            menu = CheckTypeInt();
        }
        try
        {
            if (menu == 0) break;
            if (menu == 1) list.DelBegin();
            else if (menu == 2) list.DelEnd();
            else if (menu == 3)
            {
                printf("������� ������ ��������, ������� ������ �������: ");
                index = CheckTypeInt();
                list.DelIndex(index);
            }
            else if (menu == 4)
            {
                printf("������� �������, ������� ������ ������� �� ������: ");
                key = CheckTypeInt();
                list.DelKey(key);
            }
            printf("������� ������� ������ �� ������!\n");
            printf("1 - ������� ������� �����\n");
            printf("0 - ��������� � ������� ����");
            printf("������� ��� �����: ");
            menu = CheckTypeInt();
            while (menu < 0 || menu > 1)
            {
                printf("������ ������ ��� � ����. ��������� �������: ");
                menu = CheckTypeInt();
            }
        }
        catch (char* exception)
        {
            printf("\n������: %s\n", exception);
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
        printf("���������� ������: \n");
        list.Print();
        printf("\n1 - �������� ������� � ������\n");
        printf("2 - ������� ������� �� ������\n");
        printf("3 - �������� ������\n");
        printf("4 - ������ ������ ������\n");
        printf("5 - �������� ������� ������ �� �������\n");
        printf("6 - �������� ������� ������ �� �����\n");
        printf("7 - �������� ������� ������ �� �������\n");
        printf("8 - �������� ������� ������ �� �����\n");
        printf("0 - �����\n");
        printf("������� ��� �����: ");
        menu = CheckTypeInt();
        while (menu < 0 || menu > 8)
        {
            printf("������ ������ ��� � ����. ��������� �������: ");
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
                printf("������� ������: ");
                index = CheckTypeInt();
                list.GetElementIndex(index);
            }
            else if (menu == 6)
            {
                int key;
                printf("������� ����: ");
                key = CheckTypeInt();
                list.GetElementKey(key);
            }
            else if (menu == 7)
            {
                int index, key;
                char value[10];
                printf("�������� ������: ");
                index = CheckTypeInt();
                printf("������� ����� ����: ");
                key = CheckTypeInt();
                printf("������� ����� �������� �����: ");
                gets_s(value);
                list.SetElementIndex(key, value, index);
            }
            else if (menu == 8)
            {
                int key, newkey;
                char value[10];
                printf("������� ���� ����: ");
                key = CheckTypeInt();
                printf("������� ����� ����: ");
                newkey = CheckTypeInt();
                printf("������� ����� �������� �����: ");
                gets_s(value);
                list.SetElementKey(key, newkey, value);
            }
        }
        catch (const char* exception)
        {
            printf("\n������: %s\n", exception);
            Sleep(1000);
        }
    } while (menu != 0);
}
