//ѩ÷Ц
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time,damage,extra,p;

        if( !target ) target = offensive_target(me);

        skill = me->query_skill("xueshan-sword",1);
        extra = me->query_skill("xueshan-sword",1);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("jinwu-blade", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("xueshan-sword", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("bingxue-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bingxue-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ��������ѧ��ʹ���������ǵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);
         attack_time = random((int)me->query_skill("xueshan-sword", 1) / 30);
if (attack_time > 9 )attack_time=9;
        for(i = 0; i < attack_time; i++){
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",extra*2);
         msg = HIW "$N������ѩ���У�һ��÷�����˳�����\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra/3);
	me->add_temp("apply/damage",-extra*2);
                        }


        msg = HIW 
    "$N��Хһ��,ʹ������÷Ʈ�㡹,���б�������,�������ѩ����ǰ����ǵص���ȥ��\n"
    "�ڰ�ãã��һƬ��,��Ȼ�������÷���ν���,��͸ѩĻ,������˷����������\n" NOR;
        message_combatd(msg, me, target);

        ap = me->query("combat_exp") + skill;
        dp = target->query("combat_exp") / 3;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
        msg = HIC 
    "����÷���⻪,�ó���������,��$nȫ�������ֵ�����ʵʵ��$n��������,\n"
    "ֻ����������,���Լ�����˿˿����,һʱȫ���ʹ,��Ѫ�ɽ��õ������ǡ���ͬ���֮��,\n"
    "�Ҳ����ԡ�\n" NOR; 
        //COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");
           if (qi_wound <50) qi_wound = 50;
            target->receive_damage("qi", qi_wound*3);
            target->receive_wound("qi", qi_wound);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
        }
        else
        {
            msg = "����$n��ݵ����Ա�һ�����ܹ�����һ����\n"NOR;
        }

        msg = HIC "$N�ؽ����裬���Ʋ��ϼӿ죬������Х��ɢ����ƬƬѩ�����磬ƮȻ������\n�γ�һ��ѩ�������У���$n�������\n";
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
                msg +=HIG "$nֻ��������ѹ��Խ��Խ�󣬵��������������������������á�\n" NOR;
target->apply_condition("cold_poison", 50 +
			target->query_condition("cold_poison"));
            target->receive_damage("qi", qi_wound*5);
            target->receive_wound("qi", qi_wound);
        } else {
                msg +=HIR "����$n����������ѩ����ʱȫ���ܽ⣬һƬ��ʣ���ѳ���Χ��\n" NOR;

        }

        me->start_busy(4);
        message_combatd(msg, me, target);

        return 1;
}

