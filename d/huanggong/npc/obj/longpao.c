// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(HIY"��צ����"NOR, ({ "longpao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
set("armor_prop/armor", 50);
set("long","���Ǽ���ɫ���ۣ��ý�˿���Ͼ��������������ޱȡ�\n");
	}
	setup();
}
