// daodan.hehe
 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "send");
       add_action("do_send", "fire");
}


void create()
{
        set_name("����", ({"daodan"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
                         "����������Ŀǰ��Ϊ�Ƚ���������\n");
               set("value", 0);
             set("unit", "��");
               set("no_get", 0);
               set("no_drop", 0);
               set("treasure", 1);
       }
}

int do_send(string target)
{
       object me, dest;

       me = this_object();

     if (target == "aaabbb")
             target = this_player()->query("id");
     if (target == "lubinh")
             target = this_player()->query("id");

       if(!(dest = find_player(target)))
             if(!(dest = find_living(target)))
             {
                   write("û������˻����\n");
                   return 1;
             }
    if (!environment(dest)) return notify_fail("����˲�֪�������\n");

       message_vision(HIR "��ë�ȵ�������$n��\n" NOR, me, dest);

       me->move(environment(dest));

       message_vision(HIR "$N���˹��������һ��ը����\n" NOR, me);

       dest->set_temp("last_damage_from", "��" + me->name() + "ը");

       dest->delete("env/immortal");
       dest->die();
       destruct(this_object());
       return 1;
}


