//Cracked by Kafei
// qimeigun.c
#include "ansi.h"
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name(HIY "�ƽ��" NOR, ({ "huangjin gun", "gun" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ���ƽ������Ĵ���������߳ߣ�ʮ�ֳ��أ�ʹ��������֮��һ�Żƹ⣬��������֮����\n");
                set("value", 10500);
                set("material", "gold");
		set("wield_msg", "$N���һ��$n��������һ����\n");
		set("unequip_msg", "$N�����е�$n�������\n");
        }
        init_club(350);
        set("bwdhpk",1);setup();
}

