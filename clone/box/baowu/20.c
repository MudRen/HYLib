#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit HANDS; 

void create()
{
        set_name(HIY "������" NOR, ({ "hupo shenhuan" , "hupo" , "shenhuan", "huan" }) );
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", HIY "ɢ���Ź��ӹ����ָ�������������������Ľ��"
                            "�������������񻷡�\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("armor_prop/armor", 150);
        	set("armor_prop/finger", 50);
        	set("armor_prop/strike", 50);
        	set("armor_prop/unarmed_damage", 100);
	        set("wear_msg", HIY "$N" HIY "΢΢һЦ���������һö�����񻷣���"
                                "ʱָ��⻪���䡣\n" NOR);
        	set("remove_msg", HIY "$N" HIY "�������񻷴�ָ��ȡ��������\n" NOR);
                set("stable", 100);
        }
        setup();
}
