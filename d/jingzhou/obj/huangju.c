// huangju.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	string *surname=({"����ҩ","�ƺ���","����֪","ݺ���"});
	set_name(HIY+surname[random(sizeof(surname))]+NOR, ({"huang ju","flower"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�使�޵Ļƾա�\n");
		set("material", "����");
		set("unit", "��");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N����һ��ƾգ�����ͷ�ϡ�$N�������������ޡ�\n");
		set("unequip_msg", "$N�����°״�ͷ��ժ��������\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

