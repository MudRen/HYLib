
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(MAG"����"NOR, ({ "pi jin","jin"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ��Ů�˴�������\n");
     set("material", "ϸɴ��");
     set("unit", "��");
     set("value",10);
     set("armor_prop/armor",3);
     set("female_only",1);
     
   }
   setup();
}
