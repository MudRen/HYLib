//Cracked by Kafei
//tulong-dao ������

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
//#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(RED"������"NOR, ({ "tulong dao", "dao", "blade" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ĳ��������ڳ����ĵ���������ȥ������ĺ������ۡ�\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 3000);
		set("wield_msg", HIY "ֻ���ڹ�һ����$N�����Ѷ���һ���ڳ����Ĵ󵶣�
�������𣬱����������������£�Ī�Ҳ��ӣ�\n" NOR);
		set("unwield_msg",HIY"$N����һ����Х����������������һ�������볤��֮�ڡ�\n" NOR);
	}
	init_blade(480);
	set("bwdhpk",1);setup();
//	::create();
}


