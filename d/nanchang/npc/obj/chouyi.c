
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("����", ({ "cloth","yi","chou"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","����һ������ĳ���\n");
     set("unit", "��");
     set("value", 60);
     set("armor_prop/armor", 18);
   }
   setup();
}
