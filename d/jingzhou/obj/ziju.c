// ziju.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	string *surname=({"�����","������","˫����","�̽�ϼ"});
	set_name(MAG+surname[random(sizeof(surname))]+NOR, ({"zi ju","flower" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�使�޵��Ͼա�\n");
		set("material", "����");
		set("unit", "��");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N����һ���Ͼգ�����ͷ�ϡ�$N�������������ޡ�\n");
		set("unequip_msg", "$N���Ͼմ�ͷ��ժ��������\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

