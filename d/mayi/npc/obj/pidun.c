
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIB"Ƥ��"NOR, ({ "pi dun","dun","shield"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("unit", "��");
     set("value",500);
     set("armor_prop/armor",16);
   }
   setup();
}
