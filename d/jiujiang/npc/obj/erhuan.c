
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIG"������"NOR, ({ "feicui erhuan","erhuan"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "���");
     set("unit", "ö");
     set("value",200);
     set("armor_prop/armor",10);
     set("armor_prop/dodge",1);
     set("female_only",1);
   }
   setup();
}
