
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIG"����"NOR, ({ "tengpai"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",1500);
     set("armor_prop/armor",35);
     set("armor_prop/dodge",11);
   }
   setup();
}
