
#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
   set_name(HIY"�ƽ�����"NOR, ({ "necklace"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ������Ļƽ�������\n");
     set("material", "�ƽ�");
     set("unit", "��");
     set("value", 1000);
     set("armor_prop/armor",10);
     set("armor_prop/dodge",2);
     set("armor_prop/personality",5);
   }
   setup();
}
