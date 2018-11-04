// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
    if ((!target))
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");


        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

	if ((int)me->query_skill("force", 1) < 300)
		return notify_fail("����ڹ���Ϊ��������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") 
	&& (int)target->query("eff_jing") >= (int)target->query("max_jing"))
		return notify_fail( target->name() + "��δ���ˣ�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");
		
	message_combatd(
		HIG "$N�������������ڹ�������������$n���ģ���ͨ��ѧ���ڹ���ѧ��ʼ�˹�����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("qi", 60 + (int)me->query_skill("force")/3 );
	target->add("qi", 60 + (int)me->query_skill("force")/3 );
	if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
	if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));
	target->receive_curing("jing", 60 + (int)me->query_skill("force")/3 );
	target->add("jing", 60 + (int)me->query_skill("force")/3 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
	me->add("neili", -300);
        if (random(3)==1) target->start_busy(1);
	return 1;
}
