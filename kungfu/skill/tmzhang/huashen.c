
// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int extra;
       if ( me->query_con()< 30 )
            return notify_fail(RED"�����첻��,ǿ���˹��Ầ���Լ�!\n"NOR);
    if (me->query("family/family_name") != "�������" )
        return notify_fail("�㲻��������̵��ӣ�����ʹ�����������\n");
        
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ǧ��ֻ�ܿ���ʹ�á�\n");		

        extra = me->query_skill("tmzhang",1);
        if ( extra < 70) return notify_fail(RED"��ġ���ħ�ơ����������죡\n"NOR);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIR"������ǧ��"+NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"+NOR);
       if( me->query("tmzhang")<100 )
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�����������ħ���裬һʱ�䣬��$n��Χ��ǧ��˫��Ӱ�У�\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"ħ"HIC"Ӱ"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������.\n"NOR,target);
                        target->start_busy(5);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�Ū�˸�ͷ���ۻ����ֽŶ�ʱ��������.\n"+NOR,me);
                        me->start_busy(2);
                  }
         }
      if( (me->query("tmzhang")<200)&&(me->query("tmzhang")>100) )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�����������ħ���裬һʱ�䣬��$n��Χ��ǧ��˫��Ӱ�У�\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/2) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"ħ"HIC"Ӱ"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������..\n"NOR,target);
                        target->start_busy(5);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�Ū�˸�ͷ���ۻ����ֽŶ�ʱ��������..\n"+NOR,me);
                        me->start_busy(2);
               }
                 }
          if( me->query("tmzhang")>200 )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�����������ħ���裬һʱ�䣬��$n��Χ��ǧ��˫��Ӱ�У�\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))

                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"ħ"HIC"Ӱ"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������...\n"NOR,target);

                        target->start_busy(6);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�Ū�˸�ͷ���ۻ����ֽŶ�ʱ��������...\n"+NOR,me);
                        me->start_busy(2);
               }
                 }

       me->receive_damage("jing", 100); 
       me->add("neili",-100);
        return 1;
}
