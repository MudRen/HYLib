
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("���Ͼ�����", ({ "junfu","cloth"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "��");
     set("value", 600);
     set("armor_prop/armor", 80);
   }
   setup();
}
