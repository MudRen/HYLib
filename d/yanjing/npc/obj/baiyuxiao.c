#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("������",({"baiyu xiao","xiao"}));
        set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "ͨ����,ֻ�ڴ��ڴ��м�����죮\n");
                set("value", 5000);
                set("material", "stone");
set("wield_msg","$Nȡ��$n,����ߴ�������!\n");;
                set("unwield_msg", "$N����һ��,���÷������е�$n��\n");
        }

init_sword(20);
        setup();
}

