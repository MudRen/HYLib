
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "�ƽ��", ({"goldarmor","jinarmor", "jinjia" }) );
        set_weight(35000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 20000);
                set("material", "leather");
                set("armor_prop/armor", 50);
        }
        setup();
}

