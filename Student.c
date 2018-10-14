#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 10
char* name[MAX_STUDENTS];
char* no[MAX_STUDENTS];
float English[MAX_STUDENTS];
float Math[MAX_STUDENTS];
float Chinese[MAX_STUDENTS];

int count = 0;

void menu(void);
void init(void);
int  findStudent(char* student);
void insert(void);
void printAll(void);
void searchInNumber(void);
void searchInName(void);

int main(void)
{
  int code;
  init();
  menu();
  for(;;){
    printf("Enter operation code:");
    scanf("%d",&code);
    while(getchar() != '\n');
    switch(code){
      case 0:return 0;
      case 1:insert();break;
      case 2:printAll();break;
      case 3:searchInNumber();break;
      case 4:searchInName();break;
      default: printf("Illegal code\n");
    }
  }
}

void menu(void)
{
  printf("0:退出\n");
  printf("1:插入学生信息\n");
  printf("2:打印全部学生信息\n");
  printf("3:输入学号查找学生信息\n");
  printf("4:输入姓名查找学生信息\n");
}
void init(void)
{
  int i;
    for(i=0;i<MAX_STUDENTS;i++){
    no[i]=(char*)malloc(30*sizeof(char));
    name[i]=(char*)malloc(30*sizeof(char));
    English[i]=0.0f;
    Chinese[i]=0.0f;
    Math[i]=0.0f;
  }
}
int findStudent(char* student)
{
  int i;
  for(i=0;i<count;i++){
    if(strcmp(no[i],student)==0)
       return i;
    else if(strcmp(name[i],student)==0)
        return i;
  }
  return -1;
}

void insert(void)
{
  char* student;
  float grade;
  student = (char*)malloc(30*sizeof(char));
  if(count == MAX_STUDENTS){
     printf("Database is full; can't add more students.\n");
     return ;
  }

  printf("Enter student number:");
  scanf("%s",student);
  if(findStudent(student)>=0){
    printf("Student already exists");
    return;
  }
  strcpy(no[count],student);
  printf("Enter student name:");
  scanf("%s",student);
  if(findStudent(student)>=0){
    printf("Student already exists");
    return;
  }
  strcpy(name[count],student);

  printf("Enter English grade:");
  scanf("%f",&grade);
  English[count]=grade;

  printf("Enter Chinese grade:");
  scanf("%f",&grade);
  Chinese[count]=grade;

  printf("Enter Math grade:");
  scanf("%f",&grade);
  Math[count]=grade;
  count++;
}
void printAll(void)
{
  int i;
  for(i=0;i<count;i++){
    printf("Student number:");
    printf(" %s\n",no[i]);

    printf("Student name:");
    printf(" %s\n",name[i]);

    printf("English grade:");
    printf(" %.2f\n",English[i]);

    printf("Chinese grade:");
    printf(" %.2f\n",Chinese[i]);

    printf("Math grade:");
    printf(" %.2f\n",Math[i]);

    printf("\n");
  }
}
void searchInNumber(void)
{
  char* student;
  int i;
  student = (char*)malloc(30*sizeof(char));
  printf("Enter student number:");
  scanf("%s",student);

  i = findStudent(student);
   if(i>=0){
    printf("Student number:");
    printf(" %s\n",no[i]);

    printf("Student name:");
    printf(" %s\n",name[i]);

    printf("English grade:");
    printf(" %.2f\n",English[i]);

    printf("Chinese grade:");
    printf(" %.2f\n",Chinese[i]);

    printf("Math grade:");
    printf(" %.2f\n",Math[i]);
    printf("\n");
  }
  else printf("Student not found\n");
}

void searchInName(void)
{
  char* student;
  int i;
  student = (char*)malloc(30*sizeof(char));
  printf("Enter student name:");
  scanf("%s",student);

  i = findStudent(student);
  if(i>=0){
    printf("Student number:");
    printf(" %s\n",no[i]);

    printf("Student name:");
    printf(" %s\n",name[i]);

    printf("English grade:");
    printf(" %.2f\n",English[i]);

    printf("Chinese grade:");
    printf(" %.2f\n",Chinese[i]);

    printf("Math grade:");
    printf(" %.2f\n",Math[i]);
    printf("\n");
  }
  else printf("Student not found\n");
}