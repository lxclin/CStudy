#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

#define MAX_COUNT_OF_STUDENTS 30
#define MAX_LENGTH_OF_STUDENT_NAME 20
#define MAX_LENGTH_OF_STUDENT_ID 13
#define MAX_LENGTH_OF_MAIL 20
#define MAX_LENGTH_OF_PHONE 11
#define MAX_LENGTH_OF_SEX 4


/*
 * 定义一种枚举类型叫做status
 * 表示状态，状态包括：正确 和 错误
 * 对应就是 OK or ERROR
 */
typedef enum {
    OK,
    ERROR
}Status;

/*
 * 定义一种结构体叫做student表示
 * 表示学生的数据结构，状态包括：
 *  id      学生的编号，类型为int
 *  student_id   学号，类型为数组
 *  name    学生的姓名，类型为数组
 *  sex     学生的性别，类型为数组
 *  mail    学生的邮箱，类型为数组
 *  phone   学生的电话，类型为数组
 */
typedef struct {
    int id;
    char name[MAX_LENGTH_OF_STUDENT_NAME];
    char student_id[MAX_LENGTH_OF_STUDENT_ID+1];
    char sex[MAX_LENGTH_OF_SEX];
    char mail[MAX_LENGTH_OF_MAIL];
    char phone[MAX_LENGTH_OF_PHONE+1];
}Student;


/*
 * 打印所有学生信息
 * @param student[] 所有学生信息，是一个存储Student信息的数组
 * @param count 数组的实际长度
 */

void printOneStudent(Student student){
    printf("%d\t%s\t%s\t%s\t%s\t%s\n",student.id, student.name, student.student_id, student.sex, student.mail, student.phone);

    //你可以试着注释掉上面的print，试试下面这段，想想为什么？
//    printf("%d\t%s\t",student.id,student.name);
//    if(strlen(student.name) < 8){
//        printf("\t");
//    }
//    printf("%s\t%s\t%s\t%s\n",student.student_id,student.sex,student.mail,student.phone);
}

void printAllStudent(Student students[], int count) {
    printf("ID\t姓名\t\t学号\t\t\t\t性别\t邮箱\t\t\t\t\t电话\n");
    for(int i = 0; i < count; i++) {
        printOneStudent(students[i]);
    }
}

/*
 * 判断两个字符数组内容完全相符
 */
bool isCharArrayeEqual(char aStr[],char bStr[]){
    //待实现
    return false;
}

/*
 * 根据学生学号获取学生信息
 * @param student[] 所有学生信息，是一个存储Student信息的数组
 * @param count 数组的实际长度
 * @param student_id 目标学生学号
 */
Student studentInArrayWithSrudentId(Student students[], int count, char student_id[]){
    //请填写这里，需要了解如何判断两个数组中的字符完全相等。
    Student targetStudent = {};

    return targetStudent;
}

/*
 * 根据学生编号获取学生信息
 * @param student[] 所有学生信息，是一个存储Student信息的数组
 * @param count 数组的实际长度
 * @param id 目标学生编号
 */

Student studentInArrayWithId(Student students[], int count, int id){
    Student targetStudent = {};
    //用for循环对学生数组进行遍历，遍历是什么意思，你可以百度
    for(int i = 0; i < count; i++) {
        //把每个student信息取出来比对一次。
        Student tempStudent = students[i];
        if(tempStudent.id == id){
            //如果学生id相等
            targetStudent = tempStudent;
            break;
        }
    }
    return targetStudent;
}

void main() {
    //定义文件路径变量，用指针指向这个变量。
    char *filePath = "../resource/class_student_info.txt";
    printf("文件路径为：%s\n",filePath);

    //定义一个长度为30的数组，数组中每个变量都是Student类型。
    Student students[MAX_COUNT_OF_STUDENTS];

    FILE* pFile;
    if((pFile=fopen(filePath,"r"))==NULL){
        printf("打开文件失败\n");
        return;
    }else{
        printf("打开文件成功\n");
    }
    //读取文件，!feof()表示文件流能够读到数据。

    printf("开始读取文件...\n");
    int i = 0;//作为循环变量
    while(!feof(pFile)){
        fscanf(pFile,"%d",&students[i].id);
        fscanf(pFile,"\t%s",students[i].name);
        fscanf(pFile,"\t%s",students[i].student_id);
        fscanf(pFile,"\t%s",students[i].sex);
        fscanf(pFile,"\t%s",students[i].mail);
        fscanf(pFile,"\t%s",students[i].phone);
        i++;
    }

    //定义学生学生总数
    int countOfStudent = i;

    //定义操作码
    int operationCode = 0;
    printf("/**********************************/\n");
    printf("/**********学生信息管理系统**********/\n");
    printf("/**********************************/\n");
    printf("请选择操作：\n");
    printf("1、打印所有学生信息\n");
    printf("2、根据id查询学生信息\n");
    printf("3、根据学号查询学生信息\n");
    printf("4、增加学生信息\n");
    printf("5、删除学生信息\n");
    scanf("%d",&operationCode);
    switch(operationCode){
        case 1:
            printAllStudent(students,countOfStudent);
            break;
        case 2:
            printf("请输入学生编号\n");
            int targetId = 0;
            scanf("%d",&targetId);
            Student student = studentInArrayWithId(students,countOfStudent,targetId);
            printOneStudent(student);
            break;
        case 3:
            printf("请输入学生学号\n");
            char targetStudentId[] = {0};

            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("输入的操作码不正确");
            break;
    }
}