// longsword.c ����
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
set_name(BLU"����"NOR,({ "hei suo", "whip","bian","suo" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
                set("weapon_prop/dodge", 3);
                set("weapon_prop/parry", 1);
                set("treasure",1);
                set("wield_neili", 200);
                set("wield_maxneili", 800);
                set("wield_str", 20);
		set("material", "leather");
                set("long", BLU"������ͨ������޹�ĳ���������һ��������צ��ī����ҹ���趯֮ʱ�Ʋ������Ӱ�ӡ�\n"NOR);                
                set("unwield_msg", "$N����һ������$n�̻����䡣\n");
                set("wield_msg", "$N����һ�������һ��$n�������С�\n");
	}
	init_whip(280);
	setup();
}
