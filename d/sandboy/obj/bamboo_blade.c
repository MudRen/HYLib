#include <weapon.h>

inherit BLADE;

void create()
{
   set_name("����", ({"bamboo blade","dao","blade"}) );
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 100);
     set("material", "iron");
     set("long", "һ�ѳ������񵶡�\n");
     set("wield_msg", "$N�Ӻ��������һ��$n�������С�\n");
     set("unequip_msg", "$N�����е�$n�������䡣\n");
   }
   init_blade(35);
   setup();
}
