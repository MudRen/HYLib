//inherit <ansi.h>
inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
        int i, j, num;
        string *dir, *ppls, name,str,str2="\n";
        object ob,obj;

        seteuid(getuid());
//        message("system", "\n ������Ҵ��浵�У����Ժ�....\n" NOR, users());
//        write("�����У�\n");
        dir = get_dir(DATA_DIR + "login/");
        str="\n";
        ob=new("/clone/misc/player");
        num = 0;
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                                if( (string)SECURITY_D->get_status(name)!="(player)" ){
                                    write("�ų���ʦ"+name+"\n");
                                        continue;
                                }
                                if (!ob->new_object(name))  continue;
                                  obj=present("thousand-gold",ob);
        str+=sprintf("%-8s(%-8s),����%-4d��\n",ob->name(),name,ob->query("mud_age")/86400);                                
                        num++;
        str2 = sprintf("\nĿǰ����Ϸ����%d�����\n",num);
                        }
                }
        }
        destruct(ob);
        message("system", "\n �������!\n", users());
        me->start_more(str+str2);
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��listusers

HELP
        );
    return 1;
}

