#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

#define Student struct Stud

void Add(FILE * fp);
void Update(FILE * fp);
void Display(FILE * fp);
void Indivisual(FILE *fp);
void Password(FILE *fp);
FILE * Del(FILE * fp);
void printChar(char ch,int n);
void Title();
FILE *tp;

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct Pass
{
	char Pass[25];
}Pa;

struct Stud
{
    char SName[1000];
    char FName[1000];
    char Dept[100];
    int Roll;
    int SMob;
    int FMob;
    char USN[100];
    char Email[1000];
    float SGPA[8];
    float CGPA;
};


int main()
{
    int ch,id,k,i;
    char c,Pas[50];
    SetConsoleTitle("Student Database Record | NHCE");
    FILE * fp;
    Student s;
    int Option;
    char Another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    system("color 2f");
	gotoxy(42,8);
	printf("LOGIN(If 1st login press ENTER)");
	gotoxy(42,10);
	printf(" __________________________________");
	gotoxy(42,11);
	printf("|\tEnter password :             |");
	gotoxy(42,12);
	printf("|__________________________________|");
	//printf("\n\t\t\t\t\t");
	gotoxy(65,11);
	while( k<10)
	{
	    Pas[k]=getch();
	    char s=Pas[k];
	    if(s==13)
		 break;
	    else printf("*");
	    k++;
	}
	Pas[k]='\0';
	tp=fopen("F:/Password.txt","r+");
    fgets(Pa.Pass,25,tp);
    if(strcmp(Pas,Pa.Pass)==0)
	{
		system("cls");
		gotoxy(10,3);
		printf("<<<< Loading Please Wait >>>>");
		for(i=0; i<5; i++)
        {
            printf("\t(*_*)");
            Sleep(500);
        }
        printf("\n\n\n\n\n\t\t\t\t\t\t@  @  @  @  @  @  @  @");
		printf("\n\n\t\t\t\t\t        @                    @");
		printf("\n\n\t\t\t\t\t        @       WELCOME      @");
		printf("\n\n\t\t\t\t\t        @                    @");
		printf("\n\n\t\t\t\t\t        @  @  @  @  @  @  @  @");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
		getch();

    Title();
    printf("\n\n\t\t\t\t Mini Project 2021");
    printf("\n\n\t\t\t   New Horizon Collage Of Engineering \n\t\t\t");
    printChar('=',38);
    printf("\n\n\n\t\t\t       press any key to Enter");
    getch();

    while(1)
    {
        Title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Update Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Individual View");
        printf("\n\n\t\t\t\t5. Remove Student");
        printf("\n\n\t\t\t\t6. Change Password");
        printf("\n\n\t\t\t\t7. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&Option);

        switch(Option)
        {
            case 1:
                Add(fp);
                break;
            case 2:
                Update(fp);
                break;
            case 3:
                Display(fp);
                break;
            case 4:
                Indivisual(fp);
                break;
            case 5:
                fp=Del(fp);
                break;
            case 6:
                    system("cls");
				    system("color Cf");
			        Password(fp);
                break;
            case 7:
                return 1;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }
    }
    }
    else
    {
        printf("Wrong Password . Get Out");
        getch();
    }
    return 1;

}


void Password(FILE * fp)
{
	char c;
	printf("\nEnter new password :");
	fflush(stdin);
	gets(Pa.Pass);
	printf("\nSave password (y/n) :");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		tp=fopen("F:/Password.txt","w+");
	    fwrite(&Pa,sizeof(Pa),1,tp);
	    fclose(tp);
		printf("\n\tPassword Saved\n");
	}
	else
	{
		printf("Password not saved :\n");
		printf("Press any key to continue >>>");
		getch();
	}
}


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void Title()
{
    system("cls");
    system("COLOR 06");
    printf("\n\n\t");
    printChar('=',19);
    printf(" Student Database Record ");
    printChar('=',19);
    printf("\n");
}


 void Add(FILE * fp)
{
    Title();

    char another='y';
    Student s;
    int i;
    float CGPA;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.SName,1000,stdin);
        s.SName[strlen(s.SName)-1]='\0';

        printf("\n\n\t\tEnter Father's Name of the Student: ");
        fflush(stdin);
        fgets(s.FName,1000,stdin);
        s.FName[strlen(s.FName)-1]='\0';

        printf("\n\n\t\tEnter Depertment Name: ");
        fflush(stdin);
        fgets(s.Dept,100,stdin);
        s.Dept[strlen(s.Dept)-1]='\0';

        printf("\n\n\t\tEnter Student's Mobile Number: ");
        scanf("%d",&s.SMob);

        printf("\n\n\t\tEnter Father's Mobile Number: ");
        scanf("%d",&s.FMob);

        printf("\n\n\t\tEnter Roll number: ");
        scanf("%d",&s.Roll);

        printf("\n\n\t\tEnter USN of Student: ");
        fflush(stdin);
        fgets(s.USN,100,stdin);
        s.USN[strlen(s.USN)-1]='\0';

        printf("\n\n\t\tEnter Email Address of Student: ");
        fflush(stdin);
        fgets(s.Email,1000,stdin);
        s.Email[strlen(s.Email)-1]='\0';

        printf("\n\n\tEnter SGPA for 8 semesters\n");
        for(i=0,CGPA=0; i<8; i++)
        {
            scanf("%f",&s.SGPA[i]);
            CGPA+=s.SGPA[i];

        }

        CGPA/=8.0;
        s.CGPA=CGPA;

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}


