inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��������¶" , ({ "potion", "magic potion" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  set("long", WHT
      "����һ�������湦Ч��¶ˮ��\n"
      "���������������ļ��ޣ�\n" NOR);

		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
	object me;
	int max_gin, max_kee, max_sen;
	me = this_player();
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
