
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIG"����Ŵ��"NOR, ({ "ru shan","shan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ˫Ů�˴��Ľ���Ŵ����\n");
     set("material", "��");
     set("unit", "��");
     set("value",10);
     set("armor_prop/armor",3);
     set("female_only",1);
     
   }
   setup();
}
