#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit HANDS; 

void create()
{
        set_name(HIM "��ң���ɻ�" NOR, ({ "shenxian huan" , "xiaoyao" , "shenxian", "huan" }) );
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", HIM "ɢ���Ź��ӹ�������ָ���������ң������������ң���ɻ���\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("armor_prop/armor", 130);
        	set("armor_prop/hand", 50);
        	set("armor_prop/strike", 50);
        	set("armor_prop/unarmed_damage", 100);
	        set("wear_msg", HIM "$N" HIM "΢΢һЦ���������һö���ָ����ʱָ��⻪���䡣\n" NOR);
        	set("remove_msg", HIM "$N" HIM "����ң���ɻ���ָ��ȡ��������\n" NOR);
                set("stable", 100);
        }
        setup();
}
