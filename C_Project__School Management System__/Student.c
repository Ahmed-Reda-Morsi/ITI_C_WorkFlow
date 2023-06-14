#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../c_codes/libs/STD_Types.h"
#include "Student.h"

#pragma pack(1)

Student_t *Head = NULL;

//-------------------------------- functions to check the validity of user inputs------------------------------------------------

// return 0 -> Not Valid | 1-> Valid.
u8 check_name(u8 *String)
{
    for (u8 i = 0; String[i] != '\0'; i++)
    {
        if (!(((String[i] >= alpha_lower_begin) && (String[i] <= alpha_lower_end)) || ((String[i] >= alpha_upper_begin) && (String[i] <= alpha_upper_end)) || String[i] == ' '))
        {
            printf("entered name is not valid\nplease try again:");
            return 0;
        }
    }
    return 1;
}
// return 0 -> Not Valid | 1-> Valid.
u8 check_PhoneNumber(u8 *String)
{
    u8 flag = 1, count = 1;
    if (String[0] != '0' || strlen(String) != 11)
    {
        flag = 0;
    }
    else
    {
        for (u8 i = 1; String[i] != '\0'; i++)
        {
            if (!((String[i] >= Number_begin) && (String[i] <= Number_end)))
            {
                count++;
                flag = 0;
            }
        }
    }
     if (flag==0)
    {
        printf("phone must be 11 digits  and start with zero  (0xxxxxxxxxx) \n please try again:");
    }
    return flag;
}
// return 0 -> Not Valid | 1-> Valid.
u8 check_Date_Of_Birth(u8 *String)
{
    u8 flag = 1;
    u8 *ptr = strtok(String, "/");
    u16 day = atoi(ptr);
    ptr = strtok(NULL, "/");
    u16 month = atoi(ptr);
    ptr = strtok(NULL, "/");
    u16 year = atoi(ptr);

    if (day == 0 || day > DOB_DAY_MAXIMUM)
    {
        flag = 0;
    }
    else if (month == 0 || month > DOB_NOMTH_MAXIMUM)
    {
        flag = 0;
    }
    else if (year == 0 || year > DOB_YEAR_MAXIMUM)  
    {
        flag = 0;
    }

    if (flag==0)
    {
        printf("entered birth day is not valid only valid form is 00/00/0000 and \n please try again:");
    }
    
    return flag;
}

