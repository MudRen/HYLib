#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( "������", ({ "green ruyi", "ruyi", "sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ī��ɫ�����⣬˳�������ɲ�����״��\n");
                set("value", 3000);
                set("no_sell",1);
                set("wield_msg", "$N�ó�$n�������ϡ�\n");
        	set("weapon_prop/karma", 15);
                set("material", "stone");
        }
        init_sword(115);
        setup();
}
