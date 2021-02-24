typedef char *string;

enum allowed_characters
{
    Alls,
    OnlyNumbers,
    OnlyLetters,
    LettersAndSymbols,
    NumbersAndSymbols
};

int characters;
bool isPassword;
int MaxStrLn = 80;
int MinStrLn = 2;
int charPassword = 42;

string get_string(char *message)
{
    string text;
    int letter = 0;
    char temp_string[80]={'\0'};

    printf("%s", message);
    while (letter < MaxStrLn)
    {
        temp_string[letter] = getch();

        if ((characters == LettersAndSymbols || characters == NumbersAndSymbols || characters == Alls) && letter < MaxStrLn - 1 && ((temp_string[letter] >= 33 && temp_string[letter] <= 47) || (temp_string[letter] >= 58 && temp_string[letter] <= 64) || (temp_string[letter] >= 91 && temp_string[letter] <= 96) || (temp_string[letter] >= 123 && temp_string[letter] <= 126)))
        {
            cprintf("%c", isPassword ? charPassword : temp_string[letter]);
            letter++;
        }
        else if ((characters == OnlyNumbers || characters == Alls) && letter < MaxStrLn - 1 && temp_string[letter] >= 48 && temp_string[letter] <= 57)
        {
            cprintf("%c", isPassword ? charPassword : temp_string[letter]);
            letter++;
        }
        else if ((characters == OnlyLetters || characters == LettersAndSymbols || characters == Alls) && letter < MaxStrLn - 1 && ((temp_string[letter] >= 65 && temp_string[letter] <= 90) || (temp_string[letter] >= 97 && temp_string[letter] <= 122) || (temp_string[letter] >= 48 && temp_string[letter] <= 57)))
        {
            cprintf("%c", isPassword ? charPassword : temp_string[letter]);
            letter++;
        }
        else if (temp_string[letter] == 32)
        {
            cprintf(" ");
            letter++;
        }
        else if (temp_string[letter] == 8 && letter > 0)
        {
            temp_string[letter] = '\0';
            cprintf("\b \b");
            letter--;
        }
        else if (temp_string[letter] == 13 && letter >= MinStrLn)
        {
            temp_string[letter] = '\0';
            break;
        }
    }
    memcpy(text, temp_string, sizeof(temp_string));
    return text;
}