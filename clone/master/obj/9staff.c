
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("�Ż�����" , ({ "9-ring staff", "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ִ��ֳ��ĺ������ȣ����������Ÿ��𻷡�\n");
		set("value", 6200);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ���ںڵ�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(163);
	setup();
}
