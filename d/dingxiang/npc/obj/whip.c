#include <weapon.h>

inherit WHIP;

void create()
{
   set_name("����", ({ "whip" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");   
     set("material", "��Ƥ");
     set("long", "����һ����Ƥ���ĳ��ޡ�\n");
     set("wield_msg","$N���$n�������ž�ش���졣\n");
     set("unequip_msg", "$N��$n�������䡣\n");
   }
   init_whip(25);
   setup();
}
