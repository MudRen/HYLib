// star.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLINK HIY "����" NOR, ({ "star" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "�������ժ����һ�����ǣ���ɲ����ý�Ǯ��"
                            "�����ģ���ôҲ����һ�����Ⱒ��\n" NOR);
                set("value", 0);
		set("unit", "��");
	}
        setup();
}
