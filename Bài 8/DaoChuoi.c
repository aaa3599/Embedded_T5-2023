#include <stdio.h>

int demChuoicon(char arr[]){
    int dem=0;
    int i=0;
    while (arr[i]== '\0')
    {
        if (arr[i] ==' ') dem++;
        i++;
    }
    return dem+1;
}

char* my_strtok(char* str, const char* delim) {
    static char* nextToken = NULL;
    static char* prevToken = NULL;

    if (str != NULL) {
        prevToken = str;
        nextToken = str;
    }

    if (prevToken == NULL || *prevToken == '\0') {
        return NULL;
    }

    char* token = nextToken;
    char* tokenEnd = NULL;

    while (*nextToken != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*nextToken == *d) {
                tokenEnd = nextToken;
                *tokenEnd = '\0';
                nextToken++;
                return token;
            }
            d++;
        }
        nextToken++;
    }

    if (tokenEnd == NULL) {
        return NULL;
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
    for (int k = 0; token[k] != '\0'; i++)
    {
        p[i][k] = token[k];
    }
    
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
    char arr[] = "I want to become pro dev";
    daoChuoi(arr);
}