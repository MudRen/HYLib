//Cracked by Kafei
// hammer.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
static int amount;

void create()
{
        set_name(HIY"����"NOR, ({ "jin lun", "falun", "lun" }) );
//	set_color("$HIY$");
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit", "ֻ");
                set("base_weight", 10000);
		set("long", "����һֻ��������ֱ���߰��һ��Բ����������������ڷ�ħ���ԣ������пգ����оŸ�����\n");
		set("value", 7000);
		set("material", "iron");
		set("base_weapon", 50);
		set("rigidity", 100000);
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

        init_hammer(380);
//	set_amount(5);
	setup();
}


