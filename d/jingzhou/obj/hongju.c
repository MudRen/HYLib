// hongju.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	string *surname=({"���ƺ�","��ܽ��","����֦","���˺�"});
	set_name(HIR+surname[random(sizeof(surname))]+NOR, ({"hong ju","flower" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�使�޵ĺ�ա�\n");
		set("material", "����");
		set("unit", "��");
		set("unique", 1);
		set("value", 1000);
		set("wear_msg", "$N����һ���գ�����ͷ�ϡ�$N�������������ޡ�\n");
		set("unequip_msg", "$N����մ�ͷ��ժ��������\n");
		set("armor_prop/personality", 2);
		set("female_only", 1);
	}
	 setup();
}

