// gonggui.c ȫ�潣�� ͬ�齣��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill;
	int extra;
        string msg;
	extra = me->query_skill("quanzhen-jian",1);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ͬ���ھ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 135 )
                return notify_fail("���ȫ�潣��������죬����ʹ�á�ͬ�齣������\n");

        if( (int)me->query_skill("xiantian-qigong",1) < 100)
                return notify_fail("��������񹦻�򲻹�������ʹ�á�ͬ�齣������\n");
    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("��Ҫ����������Ϊ�ڹ������á�\n");

        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("���Ѿ�����̫�����ˡ�\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("���Ѿ����˿����޵й��ˡ�\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 
        
//                if(!( me->query("eff_qi")<1||(int)(me->query("max_qi")/me->query("eff_qi"))>=2.5))
//                return notify_fail("�㻹û�����ˣ���Ҫʹ�ô˽�����\n");

        if( (int)me->query("neili") < 800  ) 
                return notify_fail("�������������\n");
 
//        if( (int)me->query_temp("powerupxtg") ) 
//                return notify_fail("���Ѿ�����������ˡ�\n");


        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

        if( me->query_temp("qzjtong") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        msg = HIB+me->name()+HIB"������һ����������������" + weapon->name() + "��ƴ������������һʽ��ͬ�齣������\n";
	msg += "Ԧ�����Ҿ��׵س���"+target->name()+HIB",��ͼ��"+target->name()+HIB"ͬ��һ����\n"NOR;
        message_vision(msg, me, target);
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIC "$N�������ǣ� ��ת��Ȩ��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "$N�������ǣ� �綯��⣡" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>200)
{
        msg = HIW "$N�������ǣ� �������٣�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

        me->set_temp("qzjtong", 1);
        me->set_temp("qzj_tong", 1);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
	me->add_temp("apply/dexerity",extra/2);
        me->add_temp("apply/strength",extra/2);
//        me->add_temp("apply/dodge", -(int)me->query_skill("dodge",1)/2);
        me->add_temp("apply/damage",(int)me->query_skill("quanzhen-jian",1)/2);
        me->set_temp("qzj_tong", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, (int)me->query_skill("dodge",1)/2, (int)me->query_skill("quanzhen-jian",1)/2:), 30);
	me->add("neili", -500);
	me->start_busy(3);

        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	int extra;
	extra = me->query_skill("quanzhen-jian",1);
	me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
	me->add_temp("apply/dexerity",-extra/2);
        me->add_temp("apply/strength",-extra/2);
        me->add_temp("apply/damage",-(int)me->query_skill("quanzhen-jian",1)/2);
        me->delete_temp("qzj_tong");
        me->delete_temp("qzjtong");
	me->start_busy(1);
       tell_object(me, "���˹���ϡ�\n"); 
}

