// tianxiang.c  ��������

#include <ansi.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_skill("feitian-yujianliu",1) < 300)
		return notify_fail("��ķ�������������Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("blade") < 300)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 300)
   return notify_fail("���ɱ���ķ���򲻹���\n");

        if( userp(me) && !me->query("feitian/tianxiang"))
                return notify_fail("��ֻ��˵��,�������á�������������\n");   
                
	weapon = me->query_temp("weapon");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

        
       if( !((int)(me->query("max_qi")/me->query("qi"))>=4))
             return notify_fail("�㻹û�����ˣ���᲻�������������־��硣\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("�������������\n");

        if( (int)me->query_temp("tx_tong") ) 
                return notify_fail("���Ѿ���ʹ�������������ˡ�\n");

message_vision(RED"$N��������ɫ���۾���ͻȻ���������Ĺ��$n��\n"NOR,me,target);
message_vision(HIR"$N�ѵ�����˵��ʡ������ٵİε�����׼������,ǿ�ҵ�������־ʹ$n�е�������  \n"NOR,me,target);
message_vision(RED"$NĿ��ת���ض���$n��׼����������һ����ͬʱ$N�����ٵ�������ʱ׼������$n�Ĺ�����Χ��  \n"NOR,me,target);
	me->start_busy(4);
	me->add("qi",1800);
	me->add("eff_qi",1800);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(5)+5);
	return 1;
	
        me->add_temp("apply/armor", (int)me->query("feitian-yujianliu")/2);
        me->add_temp("apply/dodge", (int)me->query_skill("feitian-yujianliu",1)/2);
        me->set_temp("tx_tong", 1);
        me->add("neili", -((int)me->query("neili")/2));

        return 1;
}


void kill_him(object me, object target)
{
	string msg;
        me->add_temp("apply/armor", - (int)me->query("feitian-yujianliu")/2);
        me->add_temp("apply/dodge", - (int)me->query_skill("feitian-yujianliu",1)/2);
        me->delete_temp("tx_tong");

	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
msg = HIW "$Nʹ����������������߽�����" + HIR "��������" +HIW "��$nֻ��$N����һ�����ʺ��ѱ��Դ������� " ;
msg +=  HIY"\nһ��Ѫ����ӿ��������$n���۾�������ͻ�˳�������\n" NOR;
	message_vision(msg, me, target);
if (target->query("qi") > 50000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
	}
	return ;
}

