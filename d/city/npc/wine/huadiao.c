//Cracked by Roath
// huaduai.c �����

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"��ƿ"NOR, ({"huadiao", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
һ������װ����Ƶľ�ƿ���ƾ��е���Ʒ����࣬���ʺ�Ũ����ζ�������ɳ���
���ء�
LONG
        );
		set("unit", "��");
		set("value", 130);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�����",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}
