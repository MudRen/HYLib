//ai.c ����֮��
//by sdong

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
string msg;
        int bili,original,dodge,skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����֮��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if( me->query_skill("zixia-shengong", 1) < 60 )
                return notify_fail("�����ϼ�񹦻��δ�����޷�ʩչ��Ů���ģ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");


        if( me->query_skill("chongling-jian") < 155 )
                return notify_fail("��ĳ��齣����Ϊ���㣬������ʹ����Ů���ģ�\n");

        if( me->query("neili") <= 400 )
                return notify_fail("�����������ʹ�ð���֮����\n");
        if( me->query("jing") <= 100 )
                return notify_fail("��ľ�������ʹ�ð���֮����\n");




        if(!me)
                return notify_fail("����û�ˣ�\n");
        if(!target)
                return notify_fail("����û�ˣ�\n");

        skill = (int)me->query_skill("chongling-jian", 1);
        original = me->query_skill("zixia-shengong")/2;
        bili = me->query_str();
        dodge = me->query_dex();

        me->add_temp("apply/strength", 50);
        me->add_temp("apply/dexerity", 50);
        me->add_temp("apply/damage", 550);


  message_vision(HIC"ֻ��$N���������Ž�ʽһ�䣬������������ҫ�۵Ĺ�â�������һƬãã�Ľ�Ļ\n"
                 HIW"\t����"BLINK""HIR"   �����쳾����˼����  "NOR""HIW"  ����\n"NOR,me,target);

	msg = HIR "--<<��>>��������粻�����������������Ӧ����--"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     msg = YEL  "--<<��>>�������������ã�������ɣ�����������--" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     msg = HIY  "--<<��>>�����������Ъ��������£��������˵--" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);



      if (!target->is_busy() && random(3)==0)
      target->start_busy(2); 
       msg = HIG  "--<<��>>������������ʣ��������ǿ�ֻ���ζ--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       msg = HIB  "--<<��>>���������Ҳ�˻����ͽ����������ȥ��ʱ--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       msg = HIW  "--<<��>>�������������ߣ�������ϣ��������˼�--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       msg = HIM  "--<<��>>��������׷��˼��������������˼��--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     if(random(skill) > 180)
     {
message_vision(sprintf(HIC"$n��$N����ɫ����������ȫ�������˺����ۣ�\n"NOR),me,target);
          target->receive_wound("qi",skill*3);
          COMBAT_D->report_status(target,1);
     }


        me->add_temp("apply/strength", -50);
        me->add_temp("apply/dexerity", -50);
        me->add_temp("apply/damage", -550);

        me->start_busy(3);
        me->add("neili", -350);
        me->add("jing", -50);
        me->set_temp("suxin", 1);


//      me->start_busy(3);


        return 1;
}


