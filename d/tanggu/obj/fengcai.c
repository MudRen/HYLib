#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY"����"NOR, ({ "fengcai", "cai" }));
        set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����Ӳӵ����ӣ������һֻ��˵����ӡ�\n");
                set("value", 5000);
		set("material", "gold");
		set("female_only", 1);
		set("armor_prop/armor", 1);
	}
	setup();
}
