//gangfu.c �ָ�
#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name("����",({ "tie fu", "fu", "axe"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N৵�һ�������г��һ��������\n");
                set("long", "����һ����ͨͨ��������\n");                
                set("unwield_msg", "$N���������������С�\n");                
        }
        init_axe(20);
        setup();
}
