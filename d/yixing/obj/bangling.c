// /d/yixing/obj/bangling.c
// Last Modified by winder on Jul. 12 2002


#include <ansi.h>

inherit ITEM;



void create()
{
	set_name("����", ({ "bang ling", "ling" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����г��õİ��\n");
		set("value", 0);
		set("material", "wood");
		set("partyname", HIC"���ְ�"NOR);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
	}
	setup();
}

