
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIC"������ָ��"NOR, ({ "zhihuan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "ö");
     set("value",6000);
     set("armor_prop/armor",16);
     set("armor_prop/dodge",12);
   }
   setup();
}
