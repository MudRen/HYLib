#pragma save_binary
 
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{  
        set_name( CYN"����" NOR,({ "yu_xiao" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "ֻ");
        set("long","һֻ��Ө͸��������������������ġ�������ż�����\n"
					HIM"\t\tӯӯ��\n"NOR);
        set("value", 10000);
        set("material", "�������");
        set("wield_msg", "$N�ӻ�������һֻ$n��Ϊ������\n");
        set("unwield_msg", "$N�����е�$n���뻳�\n");
        set("owner","�����");
		set("task",1);	
        set("no_put_in",1);
            }
                init_sword(250);
        setup();
}

