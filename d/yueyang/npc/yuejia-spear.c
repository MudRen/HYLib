

#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
   set_name(HIR"-������-������ǹ"NOR, ({ "yuejia qiang","qiang","club" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 8500);
     set("material", "iron");
     set("long", "���ǹ������ȡ�ԡ������족֮�⡣\n");
     set("wield_msg", RED"$Nһ��$n�������⡱һ���γ�����ǹ������$n�������С�\n"NOR);
     set("unequip_msg", "$N�����е�$n�ŵ������\n");
   }
   init_club(880);
   setup();
}
