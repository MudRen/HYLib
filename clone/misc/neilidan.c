// z-dan.c
// ����(lywin)��������������
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "chi");
}

void create()
{
	set_name("������", ({"neilidan", "neilidan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ż����ࡣ�������chi��������\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        if(me->is_busy())
        return notify_fail("��������æ��û���Զ�����\n");

        if(!me->is_fighting())
        return notify_fail("����������վ���м��õģ�\n");

        if( (int)me->query("neili") * 100 / (int)me->query("max_neili") >= 40)
        return notify_fail("�����������������أ�\n");

	if ( me->query("max_neili") < 600 )
	{
        me->add("neili", 1);
		message_vision(HIR "$N����һ�Ż����ֻ࣬����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("neilidan") > 0 )
	{
        me->add("neili", 1);
		message_vision(HIR "$N����һ�Ż����ֻ࣬����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
        me->add("neili", me->query("max_neili")/2);
        message_vision(HIG "$N����һ�Ż����ֻ࣬������������ԴԴ������������������!\n" NOR, me);
	}

        me->apply_condition("neilidan", 2);
	
	destruct(this_object());
	return 1;
}