// demon_staff.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
	set_name( RED "* �� Ѫ �� ħ �� *" NOR, ({ "demon staff", "staff" }) );
	set_weight(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("no_get", 1);
                set("no_drop", 1);
		set("unit", "��");
		set("long", "һ�Ѱ���ɫ�����ɶ೤�ľ��ơ�\n");
		set("material", "crimson gold");
	}
    init_staff(200+random(2000),1);
	setup();
}
