#include <ansi.h>
inherit F_SSERVER;
void attack_1();
void attack_2();
void attack_3();
void finish();
int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ��콣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (me->query_skill("kuangfeng-jian",1) < 150 )
        ||      (me->query_skill("huashan-neigong",1) < 150 ) ) 
                return  notify_fail("��Ĺ��򻹲�����죬����ʹ�ÿ��콣��\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "sword"
        ||      me->query_skill_mapped("sword") != "kuangfeng-jian" ) 
                return  notify_fail("�������޷�ʹ�ÿ��콣��\n");

        if( me->query("neili") < 1300 )
                return notify_fail("�������������\n");
        if( me->query("jing") < 500 )
                return notify_fail("��ľ�������\n");
      if( me->query_temp("kuangfeng"))
                return notify_fail("���������ÿ��콣�ˣ�\n"); 


        me->start_perform(7,"���콣");
        msg = HIG "$N����һ����Х��б�ж�ǰ��" + weapon->name() + HIG"����ֱ����Ѹ���ޱȣ�δ�������У��������ѷ�������������\n"NOR;

  me->set_temp("kuangfeng", 20);
// busy �ڸ��� callout ��������
        me->start_busy(2);
        message_vision(msg, me, target);
        call_out("attack_1",3);
        me->add("jing", -200);
        me->add("neili", -500);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;
      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n$N����һ������һ����������ķ���ҲԽ��Խǿ��\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_2",3); } else
      call_out("finish",1);
}

void attack_2()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n$N��������������һ�ɾ���������չ��\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_3",3);} else
      call_out("finish",1);
}

void attack_3()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n�Թ�����ֻ���������ˣ����ϡ����ϱ�����ε��������ۣ����������ĺ��ˣ�\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_4",3);} else
      call_out("finish",1);
}

void attack_4()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n�����������ϵ��´��������Ƶ�����Ʈ����������ķ������н�������֮�ơ���\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_5",3);} else
      call_out("finish",1);
}

void attack_5()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
      me->add("apply/attack",100);
      me->add("apply/parry",100);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

         message_vision(HIG"�Թ����˲��������ĺ��ˣ�Χ���භ�������ܵ�Ȧ�ӽ�������\n"NOR, me, target);
      me->start_busy(1);
      call_out("finish",1);} else
      call_out("finish",1);
}

void finish()
{
      object me = this_player();
if (!me) return;

 me->delete_temp("kuangfeng");
      message_vision(HIY"$N�⡰���콣��ίʵ�켫��һ�������Ƭ�̼����ʹ�ꡣ\n"NOR, me);
}

