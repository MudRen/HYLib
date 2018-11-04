// color_head.c

#include <armor.h>
#include <ansi.h>

inherit SHIELD;

string* titles = ({
	HIY "�껨ʯ" NOR,
	HIR "�껨ʯ" NOR,
	HIG "�껨ʯ" NOR,
	HIB "�껨ʯ" NOR,
	HIM "�껨ʯ" NOR,
	HIC "�껨ʯ" NOR,
	HIW "�껨ʯ" NOR,
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "stone", "yuhuashi" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������껨ʯ��\n");
		set("unit", "��");
		set("value", 1000);
		set("material", "stone");
		set("armor_prop/armor", 1);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

