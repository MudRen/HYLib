
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name("���۷�", ({ "cloth"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","�������������������·���\n");
     set("material", "�ֲ�");
     set("unit", "��");
     set("value",90);
     set("armor_prop/armor",2);
     
   }
   setup();
}
