#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��ʯ", ({ "stone" , "��ʯ"}) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ɫ�ľ�ʯ��������������˵�ɫ��.\n");
		set("value", 1);
set("no_steal",1);
             set("no_drop",1);
             set("no_sell",1);
		set("material", "stone");

	}
setup();
}
void init()
{
	add_action("do_eat", "eat");
}
do_eat(string arg)
{
	object me;
	int max_gin, max_kee, max_sen;
	me = this_player();
	if( !living(me))	return 0;
      if (!arg) return notify_fail("��Ҫ��ʲô?\n");
	max_gin = (int) me->query("max_qi");
        max_kee = (int) me->query("max_jing");
        max_sen = (int) me->query("max_neili");
	message_vision( HIR "$N��ȫ��ӳ��һ���⣡��\n" NOR, me);
	max_gin = max_gin * 11/10;
	max_kee = max_kee * 11/10;
	max_sen = max_sen * 11/10;
	switch(random(3)){
		case 0:
			me->set("max_qi", max_gin);
			break;
		case 1:
			me->set("max_jing", max_kee);
			break;
		case 2:
			me->set("max_neili", max_sen);
			break;
			}
	destruct(this_object());
        return 1;
}


