#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"��ҪΪ˭ʹ�ø�Ԫ����\n"NOR);

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("����������㣡\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( me->query("zhuanfinal/1") !=1 )
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if( userp(target) && target!=me && query_ip_name(target)==query_ip_name(me) )
	return notify_fail("�㲻�ܶ��Լ����������������\n");

        if ( me->is_busy() )
        return notify_fail("��������æ���޷�ʹ�ø�Ԫ��");

	if((int)target->query("neili") > (int)target->query("max_neili")-(int)target->query("max_neili")/3)
	return notify_fail("Ŀ�����ڲ���Ҫʹ�ø�Ԫ����\n");

	msg = HIY "$N���һ����һ������ֱ�����!\n";
	msg += HIY "$N����ֱ͸���� ��߶���ͻȻ��ǿ����!!����\n";
	me->start_busy(2);

	if((int)target->query("neili") < (int)target->query("max_neili")+(int)target->query("max_neili")/3)
        {
        target->set("neili",target->query("max_neili"));
        }
        if (target==me)
        me->apply_condition("tianrenheyi",3);
else    me->apply_condition("tianrenheyi",6);
		message_combatd(msg, me, target);
	return 1;
}
