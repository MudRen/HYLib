#include <ansi.h>
inherit F_SSERVER;
void attack_1();
void attack_2();
void attack_3();
void finish();
void finish_2();
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������˫�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (me->query_skill("jiuyin-shenzhang",1) < 150 )
        ||      (me->query_skill("jiuyin-zhengong",1) < 150 ) ) 
                return  notify_fail("��Ĺ��򻹲�����죬����ʹ������˫�ơ�\n");

        if( me->query("neili") < 5000 )
                return notify_fail("�������������\n");

        me->start_perform(20,"����˫��");
        msg = HIG "$Nʹ������˫�ƣ����Ƶ�ʱ��$n�����ס��\n"NOR;

        me->start_busy(20);
        target->start_busy(20);
        message_vision(msg, me, target);
        call_out("attack_1",5);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target = offensive_target(me);
      if (!target) return;
      message_vision(HIY"$N��$n���ɼ���������������ƴ��\n"NOR, me, target);
      me->add("neili",-(target->query_skill("force")));
      target->add("neili",-(me->query_skill("force")));
      if (me->query("neili")<=0||target->query("neili")<=0) {
      if (me->query("neili")<=0) {
              message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,me);
              me->set("neili",0);
              me->receive_wound("qi",target->query_skill("force")); }
      if (target->query("neili")<=0) {
              message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,target);
              target->set("neili",0);
              target->receive_wound("qi",me->query_skill("force")); }
      call_out("finish",1); } else
      call_out("attack_2",5);
}

void attack_2()
{
      object me = this_player();
      object target = offensive_target(me);
if (!target) return;
      message_vision(HIY"$N��$n����ı�������Լ�ǿ��������ʩΪ��\n"NOR, me, target);
      me->add("neili",-(target->query_skill("force")*3));
      target->add("neili",-(me->query_skill("force")*3));
      if (me->query("neili")<=0||target->query("neili")<=0) {
      if (me->query("neili")<=0) {
              message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,me);
              me->set("neili",0);
              me->receive_wound("qi",target->query_skill("force"));}
      if (target->query("neili")<=0) {
              message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,target);
              target->set("neili",0);
              target->receive_wound("qi",me->query_skill("force"));}
      call_out("finish",1); } else
      call_out("attack_3",5);
}

void attack_3()
{
      object me = this_player();
      object target = offensive_target(me);
if (!target) return;
      message_vision(HIY"$N��$n����ͷ����ð����ˮ��������������ȫ���Թ���\n"NOR, me, target);
      me->add("neili",-(target->query_skill("force")*5));
      target->add("neili",-(me->query_skill("force")*5));
      if (me->query("neili")<=0||target->query("neili")<=0) {
      if (me->query("neili")<=0) {
              message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,me);
              me->set("neili",0);
              me->receive_wound("qi",target->query_skill("force"));}
      if (target->query("neili")<=0) {
              message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,target);
              target->set("neili",0);
              target->receive_wound("qi",me->query_skill("force"));}
      call_out("finish",1); } else
      call_out("finish_2",5);
}

void finish()
{
      object me = this_player();
      object target = offensive_target(me);
if (!target) return;
      message_vision(HIY"$N��$n�������ã�ֹͣ�˶��ƣ�������ֹ��\n"NOR, me,target);
}

void finish_2()
{
      object me = this_player();
      object target = offensive_target(me);
if (!target) return;
      message_vision(HIY"$N��$n���Դ��һ����ֹͣ�˶��ƣ��˿����ߡ�\n"NOR, me,target);
}
