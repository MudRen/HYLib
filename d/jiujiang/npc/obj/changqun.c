
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"��ȹ"NOR, ({ "chang qun","qun"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ��Ů�˴���խ��ȹ��\n");
     set("material", "ϸɴ��");
     set("unit", "��");
     set("value",10);
     set("armor_prop/armor",3);
     set("female_only",1);
     
   }
   setup();
}
