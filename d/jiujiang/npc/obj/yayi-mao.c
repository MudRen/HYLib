
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name("����ñ", ({ "mao"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","������������������ñ�ӡ�\n");
     set("material", "�ֲ�");
     set("unit", "��");
     set("value",10);
     set("armor_prop/armor",1);
     
   }
   setup();
}
