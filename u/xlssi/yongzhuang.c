// jingang-zhao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("�Ը�Ӿװ", ({ "xinggan yongzhuang", "yongzhuang" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "����һ���Ըе�Ӿװ����������ס��������Ҫ�Ĳ�λ��\n");
		set("material", "cloth");
		set("unit", "��");
        set("value",1);
                set("wear_msg", HIY "$NѸ�ٵ��ѹ��ȫ����·�����ʱ�������ޡ���������
$NЦ��Ц���ó�һ���Ը�Ӿװ������ȥ\n" NOR);
                set("remove_msg", HIY "$N�����ý�Ӿװ�����������������۵���СС��һ�š������޴���\n" NOR);
                set("armor_prop/armor", 100);
	}
	setup();
}
