#ifndef STUDENT_H
#define STUDENT_H
#include "../../c_codes/libs/STD_Types.h"

#define NAME_MAXIMUM                    50
#define ADDRESS_MAXIMUM                 50
#define PHONE_NUMBER_MAXIMUM            12
#define DATE_OF_BIRTH_MAXIMUM           11

#define DOB_YEAR_MAXIMUM                2017  // at least 6 years old student 
#define DOB_NOMTH_MAXIMUM               12
#define DOB_DAY_MAXIMUM                 31

#define ID_SORT                         0
#define NAME_SORT                       1
#define CS_SORT                         2


#define NAME_EDIT                       1
#define ADDRESS_EDIT                    2
#define DATE_OF_BIRTH_EDIT              3
#define PHONE_NUMBER_EDIT               4
#define ID_EDIT                         5
#define SCORE_EDIT                      6


#define  Create_New_Student             1
#define  Update_Existing_Student        2
#define  View_Existing_Student          3
#define  Remove_Existing_Student        4
#define  List_Existing_Students         5
#define  Rank_Students_According_To_CS  6

#define alpha_lower_begin               0x41 // 'a'
#define alpha_lower_end                 0x5A // 'z'
#define alpha_upper_begin               0x61 // 'A'
#define alpha_upper_end                 0x7A // 'Z'
#define Number_begin                    0x30 //'0'
#define Number_end                      0x39 //'9'



typedef struct Grades{
u16 Compter_Science;
}Grades_t;

typedef struct Student
{
    u8 Name[NAME_MAXIMUM];
    u32 ID;
    u8 Address[ADDRESS_MAXIMUM];
    u8 Phone_Number[PHONE_NUMBER_MAXIMUM];
    u8 Date_Of_Birth[DATE_OF_BIRTH_MAXIMUM];
    Grades_t Grades;
    struct Student *Next;
} Student_t;


/* 
* @brief:this function displays the welcome screen,targeted activates and manage the program flow.
* 
*/
void MAIN_MENU (void); 

/* 
* @brief:this function creates a new student account (node), takes all student details. 
* @params: a pointer for student struct that hold new student info.
*/
void STUDENT_NEW(Student_t *NewStudent);

/* 
* @brief:this function is for deleting a customer student account.
* @params: Student ID.
* @return: 0 if id is note exist | 1 if it deleted successfully.
 */
u8 STUDNET_DELETE(u32 id);

/* 
* @brief:this function, you can view the students information such as name, date of birth,
*        ID, address and phone number in table form (alphabetically ascending).
*/
void STUDENT_LIST(void); //this function, you can view the students information

/* 
* @brief: this function has been used for updating a particular student account.
* @param: Student ID
* @param: Student field to be edit.
* @param: Student field content.
* @return: 0 if id is note editted | 1 if it editted successfully.
 */
u8 STUDENT_EDIT(u32 id, u8 edit_type, u8 *edit_content);

/* 
* @brief:this function can sort all students according to computer science score in descending order. 
* @param: Student subject to be rank based on it.
 */
void STUDENT_RANK(u8 subject_rank);

/* 
* @brief:this function has been used for updating score of all students.
* @param: Student ID
* @param: Student new computer science score .
* @return: 0 if id is note editted | 1 if it editted successfully.
 */
u8 STUDENT_SCORE(u32 id, u16 score);

/* 
* @brief:this function can sort all students according to choosed sort type in descending order. 
* @param: Student subject to be rank based on it.
* @return: 0 if id is note sorted | 1 if it sorted successfully.
 */
u8 STUDENT_SORT(u8 sort_type);

/* 
* @brief:this function list all students in order as them in the linked list. 
 */
void Display(void);

/* 
* @brief:this function view certain student information. 
* @param: Student ID
 */
void STUDENT_VIEW(u32 id);

#endif

