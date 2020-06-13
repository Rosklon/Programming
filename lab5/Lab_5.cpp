#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <conio.h>


using namespace std;

struct saleofapart
{
    int area;
    char fio[40] = { '\0' };
    char dist[25] = { '\0' };
    int cost;
};
tuple <saleofapart*, int> input();
void information(saleofapart* tick);
void surname(saleofapart* tick);
void dursort(saleofapart* tick);

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "1. Информация о всех выставленных на продажу квартирах" << endl << "2. Квартиры, которые не находятся в Заводском районе" << endl << "3. Квартиры со стоимостью более полутора миллионов рублей." << endl << "0. Выход" << endl << endl << "Введите номер задания: ";
    int num;
    cin >> num;
    cout << endl;
    cin.clear(); 
    cin.ignore();
    saleofapart* apart = get<0>(input());
    system("cls");
    while (num)
    {
        if (num == 1)
        {
            information(apart);
            _getch();
            system("cls");
        }
        if (num == 2)
        {
            surname(apart);
            _getch();
            system("cls");
            
        }
        if (num == 3)
        {
            dursort(apart);
            _getch();
            system("cls");
        }
        if (num > 3 || num < 1) cout << "Вы выбрали не существующую задачу. Повторите выбор." << endl;
        cout << "1. Информация о всех выставленных на продажу квартирах" << endl << "2. Квартиры, которые не находятся в Заводском районе" << endl << "3. Квартиры со стоимостью более полутора миллионов рублей." << endl << "0. Выход" << endl << endl << "Введите номер задания: ";
        cin >> num; cout << endl;
        system("cls");
    }
}

tuple <saleofapart*, int> input() //кортеж, возвращающий все квартиры и их кол-во
{
    ifstream info("info.txt");
    char apart_inf[255];
    int cnt = 0;
    while (info.getline(apart_inf, 255, '\n')) cnt++; 
    saleofapart* inf = new saleofapart[cnt]; 
    char* buf;
    int i = 0;
    info.close();
    info.open("info.txt");
    while (info.getline(apart_inf, 255, '\n')) 
    {
        buf = strtok(apart_inf, "/");
        inf[i].area = stoi(buf);
        buf = strtok(NULL, "/");
        strcpy(inf[i].fio, buf);
        buf = strtok(NULL, "/");
        strcpy(inf[i].dist, buf);
        buf = strtok(NULL, "/");
        inf[i].cost = stoi(buf);
        i++;
    }
    info.close();
    return make_tuple(inf, cnt);
}

void information(saleofapart* tick)
{
    for (int i = 0; i < get<1>(input()); i++) 
    {
        cout << "Площадь квартиры - " << tick[i].area << " кв.м" << endl;
        cout << "ФИО владельца - " << tick[i].fio << endl;
        cout << "Район - " << tick[i].dist << endl;
        cout << "Стоимость - " << tick[i].cost << " руб." << endl;
        cout << endl;
    }
}

void surname(saleofapart* tick) //выводит квартиры с запрашиваемой фамилией
{
    string sur = "Zavodskoj";
    cout << "                 Квартиры, расположенные не в Заводском районе: " << endl;
    char* buf;
    string sur_;
    for (int i = 0; i < get<1>(input()); i++) //ищем фамилию
    {
        sur_ = tick[i].fio;
        buf = strtok(tick[i].dist, " ");
        if (buf != sur) 
        {
            cout << "Площадь квартиры - " << tick[i].area << " кв.м" << endl;
            cout << "ФИО владельца - " << sur_ << endl;
            cout << "Район - " << tick[i].dist << endl;
            cout << "Стоимость - " << tick[i].cost << " руб." << endl;
            cout << endl;
        }
    }
}

void dursort(saleofapart* tick) //выводит (по алфавиту) квартиры больше 1.5 млн
{
    int cnt = 0;
    for (int i = 0; i < get<1>(input()); i++)
        if (tick[i].cost > 1500000) cnt++; 
    int* a = new int[cnt];
    for (int i = 0, j = 0; i < get<1>(input()); i++) 
    {
        if (tick[i].cost > 1500000)
        {
            a[j] = i;
            j++;
        }
    }

    saleofapart* temp = new saleofapart[cnt]; 
    for (int i = 0 ; i < cnt; i++)
    {
        temp[i].area = tick[a[i]].area;
        strcpy(temp[i].fio, tick[a[i]].fio);
        strcpy(temp[i].dist, tick[a[i]].dist);
        temp[i].cost = tick[a[i]].cost;
    }

    saleofapart temp2;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (strcmp(temp[j].fio, temp[j - 1].fio) < 0) //сортируем, сравнивая фамилии 
            {
                temp2 = temp[j];
                temp[j] = temp[j - 1];
                temp[j - 1] = temp2;
            }
        }
    }
    for (int i = 0; i < cnt; i++) 
    {
        cout << "Площадь квартиры - " << temp[i].area << " кв.м" << endl;
        cout << "ФИО владельца - " << temp[i].fio << endl;
        cout << "Район - " << temp[i].dist << endl;
        cout << "Стоимость - " << temp[i].cost << " руб." << endl;
        cout << endl;
    }
}
