

#include <weapon.h>

inherit DAGGER;

void create()
{
   set_name("ذ��", ({ "dagger" }) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һѰ����ذ�ס�\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n������䡣\n");
   }
   init_dagger(120);
   setup();
}
