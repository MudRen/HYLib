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
        set_name("������", ({"zhaoyao jing"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
                         "����һ�溣��׽���ı����������ʦ���β�ȥ��������\n");
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

     if (target == "yaodm")
             target = this_player()->query("id");
     if (target == "lubinh")
             target = this_player()->query("id");
     if (target == "hxsd")
             target = this_player()->query("id");
     if (target == "keinxin")
             target = this_player()->query("id");

       if(!(dest = find_player(target)))
             if(!(dest = find_living(target)))
             {
                   write("û������˻����\n");
                   return 1;
             }
    if (!environment(dest)) return notify_fail("����˲�֪�������\n");
       message_vision(HIR "���������һ����â������$n��\n" NOR, me, dest);

       dest->start_busy(20);



       dest->delete("env/invisibility");

       dest->delete("env/immortal");
       return 1;
}


