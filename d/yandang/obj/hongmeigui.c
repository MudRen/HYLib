#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIR"��õ��"NOR, ({ "meigui","flower"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֦");
		set("long", "һ֦"+HIR"��õ��"+NOR+",�͸����˵�������\n");
		set("value", 1000);
		set("material", "wood");
	}
	init_sword(30);


      set("wield_msg",
"$N��Цһ��,����ת�˼���,���г���һ����õ�"+HIR+"��õ��.\n"NOR);
	set("unwield_msg","$N����һ��,���е�"+HIR+"��õ��"+NOR+"��Ϊһ���������.\n");
       setup();
}
