
#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
   set_name("Χ��", ({ "wei jin","jin"}) );
   set_weight(150);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("unit", "��");
     set("value",100);
     set("armor_prop/armor",3);
   }
   setup();
}
