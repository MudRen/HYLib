// longsword.c ����
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
set_name(HIM"��"HIY"��"HIG"��"HIW"��"HIR"��"NOR, ({"wudu shenbian", "bian", "wudushenbian"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"�����嶾�̵���������˵���������Ķ������ɵġ�\n"NOR);
		set("treasure",1);
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 3);
		set("value", 100);
		set("material", "leather");
		set("wield_msg", HIB"ֻ�ŵ�һ����,$N��ৡ���һ������һ���������ڵ�$n�������С�\n"NOR);
		set("unwield_msg", HIY"������ʧ��$N�����е�$n������䡣\n"NOR);
	}
	init_whip(500);
	setup();
}
int hit_ob(object me, object victim, int damage)
{
if (random(5) >3)
	       victim->apply_condition("snake_poison",
		        (int)victim->query_condition("snake_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("wugong_poison",
		        (int)victim->query_condition("wugong_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("zhizhu_poison",
		        (int)victim->query_condition("zhizhu_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("xiezi_poison",
		        (int)victim->query_condition("xiezi_poison") + 3 );
else 	       
	       victim->apply_condition("chanchu_poison",
		        (int)victim->query_condition("chanchu_poison") + 3 );
        return 0;
}
