//shezhang.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIR"������"NOR, ({ "sheng shezhang", "shengzhang" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������, ��ͷ����С��, ��������, ʮ�ֹ��졣\n");
set("no_give",1);
		set("treasure",1);
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 3);
		set("value", 100);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ջر���\n");
	}
	init_staff(500);
	setup();
}
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 3);
        return 0;
}
