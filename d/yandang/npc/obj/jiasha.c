#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIC "��������" NOR, ({ "tianluo-jiasha", "cloth" }) );
      set("long","�����ô�ѩɽ�б��ϵ�˿��֯�ɵ�,��������,ˮ����.\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 40000);
		set("material", "cloth");
		set("armor_prop/armor", 510);
		set("armor_prop/dodge", 35);
	}
	setup();
}
