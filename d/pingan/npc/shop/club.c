// shutonggun.c

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("ľ��",({"mu gun","club"}));
	set_weight(1500);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʮ������ľ����\n");
		set("value",800);
		set("material", "bamboo");
		set("wield_msg", "$N���ִ������һ��ľ����\n");
		set("unwield_msg", "$N������һ�ۣ���ľ���������\n");
	}
	init_club(20);
	setup();
}
