// ��
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name(HIW "��������" NOR, ({ "bingbo shenzhen", "zhen", "needle", "shenzhen" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö͸����ϸ�룬��ɢ������������һ����֪������ι�о綾��\n");
		set("value", 200000);
		set("material", "steel");
                set("needle", 1);
                set("weapon_prop/dodge", 2);
                set("wield_msg", "$N��ɳֽ����������һö$n��\n");
		set("unwield_msg", "$N��$n��ɰֽ���������ػػ��С�\n");                
                set("treasure", 1);
                set("poisoned", "bing_poison");
                set("poison_number", 300);
	}
	init_sword(35);
	setup();
}
