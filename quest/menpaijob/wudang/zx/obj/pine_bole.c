//Cracked by Kafei
// pine_bole.c �������� 
// By Marz@XKX 11/11/96

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"��������"NOR,({ "bole", "pine bole" }));
	set_weight(70000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������ɣ����������ĺò��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("self_destruct", 1);
    	}
	
	setup();
}


int value()
{
	return 1;
}

// End of File
