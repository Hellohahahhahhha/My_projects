#include<string>
#include<iostream>
#include<fstream>
using namespace std;

struct student
{
    string name;
    float cj;
}st{"sss",0};
/*
void students_info(student* sl,float& avg,int& low,bool (* f)(int x),int length)
{
    int n=0;
    float sum=0;
    for(int i=0;i<length;i++)
    {
        if(f(sl[i].cj)){n++;}
        sum+=sl[i].cj;
    }
    avg=sum/length;
    low=n;
}

bool lower_than_140(int x)
{
    if(x<140)
    {
        return true;
    }
    return false;
}*/
                            //read binary files
int main()
{
    ofstream ofs;
    ofs.open("C:\\Users\\Administrator\\Desktop\\file_manage.txt",ios::out | ios::binary);
    if(!ofs.is_open()){return 0;}
    ofs.write((const char*)&st,sizeof(student));
    ofs.close();

    ifstream ifs;
    ifs.open("C:\\Users\\Administrator\\Desktop\\file_manage.txt",ios::in|ios::binary);
    if(!ifs.is_open()){return 0;}
    student stt;
    ifs.read((char*)&stt,sizeof(student));
    cout<<stt.name<<endl<<stt.cj<<endl;
    ifs.close();
    return 0;
}
/*
int main()
{
    ofstream ofs;
    ofs.open("C:\\Users\\Administrator\\Desktop\\file_manage.txt",ios::out);
    if(!ofs.is_open())
    {
        cout<<"Failed to open file"<<endl;
        return 0;
    }
    ofs<<"kd gf sf rt e dsfd";
    ofs.close();
    ifstream ifs;
    ifs.open("C:\\Users\\Administrator\\Desktop\\file_manage.txt",ios::in);
    string fs;
    if(!ifs.is_open())
    {
        return 0;
    }
    while(ifs>>fs)
    {
        cout<<fs<<endl;
    }
    return 0;
}
*/

/*
int main()
{



   FILE *fp = NULL;
   fp = fopen("C:\\Users\\Administrator\\Desktop\\test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
                            //C method is below
    FILE *f=NULL;
    f=fopen("C:\\Users\\Administrator\\Desktop\\file_manage.txt","r");
    if(f==NULL)
    {
        cout<<"failed to open\'C:\\Users\\Administrator\\Desktop\\file_manage.txt\'"<<endl;
        return 0;
    }
    string s="";
    char ch;
    while(!feof(f))
    {
        s+=fgetc(f);
    }
    cout<<s<<endl;
    fclose(f);
    return 0;
}
*/

/*
int main()
{
    int *p=NULL;
    p=(int*)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
    {
        p[i]=i;
    }
    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }

    string str="jklj";
    cout<<str.substr(0,0)<<endl;

    free(p);

    cout<<"Hello What the fuck!"<<endl;
    float avg;
    int low;
    student sl[5]={{"1",120},{"2",119},{"3",114},{"4",151},{"5",112}};
    students_info(sl,avg,low,lower_than_140,5);
    printf("avg: %0.2f\nlow: %d\n",avg,low);
    return 0;
}*/
