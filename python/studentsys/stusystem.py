import  os

filename = 'students.txt'

def main():
    while True:
        menu()
        choice = int(input("请选择:"))
        if choice in [0,1,2,3,4,5,6,7]:
            if choice == 0:
                answer = input('您确定要退出系统吗？y/n')
                if answer == 'y' or answer == 'Y':
                    print('谢谢您的使用！！！')
                    break
                else:
                    continue
            elif choice == 1:
                insert() #录入学生信息
            elif choice == 2:
                search() #
            elif choice == 3:
                delete()
            elif choice == 4:
                modify()
            elif choice == 5:
                sort()
            elif choice == 6:
                total()
            elif choice == 7:
                show()


def menu():
    print('==========学生信息管理系统================')
    print('=============功能菜单===========')
    print('\t\t\t\t\t\t1.录入学生信息')
    print('\t\t\t\t\t\t2.查找学生信息')
    print('\t\t\t\t\t\t3.删除学生信息')
    print('\t\t\t\t\t\t4.修改学生信息')
    print('\t\t\t\t\t\t5.排序')
    print('\t\t\t\t\t\t6.统计学生总人数')
    print('\t\t\t\t\t\t7.显示所有学生信息')
    print('\t\t\t\t\t\t0.退出系统')
    print('------------------------------')

def insert():
    student_list = []
    while True:
        id = input("请输入ID(如1001):")
        if not id:
            break
        name = input("侵输入姓名:")
        if not name:
            break
        try:
            englist = int(input('请输入英语成绩'))
            python = int(input('请输入python成绩'))
            java = int(input('请输入java成绩'))
        except:
            print('输入无效，不是整数类型，请重新输入')
            continue
        #将录入的学生信息保存到字典当中
        student = {'id':id,'name':name,'englist':englist,'python':python,'java':java}
        student_list.append(student)
        answer = input('你是否继续添加？y/n\n')
        if answer == 'y' or answer == 'Y':
            continue
        else:
            break
            #调用save函数
    save(student_list)
    print('学生信息录入完毕')
def save(lst):
    try:
        stu_txt = open(filename,'a',encoding='utf-8')
    except:
        stu_txt = open(filename,'w',encoding='utf-8')
    for item in lst:
        stu_txt.write(str(item)+'\n')
    stu_txt.close()

def search():
    pass

def delete():
    while True:
        sthdent_id = input("请输入要删除学生的id")
        if sthdent_id !=' ':
            if os.path.exists(filename):
                with open(filename,'r',encoding='utf-8') as file:
                    sthdent_old  = file.readlines()
            else:
                sthdent_old=[]
            flag = True #标记是否删除
            if sthdent_old:
                with open(filename,'w',encoding='utf-8') as wfile:
                    d={}
                    for item in sthdent_old:
                        dict(eval(item)) #将字符串转换成字典
                        if d['id'] != sthdent_old:
                            wfile.write(str(d)+'\n')
                        else:
                            flag = True
                    if flag:
                        print(f'id为{strudent_id}的学生信息已被删除')
                    else:
                        print(f'没有找到ID为{student_id}的学生信息')
            else:
                print('无学生信息')
            show()  #删除之后要重新显示学生信息
            answer=input('是否继续删除？y/n\n')
            if answer == 'Y' or answer == 'y':
                continue
            else:
                break

def modify():
    pass

def sort():
    pass

def total():
    pass
def show():
    pass

if __name__=='__main__':
    main()