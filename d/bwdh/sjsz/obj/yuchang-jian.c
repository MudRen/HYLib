//Cracked by Kafei

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
//#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIW"�㳦��"NOR,({ "yuchang jian", "yuchang", "sword", "jian" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000);
                set("material", "steel");
		set("rigidity", 50);
                set("long", 
		"һ���߰볤�̽��������������ϱ�����������ò�����\n");
                set("wield_msg", 
		HIW"$N��ס�㳦��������������ֻ�����в�ס�������ƺ�ֻ������һ���������۶ϡ�\n"NOR);
        }
	init_sword(280);
        setup();
//	::create();
}

