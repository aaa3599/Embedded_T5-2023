#include <stdio.h>

int demChuoicon(char arr[]) {
    int dem = 0;
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] == ' ') {
            dem++;
        }
        i++;
    }
    return dem + 1;
}

void my_strcpy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Add null terminator to the destination string
}

char* my_strtok(char* str, const char* delim) {
    static char* nextToken = NULL;

    if (str != NULL) {
        nextToken = str;
    } else if (nextToken == NULL || *nextToken == '\0') {
        return NULL;
    }

    char* token = nextToken;
    int foundDelim = 0;

    while (*nextToken != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*nextToken == *d) {
                *nextToken = '\0';
                nextToken++;
                foundDelim = 1;
                break;
            }
            d++;
        }

        if (foundDelim) {
            break;
        }
        nextToken++;
    }

    if (!foundDelim && *nextToken == '\0') {
        nextToken = NULL;
    }

    return token;
}


void daoChuoi(char arr[])
{
    int n = demChuoicon(arr);
    char p[n][10];
    int i=0;
    // Lấy token đầu tiên
    char * token = my_strtok(arr, " ");
  // Lấy ra toàn bộ token
  while( token != NULL ) {
    my_strcpy(p[i],token);
    i++;
    token = my_strtok(NULL, " ");
  }

  for (int j = n; j > 0 ; j--)
  {
    printf("%s ",p[j-1]);
  }
  
  
}



int main()
{
    char arr[] = "I want to become pro dev"; // dev pro become to want I
    daoChuoi(arr);
}