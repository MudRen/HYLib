// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
      set_name("��ɣ��", ({ "fusang dao", "blade", "dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
              set("value", 8500);
		set("material", "iron");
            set("long", "����һ�ѷ����ĵ���������һ�����⡣\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
        init_blade(130);
	setup();
}
