// qianzhu-wandushou.c ǧ����
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
       int damage;
int rlevel,i;
object weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ǧ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//	if((int)me->query_skill("duji",1) < 100)
//		return notify_fail("�㶾��̫��,����ʹ����һ����!\n");

//	if((int)me->query_skill("wudu-shengong",1) < 80)
//		return notify_fail("���嶾�񹦵Ĺ�����������ʹ��ǧ����!\n");

	if((int)me->query_skill("qianzhu-wandushou",1) < 150)
		return notify_fail("���ǧ��������Ϊ����,������ʹ��ǧ���򶾵ľ���!\n");

	if((int)me->query("max_neili") < 700)
		return notify_fail("��������Ϊ����, ����ʹ��ǧ����! \n");

	if((int)me->query("neili") < 300)
		return notify_fail("����������, ����ʹ��ǧ����! \n");
if (me->query("family/family_name") == "�嶾��"
&&(int)me->query("neili") < 500)
return notify_fail("����������, ����ʹ��ǧ����! \n");
if ( me->query("family/family_name") == "�嶾��"
&& !objectp(me->query_temp("weapon")) 
)
{
rlevel=(int) me->query_skill("wudu-shengong", 1)/10;
if (!rlevel) rlevel=10;
	for(i=0;i<rlevel/4;i++)
	{
	me->add_temp("apply/attack", (rlevel*2));	
	me->add_temp("apply/damage", (rlevel*4));
        msg = HIB "$N�����嶾��,ͷ���������ڣ�һ�����˳�����\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(rlevel*2));	
	me->add_temp("apply/damage", -(rlevel*4));
}
	i = rlevel/4;
me->start_busy(2);
me->add("neili",-40*i);
}
	msg = HIR "$Nһ����Ц�����������һָ��$n��ü�ĵ�ȥ��\n";
	message_vision(msg, me, target);

	if( random(me->query_skill("qianzhu-wandushou",1)) > random((int)target->query_skill("dodge",1)* 2 / 3 )) {
		msg = HIR"ֻ��һ�ƺ�����$N��ָ��͸����ֻһ����û��$n��ü�ģ�\n" NOR;
	       message_vision(msg, me, target);
             if(target->query_skill("hunyuan-yiqi",1)>me->query_skill("qianzhu-wandushou",1)*12/10&&random(2)==0){             
		msg = RED"$N��Ȼ����ָ����һ�����εľ��������ţ�������ֻ��\n
$nһ����ȣ�$N��ʱ��һ�����ݰ㱻����Զ����\n" NOR;
	       message_vision(msg, me, target);
		msg = RED"$Pֻ����һ����ɽ�ľ���˳ָ���͹�������ֻ����ȫ������ܡ�\n��Ȼ�ؿ�һʹ�����ɡ��ۡ���һ���³�һ�ں�Ѫ��\n" NOR;
	       message_vision(msg, me);
              damage=(int)me->query_skill("qianzhu-wandushou",1)
                     +(int)me->query_skill("wudu-shengong",1);
              if(damage < 50 ) damage = 50;
		target->receive_wound( "qi",damage);
		me->add("neili", -100);
              me->start_busy(2);
              }    
              else{
		msg = HIR"$n����һ���Һ�ˤ���ڵأ�������ʹ���������һ�ţ�\n" NOR;
	       message_vision(msg, me, target);
              damage=(int)me->query_skill("duji",1)
                    +(int)me->query_skill("qianzhu-wandushou",1)
                    +(int)me->query_skill("wudu-shengong",1)/2;
              if(damage > 900 ) damage = 900;
		target->receive_wound( "qi",damage);
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 50 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 50 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 50 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 50 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 50 );
		me->add("neili", -100);
if ( me->query("family/family_name") != "�嶾��")
{
             target->start_busy(3);
}
             }
	} 
       else {
		msg = HIG "����$n����׼����һ����¿����������������һ�С�\n" NOR;
		me->start_busy(4);
	       message_vision(msg, me, target);
		me->add("neili", -100);
	}
//	if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}

