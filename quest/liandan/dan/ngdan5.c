//Cracked by Kafei
// shouwu.c ������
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("������", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó������εĺ����ڡ�\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                me->add("max_neili", -1);
		me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N����һ֧�����ڣ�ֻ����ͷ�ؽ��ᣬ�������ڣ�ԭ����ʳ̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
		destruct(this_object());
        }
	if( random(2) == 1)
	{
        message_vision("$N����һ�ú����ڣ������������ġ�\n", me);
        destruct(this_object());
        return 1;
        }
	else
	{
	me->add("max_neili", 1);
	message_vision(HIG"$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n"NOR, me);
	}
	me->apply_condition("bonze_drug", 
	this_player()->query_condition("bonze_drug")+30);
	destruct(this_object());
	return 1;
}

