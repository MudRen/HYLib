#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
          set_name(HIY"����"NOR, ({"jin chai","jin","chai"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long",
                "\n����һ֧����Ư���Ľ��Σ�����һ�������ִ���Բ������ӨȻ��\n");
		set("unit", "��");
		set("value", 3000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");

		set("female_only", 1);

	}
	setup();
}

