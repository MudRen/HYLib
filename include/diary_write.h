// #include <ansi.h>
string g_place(object ob);
string g_time()
{
return NATURE_D->game_time();
}

int diary_write(object ob,string sth)
{
   string dir,idu,tmp,time,place,path,nameu;
   int back;
    time=g_time();
     nameu=ob->query("name");
    idu=ob->query("id");
       place=g_place(ob);
    dir="/data/diary/"+sprintf("%-1.1s",idu);
     path="/data/diary/"+sprintf("%-1.1s",idu)+"/"+idu;
    if(file_size(path)<=0) back=mkdir(dir); 
    write(HIG"�������¼�,���õؼ����˻���¼.\n"NOR);

     back= write_file(path,HIY" "+ time+"   "HIR +nameu+"��"+place+sth+NOR"\n",0);
return back;
}



string g_place(object ob)
{
 object  where;

if(!where=environment(ob)) return "ĳ��";
 where=environment(ob);
return where->query("short");
}  
