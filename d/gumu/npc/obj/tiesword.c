#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( CYN "������" NOR, ({ "xuantiesword" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ��ʮ�ֳ��ص��������˽������������������֮һ�������������\n"
);
               set("weapon_prop/intelligence",2);
 		 set("value", 38000);
	       
                set("material", "steel");
                set("wield_msg", "ֻ������һ����$N�Ѱ�$nװ�������С�\n");
                set("unequip_msg", "$N�����е�$n�Ѿ����ʡ�\n");
        }

        init_sword(500);
        setup();}
