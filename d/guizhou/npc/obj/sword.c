
#include <weapon.h>

inherit SWORD;

void create()
{
   set_name("�ֽ�", ({ "sword" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 1500);
     set("material", "iron");
     set("long", "����һѰ���ĸֽ���������Լ�����߽��ء�\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
   }
   init_sword(35);
   setup();
}
