// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"��ʹ����"NOR, ({ "angel cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 390);
        }
        setup();
}

