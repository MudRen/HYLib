// invocation.c
#include <ansi.h>
inherit F_SSERVER;
#define MAX_GUARD 15
int perform(object me, object target)
{
	object soldier;
	int	spells;
	string 	msg;
	object	env;
	object	*inv;
	int	i,exp;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIB"���ٻ���ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-dark",1)< 650)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в����ٻ���ħ��\n");
	
        if (present("dark angel",environment(me)))
		return notify_fail("ֻ���绽һ����ħΪ����ս��\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("�ٻ����ɲ���һ�쵽����!\n");
	
	message_vision(HIB"$N"HIB"��������ջ���һ����â�ǣ������૵���������\n", me,target);
	message_vision(HIB"$N"HIB"������ص���â���ٻ�ˮ����â���ٻ������â���ٻ������â! \n", me,target);
	message_vision(HIB"$N"HIB"���ΰ������񰡣�������Χ��ҫ��â�ǵĹ�â��!\n", me,target);
	message_vision(HIB"$N"HIB"������������â�д����������ɣ�����\n", me,target);
	message_vision(HIB"$N"HIB"���ͳ���Ľ�ĺڰ�֮����! \n", me,target);
	message_vision(HIB"$N"HIB"����������кڰ������˰� ��\n", me,target);
	message_vision(HIB"$N"HIB"�����չ������׳�����˰� ��\n", me,target);
	message_vision(HIB"$N"HIB"��������Ǿ޴�ĺڶ� ��\n", me,target);
	message_vision(HIB"$N"HIB"������ְɣ�׹��ʹ ·����!!! \n", me,target);
 

	me->add("neili", -2500);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/darkman");
message_vision(HIB"$N"HIB"�������,������ʹ·���������ˣ���\n", me,target);
	soldier->move(environment(me));
if (userp(me))
{
	soldier->set("combat_exp",me->query("combat_exp"));
exp = (int)me->query("combat_exp");
	soldier->set("qi",me->query("max_qi"));
	soldier->set("eff_qi",me->query("max_qi"));
	soldier->set("max_qi",me->query("max_qi"));
	soldier->set("jing",me->query("max_qi"));
	soldier->set("eff_jing",me->query("max_qi"));
	soldier->set("max_jing",me->query("max_qi"));
	soldier->set("neili",me->query("max_neili"));
	soldier->set("max_neili",me->query("max_neili"));
}
        soldier->invocation(me, (exp));
	soldier->set("possessed", me);
	return 1;
}
