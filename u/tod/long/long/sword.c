// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���콣", ({ "yitian sword" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "�������µ�һ�������С����첻����˭�����桱֮˵��\n");
		set("value", 400);
		set("material", "steel");
	}
        init_sword(99);

// These properties are optional, if you don't set them, it will use the
// default values.

        	set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
        	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");

// The setup() is required.

	setup();
}
