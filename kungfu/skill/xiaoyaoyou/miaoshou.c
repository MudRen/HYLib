// ���ֿտ� by oldsix
//modify by ksusan 7/29/97 16:55

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int k;
	object thing,*inv;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("���ֿտ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_skill("huntian-qigong", 1)<120)
                return notify_fail("��ı����ڹ����δ������\n");
		
	if( (int)me->query_skill("begging",1)<80)
	return notify_fail("������ֿտղ�����죬����ʹ�á����ֿտա���\n");
	if( (int)me->query_skill("xiaoyaoyou",1)<80)
	return notify_fail("��ı������������ݣ�����ʹ�á����ֿտա���\n");
	if( (int)me->query_skill("checking",1)<80)
	return notify_fail("��ĵ���;˵����������ʹ�á����ֿտա���\n");

	if( (int)me->query("neili")<200)
	return notify_fail("����������̫��������ʹ�á����ֿտա���\n");

	if(me->query("qi")<50)
	return notify_fail("�����������㣬�޷�ʹ�á����ֿտա���\n");
	if(me->query_temp("have_pfm"))
	return notify_fail("���չʩ��������ʽ����Ϣ��û����������\n");
	me->set_temp("have_pfm",1);
	msg = CYN "$NͻȻ����һչ��ʹ�������ֿտա���$n������ȥ��\n"NOR;
	k=me->query("oldsix_flag/tanyunshou");
	if(!k||k==0)	k=2;
	if(random(me->query("combat_exp"))>target->query("combat_exp")/3)	{
		
	me->add("neili",-random(100));
	me->add("qi",-20-random(50));
	me->start_busy(1);
	inv=all_inventory(target);
		if(!sizeof(inv))	{
			msg +=CYN"$n���Ͽտ���Ҳ��$NʲôҲû��̽������\n"NOR;
		}
		else	{
			thing=inv[random(sizeof(inv))];
		if( (thing->query("equipped"))
		|| (int)thing->query("no_get")
		|| (int)thing->query("no_drop")
		|| (int)thing->query("ownmake"))
		msg +=CYN"$n˫�ֽ���ץס"+thing->query("name")+"û��$N�óѣ�\n"NOR;
	else 	{
		if(thing->query("equipped"))	thing->unequip();
		thing->move(me);
		msg +=CYN"$N���ֿտգ���$n���ϵõ�"+thing->query("unit")+thing->query("name")+"��\n"NOR;
	}
			}
	} else 
		{
		me->add("neili",-5);
		me->start_busy(3);
		msg += CYN"����$p������$P����ͼ������һ�����˿�ȥ��\n"NOR;
		}
	message_vision(msg, me, target);
	call_out("do_reset",6,me);
	return 1;
}

void do_reset(object me)
{
        if( !objectp(me))       return;
        if( (int)me->query_temp("have_pfm"))
                me->delete_temp("have_pfm");
}
