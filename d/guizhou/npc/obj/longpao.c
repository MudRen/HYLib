
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIY"����"NOR, ({ "long pao","pao","cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","����һ���ʵ۴������ۣ�������������������������\n");
     set("material", "cloth");
     set("unit", "��");
     set("value", 1000);
     set("armor_prop/armor", 60);
   }
   setup();
}
