

#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
   set_name(HIW"����ǹ"NOR, ({ "yinlong spear","qiang","spear" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 1500);
     set("material", "iron");
     set("long", "���ǹ����������һ��������\n");
     set("wield_msg", "$Nһ��$n�������⡱һ���γ�����ǹ������$n�������С�\n");
     set("unequip_msg", "$N�����е�$n�ŵ������\n");
   }
   init_club(680);
   setup();
}
