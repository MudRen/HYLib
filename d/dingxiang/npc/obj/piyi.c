
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"Ƥ��"NOR, ({ "pi yi","yi","cloth"}) );
   set_weight(400);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("unit", "��");
     set("value",200);
     set("armor_prop/armor",5);
   }
   setup();
}
