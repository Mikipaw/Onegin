/*!
 * @mainpage
 *  \brief     Romeo and Juliet
 *  \details   This program is used to make an encyclopedia using "Romeo and Juliet" tragedy.
 *  \author    Michael Pavlov
 *  \author    Mikhail Pavlov
 *  \version   C++20
 *  \date      09.2020
 *  \pre       First initialize the system.
 *  \bug       No
 *  \warning
 *  \copyright GNU Public License.
 */

#include <cstdlib>
#include <cstdio>

#include "Tests.h"

#define END_OF_FILE "~"

void Print          ();
//??   Print_n_cut();
void PrintSorted    ();
void PrintReversed  ();
char** Filling_The_Array(FILE* text, int number_of_lines);

int print_n_count_number_of_lines(const char* text, FILE* result_file_name);

char* text_from_file(FILE* file_name);

void Interface();

int main() {
    AllTests();

    //printf("%s", text);
    Interface();
    return 0;
}


char** Filling_The_Array(FILE* text, int number_of_lines){
    fseek (text,0,SEEK_SET);
    char** pointers = (char**) calloc(number_of_lines + 1, sizeof(pointers[1]));
    int i = 0;
    char line[50];
    while(TRUE) {
        pointers[i] = fgets(line, 50, text);
        if(pointers[i] == nullptr) break;
        printf("%s", pointers[i]);
        if(str_cmp(pointers[i], END_OF_FILE) == TRUE) break;
        ++i;
    }
    return pointers;
}

int print_n_count_number_of_lines(const char* text, FILE* result_file_name){
    int result = 0;
    int c = 0, i = 0;
    while(c != '~'){
        c = (char)text[i];
        if((char)c == '\n'){
            result++;
            fputc('\n', result_file_name);
        }
        else fputc(c, result_file_name);
        ++i;
    }
    _flushall();
    return result;
}

char* text_from_file(FILE* file_name){
    fseek(file_name, 0, SEEK_SET);
    char* result_string = (char*)malloc(106592);
    char c;
    int i = 0;
    while(!feof(file_name)){
        c = (char)fgetc(file_name);
        /*if (c != '\n') result_string[i++] = c;
        else result_string[i++] = '\0';*/
        result_string[i++] = c;
    }
    result_string[i++] = '\n';
    result_string[i++] = '\0';
    result_string[i++] = '~';
    result_string[i] = '\0';
    return result_string;
}

void Interface(){

    //Program is opening the file "Romeo and Juliet"
    FILE* original_text = fopen("C://Programming/projects/Onegin/RaJf.txt", "rb");
    FILE* result_file = fopen("C://Programming/projects/Onegin/Result.txt", "wb");
    if(original_text == nullptr || result_file == nullptr){
        fprintf(stderr, "Error opening file!\n");
        abort();
    }
    char* text = text_from_file(original_text);

    //Program prints original text on the screen
    int number_of_lines = print_n_count_number_of_lines(text, result_file);
    //int number_of_lines = 7022;
    printf("%d\n", number_of_lines);
    //char* text;
    //text = text_from_file(original_text);
    _flushall();
    FILE* orig_text = fopen("C://Programming/projects/Onegin/RaJft.txt", "rb");
    char** pointers = Filling_The_Array(orig_text, number_of_lines);
    _flushall();
    printf("Complete!\n");
    printf("Complete!\n");
    printf("%p\n", &pointers[3]);
    //for(int i = 0; i < number_of_lines; ++i) printf("%s\n", pointers[i]);


    //for(int i = 0; i < number_of_lines; ++i) printf("%s\n", &pointers[i]);

    //Program prints sorted text on the screen
    //PrintSorted     (&text);

    //Program prints reversed text on the screen
    //PrintReversed   (&text);

    //Program shows the original text on the screen again
    //Print           (&text);
    /*for(int i = 0; i < number_of_lines; ++i){
        free(pointers[i]);
    }
     */
}





