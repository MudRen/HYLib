//jiuhuawan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIG"�������ͷ"NOR, ({"jiayu tou","tou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������������ҩ�Ľ��ݵļ���ͷ�������㾫�����ƣ�
������״��֮��Ч����˵�����ú�һ�����ϰ�˯��XX��\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if(arg=="tou") 
	{
                fw = (int)me->max_food_capacity();
              fw = fw*2;
                me->set("food", fw);
                me->set("water", fw);
                me->set("eff_jing",me->query("max_jing")*1);
                me->set("eff_qi",me->query("max_qi")*1);
                me->set("jing",me->query("max_jing")*2);
                me->set("qi",me->query("max_qi")*2);
                me->set("neili",me->query("max_neili")*2);
message_vision(HIG"$N����һ���������ͷ�裬�е��������ȣ����ɵĿ�ʼ�������������ˣ�\n"NOR,me);
		me->start_busy(1);
        	destruct(this_object());
	}
	return 1;
}

