// Ľ��ȭ��֮̽���� by oldsix
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
	return notify_fail("̽����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		
	if( (int)me->query_skill("douzhuan-xingyi",1)<80)
	return notify_fail("������ƶ�ת������죬����ʹ�á�̽���֡���\n");
	if( (int)me->query_skill("yanling-shenfa",1)<80)
	return notify_fail("����������������ݣ�����ʹ�á�̽���֡���\n");
	if( (int)me->query_skill("shenyuan-gong",1)<80)
	return notify_fail("��ı����ڹ�����������ʹ�á�̽���֡���\n");

	if( (int)me->query("neili")<200)
	return notify_fail("����������̫��������ʹ�á�̽���֡���\n");

	if(me->query("qi")<50)
	return notify_fail("�����������㣬�޷�ʹ�á�̽���֡���\n");
	if(me->query_temp("have_pfm"))
	return notify_fail("���չʩ��������ʽ����Ϣ��û����������\n");
	me->set_temp("have_pfm",1);
	msg = CYN "$NͻȻ����һչ��ʹ����̽���֡���$n������ȥ��\n"NOR;
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
		if( (thing->query("equipped")&&random(me->query("kar"))<10)
		|| (int)thing->query("no_steal") || (int)thing->query("no_get"))
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
		me->start_busy(1);
		msg += CYN"����$p������$P����ͼ������һ�����˿�ȥ��\n"NOR;
		}
	message_vision(msg, me, target);
	call_out("do_reset",3,me);
	return 1;
}

void do_reset(object me)
{
        if( !objectp(me))       return;
        if( (int)me->query_temp("have_pfm"))
                me->delete_temp("have_pfm");
}
