#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <direct.h>
#include <stdlib.h>
#include "infobook_fn.h"
const int MAX_ATTEMPTS = 3;
void setxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Exit() // this function is used to exit the program
{
    char msg[] = "DONE BY";
    int j, z = strlen(msg);
    system("cls");
    Sleep(50);
    setxy(22, 2);
    for (j = 0; j <= 8; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        printf("%c", msg[j]);
    }

    for (j = 0; j <= 8; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    setxy(22, 4);
    printf("\xDB");
    printf("DISHA");
    Sleep(1000);
    exit(0);
}

void menu() // this function is used to access other functions
{
    int t, j;
    char name[30] = "PHONEBOOK DIRECTORY";
    int z = strlen(name);
    system("cls");
    setxy(30, 1);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        printf("%c", name[j]);
    }

    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    {
        setxy(30, 4);
        printf("\xDB");
        printf(" 1.Add New");
        setxy(30, 6);
        printf("\xDB");
        printf(" 2.Search");
        setxy(30, 8);
        printf("\xDB");
        printf(" 3.List");
        setxy(30, 10);
        printf("\xDB");
        printf(" 4.Modify");
        setxy(30, 12);
        printf("\xDB");
        printf(" 5.Delete");
        setxy(30, 14);
        printf("\xDB");
        printf(" 6.exit ::");
        // getch();
    }
    scanf("%d", &t);
    if (t < 1 || t > 6)
    {
        system("cls");
        printf("\n invalid choice exiting from application");
        Sleep(1000);
        Exit();
    }
    else if (t == 1)
        addperson();
    else if (t == 2)
        searchperson();
    else if (t == 3)
        listperson();
    else if (t == 4)
        modifyperson();
    else if (t == 5)
        deleteperson();
    else
        Exit();
}
void deleteperson() // this function is used to delete a record
{
    FILE *p, *p1;
    char c, s[50], del[50];
    int i = 0, d = 0, q = 1, l = 0;
    system("cls");
    p = fopen("info.txt", "r");
    p1 = fopen("1.txt", "w");
    setxy(22, 4);
    printf("\xDB enter the CONTACT name that you want to delete:");
    scanf("%s", del);
    fseek(p, 0, SEEK_END);
    i = ftell(p);
    fseek(p, 0, SEEK_SET);
    while (!feof(p))
    {
        // searching for the line number of the record so that we can avoid copying the record into the new record
        d = 0;
        while (c != ' ')
        {
            c = fgetc(p);
            s[d] = c;
            d++;
        }
        s[d - 1] = '\0';
        l++;
        if (strcmp(del, s) == 0)
        {
            d = 100;
            break;
        }
        while (c != '\n')
        {
            c = fgetc(p);
        }
        if (i == ftell(p))
        {
            i = 1;
            break;
        }
    }
    fseek(p, 0, SEEK_SET);
    c = fgetc(p);
    if (i != 1)
    {

        while (!feof(p))
        {
            // if line number is equal to the same line in which record is found then that line will not be copied in the new file
            if (q != l)
            {
                fputc(c, p1);
            }
            if (c == '\n')
            {
                q++;
            }
            c = getc(p);
        }
    }
    fclose(p);
    fclose(p1);
    setxy(22, 6);
    if (i == 1)
        printf("record not found");
    else
    {
        // deleting the old file and renaming the new file the same as the old one
        printf("record deleted successfully");
        remove("info.txt");
        rename("1.txt", "info.txt");
    }
    fclose(p);
    fclose(p1);
    setxy(22, 9);
    printf("press 'y' for main menu and 'n' to delete another record::");
    scanf("%s", s);
    if (s[0] == 'y')
        menu();
    else if (s[0] == 'n')
        deleteperson();
    else
        Exit();
}
void modifyperson() // this function is used to modify the record data
{
    FILE *p, *p1;
    char c, s[50], mod[50];
    int i = 0, d = 0, q = 1, l = 0, j;
    system("cls");
    p = fopen("info.txt", "r");
    p1 = fopen("1.txt", "w");
    printf("enter the name :");
    scanf("%s", mod);
    system("cls");
    //using fseek to set the file pointer position to the end
    fseek(p, 0, SEEK_END);
    i = ftell(p);
    //using fseek function to set the file pointer position to the start of the file
    fseek(p, 0, SEEK_SET);
    while (!feof(p))
    {
        d = 0;
        //searching for record in the file
        while (c != ' ')
        {
            c = fgetc(p);
            s[d] = c;
            d++;
        }
        s[d - 1] = '\0';
        l++;
        if (strcmp(mod, s) == 0)
        {
            break;
        }
        while (c != '\n')
        {
            c = fgetc(p);
        }
        if (i == ftell(p))
        {
            i = 1;
            break;
        }
    }
    fseek(p, 0, SEEK_SET);
    c = fgetc(p);
    if (i != 1)
    {
        setxy(22, 4);
        printf("|");
        for (j = 0; j <= 16; j++)
        {
            Sleep(50);
            printf("\xDB");
        }
        printf("MODIFY SECTION OPEN");
        for (j = 0; j <= 16; j++)
        {
            Sleep(50);
            printf("\xDB");
        }
        printf("|\n");
        //copying the data of one file to another file and when the record line is being copied changing the data
        while (!feof(p))
        {
            if (q != l)
            {
                fputc(c, p1);
            }
            else
            {
                c = 's';
                while (c != '\n')
                {
                    c = fgetc(p);
                }
                fputs(mod, p1);
                fputc(' ', p1);
                setxy(26, 6);
                printf("enter the new city\t\t:");
                scanf("%s", s);
                fputs(s, p1);
                fputc(' ', p1);
                setxy(26, 8);
                printf("enter the new EMAIL\t\t:");
                scanf("%s", s);
                fputs(s, p1);
                fputc(' ', p1);
                setxy(26, 10);
                printf("enter the new GENDER\t\t:");
                scanf("%s", s);
                fputs(s, p1);
                fputc(' ', p1);
                setxy(26, 12);
                printf("enter the new PHONE\t\t:");
                scanf("%s", s);
                fputs(s, p1);
                fputc('\n', p1);
            }
            if (c == '\n')
            {
                q++;
            }
            c = fgetc(p);
        }
    }
    fclose(p);
    fclose(p1);
    if (i == 1)
        printf("record not found");
    else
    {
        printf("record modified");
        remove("info.txt");
        rename("1.txt", "info.txt");
    }
    fclose(p);
    fclose(p1);
    printf("\npress 'y' for main menu and 'n' to modify another record");
    scanf("%s", s);
    if (s[0] == 'y')
        menu();
    else if (s[0] == 'n')
        modifyperson();
    else
        Exit();
}

