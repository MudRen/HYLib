// �������
// sdong 11/11/98

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate, neili_cost, jingli_cost;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) )
         return notify_fail("�������ֻ����ս�����á�\n");

  if( target->query("eff_qi") < target->query("max_qi")/4 )
         return notify_fail("��Ķ��������˺����ۣ�ʹ�÷��������Υ��Ҵȱ�Ϊ���ı��⡣\n");

  if( target->query("qi") < target->query("max_qi")/6 )
         return notify_fail("��Ķ��������˺����ۣ�ʹ�÷��������Υ��Ҵȱ�Ϊ���ı��⡣\n");

  if( me->query_temp("yield") )
         return notify_fail("�㲻���֣����ʹ�ó�������գ�\n");
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     


  if( (skill = (int)me->query_skill("jinding-zhang", 1)) < 150 )
         return notify_fail("��Ľ����Ʋ�����죬����ʹ������ա�\n");

  if( (int)me->query_skill("linji-zhuang", 1) < 120 )
         return notify_fail("����ټ�׮����Ϊ����������ʹ�÷�����ա�\n");

  if( me->query_skill_mapped("force") != "linji-zhuang" )
         return notify_fail("�����õĲ����ټ�׮��ʹ����������գ�\n");

  jiali=(int)me->query("jiali");
  if( jiali < 50 )
         return notify_fail("������������ڼҹ������ϲ�������ʹ��������\n");

  if( me->query("neili") < 300 ) return notify_fail("������������ڼҹ����������������㣬ʹ������һ�С�\n");

  msg = HIY "\n$NͻȻ��ȫ������з����������ĵ���΢����֮���������������δ������������$n�ؿڻ�ȥ��\n\n"NOR;
  msg += HIG"��һ���Ƕ����ɵľ�ѧ��������������ա����⡰������ա����Ʒ���ֻһ�У�������\n";
  msg += HIG"һ��Ҳ�������仯����ʽƽƽ������һ�ɲ��䣬����������֮�����������Զ����ɾ���\n";
  msg += HIG"�ڹ���Ϊ������һ�Ƽȳ�����������ɽ����һ��Ϯ�������˵��޿ɵ������޿ɱܡ�\n\n";

// because hy2 can not jiajin, so update jiajin to jiali (by xbd)
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        if(damage > 5100) damage = 5100;
                        if(damage < 500) damage = 500;
                        me->add("neili", -damage/2 );
//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);
                        target->start_busy(1+random(3));

                msg += HIR"��������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
                }else if ( damage < 1000) {
                        msg += YEL"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ\n"NOR;
                }else if ( damage < 2000) {
                        msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;
                }else if ( damage < 3000) {
                        msg += RED"ֻ��һ�����죬$n������Ѫ���磬ȫ��������ѡ�\n"NOR;
                }else {
                        msg += RED"ֻ��һ�����죬$nȫ��������ѣ���������ɽ�������һ�������Ӵ�������ء�\n"NOR;
                }
                msg += NOR;
                me->start_busy(2);
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
                                &&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        damage = damage / 2;
                        if(damage > 5000) damage = 5000;
                        if(damage < 350) damage = 350;

                        me->add("neili", -damage/2 );
//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);
                        target->start_busy(1+random(3));

                        msg += HIY"$p�ۿ���һ���������ڣ�֪�����ڶԸ�����æ�����ֿ�����������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
                }else if ( damage < 1000) {
                        msg += RED"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ\n"NOR;
                }
                else msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
                me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
          random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        damage = damage / 3;
                        if(damage > 5000) damage = 5000;
                        if(damage < 250) damage = 250;

                        me->add("neili", -damage/2 );
//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);
                        target->start_busy(1+random(3));

                        msg += HIM"$p�ۿ���һ���������ڣ���æʹ�������������Ծ�����ɣ��������������̲ض�ü�ڼ��ϳ��ڹ���\n";
                        msg += "��Բ���ɶ��������𺳣�$pֻ���ú���һ���ѱ�������������.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
                }else if ( damage < 1000) {
                        msg += RED"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ��\n"NOR;
                }
                else msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
                me->start_busy(2+random(2));
  }
  else {
         msg += HIC"$n�ۿ���һ���������ڣ�ʹ��������������Ծ�����ɣ�\n\n"NOR;
         msg += HIW"$N��һ������ʹ����ȫ����˿��������ء�û�뵽ȫ���ô��������������ң�����΢΢������\n" NOR;
         neili_cost = jiali*3;
//         jingli_cost = me->query("jiajin")*2;
         if(neili_cost > me->query("neili")) 
                neili_cost = me->query("neili");
         if(jingli_cost > me->query("jingli"))
                jingli_cost = me->query("jingli")-1;
         me->add("neili", -neili_cost );
         me->add("jing", -jingli_cost );
         me->start_busy(3);
         message_vision(msg+"\n", me, target);
         return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}

