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
#include <cstring>

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
char* text_from_file(FILE* file_name, size_t size_of_file);

void Interface();

//TODO: take names of files from command prompt
int main(/*int argc, char** argv*/) {
    AllTests();

    //TODO: to handle errors
    //Interface();
    return 0;
}


void Filling_The_Array(char** text, char*** pointers, int number_of_lines){}

int print_n_count_number_of_lines(const char* text, FILE* result_file_name){
    fprintf(result_file_name, "Original text:\n");
    int result = 0;
    int c = 0, i = 0;

    while(c != END_OF_FILE_SYM){
        c = (char) text[i];
        if((char) c == '\0'){
            result++;
            //fputc('\n', result_file_name);
        }
        else if(c != '\r') fputc(c, result_file_name);
        ++i;
    }
    _flushall();
    return result;
}

char* text_from_file(FILE* file_name, size_t size_of_file){
    fseek(file_name, 0, SEEK_SET);

    char* result_string = (char*) calloc(size_of_file + 5, sizeof(char));
    char c = 0;
    int i = 0;

    while(!feof(file_name)) {
        c = (char) fgetc(file_name);

        if(c != '\n' && c != '\r') {
            result_string[i++] = c;
        }
        else if(c != '\r') result_string[i++] = '\0';
        else result_string[i++] = '\n';
    }

    result_string[i-1] = '\n';
    result_string[++i] = '\0';
    result_string[++i] =  '~';
    result_string[++i] = '\0';

    return result_string;
}

void Interface() {

    //Program is opening the file "Romeo and Juliet"
    FILE* original_text = fopen("C://Programming/projects/Onegin/Test.txt", "rb");
    FILE* result_file = fopen("C://Programming/projects/Onegin/Result.txt", "wb");

    if (original_text == nullptr || result_file == nullptr) {
        fprintf(stderr, "Error opening file!\n");
        return;
    }

    fseek(original_text, 0, SEEK_END);
    size_t size_of_file = ftell(original_text);
    fseek(original_text, 0, SEEK_SET);

    char* text = text_from_file(original_text, size_of_file);
    assert(text != nullptr);

    //Program prints original text on the screen
    int number_of_lines = print_n_count_number_of_lines(text, result_file);
    assert(number_of_lines != 0);
    printf("Number of lines in input text - %d\n", number_of_lines);

    auto *pointers = (simple_string *) calloc(number_of_lines + 1, sizeof(simple_string));

    pointers[0].string = text;

    int number_of_empty_lines = 0;

    char* text_ptr = text;
    char* ptr = nullptr;
    for (int i = 1; i < number_of_lines; ++i) {
        ptr = strchr(text, '\0');
        ptr++;
        pointers[i].string = ptr;
        pointers[i-1].size = (int) (pointers[i].string - pointers[i-1].string);
        text+=pointers[i-1].size;
        if(pointers[i-1].string[0] == '\n') number_of_empty_lines++;
    }
    pointers[number_of_lines-1].size = (int) (pointers[number_of_lines-1].string - pointers[number_of_lines-2].string);
    _flushall();

    //Program prints original text in the file
    quick_sort_strings(pointers, 0, number_of_lines - 1);
    //qsort(pointers, number_of_lines, sizeof(char*),
    //(int(*)(const void*, const void*))str_cmp_4_sort);

    //Program prints sorted text in the file
    fprintf(result_file, "\nSorted from begin:\n");
    for (int i = number_of_empty_lines; i < number_of_lines; ++i) {
        fwrite(pointers[i].string, pointers[i].size, sizeof(char), result_file);
    }

    //Program prints sorted from end text in the file
    fprintf(result_file, "\nSorted from end:\n");
    quick_sort_strings(pointers, 0, number_of_lines - 1, "FROM END");
    for (int i = number_of_empty_lines; i < number_of_lines; ++i) {
        fwrite(pointers[i].string, pointers[i].size, sizeof(char), result_file);
    }

    //Program prints original text again
    fprintf(result_file, "\nFinal text:\n");
    fwrite(text_ptr, size_of_file, sizeof(char), result_file);

    //Closing files and free the memory
    fclose(original_text);
    fclose(result_file);

    for (int o = 0; o < number_of_lines; ++o) {
        free(pointers[o].string);
    }
    free(pointers);
    free(text_ptr);
    free(ptr);

}
