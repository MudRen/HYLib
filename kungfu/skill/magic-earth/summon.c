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
                return notify_fail(YEL"���ٻ����ˡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-earth",1)< 600)
	return notify_fail("�����ϵħ��̫���ˣ�\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в����ٻ����ˣ�\n");
	
        if (present("dadi man",environment(me)))
		return notify_fail("ֻ���绽һλ����Ϊ����ս��\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("�ٻ����ɲ���һ�쵽����!\n");
	
	message_vision(YEL"$N"YEL"��������ջ���һ����â�ǣ������૵���������\n", me,target);
	message_vision(YEL"$N���˹���������飬ʢѪ��ʥ������������������ɣ�������n", me,target);
	message_vision(YEL"$N����Ժڰ��Ĺ��ӣ�а��ĳ��Ӻ����ǵ���Ϊ������\n", me,target);
	message_vision(YEL"$N�����������صľ��飬�밴������Լ����������ɣ������� \n", me,target);
	message_vision(YEL"$N�����������֮��ľ����ϣ����ݹ��ϵ���Լ��չ�����ǵ������ɣ���������\n", me,target);
	message_vision(YEL"$N�����չ������׳�����˰� ��\n", me,target);
	message_vision(YEL"$N��������Ǵ�ص��� ��\n", me,target);
	message_vision(YEL"$N������ְɣ�����!!! \n", me,target);
 

	me->add("neili", -2000);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/earthman");
message_vision(YEL"$N"YEL"�������,һ�����޴�Ĵ�ؾ��˳����ˣ���\n", me,target);
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
