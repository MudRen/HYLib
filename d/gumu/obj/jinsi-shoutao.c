//jinsi-shoutao.c ��˿����
//By Kayin @ CuteRabbit Studio 1999/3/21 new

#include <armor.h>
#include <ansi.h> 
inherit HANDS;

void create()
{
	set_name( HIC"��˿����"NOR, ({ "jinsi shoutao", "shoutao" ,"gloves"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
                set("treasure",1);
		set("long", "����һ˫�н�˿�Ƴɵ����ף������ޱȣ����������ˡ�\n");
		set("value", 1000000);
		set("material", "gold");
                 set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�����������ܸ��ˡ�\n");
             set("nopawn",1);
             set("no_get",1);
                set("wield_msg", HIY"$N�ӻ����ͳ�һ˫$n�������ϡ�\n"NOR);
                set("unwield_msg", HIY"$Nȡ��$n���뻳�С�\n"NOR);
		set("armor_prop/armor", 300);
		set("armor_prop/damage",200);
	}
	setup();
}
