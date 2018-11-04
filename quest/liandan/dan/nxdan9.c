//Cracked by Kafei
// hugu.c ����

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
	set_name("����", ({ "hu gu", "gu" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("unit", "֧");
                set("long", "����һ֧�ϻ����ֹǣ����Ǽ�Ϊ����ҩ�ġ�\n");
	        set("value", 8000);
	        set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        me->add("food", 40);

        if ( (int)me->query_condition("medicine" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("medicine", 30);
                message_vision(HIR "$N����һ֧���ǣ�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
                call_out("destroy", 0);
                return 1;
        }

        if( !me->query_temp("cbs/hugu") ) {
                me->add_temp("apply/strength", 3);
                me->set_temp("cbs/hugu", 1);
        }

        me->receive_curing("qi", 200);
        me->set("qi", me->query("max_qi"));

        me->apply_condition("medicine", 
        me->query_condition("medicine")+30);
        message_vision(HIY "$N����һ֧���ǣ�ֻ����ȫ��ð����ˬ�����졣\n" NOR, me);
        call_out("destroy", 0);
        return 1;
}

void destroy()
{
        destruct(this_object());
}
