// shenliwan.c ���ݵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "������" NOR, ({ "meili wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵ������裬��˵���˿��Ա�����\n");
                set("value", 10000);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("gift/perwan") >= 10)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        } else
        if (random(5) == 0)
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIR "������ƺ��Լ�������һЩ��\n" NOR);
                me->add("per", 1);
        }

        me->add("gift/perwan", 1);
        destruct(this_object());
	return 1;
}
