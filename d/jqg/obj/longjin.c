// longjin.c

#include <ansi.h>

inherit ITEM;

void init()
{
     add_action("do_drink", "drink");
}

void create()
{
       set_name(HIY "������" NOR, ({"longjin cha", "lingjin", "cha", "tea"}));
       set_weight(700);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long", "�������ɼ�������������Ʒ�衣\n");
               set("unit", "��");
               set("value", 1000);
               }
}

int do_drink(string arg)
{
       object me = this_player();
       if (!id(arg)) return 0;
       if ( me->query("water") >= me->max_water_capacity())
         return notify_fail("�㶼�ȱ��ˣ���ô��Ҫ�ȣ�\n");       
       message_vision(HIG "$NƷ��һ��"
       +this_object()->query("name")+
       HIG "����ʱ���þ���Ϊ֮һ��\n"
       NOR,me);
       me->set("water", me->max_water_capacity());
       destruct(this_object());
       return 1;
}
