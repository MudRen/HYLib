// /d/yixing/obj/caili.c  ����
// Last Modified by winder on Jul. 12 2002


#include  <ansi.h>

inherit ITEM;


void create()
{
	set_name(RED"����"NOR, ({ "caili" }));
	set("weight", 20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"����һ�ݰ�װ���ƵĲ�������һ��װ�Ź��صĶ�����\n");
		set("unit", "��");
		set("value", 30);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");	    
	}

	setup();

	
}


// to avoid players from cheating
// like go by da che or let other players carry them
// like go by following another player or driven by another player

// i still think, it is better to change follow.c and sing.c files
// then will save source

