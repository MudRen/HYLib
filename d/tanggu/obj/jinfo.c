
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"���"NOR, ({ "jin fo", "fo" }));
        set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ�������ֿ������Ц��\n");
                set("value", 10000);
		set("material", "gold");
	}
	setup();
}
