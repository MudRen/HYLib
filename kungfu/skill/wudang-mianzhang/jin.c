// jin.c �䵱����֮����
// By lius 99/8

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
  int i,j,p,k,z,damage;
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("���ƾ���ֻ����ս����ʹ�á�\n");       
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("�ȷ������е�������˵�ɣ�\n");
        if((int)me->query_skill("strike", 1) < 120 )
                return notify_fail("��Ļ����Ʒ�̫�ͣ��޷�ʹ������֮������\n");  
        if((int)me->query_skill("wudang-mianzhang", 1) < 120 )
                return notify_fail("������ƻ�������죬����ʹ������֮������\n");
        if ( me->query_skill_mapped("parry") != "wudang-mianzhang")
                return notify_fail("�㲻ʹ�����ƣ�������ʹ������֮��������\n");   
        if ( me->query_skill_mapped("unarmed") != "wudang-mianzhang")
                return notify_fail("�㲻ʹ�����ƣ�������ʹ������֮��������\n");   

        if( (int)me->query("max_neili", 1) < 500 )
                return notify_fail("��������Ϊ̫ǳ���޷��˾��˵У�\n");                
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("�������������������ܷ�������֮������\n");
        if( (int)me->query("shen", 1) < 50000 )
                return notify_fail("������а�����ģ����������Һ�Ȼ֮ȭ����\n");
        if(userp(me) && (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("��ı����ڹ��ȼ�����������Ӧ������֮������\n");
        if(userp(me) && (int)me->query_skill("taoism", 1) < 100 )
                return notify_fail("��ȭ�����ģ���Ե�ѧ�ķ������򲻹����ǲ�����������֮�����ġ�\n");
        if(userp(me) && me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("����ڹ��ķ����ԣ����Ӳ������ƾ���֮����\n");                                                                                     
        
  i=me->query_skill("strike",1)+me->query_skill("wudang-mianzhang",1)+me->query_skill("force",1);
  j=target->query_skill("parry",1)+target->query_skill("dodge",1)+target->query_skill("force",1);
  p =(me->query("combat_exp",1)-target->query("combat_exp"))/200000;		 
     z = i/10 - j/10 + p;
     if ( z < 3 ) z = 3;
     if ( z > 13 ) z = 13;
     k = random(z) + 4;

        message_vision(HIY"$N˫�������ߣ�Ʈ�ݲ���������ʮ��·�ྡྷ�е�"MAG"[ �� ]"HIY"�־�����$n��������ֱ�������\n"NOR,me, target);
         me->add("neili", -500);
         me->start_busy(3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	 if ( me->is_fighting(target) && me->query_skill("wudang-mianzhang", 1) > 140 && k > 3 ){
	 message_vision(MAG"$N����Ĭ����в��ܣ�˳�ƶ��¡������ƽ���$n�ؽڣ�������"HIG"[ �� ]"MAG"�Է����ţ�
$n��ʱ���Ƶ���æ���ҡ�\n"NOR,me, target);
	  if (!target->is_busy())
	  target->start_busy(5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
       }
	 if ( me->is_fighting(target) && !me->query_temp("mz_jin") && me->query_skill("wudang-mianzhang", 1) > 160 && k > 6 ){
	 message_vision(HIG"$N�������ĵĶ���һȭ������һ�ƣ�$nһ����Ӱ���������������ޣ����黹ʵ��������Ӱ��"WHT"[ �� ]"HIG"ס��
����һ����Ҳ�޷�ʩչ��\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	  me->set_temp("mz_jin", 1);
        target->start_call_out((: call_other, __FILE__, "remove_effect", target :),i/6);
        }
	 if ( me->is_fighting(target) && me->query_skill("wudang-mianzhang", 1) > 180 && k > 10 ){
	 message_vision(WHT"$N��$n��־��ʧ���Ż��󿪣������ٲ���ԥ��˫��һ�ϣ��ھ����£�"RED"[ �� ]"WHT"�־����֣���Ϊ��ʮ��·�ྡྷ
������һ�������ľ�š�\n"NOR,me, target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
		damage = i/3;	
		damage = damage/2 + random(damage);		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -(200+random(100)));}
        return 1;
}

void remove_effect(object target)
{
      if(!target) return;      
      target->delete_temp("mz_jin");
      return 0;
}
