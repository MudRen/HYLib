// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "dart" ,"biao","fei biao"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"������һ��ʮ�ֳ����İ�����\n");
		set("unit", "Щ");
		set("base_unit", "֦");
		set("base_weight", 200);
		set("base_value", 1200);
		set("value", 1200);
	}
	set_amount(40);
	init_throwing(20);
	setup();
}
