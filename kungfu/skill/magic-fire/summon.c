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
                return notify_fail(RED"���ٻ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-fire",1)< 600)
	return notify_fail("��Ļ�ϵħ��̫���ˣ�\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в����ٻ�������\n");
	
        if (present("shenghuo long",environment(me)))
		return notify_fail("ֻ���绽һͷ����Ϊ����ս��\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("�ٻ����ɲ���һ�쵽����!\n");
	
	message_vision(HIM"$N"HIM"��������ջ���һ����â�ǣ������૵���������\n", me,target);
	message_vision(HIM"$N���ΰ��Ļ�֮���������������ҵĺ���ֳ�����ʵ�������ɣ���\n", me,target);
	message_vision(HIM"$N���������ڵ�����֮��!\n", me,target);
	message_vision(HIM"$N���������ʯҲ���ڻ�������֮��!\n", me,target);
	message_vision(HIM"$N���Զ������������ľ��鰡! \n", me,target);
	message_vision(HIM"$N����������л�������˰� ��\n", me,target);
	message_vision(HIM"$N�����չ������׳�����˰� ��\n", me,target);
	message_vision(HIM"$N�������������֮�� ��\n", me,target);
	message_vision(HIM"$N������ְɣ���������!!! \n", me,target);
 

	me->add("neili", -2000);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/huolong");
message_vision(HIR"$N"HIR"�������,һ���޴�Ļ��������ˣ���\n", me,target);
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
