 // cloth.c
//
// This is the basic equip for players just login. 
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name("���ް�", ({ "ao" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("bigcloth",1);
                set("armor_prop/armor", 10);
        }

} 
