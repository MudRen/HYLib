#include <ansi.h>
#include <armor.h>
inherit ARMOR; 
void create() {
        set_name("����", ({ "furcoat", "coat" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value", 8000);
                set("armor_prop/armor", 55);
                set("long","һϮ��ֵǧ������á�\n");
        }
        
}      
