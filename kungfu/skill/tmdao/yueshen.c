 // counterattack.c
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int cps,skill;
        int extra, bonus, i, n, num;
        
        object *enemy,weapon;
               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��"HIG"����һ��"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("tmdao",1) <= 300)
                return notify_fail("�����ħ�����������������ܷ�����"HIG"����һ��"NOR"����\n"); 

      if ( (int)me->query_dex() < 50 )
        return notify_fail("��������ٶȲ��㣬����������ħ���ľ�����ʽ"RED"������һ������\n"NOR);
        
        if( (int)me->query_skill("tmjian",1)<199)
        return notify_fail("�����ħ����������죡\n"NOR);
        
        if( (int)me->query_skill("tmdao",1)<199)
        return notify_fail("�����ħ����������죡\n"NOR);

        if( (int)me->query_skill("tmquan",1)<199)
        return notify_fail("�����ħȭ��������죡\n"NOR);

        if( (int)me->query_skill("tmzhang",1)<199)
        return notify_fail("�����ħ�Ʒ�������죡\n"NOR);

        if( (int)me->query_skill("pmshenfa",1)<199)
        return notify_fail("���Ʈ����������죡\n"NOR);

        if( (int)me->query_skill("tmdafa",1)<199)
        return notify_fail("�����ħ�󷨲�����죡\n"NOR);


        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("������û��װ������������\n");
        if( (int)me->query("neili")<500)
        return notify_fail("����������̫��������ʹ�ã�\n"NOR);

 msg = HIR "\n$N"+HIR"����������ǰ��������ָ�ڵ�����һ�������ֽ����ӵ�������\n"NOR;
        message_vision(msg,me);
		skill=(int)me->query_skill("tmdao",1);
		extra=skill;
		n = skill/200;
		if(n==1) n=2;
		if(n > 6) n = 6;

        for(i=0;i<n;i++)
        {
            if(random(target->query("combat_exp")) < (int)me->query("combat_exp")/2) {
                message_vision(HIW"ֻ��һ�������$N"+HIW"��ǰ��������\n"NOR,target);
                target->receive_wound("qi",random(extra/2)+extra/2);
                target->receive_damage("qi",extra+extra/2);
                COMBAT_D->report_status(target);
			}
}
        message_vision(HIC"ͻȻ����ػ谵��$N���еĵ���û��������¹⣬Ѥ�õĹ�â�У�����������\n�������裬���������������ȴ���������еĶ���ԹԹ��\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(2)+1);
        me->start_busy(2);
        cps = (int)target->query("dex");
        if( random(cps) < 30 ) target->start_busy(1+random(1));
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        object weapon;
        int cps,myexp,tarexp,damgin,damsen,targin,tarsen;
        targin=target->query("max_qi");
        tarsen=target->query("max_jing");
        damgin = targin/2;
        damsen = targin/2;
        if (damgin>=30000) damgin=30000;
        if (damsen>=30000) damsen=30000;
        cps = (int)target->query("dex");
        myexp=me->query("combat_exp");
        weapon=target->query_temp("weapon");
        tarexp=target->query("combat_exp");
        
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
        	if ( (2*myexp+random(myexp/4)) >= tarexp ){
        		if(random(cps) < 30 && objectp(weapon)){
				message_vision(HIG "$N����ǰ�ľ����Ի󣬴����ķ������е�"NOR+weapon->query("name")+HIG"��\n"NOR,target);
				weapon->unequip();
				message_vision(HIG "ͻȻ֮�䣬��������������$N��âɢȥ�������¹�����һ���������$n��������\n"NOR,me,target);
                	} else if( !objectp(weapon) ){
                		message_vision(HIG "$N����ǰ�ľ����Ի󣬾�Ȼ�����˽����ٶȡ�\n"NOR,target);
				message_vision(HIG "ͻȻ֮�䣬��������������$N���еĹ�âɢȥ�������¹�����һ���������$n��������\n"NOR,me,target);
			} else {
				message_vision(HIG "ͻȻ֮�䣬��������������$N���еĹ�âɢȥ�������¹�����һ���������$n��������\n"NOR,me,target);
			}
			//target->set_temp("last_damage_from",me);							
                	//target->die();
                	target->receive_damage("jing",damsen);
                	target->receive_damage("qi",damgin); 
                target->start_busy(8);
                }
                else{
                	message_vision(HIR"$N��������ͻȻ����ãã���¹���$n�ĵ��澹���Լ����ʺ��������\n"NOR,target,me);
                	if(objectp(weapon)){
                		weapon->unequip();
                	        message_vision(HIR"ǧ��һ��֮����$N�������б��������ݼ��ˣ�$n�ĵ���������������ãã����������������������\n"NOR,target,me);
                	}
                	else message_vision(HIR"ǧ��һ��֮����$N���ݼ��ˣ�$n�ĵ���������������ãã����������������������\n"NOR,target,me);
                	target->receive_damage("jing",damsen);
                	target->receive_damage("qi",damgin); 
//                        target->receive_wound("gin",10 + random(celepower),me);
                        COMBAT_D->report_status(target);
                        COMBAT_D->win_lose_check(me,target,1);
                }                         
        }
        me->add("neili",-500);
        me->start_busy(3);        
        return ;
}     
