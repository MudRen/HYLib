// �з����� unix 1998.10

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("�з�����", ({"shan jian", "jian", "sword"}));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	set("long", HIW"���ǵ�������͸������ǰ����˵�"NOR+HIY"�з�����"NOR+HIB"����ն����, ��ն�ҳ���\n"NOR);
		set("value", 80000);
		set("material", "gold");
	set("wield_msg", HIY"һ��������, $N�ӻ��аγ�һ����������\n"NOR+
HIB"		*�з�����*\n"NOR);
	set("unwield_msg", HIY"$NС�Ľ��з�������ؽ���֮��\n"NOR);
}
	init_sword(1100);
	setup();
}