void listperson()
{
    //it is used to display all the data 
    FILE *p;
    char c, s[50];
    int t = 0, j, q = 1, d = 0;
    system("cls");
    p = fopen("info.txt", "r");
    fseek(p, 0, SEEK_SET);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    Sleep(60);
    printf("LIST SECTION OPENED");
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    printf("\n");
    while (!feof(p))
    {
        //reading records from file and printing all the records
        c = fgetc(p);
        s[d] = c;
        d++;
        if (c == ' ' || c == '\n')
        {
            s[d - 1] = '\0';
            d = 0;
            if (t == 0)
            {
                for (j = 0; j <= 16; j++)
                {
                    printf("-");
                }
            }
            t++;

            if (t == 1)
            {
                printf("\nNAME:%s", s);
            }
            else if (t == 2)
            {
                printf("\nCITY:%s", s);
            }
            else if (t == 3)
            {
                printf("\nEMAIL:%s", s);
            }
            else if (t == 4)
            {
                printf("\nGENDER:%s", s);
            }
            else if (t == 5)
            {
                printf("\nPHONE:%s\n", s);
                t = 0;
                for (j = 0; j <= 8; j++)
                {
                    Sleep(50);
                    printf("-");
                }
                if (t == 0)
                {
                    printf("\xDBrecord::%d\xDB", q);
                }
                printf("\n");
                q++;
            }
        }
    }
    printf("press 'y'to go to main menu ");
    scanf("%s", s);
    fclose(p);
    if (s[0] == 'y')
        menu();
    else
        Exit();
}
void searchperson()
{
    FILE *p;
    char c, s[50], search[50];
    int i = 0, j, q, d = 0, t = 1, k;
    system("cls");
    p = fopen("info.txt", "r");
    setxy(22, 4);
    printf("\xDB enter the name of the person u want to see the detail about::");
    scanf("%s", search);
    fseek(p, 0, SEEK_END);
    k = ftell(p);
    fseek(p, 0, SEEK_SET);
    while (!feof(p))
    {

        while (c != ' ')
        {
            c = fgetc(p);
            s[d] = c;
            d++;
        }
        s[d - 1] = '\0';
        setxy(22, 6);
        //searching for the record in the file
        if (strcmp(search, s) != 0)
        {
            while (c != '\n')
            {
                c = fgetc(p);
            }
            d = 0;
            c = fgetc(p);
            if (k != ftell(p))
                fseek(p, -1, SEEK_CUR);
            else
                printf("No record found\n");
        }
        else if (strcmp(search, s) == 0)
        {
            setxy(22, 6);
            for (j = 0; j <= 16; j++)
            {
                Sleep(50);
                printf("\xDB");
            }
            printf("RECORD FOUND");
            for (j = 0; j <= 16; j++)
            {
                Sleep(50);
                printf("\xDB");
            }
            setxy(22, 7);
            for (j = 0; j <= 16; j++)
            {
                Sleep(50);
                printf("-");
            }
            setxy(22, 8);
            printf("|\xDB NAME  %s", s);
            //printing the record
            while (c != '\n')
            {
                d = 0;
                t++;
                c = '\0';
                while (c != ' ')
                {
                    c = fgetc(p);
                    if (c == '\n')
                        break;
                    s[d] = c;
                    d++;
                }
                s[d - 1] = '\0';
                if (t == 2)
                {
                    setxy(22, 9);
                    printf("|\xDB CITY:%s", s);
                }
                else if (t == 3)
                {
                    setxy(22, 10);
                    printf("|\xDB EMAIL:%s", s);
                }
                else if (t == 4)
                {
                    setxy(22, 11);
                    printf("|\xDB GENDER:%s", s);
                }
                else if (t == 5)
                {
                    setxy(22, 12);
                    printf("|\xDB PHONE:%s\n", s);
                    t++;
                    setxy(22, 13);
                    for (j = 0; j <= 16; j++)
                    {
                        Sleep(50);
                        printf("-");
                    }
                    break;
                }
            }
            if (t == 6)
                break;
        }
    }
    if (t == 6)
        setxy(22, 14);
    else
        setxy(22, 8);
    printf("||press 'y'to go to main menu and 'n' to search again.....");
    scanf("%s", s);
    fclose(p);
    if (s[0] == 'y')
        menu();
    else if (s[0] == 'n')
        searchperson();
    else
        Exit();
}

