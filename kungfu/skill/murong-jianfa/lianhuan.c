#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
 int i=me->query_skill("murong-jianfa",1)/5;
    int j=me->query_skill("canhe-zhi",1)/5;
    int d=me->query_skill("shenyuan-gong",1)/5;  
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("�߽�����ָֻ�ܶ�ս���еĶ���ʹ�á�\n");                

        
        if( (int)me->query_skill("murong-jianfa", 1) < 100 )
                return notify_fail("��Ľ�����δ���ɣ�����ʹ���߽�����ָ��\n");        
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("������û�н����޷�ʹ���߽�����ָ��\n");
        if((int)me->query_skill("canhe-zhi", 1) < 100 )
                return notify_fail("���ָ����δ���ɣ�����ʹ���߽�����ָ��\n");        
        if(me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("��û����ָ���޷�ʹ���߽�����ָ��\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("�������������㣬����ʹ���߽�����ָ��\n");
        if((int)me->query_temp("lianhuan"))
                return notify_fail("������ʹ���߽�����ָ��\n");      
        if (me->query_skill("shenyuan-gong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

        if((int)me->query_skill("sword", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ���߽�����ָ��\n");
        if((int)me->query_skill("finger", 1) < 100 )
                return notify_fail("��Ļ���ָ��������죬�����ڽ�����ʹ���߽�����ָ��\n");
        message_vision(MAG"\n$Nʹ���߽�����ָ������һת������ʳָ���ŵ�����ֻ������ָ�������ӳ��ֱϮ$n��\n"NOR, me,target);
        me->add("neili", -50); 
        me->add("jing", -50);      
        me->set_temp("lianhuan", 2+me->query_skill("murong-jianfa", 1)/40);
   me->add_temp("apply/attack", (i+j)/3*2);
    me->add_temp("apply/damage", d);
    call_out("check_fight", 1, me);
        return 1;
}

void remove_effect(object me)
{
    int i=me->query_skill("murong-jianfa",1)/5;
    int j=me->query_skill("canhe-zhi",1)/5;
    int d=me->query_skill("shenyuan-gong",1)/5;   
    me->add_temp("apply/attack", -(i+j)/3*2);
    me->add_temp("apply/damage", -d);
    me->delete_temp("lianhuan");
      }

void check_fight(object me)
{
    object weapon;      

    if (!me) return;
    if (!me->is_fighting()||!me->query_temp("lianhuan")){
    tell_object(me, HIY"��ġ��߽�����ָ������������ϣ����ص���,�����չ�");
    remove_effect(me);
    return;
    }
   if (me->query_skill_mapped("finger") != "canhe-zhi"
     ||me->query_skill_prepared("finger") != "canhe-zhi")
     {
   tell_object(me, HIR"����ʱ�Ļ��书,��������ʹ�á��߽�����ָ������");
   remove_effect(me);
   return;
    }
    if(me->query_skill_mapped("parry") != "canhe-zhi")
      if(me->query_skill_mapped("parry") != "murong-jianfa")
     {
   tell_object(me, HIR"����ʱ�Ļ��书,��������ʹ�á��߽�����ָ������");
   remove_effect(me);
   return;
    }
    call_out("check_fight", 1, me);
}
