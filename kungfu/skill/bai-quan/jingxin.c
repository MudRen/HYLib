// counterattack.c

#include <ansi.h>
#include <command.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	int gin,jing,sen,eff_gin,eff_jing,eff_sen;
	if( !target ) target = me;
	if(me->is_fighting() )
		return notify_fail("�۾��ķ��ݲ�����ս����ʹ�á�\n");
	if( target != me)
		return notify_fail("�۾��ķ���ֻ�ܶ��Լ�ʹ�á�\n");
        lvl = random((int)me->query_skill("bai-quan",1));

	msg = YEL "$N����ƽ����̤̤ʵʵ��ʩչ��һ�˰׼�ȭ��\n" NOR;
	gin = (int)me->query("qi");
        jing = (int)me->query("jing");
        sen = (int)me->query("sen");
        eff_gin = (int)me->query("eff_qi");
        eff_jing = (int)me->query("eff_jing");
        eff_sen = (int)me->query("eff_sen");

        if(lvl+jing > eff_jing) me->set("jing",eff_jing); else me->add("jing", lvl);
        if(lvl+gin > eff_gin) me->set("qi",eff_gin); else me->add("qi", lvl);
        message_vision(msg, me);
	me->start_busy(6);
	return 1;
}
