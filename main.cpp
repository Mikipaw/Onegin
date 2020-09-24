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
#define END_OF_FILE_SYM '~'

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
    while(c != END_OF_FILE_SYM){
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
    fseek(file_name, 0, SEEK_END); // seek to end of file
    size_t size_of_file = ftell(file_name); // get current file pointer
    fseek(file_name, 0, SEEK_SET); // seek back to beginning of file
    char* result_string = (char*)malloc(size_of_file);
    char c = 0;
    int i = 0;

    while(!feof(file_name)){
        c = (char)fgetc(file_name);
        if (c != '\n'){
            result_string[i++] = c;
        }
        else if(result_string[i - 1] != '\0') result_string[i++] = '\0';
    }
    result_string[i++] = '\n';
    result_string[i++] = '\0';
    result_string[i++] =  '~';
    result_string[i]   = '\0';

    return result_string;
}

void Interface(){

    //Program is opening the file "Romeo and Juliet"
    FILE* original_text = fopen("C://Programming/projects/Onegin/Test.txt", "rb");
    FILE* result_file   = fopen("C://Programming/projects/Onegin/Result.txt", "wb");

    if(original_text == nullptr || result_file == nullptr){
        fprintf(stderr, "Error opening file!\n");
        abort();
    }

    char* text = text_from_file(original_text);

    //Program prints original text on the screen
    int number_of_lines = print_n_count_number_of_lines(text, result_file);
    printf("Number of lines in input text - %d\n", number_of_lines);

    char** pointers = (char**) calloc(number_of_lines + 1, sizeof(char*));

    pointers[0] = (char*) calloc(60, sizeof(char));
    pointers[0] = text;

    int pos = 0;
    for(int i = 1; i < number_of_lines; ++i){
        pointers[i] = (char*) calloc(60, sizeof(char));
        while(text[pos] != '\0') ++pos;
        while(text[pos] == '\0') ++pos;
        pointers[i] = &text[pos++];
    }
    _flushall();

    //Program prints original text in the file
    fprintf(result_file,"Original text:\n");
    for(int i = 0; i < number_of_lines; ++i) fprintf(result_file, "%s\n", pointers[i]);

    quick_sort_strings(pointers, 0, number_of_lines - 1);
    //qsort(pointers, number_of_lines, sizeof(char*),
          //(int(*)(const void*, const void*))str_cmp_4_sort);

    //Program prints sorted text in the file
    fprintf(result_file, "\nSorted from begin:\n");
    for(int i = 0; i < number_of_lines; ++i) {
        if(str_cmp(pointers[i], "\n") == FALSE)
            fprintf(result_file, "%s\n", pointers[i]);
    }

    //Program prints sorted from end text in the file
    fprintf(result_file, "\nSorted from end:\n");
    quick_sort_strings(pointers, 0, number_of_lines - 1, "FROM END");
    for(int i = 0; i < number_of_lines; ++i){
        if(str_cmp(pointers[i], "\0") == 0)
            fprintf(result_file, "%s\n", pointers[i]);
    }

    //Program prints original text again
    fprintf(result_file, "\nFinal text:\n");
    fseek(original_text, 0, SEEK_SET);
    char c = 0;
    while(!feof(original_text)) {
        c = (char) fgetc(original_text);
        fputc(c, result_file);
    }

    //Closing files and free the memory
    fclose(original_text);
    fclose(result_file);
    for(int o = 0; o < number_of_lines; ++o) {
        free(pointers[o]);
    }
    free(pointers);
}
