#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "changdao" ,"dao","blade"}) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "iron");
                set("long", "����һ�ѱȽ������ĵ���\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(35);
        setup();
}
