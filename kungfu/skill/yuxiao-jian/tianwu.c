// tianwu.c �������

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int dodge, parry, attack, sword, force;

        weapon = me->query_temp("weapon");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽����������á�������衹����\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");

        if( me->query_skill("yuxiao-jian",1) < 200 )
                return notify_fail("�����｣����Ϊ����������δ���򡸷�����衹��\n");

        if( me->query_skill("bibo-shengong",1) < 180)
                return notify_fail("��ı̲�����Ϊ���δ����ʩչ��������衹ֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("�����õ��ڹ��롸������衹�ķ���㣣�\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ��������衹��\n");

        if( me->query("neili") < me->query("max_neili") )
                return notify_fail("�����������������������ʩչ��������衹��\n");

        if( me->query("jing") <= 100 )
                return notify_fail("��ľ������ޣ�������ʩչ��������衹��\n");
        
        if( me->query("eff_qi") < me->query("max_qi"))
                return notify_fail("�������״��ʩչ��������衹������������Σ�գ�\n");
        
        
        dodge = target->query_skill("dodge");
        parry = target->query_skill("parry");
        attack = sword = (dodge+parry)/2;
        force = me->query_skill("force");

        message_vision(HIR"\n$N��Хһ����ǿ�������嵤���ٻᣬ��̼����߰�Ѩ��һ����ͨʮ�����������أ���ɫ�����Ѫ�������Ȼ��Ѫ˿�߳���\n",me);
        message_vision(HIG"$N���ܾ������䣬���г���������������죬����"+weapon->name()+HIG"�������������������������ͣ�������������ȫȻ��������Σ��\n" NOR, me);
        me->add("neili", force*20);
        me->start_busy(2);
        me->add("jiali", force/5);
        me->add_temp("apply/dodge", dodge);
        me->add_temp("apply/parry", parry);
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/sword", sword);
        me->add_temp("apply/speed", dodge);
        call_out("remove_effect", sword/15, me, dodge, parry, attack, sword);

        me->set_temp("yuxiao/tianwu", 1);

        return 1;
}

void remove_effect(object me, int dodge, int parry, int attack, int sword)
{
        me->add_temp("apply/dodge", -dodge);
        me->add_temp("apply/parry", -parry);
        me->add_temp("apply/attack", -attack);
        me->add_temp("apply/sword", -sword);
        me->add_temp("apply/speed", -dodge);

        message_vision(RED"\n$N������Ѫ���磬��ɫ�԰ף��������������˼������ˡ�\n" NOR, me);
        me->delete_temp("yuxiao/tianwu");
        me->start_busy(2);
        me->set("neili", 100);
        me->set("jiali", 0);
        me->add("jing", -100);
        me->receive_damage("qi", 500);
        me->receive_wound("qi", 500);
        
}
