///u/jpei/thd/obj/biyuxiao.c ������
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG"������"NOR,({"biyu xiao","xiao"}));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","֧");
		set("value",20000);
                set("treasure",1);
		set("material","steel");
		set("long","����һ֧ͨ�徧Ө���ñ�����������������ʮ�־�Զ��\n");
		set("wield_msg",HIM"$N��������һ�У�һ֧$n�ѳ�����$N���С�\n"NOR);
		set("unwield_msg",HIM"$Nһ����Х����$n������䡣\n"NOR);
	}
	init_sword(100);
	setup();
}
