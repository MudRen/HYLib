#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("�㳦��", ({ "yuchang-sword","sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��С�Ľ���ã����,���ֺ�����һ������.\n");
		set("value", 100000);
		set("material", "steel");
	}
	init_sword(860);


      set("wield_msg",
"��---��----��----------$N���쳤Х,һ�Ѷ�С�Ľ�����������!\n");
	set("unwield_msg","$N�Ѷ̽�С�ĵ��պ�.\n");
       setup();
}
