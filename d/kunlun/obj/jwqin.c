//jiaowei qin ��β��

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
set_name(HIM"��β��"NOR,({"jiaowei qin","qin"}));
  set_weight(500);
	if(clonep())
		 set_default_object(__FILE__);
	else{
			set("unit","��");
			set("value",40000);
			set("material","steel");
set("long","�ഫ����ǵ�����ļ��ӻ������ȳ��Ľ�ľ���ɵ����٣��ٵ�β���Կɼ�����ɫ��\n");
set("wield_msg",HIY"$N��������һ��,һ�Ž�β�ٱ��ѳ�����$N����.\n"NOR);
set("unwield_msg",HIY"$Nʮָһ��������ҷȻ��ֹ��$N����β�٣��Ž����ŵİ����\n"NOR);
set("unequip_msg",HIY"��ʮָһ��������ҷȻ��ֹ��������β�٣��Ž����ŵİ����.\n"NOR);
			}
    init_sword(500);
	setup();
}

void init()
{
		add_action("do_play", "play");
}
