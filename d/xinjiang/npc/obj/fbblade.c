#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("��ڵ�С��", ({ "black blade", "blade" }) );
        set_weight(15000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("value", 2000);
            set("material", "steel");
            set("for_create_weapon",1);
            set("long", 
        "һ����״�����صĵ���������ڣ�������ڡ�\n");
            set("wield_msg", "$N����ڵĵ����г��һ��$n\n");
            set("unequip_msg", "$N�������е�$n��\n");
        }
        ::init_blade(180);
}     
