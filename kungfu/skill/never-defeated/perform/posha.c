// posha ��ɱ��
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object me, int f, int j);

int perform(object me)
{
        object weapon,victim_w,armor,ring;
        int damage,p,i;
        string msg,dodge_skill;
object target;        
        int attack_time,extra;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail(RED"��Ҫ��˭ʹ�á���ɱ�𡹡�\n"NOR);


	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force", 1) < 300)
		return notify_fail("����ڹ���Ϊ��������\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ������\n");

	if (me->query_skill("never-defeated", 1) < 100)
		return notify_fail("��Ĳ����񹦻�������죬����ʹ����ɱ��\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ��ɱ��\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

        if (me->query("neili") < 200)
                return notify_fail("�������������\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");     

        if (target->is_busy()) 
		return notify_fail("�Է���æ���أ��Ͽ칥���ɣ�\n");		        
        msg = HBWHT "$N������������ͨ��ѧ֮���裬ʹ��������֮��ѧ��\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);

        msg = HIR "$Nʹ������ɱ�𡹣��������������$n��ȫ��\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
        msg += HIR "\n ��Ѩ�� ��$p����������ȫ��Ѩλ��\n" NOR;
                target->start_busy( (int)me->query_skill("force",1) / 60 + 3 );
        i=(int)me->query_skill("force",1) / 60 + 3;
       if (wizardp(me)) msg += HIR "\n ��Ѩʱ��"+i+"�롣\n" NOR;
if (userp(target))
{
        msg += HIY " �Ʒ��� ��$pȫ��ķ�����ȫ���ƻ���\n" NOR;
       if (target->query_temp("apply/armor") > 1)
        target->set_temp("apply/armor", target->query_temp("apply/armor")/2);
        if (target->query_temp("apply/dodge") > 1)
        target->set_temp("apply/dodge", target->query_temp("apply/dodge")/2);
        if (target->query_temp("apply/defense") > 1)
        target->set_temp("apply/defense", target->query_temp("apply/defense")/2);

        msg += HIW " �ƹ��� ��$pʹ�õ���ʽ��ȫ��������\n" NOR;
       if (target->query_temp("apply/attack") > 1)
        target->set_temp("apply/attack", target->query_temp("apply/attack")/2);
        if (target->query_temp("apply/damage") > 1)
        target->set_temp("apply/damage", target->query_temp("apply/damage")/2);

        msg += HIB " ������ ��$p���������ٶ���ȫ�����ң�\n" NOR;
        if (target->query_temp("apply/strength") > 1)
        target->set_temp("apply/strength",target->query_temp("apply/strength")/2);
        if (target->query_temp("apply/dexerity") > 1)
        target->set_temp("apply/dexerity",target->query_temp("apply/dexerity")/2);
        if (target->query_temp("apply/intelligence") > 1)
        target->set_temp("apply/intelligence",0);
}
        msg += HIC " ������ ��$p�������ͷ���ʧȥ�����ã�\n\n" NOR;
        if( target->query_temp("armor/cloth")){
        armor = target->query_temp("armor/cloth");
	armor->unequip();
	armor->reset_action();
        }

        if( target->query_temp("armor/shield")){
        ring = target->query_temp("armor/shield");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/ring")){
        ring = target->query_temp("armor/ring");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/gem")){
        ring = target->query_temp("armor/gem");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/armor")){
        ring = target->query_temp("armor/armor");
	ring->unequip();
	ring->reset_action();
        }
        
	if (target->query_temp("weapon")){
	victim_w = target->query_temp("weapon");
        victim_w->unequip();
	victim_w->reset_action();
        }
        
        } else {
                msg += HIG"����$p��ʶ$P���������ӳ��˹�����Χ��\n" NOR;
                me->start_busy(2);
        }
if (me->query("zhuanfinal/4") ==1 && random(2)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$Nʹ�������ɾ�!!$Nȫ����˺��˺ܶ�!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(2)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$Nʹ���˶��ɾ�!!$NͻȻ�����ֿ���!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(2)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$Nʹ�������ɾ�!!$NͻȻ�����ָ���!\n"NOR;
}
        message_combatd(msg, me, target);
       if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
         attack_time = random((int)me->query_skill("never-defeated", 1) / 40);
        if (attack_time > 8 ) attack_time=8;
        for(i = 0; i < attack_time; i++){
         msg = HIY "$N��ʽ���죬ת���Ծ����һ����\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
        me->start_busy(3);
}

        return 1;
}

