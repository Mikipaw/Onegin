/*!
 * @mainpage
 *  \brief     Romeo and Juliet
 *  \details   This program is used to make an encyclopedia using "Romeo and Juliet" tragedy.
 *  \author    Michael Pavlov
 *  \author    Mikhail Pavlov
 *  \version   C++20
 *  \date      22.09.2020
 *  \pre       First initialize the system.
 *  \bug       No
 *  \warning
 *  \copyright GNU Public License.
 */

#include <cstdlib>
#include <cstdio>

#include "Tests.h"

#define END_OF_FILE "~"

/*!
*  \function void Print(FILE* input_file, FILE* output_file)
*  \brief Printing text from file input_file in file output_file
*  \param input_file a FILE*.
*  \param output_file a FILE*.
*  \return nothing
*/
void Print (FILE* input_file, FILE* output_file);

/*!
*  \function void PrintSorted(FILE* input_file, FILE* output_file)
*  \brief Printing text from file input_file in file output_file sorted by strings
*  \param input_file a FILE*.
*  \param output_file a FILE*.
*  \return nothing
*/
void PrintSorted (FILE* input_file, FILE* output_file);

/*!
*  \function void PrintReversed(FILE* input_file, FILE* output_file)
*  \brief Printing text from file input_file in file output_file sorted in reverse order by strings
*  \param input_file a FILE*.
*  \param output_file a FILE*.
*  \return nothing
*/
void PrintReversed  (FILE* input_file, FILE* output_file);

/*!
*  \function void Filling_The_Array(char** text, char*** pointers, int number_of_lines)
*  \brief Filling the array of strings (pointers) with strings from text
*  \param text a char**
*  \param pointers a char***
*  \param number_of_lines an int
*  \return nothing
*/
void Filling_The_Array(char** text, char*** pointers, int number_of_lines);

/*!
*  \function int print_n_count_of_lines(const char* text, FILE* result_file_name)
*  \brief Prints the text in result_file_name & counts number of lines in the text
*  \param text a const char*
*  \param result_file_name a FILE*
*  \return an integer - number of lines
*/
int print_n_count_number_of_lines(const char* text, FILE* result_file_name);


/*!
*  \function char* text_from_file(FILE* file_name)
*  \brief Returns text from file_name
*  \param file_name a FILE*
*  \return a char* - text from file
*/
char* text_from_file(FILE* file_name);

void Interface();

int main() {
    AllTests();

    Interface();
    return 0;
}


void Filling_The_Array(char** text, char*** pointers, int number_of_lines){}

int print_n_count_number_of_lines(const char* text, FILE* result_file_name){
    int result = 0;
    int c = 0, i = 0;
    while(c != '~'){
        c = (char)text[i];
        if((char)c == '\0'){
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
    //ftell
    fseek(file_name, 0, SEEK_SET);
    char* result_string = (char*)malloc(4096);
    char c = 0;
    int i = 0;

    while(!feof(file_name)){
        c = (char)fgetc(file_name);
        if (c != '\n')
            result_string[i++] = c;
        else
            result_string[i++] = '\0';
    }
    result_string[i++] = '\n';
    result_string[i++] = '\0';
    result_string[i++] = '~';
    result_string[i] = '\0';

    return result_string;
}

void Interface(){

    //Program is opening the file "Romeo and Juliet"
    FILE* original_text = fopen("C://Programming/projects/Onegin/simpleTest.txt", "rb");
    FILE* result_file = fopen("C://Programming/projects/Onegin/Result.txt", "wb");

    if(original_text == nullptr || result_file == nullptr){
        fprintf(stderr, "Error opening file!\n");
        abort();
    }

    char* text = text_from_file(original_text);
    fclose(original_text);
    //printf("%s", text);

    //Program prints original text on the screen
    int number_of_lines = print_n_count_number_of_lines(text, result_file);
    //int number_of_lines = 7022;
    printf("%d\n", number_of_lines);
    //char* text;
    //text = text_from_file(original_text);
    char** pointers = (char**) calloc(number_of_lines + 1, sizeof(char*));
    //Filling_The_Array(&text, &pointers, number_of_lines);
    //pointers = (char**) calloc(number_of_lines, sizeof(char));
    int j = 0;
    pointers[0] = (char*) calloc(50, sizeof(char));
    pointers[0] = text;

    for(int i = 1; i < number_of_lines; ++i){
        pointers[i] = (char*) calloc(50, sizeof(char));
        while(text[j] != '\0') ++j;
        while(text[j] == '\0') ++j;
        pointers[i] = &text[j++];
    }
    int a[150] = {};
    _flushall();
    printf("Complete!\n");
    printf("Complete!\n");
    for(int i = 0; i < number_of_lines; ++i) printf("%s\n", pointers[i]);

    quick_sort_strings(pointers, 0, number_of_lines - 1);
    //qsort(pointers, number_of_lines, sizeof(char*),
          //(int(*)(const void*, const void*))str_cmp_4_sort);
    for(int i = 0; i < number_of_lines; ++i) printf("%s\n", pointers[i]);

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

    free(text);
    for(int o = 0; o < number_of_lines; ++o) {
        free(pointers[o]);
    }
    free(pointers);
}


