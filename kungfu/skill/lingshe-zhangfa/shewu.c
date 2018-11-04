// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c ���߲���

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp,damage,lvl,count,i;
        string type;         
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("�����߲���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("���á����߲������б�����ȣ�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹���\n");

        if ((int)me->query_skill("staff") < 80)
                return notify_fail("����ȷ��������ң��޷�ʹ�á����߲�����\n");

        if ((int)me->query_skill("lingshe-zhangfa",1) < 280)
                return notify_fail("��������ȷ��������ң��޷�ʹ�ã�\n");

        if ((int)me->query_skill("xiyu-tiezheng",1) < 180)
                return notify_fail("��������������������ң��޷�ʹ�ã�\n");

        if ((int)me->query_skill("shentuo-zhang",1) < 180)
                return notify_fail("�������ѩɽ�ƻ������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("chanchu-bufa",1) < 180)
                return notify_fail("�����ܲ����������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("hamashengong",1) < 180)
                return notify_fail("��ĸ���񹦻������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("lingshe-quan",1) < 180)
                return notify_fail("�������ȭ�������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("qixian-wuxingjian",1) < 180)
                return notify_fail("����������ν��������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("shexing-diaoshou",1) < 180)
                return notify_fail("������ε��ֻ������ң��޷�ʹ�ã�\n");
                                                                                                
	if ((int)me->query("neili") < 500)
		return notify_fail("�����ڵ�����������\n");
        if (target->is_busy())
                return notify_fail("�Է���æ���أ��㻹�Ǽӽ������ɣ�\n");
                
        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "���е�" + weapon->name() +
              HIG "��ס�Ĳ���������һ�����ߣ�����$n" HIG "������׽����\n" NOR;

        ap =  me->query_skill("staff",1); 

        dp =  target->query_skill("dodge",1); 
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIY "$n" HIY "�ֻ�֮��ֻ�������Ż�����Ͼ������\n" NOR;
                target->start_busy(ap / 100 + 2);
        } else 
        {
                msg += HIC "����$p" HIC "������$N" HIC
                       "�����У�����������������$P�Ĺ�����" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
type="����";		
if (random(3)==0) type="����";
if (random(3)==0) type="����";
if (random(3)==0) type="����";		
message_vision(HIB"\n$N��"+weapon->name()+HIB"һ�������Ͻ𻷵���һ�����죬һ��"+type+HIB"���ȵ�ֱ��������\n"NOR,me);
	        ap = me->query_skill("staff");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
                me->add("neili", -100);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
                        target->add("qi",-damage+100);
                        target->add("qi",-damage/2+100);
msg =                    HIR"���"+weapon->name()+HIR"��$n��ǰ�ӹ�������������һ��"+type+HIR"������������Ȼ�ſ�ҧ��$n����������֮����\n"NOR;
		me->start_busy(2);
                target->start_busy(1);
	} else 
	{
		msg += CYN "$n" CYN "�����мܣ�����ֵ�ס��$P"
                       CYN "�Ĺ�����\n" NOR;
                me->add("neili", -80);
		me->start_busy(2);
                target->start_busy(1);
	}
	message_combatd(msg, me, target);


      msg = HIW "$N" HIW "���һ����������ǰ�����е�" + weapon->name() +
              HIW "���������â��һ������$n" HIW "��\n" NOR;

        if (lvl / 2 + random(lvl) > target->query_skill("parry") * 2 / 3)
        {
                msg += HIY "$n" HIY "��$N" HIY "��" + weapon->name() +
                       HIY "ʹ�û�����֣���������һ�㣬ʵ�������Եֵ���ֻ�к��ˡ�\n" NOR;
                count = lvl / 7;
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);

        } else
                count = 0;

        message_combatd(msg, me, target);
        me->add("neili", -100);
                me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 800);

        //for (i = 0; i < 7; i++)
        //{
         //       if (! me->is_fighting(target))
         //               break;
                if (random(3==0) && ! target->is_busy())
                        target->start_busy(2);
	 msg =  YEL  "$N���μӿ죬����֮�����������" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "$Nͻ�������Ĵӿ��������������$n��ǰ����һ�ȣ�" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N���Ȼ�������$n��࣬����һ����" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N����������һ�������Ӹ����£���ͷ����һ�ȣ�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "���ڰ�գ�$N����Ϊ�ƣ���ʵΪ�ȣ���$n��̹�ȥ��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N�������裬�ܲ�͸�磬ʹ$n�����е�͸����������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N���л��ɳˣ�һ�Ƚ���һ�ȣ�����������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N�������֮���������е�"+ weapon->name() +"����ǧ����˳�$n��ȥ��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        //}

        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -800);
        me->start_busy(2);
if (random(3)==0 && (int)me->query_skill("lingshe-zhangfa",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N�ø�󡹦�������ɽ���Ź��߷ۣ�������$n��ȫ��
$n��һ���������֣�$n�Ŀ�һ���ʹ��\n" NOR, me, target);
target->apply_condition("baituo_poison",50);
}

        return 1;
}

