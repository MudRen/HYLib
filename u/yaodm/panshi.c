// daodan.hehe
 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "send");
       add_action("do_send", "zhao");
       add_action("do_send", "fire");
}


void create()
{
        set_name(HIW"��ʦ��"NOR, ({"panshi jing"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
                         "����һ�溣�������ɵı�����԰�������ʦ��\n");
               set("value", 0);
             set("unit", "��");
               set("no_get", 1);
               set("no_drop", 0);
               set("treasure", 1);
       }
}

int do_send(string target)
{
       object me, dest;

       me = this_object();


       if(!(dest = find_player(target)))
             if(!(dest = find_living(target)))
             {
                   write("û������˻����\n");
                   return 1;
             }
    if (!environment(dest)) return notify_fail("����˲�֪�������\n");
       message_vision(HIR "��ʦ�����һ����â������$n����$n��������ȫ����ϴ�ɾ�\n" NOR, me, dest);


dest->set("title","��ͨ����");
dest->set("class","0");
dest->delete("family");
dest->delete("party");


       dest->delete("env/invisibility");

       dest->delete("env/immortal");
       return 1;
}


