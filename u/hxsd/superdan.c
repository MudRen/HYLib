// dahuan-dan.c ������

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
	set_name(MAG"������"NOR, ({"super dan", "super", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ϻ쾧���Ľ��������˵��˸����ִ�bug������õģ���߹�������Ч�ޱȡ�\n");
		set("value", 10000);
	}

	set("shaolin",1);
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

		me->add("per", 1);
		me->add("kar", 1);
		me->add("dex", 1);
		me->add("con", 1);
		me->add("str", 1);
		me->add("int", 1);
		message_vision(HIG "$N����һ�Ž�������ֻ������������ԴԴ���������Ϲ���������
͸ʮ����¥���鲼��������ȫ������Ȼ��� !\n" NOR, me);
		message_vision(HIY "$N����ò���� !\n" NOR, me);
		message_vision(HIW "$N�������� !\n" NOR, me);
		message_vision(HIR "$N�ı������� !\n" NOR, me);
		message_vision(HIG "$N�����Լ��� !\n" NOR, me);	
		message_vision(HIB "$N�ĸ��Ǽ��� !\n" NOR, me);
		message_vision(HIM "$N�ĸ�Ե���� !\n" NOR, me);
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}