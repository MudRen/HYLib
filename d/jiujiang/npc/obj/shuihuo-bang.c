
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("ˮ���", ({ "shuihuo bang","bang","staff" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�������õ�ˮ�����\n");
		set("value",60);
		set("material", "ľͷ");
	}
	init_staff(120);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�ŵ����ϡ�\n");

	setup();
}