FILE * Del(FILE * fp)
{
    Title();

    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter Roll number of Student to Delete the Record");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.Roll==tempRoll)
        {
            flag=1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.SName,s.Dept,s.Roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}


void Update(FILE * fp)
{
    Title();

    Student s;
    int i,flag=0,tempRoll,siz=sizeof(s);
    float CGPA;

    printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");
    scanf("%d",&tempRoll);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.Roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tRecord Found\n\t\t\t");
        printChar('=',38);
        printf("\n\n\t\t\tStudent Name: %s",s.SName);
        printf("\n\n\t\t\tStudent Roll: %d\n\t\t\t",s.Roll);
        printChar('=',38);
        printf("\n\n\t\t\tEnter New Data for the student");

        printf("\n\n\t\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.SName,1000,stdin);
        s.SName[strlen(s.SName)-1]='\0';

        printf("\n\n\t\t\tEnter Father Name of the Student: ");
        fflush(stdin);
        fgets(s.FName,1000,stdin);
        s.FName[strlen(s.FName)-1]='\0';

        printf("\n\n\t\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.Dept,100,stdin);
        s.Dept[strlen(s.Dept)-1]='\0';

        printf("\n\n\t\t\tEnter Roll number: ");
        scanf("%d",&s.Roll);

        printf("\n\n\t\t\tEnter Student's Mobile Number: ");
        scanf("%d",&s.SMob);

        printf("\n\n\t\t\tEnter Father's Mobile Number: ");
        scanf("%d",&s.FMob);

        printf("\n\n\t\t\tEnter the USN of Student: ");
        fflush(stdin);
        fgets(s.USN,100,stdin);
        s.USN[strlen(s.USN)-1]='\0';

        printf("\n\n\t\t\tEnter the Email Address of the Student: ");
        fflush(stdin);
        fgets(s.Email,100,stdin);
        s.Email[strlen(s.Email)-1]='\0';

        printf("\n\n\t\t\tEnter SGPA for 8 semesters:\n");
        for(i=0,CGPA=0; i<8; i++)
        {
            scanf("%f",&s.SGPA[i]);
            CGPA+=s.SGPA[i];

        }
        CGPA=CGPA/8.0;


        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");

}

void Display(FILE * fp)
{
    Title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\t\tSTUDENT NAME : %s",s.SName);
        printf("\n\t\t\tFATHER NAME : %s",s.FName);
        printf("\n\n\t\tDEPARTMENT : %s",s.Dept);
        printf("\n\n\t\tROLL : %d",s.Roll);
        printf("\n\n\t\tSTUDENT MOBILE NUMBER : %d",s.SMob);
        printf("\n\n\t\tFATHER'S MOBILE NUMBER : %d",s.FMob);
        printf("\n\n\t\tUSN : %s",s.USN);
        printf("\n\n\t\tE-MAIL : %s",s.Email);
        printf("\n\n\tSGPA: ");

        for(i=0; i<8; i++)
        printf("| %.2f |",s.SGPA[i]);
        printf("\n\n\t\tCGPA : %.2f\n\t",s.CGPA);
        printChar('-',65);
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void Indivisual(FILE *fp)
{
    Title();
    int tempRoll,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEnter Roll Number: ");
        scanf("%d",&tempRoll);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.Roll==tempRoll)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\t\t\tSTUDENT NAME : %s",s.SName);
            printf("\n\t\t\tFATHER NAME : %s",s.FName);
            printf("\n\n\t\tDEPARTMENT : %s",s.Dept);
            printf("\n\n\t\tROLL : %d",s.Roll);
            printf("\n\n\t\tSTUDENT MOBILE NUMBER : %d",s.SMob);
            printf("\n\n\t\tFATHER'S MOBILE NUMBER : %d",s.FMob);
            printf("\n\n\t\tUSN : %s",s.USN);
            printf("\n\n\t\tE-MAIL : %s",s.Email);
            printf("\n\n\tSGPA: ");

            for(i=0; i<8; i++)
            printf("| %.2f |",s.SGPA[i]);
            printf("\n\n\t\tCGPA : %.2f\n\t",s.CGPA);
            printChar('-',65);

        }
        else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


        printf("\n\n\t\tShow another student information? (Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
