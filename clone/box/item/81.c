// xuantie jian �����ؽ�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"�����ؽ�"NOR,({ "jinggang jian", "jinggang", "jian", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("unique", 1);
                set("rigidity", 10);
                set("sharpness", 1);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("wield_neili", 1500);
                set("wield_maxneili", 2100);
                set("wield_str", 32);
                set("long", "����һ�����λεľ����ؽ���\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");       
        }
        init_sword(600);
        setup();
}
