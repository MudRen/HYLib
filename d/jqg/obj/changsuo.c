// changsuo.c ��Ƥ��
// By River 99.5.25
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(GRN"��Ƥ��"NOR, ({ "shupi suo", "suo" }));
        set_weight(1000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������Ƥ���һ����������Ƥ���ӡ�\n");
                set("material", "wood");
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_fu","fu");
}
 
int do_fu(string arg,object obj)
{
       object me = this_player();
       object ob = this_object();
       if(me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");
       if(!arg || arg != "shugan" || ! obj=(present("zao shugan", me)))
               return notify_fail("��׼������Ƥ���������\n");
       tell_object(me,"�㽫����һ�˸��������м䡣\n");       
       me->set_temp("jqg/fu", 1);
       obj->set("long","����һ��������֦�ɣ���Լһ����ߣ����Ѿ�������һ�˸��������м��ˡ�\n");
       obj->set("jqg/fu", 1);
       destruct(ob);
       return 1;
}
