// qunmo.c  Ⱥħ����

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


int perform(object me,object target)
{
//          object weapon = me->query_temp("weapon");
        int attack, defense;
 	string msg;
	int extra;
	int i,a;
	object weapon;
	       
        if (!target) target = offensive_target(me);
        if (!target || !me->is_fighting(target))
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�Ⱥħ���衻��\n");                

        if (me->query_skill("kongming-quan", 1) < 70)
                return notify_fail("��Ŀ���ȭ�в����컹�ǲ�Ҫ���á�Ⱥħ���衻��\n");        
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á�Ⱥħ���衻��\n");  
        if (me->query("neili") < 100)
                return notify_fail("�������������㣬����ʹ��ƴ���򷨣�\n");
        if (me->query_temp("kongming_berserk"))
                return notify_fail("��Ŀǰ����ʹ�á�Ⱥħ���衻��\n");      

        if ((int)me->query_skill("xiantian-qigong", 1) <  100 )
                return notify_fail("�������������򲻵���\n");

        message_vision(HIR"\n$NͻȻ�����񣬻�����˫�ۣ�����������ȭ�硣\n"NOR, me);
        me->add("neili", -80); 
        me->add("jing", -30);      
        me->set_temp("kongming_berserk", me->query_skill("kongming-quan", 1) / 5);
        attack = me->query_temp("apply/attack");
        defense = me->query_temp("apply/defense") / 2;
if (attack <= 100) attack=100;
	if (defense <= 100) defense=100;
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/defense", -defense);

	extra = me->query_skill("kongming-quan",1) / 20;
	extra += me->query_skill("xiantian-qigong",1) /20;


	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIG "����ȭ ! ����ʵʵ���仯Ī�⣡��������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 12) a=12;
	for(i=0;i<a;i++)
	{
	msg = HIW "$Nһȭ���,����ʵʵ���仯Ī�⣡\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add("neili", - 50 * i);
	me->start_busy(3);


        call_out("remove_effect", 1, me, target, attack, defense);
        return 1;
}

void remove_effect(object me, object target, int attack, int defense)
{
        if (objectp(me)) {
                if (objectp(target) && me->query_temp("kongming_berserk") && me->is_fighting(target)) {
                        me->add_temp("kongming_berserk", -1);
                        call_out("remove_effect", 1, me, target, attack, defense);
                        return;
                }
                me->add_temp("apply/attack", - attack);
                me->add_temp("apply/defense", defense);
                me->delete_temp("kongming_berserk");
                tell_object(me, "�㷢�����Ҵ���һ��󣬾�����ЪһЪ��\n");
        }
}

