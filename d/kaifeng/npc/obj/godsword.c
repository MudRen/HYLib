// godsword.c LOTS 1998.10.16

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�з�����", ({ "godsword", "jian", "sword" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���з�����,��������ն����.\n");
		set("value", 50000);
		set("material", "gold");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(400);
	set("no_drop",1);
	set("no_get",1);
        set("no_steal",1);
        setup();

}
void owner_is_killed() { destruct(this_object()); }
