
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIR"�廨Ь"NOR, ({ "xiu hua xie","xie","shoe"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","����һ˫Ůʽ���廨Ь��\n");
     set("material", "cloth");
     set("unit", "˫");
     set("value", 200);
     set("armor_prop/armor", 8);
	 set("armor_prop/dodge", 10);
   }
   setup();
}
