
#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
   set_name(HIW"�����ָ"NOR, ({ "finger"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һö����İ����ָ��\n");
     set("material", "����");
     set("unit", "ö");
     set("value", 800);
     set("armor_prop/armor",3);
     set("armor_prop/dodge",2);
     set("armor_prop/personality",1);
   }
   setup();
}
