// guanfu.c 

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name( HIC "�ٷ�" NOR, ({ "guan fu", "fu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "˿");
		set("value", 5000);
                set("armor_prop/armor", 3);
        }
        setup();
}

