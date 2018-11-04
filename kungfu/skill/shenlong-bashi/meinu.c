#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int calc_damage(int,int); 
int perform(object me, object target)
{
	int extra;
	object weapon,ob;
	string msg,result;
	int i,j,k,total; 
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("shenlong-bashi",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���������С�ֻ����ս����ʹ�á�\n");
 
	if (me->query("gender") != "Ů��")
		return notify_fail("�㲻�Ǵ���֮�壬�������������У�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������С�ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query_skill("huagu-mianzhang", 1) < 50 )
		return notify_fail("��Ļ������ƻ���������������ʹ�á��������С���\n");

	if( (int)me->query_skill("shenlong-tuifa", 1) < 50 )
		return notify_fail("��������ȷ�����������������ʹ�á��������С���\n");

       
        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"�������ķ���򲻹���\n"NOR);

	 if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("shenlong-bashi",1) < 70 )
                return notify_fail("���������ʽ��򲻹����޷�ʹ�á��������С���\n");

        if( (int)me->query_skill("force",1) < 60 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á��������С���\n");
if ((int)me->query_skill("shenlong-xinfa",1) >250
&& me->query("neili") >1000)
{

         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "��һ������"+HIR+"����$n������\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);

	target->start_busy(1);
	me->add("jing",-10);
	me->add("neili",-200);

	i = (me->query_skill("shedao-qigong") + me->query_skill("hand") + me->query_skill("strike")) /3 ;
	j = (target->query_skill("force") + target->query_skill("dodge") + target->query_skill("parry"))/3;

	k = (-me->query("shen"))*100 / 3000000;
	if(k>1000) k=1000;
	if(k<-1000) k=-1000;
	i = i*(1000+k/3)/1000;
	k = 1000 + k/2;

	if(wizardp(me)) tell_object(me,sprintf("\nattack: %d , parry: %d  , shen: %d \n",i,j,k));

	msg = HIR"$N��$n��������֮����ƴ��ȫ��ʹ���շ��˲���֮�����������������С�"NOR;

	if( (random(me->query("combat_exp"))+300000) > (int)target->query("combat_exp")/2 ) {
		me->start_busy(1);
		me->add("neili",-random(800));
		me->add("jing",-random(10));

		total = 0;

		msg += 
MAG "\n\n$Nʹ��һ�С�����������������΢����������Ť�����㷴�ߣ���$nС����ȥ��
����˳�Ʒ�������§ס$nͷ�������ֱ��ж�׼$n���Ļ�ȥ��\n"NOR;
		i = calc_damage(me->query_skill("huagu-mianzhang",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"����");
		result = replace_string( result, "$l", "ͷ��" );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		msg =
MAG "\n$Nʹ��һ�С�С����¡����Դ�������Լ��ؿ����䣬˳���ڵ���һ��������
��$n������������ű��������ֳ�ȭ����$n���ġ�\n"NOR;
		i = calc_damage(me->query_skill("shenlong-bashi",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"����");
		result = replace_string( result, "$l", "����" );
//		result = replace_string( result, "$w", weapon->query("name") );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		msg = 
MAG "\n$Nʹ��һ�С�������衹������˳��һ�����ڱ�����һ�㣬����������$N�ʺ�
���ȥ��$N��������һ�����Ǳ�������$n�ؿڡ�\n"NOR;
		i = calc_damage(me->query_skill("shenlong-tuifa",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"����");
		result = replace_string( result, "$l", "�ؿ�" );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));

//		me->start_perform(3,"���������С�");
	}
	else {
		msg += 
MAG "\n\n$Nʹ��һ�С�����������������΢����������Ť�����㷴�ߣ���$nС����ȥ��
����˳�Ʒ�������§ס$nͷ�������ֱ��ж�׼$n���Ļ�ȥ��\n"NOR;
		msg += "����$n������$N����ͼ��û���ϵ�������ææ���Ա�һ�������˹�ȥ��\n";
		msg += 
MAG "\n$Nʹ��һ�С�С����¡����Դ�������Լ��ؿ����䣬˳���ڵ���һ��������
��$n������������ű��������ֳ�ȭ����$n���ġ�\n"NOR;
		msg += "$n����һ�������漴�侲�������ڿ�����һ��������$N���ţ�$Nֻ���ɿ����֡�\n";
		msg += 
MAG "\n$Nʹ��һ�С�������衹������˳��һ�����ڱ�����һ�㣬����������$N�ʺ�
���ȥ��$N��������һ�����Ǳ�������$n�ؿڡ�\n"NOR;
		msg += "$n��$N��ס������Σ���ң���������סҪ����ͬʱ�߸�Ծ�𣬷�����ͷײ�أ���$Nײ�˳�ȥ��\n";

		message_vision(msg,me,target);
		me->start_busy(2);
//		me->start_perform(2,"���������С�");
	}
}
else {
	me->add_temp("apply/attack",2*extra);
	me->add_temp("apply/damage",2*extra);
	me->add_temp("apply/dexerity",extra);
	me->add_temp("apply/dodge",extra);
	weapon = me->query_temp("weapon");

        msg = CYN "$N�������ģ���$n΢΢һЦ"HIY"[��������]"CYN"��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------����������" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "��һ������"+HIR+"����$n������\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        msg = GRN   "-------------------������裡" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        msg =  MAG  "-------------------------С����£�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);

	me->add_temp("apply/attack",-2*extra);
	 me->add_temp("apply/damage",-2*extra);
	me->add_temp("apply/dexerity",-extra);
	me->add_temp("apply/dodge",-extra);
        me->add("neili", -150);
        me->start_busy(3);
}
        return 1;
}

int calc_damage(int skill,int k)
{
	int i;

	if(skill>200)
		i = (200*5 + (skill-200)*40/10) * k/1000;
	else
		i = (skill * k/1000) * 5;
	i = i/2 + random(i/2);
	if(i>1500) i=1500;

	return i;
}