//================================================================
void STUDENT_NEW(Student_t *NewStudent)
{
    /* to check the if id is uniquely or not  */
    u8 flag = 0; // 0-> Id is unique  |  1-> id used before.
    Student_t *temp = Head;
    while (temp != NULL)
    {
        if (temp->ID == NewStudent->ID)
        {
            flag = 1;
            break;
        }
        temp = temp->Next;
    }

    if (flag == 0)
    {
        if (Head == NULL)
        {
            NewStudent->Next = NULL;
            Head = NewStudent;
        }
        else
        {
            NewStudent->Next = Head;
            Head = NewStudent;
        }
    }
    else
    {
        printf("The ID you have entered for student :%s \n is used before, try the with a different one!!!\n", temp->Name);
    }
}
//============================================================================
u8 STUDNET_DELETE(u32 id)
{
    u8 flag = 0;
    Student_t *Temp = Head;
    if (Head != NULL)
    {
        if (id == Head->ID)
        {
            flag = 1;
            Student_t *ptr = Head;
            Head = Head->Next;
            free(ptr);
        }
        else
        {
            while (Temp->Next != NULL)
            {

                if ((id == (Temp->Next)->ID))
                {
                    Student_t *ptr = Temp->Next;
                    Temp->Next = Temp->Next->Next;
                    flag = 1;
                    free(ptr);
                    break;
                }

                Temp = Temp->Next;
            }
        }
    }

    if (flag == 0)
    {
        printf("No Student has this ID!!.\n");
    }
    return flag;
}
//============================================================================
void STUDENT_LIST(void)
{
    u16 Student_No = 0;
    Student_t *Temp = Head;
    if (Temp == NULL)
    {
        printf("There are no Students in the list !!.\n");
    }
    else
    {
        while (Temp != NULL)
        {
            Student_No++;
            printf("\n________________________| Student No. : %d  |_____________________________\n", Student_No);
            printf("Student Name         : %s\n", Temp->Name);
            printf("Student Id           : %d\n", Temp->ID);
            printf("Student Address      : %s\n", Temp->Address);
            printf("Student Phone Number : %s\n", Temp->Phone_Number);
            printf("Student Date of Birth: %s\n", Temp->Date_Of_Birth);
            printf("__|Grades:\n");
            printf("  -> Computer Science :%d\n", Temp->Grades.Compter_Science);
            printf("_________________________________________________________________________\n");
            Temp = Temp->Next;
        }
    }
}
//============================================================================
u8 STUDENT_SORT(u8 sort_type)
{   u8 flag=0;
    Student_t Student_Copy, *first_next, *min_next;
    Student_t *first, *min, *second;
    first = Head;

    while (first != NULL)
    {
        second = first->Next;
        min = first;
        flag=1;
        while (second != NULL)
        {
            switch (sort_type)
            {
            case ID_SORT:
                if (min->ID > second->ID) // sort with students IDs ascending
                {
                    min = second;
                }
                flag=1;
                break;
            case NAME_SORT:
                if ((strcmp(min->Name, second->Name)) > 0) // sort with students Nmaes alphabetically ascending
                {
                    min = second;
                }
                flag=1;
                break;
            case CS_SORT:
                if ((min->Grades.Compter_Science) < (second->Grades.Compter_Science)) // sort with students CS score descending
                {
                    min = second;
                }
                flag=1;
                break;
            default:
                flag=0;
                break;
            }

            second = second->Next;
        }
        // save the linkedlist links
        first_next = first->Next;
        min_next = min->Next;
        // swap the contents of two Student.
        Student_Copy = *first;
        *first = *min;
        *min = Student_Copy;
        // reconnect the linkedlist.
        first->Next = first_next;
        min->Next = min_next;

        first = first->Next;
    }
    if (flag==0)
    {
        printf("NO students to be sorted !!\n");
    }
    
    return flag;
}
//============================================================================
u8 STUDENT_SCORE(u32 id, u16 score)
{   u8 flag=0;
    Student_t *Temp = Head;
    if (Temp == NULL)
    {
        printf("There are no Students in the list !!.");
    }
    else
    {
        while (Temp != NULL)
        {
            if (Temp->ID == id)
            {
                Temp->Grades.Compter_Science = score;
                flag=1;
                break;
            }

            Temp = Temp->Next;
        }
    }
    return flag;
}
//============================================================================
u8 STUDENT_EDIT(u32 id, u8 edit_type, u8 *edit_content)
{   u8 flag=0;
    Student_t *temp = Head;
    while (temp != NULL)
    {
        if (temp->ID == id)
        {
            
            switch (edit_type)
            {
            case NAME_EDIT:
                strcpy(temp->Name, edit_content);
                flag=1;
                break;
            case ADDRESS_EDIT:
                strcpy(temp->Address, edit_content);
                flag=1;
                break;
            case DATE_OF_BIRTH_EDIT:
                strcpy(temp->Date_Of_Birth, edit_content);
                flag=1;
                break;
            case PHONE_NUMBER_EDIT:
                strcpy(temp->Phone_Number, edit_content);
                flag=1;
                break;
            case SCORE_EDIT:
                temp->Grades.Compter_Science = atoi(edit_content);
                flag=1;
                break;
            case ID_EDIT:
                temp->ID = atoi(edit_content);
                flag=1;
                break; // convert string to u32 number (ID).
            default:
                break;
            }
            break;
        }
        temp = temp->Next;
    }
    return flag ;
    
}
//================================================================================
//=============================================================================
void STUDENT_VIEW(u32 id)
{
    u8 flag = 0;
    Student_t *Temp = Head;
    while (Temp != NULL)
    {
        if (Temp->ID == id)
        {
            flag = 1;
            printf("-> Student Name         : %s\n", Temp->Name);
            printf("-> Student Id           : %d\n", Temp->ID);
            printf("-> Student Address      : %s\n", Temp->Address);
            printf("-> Student Phone Number : %s\n", Temp->Phone_Number);
            printf("-> Student Date of Birth: %s\n", Temp->Date_Of_Birth);
            printf("___|Grades:\n");
            printf("  -> Computer Science :%d\n", Temp->Grades.Compter_Science);
            printf("_________________________________________________________________________\n");
            break;
        }
        Temp = Temp->Next;
    }
    if (flag == 0)
    {
        printf("No Student has this ID!!.\n");
    }
}
//==============================================================================
void STUDENT_RANK(u8 subject_rank)
{
    switch (subject_rank)
    {
    case CS_SORT:
        STUDENT_SORT(CS_SORT);
        break;
    default:
        break;
    }
}
//==============================================================================
//==============================================================================
void MAIN_MENU(void)
{
    u8 User_Selected_Operation;
    u32 id;

    printf("\n___________________________________________________________________________________\n");
    u8 *welcome_message = "|_________________|Welcome to School Management System (._.)|_______________________|\n"
                          "|  Here, you can create a new student, update information of an existing student,   |\n"
                          "|  view and manage,scores, check the details of an existing student,                |\n"
                          "|  remove existing student and view student\'s list.                                 |";
    printf("%s\n", welcome_message);
    printf(" ___________________________________________________________________________________\n");
    printf("|________________________> What You can do (^__^)  <_______________________________|\n");
    printf("|  -> 1. Create New Student                                                        |\n");
    printf("|  -> 2. Update Existing Student                                                   |\n");
    printf("|  -> 3. View Existing Student                                                     |\n");
    printf("|  -> 4. Remove Existing Student                                                   |\n");
    printf("|  -> 5. List Existing Students                                                    |\n");
    printf("|  -> 6. Rank Students According To Compter Science grades                         |\n");
    printf("|  -> 0.Exit                                                                       |\n");
    printf("|_________________| Please select what you want to do |____________________________|\n"
           "       You can enter the Number of operation  as in the list Please                   \n");

    do
    {
        printf(" ___________________________________________________________________________________\n");
        printf("\n\t\t|  -> Your selected Operation : ");
        scanf("%hhd", &User_Selected_Operation);

        switch (User_Selected_Operation)
        {
        case Create_New_Student:
            Student_t *Student = (Student_t *)malloc(sizeof(Student_t));
            printf("\nyou have select -> Create New Student\n ");
            printf(" __> Student Name : ");
            do
            {
                scanf(" %[^\n]", &Student->Name);
                printf("\n");
            }
            while(!check_name(Student->Name));

            printf(" __> Student ID : ");
            scanf("%ld", &Student->ID);
            printf("\n");

            printf(" __> Student Date Of Birth : ");
            do
            {
                scanf("%s", &Student->Date_Of_Birth);
                printf("\n");
            } while (!check_Date_Of_Birth(Student->Date_Of_Birth));

            printf(" __> Student Address : ");
            scanf("%s", &Student->Address);
            printf("\n");

            printf(" __> Student Phone number : ");
            do{
            scanf("%s", &Student->Phone_Number);
            printf("\n");
            }while(!check_PhoneNumber(Student->Phone_Number));

            printf(" __> Student Computer Sciene Score : ");
            scanf("%hd", &Student->Grades.Compter_Science);
            printf("\n");

            STUDENT_NEW(Student);
            printf("Student added successfully!(^___^)\n");
            break;

        case Update_Existing_Student:
            printf("\n\n_____________ you have select -> Update Existing Student_____________________________\n ");
            printf("|________________________> What You can edit (^__^)  <___________________________________|\n");
            printf("|  -> 1. Edit Student Name                                                               |\n");
            printf("|  -> 2. Edit Student Address                                                            |\n");
            printf("|  -> 3. Edit Student Date Of Birth                                                      |\n");
            printf("|  -> 4. Edit Student Phone Number                                                       |\n");
            printf("|  -> 5. Edit Student ID                                                                 |\n");
            printf("|_________________| Please select what you want to do |__________________________________|\n"
                   "       You can enter the Number of operation  as in the list Please                      \n");

            u8 edit_type;
            u8 edit_content[50];

            printf(" __> Student ID : ");
            scanf("%ld", &id);
            printf("\n");
            printf(" __> Edit Type : ");
            scanf("%hhd", &edit_type);
            printf("\n");
            if (edit_type==SCORE_EDIT)
            {
                u16 score;
                printf(" __> New Score: ");
                scanf(" %hd", &score);
                if(STUDENT_SCORE(id,score))
                    {printf("Student Score updated successfully!!\n");}
            }
            else{
                printf(" __> Content Edit: ");
                scanf(" %[^\n]", &edit_content);
                printf("\n");
                if(STUDENT_EDIT(id, edit_type, edit_content))
                    {printf("Student info. edited successfully!(^___^)\n");}
            }
            
            break;

        case Remove_Existing_Student:
            printf("\nyou have select -> Delete Existing Student\n ");
            printf(" __> Student ID : ");
            scanf("%d", &id);
            printf("\n");
            if (STUDNET_DELETE(id))
                {printf("Student info. deleted successfully!(^___^)\n");}
            break;

        case List_Existing_Students:
            printf("\nyou have select -> List Existing Student \n ");
            printf("List Existing Student is alphabetically ascending \n ");
            if(STUDENT_SORT(NAME_SORT))
                {STUDENT_LIST();}
            break;

        case View_Existing_Student:
            printf("\nyou have select -> view Existing Student \n ");
            printf(" __> Student ID : ");
            scanf("%d", &id);
            STUDENT_VIEW(id);
            break;

        case Rank_Students_According_To_CS:
            printf("\nyou have select -> Rank Students According To Compter Science grades   \n ");
            STUDENT_RANK(CS_SORT);
            break;
        }
    } while (User_Selected_Operation != 0);
}

//--------------------------------- extera functions ---------------------------
void Display(void)
{
    u16 Student_No = 0;
    Student_t *Temp = Head;
    if (Temp == NULL)
    {
        printf("There are no Students in the list !!.");
    }
    else
    {
        while (Temp != NULL)
        {
            Student_No++;
            printf("\n________________________| Student No. : %d  |_____________________________\n", Student_No);
            printf("Student Name         : %s\n", Temp->Name);
            printf("Student Id           : %d\n", Temp->ID);
            printf("Student Address      : %s\n", Temp->Address);
            printf("Student Phone Number : %s\n", Temp->Phone_Number);
            printf("Student Date of Birth: %s\n", Temp->Date_Of_Birth);
            printf("__|Grades:\n");
            printf("  -> Computer Science :%d\n", Temp->Grades.Compter_Science);
            printf("_________________________________________________________________________\n");
            Temp = Temp->Next;
        }
    }
}
//============================================================================