void addperson()//this function is used to add a new record
{
    FILE *p;
    char c[50], s[3];
    int j;
    system("cls");
    p = fopen("info.txt", "a+");
    setxy(22, 4);
    printf("|");
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    printf("NEW SECTION");
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    //taking data as input and storing in a file named info.txt
    setxy(22, 6);
    printf("|\xDB");
    printf("NO SPACES IN NAME||CITY||EMAIL||GENDER||PHONE");
    printf("\xDB|");
    setxy(22, 8);
    printf("NAME\t\t:");
    scanf("%s", c);
    fputs(c, p);
    fputc(' ', p);
    setxy(22, 9);
    printf("CITY\t\t:");
    scanf("%s", c);
    fputs(c, p);
    fputc(' ', p);
    setxy(22, 10);
    printf("EMAIL\t\t:");
    scanf("%s", c);
    fputs(c, p);
    fputc(' ', p);
    setxy(22, 11);
    printf("GENDER\t\t:");
    scanf("%s", c);
    fputs(c, p);
    fputc(' ', p);
    setxy(22, 12);
    printf("PHONE\t\t:");
    scanf("%s", c);
    fputs(c, p);
    fputc('\n', p);
    printf("press 'y'to go to main menu and 'n' to add another record ");
    scanf("%s", s);
    fclose(p);
    if (s[0] == 'y')
        menu();
    else if (s[0] == 'n')
        addperson();
    else
    {
        printf("not valid choice exiting");
        Exit();
    }
}

void Password(void)//this function is used so that only authorised people can access the data
{
    static int pwd_count = 0;
    system("cls");
    char password[20] = "soc";
    setxy(22, 2);
    int j;
    int z;
    char name[40] = "Authorised person only";
    z = strlen(name);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        printf("%c", name[j]);
    }
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    if (pwd_count == 3)
    {
        setxy(26, 4);
        printf("your attemps are over please re run the program....");
        Sleep(2000);
    }
    while (pwd_count < MAX_ATTEMPTS)
    {
        setxy(30, 4);
        printf("Password:");
        char ch, pass[20];
        char w = '*';
        int i = 0;
        while (ch != 13 && i < 20)
        {
            ch = getch();
            if (ch != 13 && ch != 8)
            {
                printf("%c", w);
                pass[i] = ch;
                i++;
            }
        }
        pass[i] = '\0';
        if (strcmp(pass, password) == 0)
        {
            setxy(30, 6);
            printf("CORRECT PASSWORD. you can now access INFOBOOK");
            Sleep(1000);
            menu();
        }
        else
        {
            setxy(30, 6);
            pwd_count++;
            int tc = MAX_ATTEMPTS - pwd_count;
            printf("you entered the wrong password and left %d attempts try again.", tc);
            Sleep(1000);
            for (int count = 0; count < 20; count++)
            {
                Sleep(50);
                system("cls");
            }
            Sleep(700);
            system("cls");
            Password();
        }
    }
}