

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
   set_name(MAG"��ç��"NOR, ({ "zimang bian","bian","whip" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 1500);
     set("material", "iron");
     set("long", "����һ���ֱޣ���Ϊ��ç��\n");
     set("wield_msg", "$Nһ��$n��ֻ����ž����һ������$n�������С�\n");
     set("unequip_msg", "$N�����е�$n���������ϡ�\n");
   }
   init_whip(380);
   setup();
}
