// guangming.c ����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
string *songs = ({"����֮��������","�����˷δݸγ�","���뾫ʧ����","������������Ƿ���"});

string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
}); 

string *limb=({
"����","����","����","ͷ��","С��","�ؿ�","����","�ɲ�","�Ҽ�","�ұ�","�ҽ�",
});
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count, i;
	int skill;
        int damage,p;
      string song;                                   
        string name,dodge_skill,limbs;
      song = songs[random(sizeof(songs))];
        if( !target) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��û��װ��������\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("qishang-quan", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("shenghuo-ling", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyang-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ������ѧ��ʹ�������̵ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

	skill = me->query_skill("jiuyang-shengong", 1);
        message_combatd(HIR "$N" HIR "Ĭ������񹦵Ŀھ���\n��"
                            "ǿ����ǿ��\n����ɽ�ԡ�\n���������ᣬ\n"
                            "�����մ󽭡���\nɲ�Ǽ�ֻ��$N" 
                        HIR "ȫ���ʱ���ֳ�һ����͵ľ�������$P"
                        HIR "ȫȫ���֡�\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill);
	me->add_temp("apply/strength", skill/3);
	weapon = me->query_temp("weapon");
if (random(3)==0) target->start_busy(3);
        msg =  HIW  "$N���һ������" + HIR "���Ҳ���������ʥ��" + HIW"����������������ʱ���ܿ�������\n$n���Ӳ���һ��" NOR;
   	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIR  "$N���г���������"HIR"���Ҳ���������ʥ������λ�������ο�"HIC"��" NOR;
      	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIY "$N���г���������"HIR"Ϊ�Ƴ���Ψ�����ʡ�ϲ�ֱ���Թ鳾��"HIC"��" NOR;
      	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIC "$N���г���������"HIR"�������ˣ��ǻ�ʵ�࣡�������ˣ��ǻ�ʵ��"HIC"����\n" NOR;
   	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill);
	me->add_temp("apply/strength", -skill/3);

	me->start_busy(4);
        msg = HIC"\n$N���һ����"HIR"Ϊ�Ƴ���Ω�����ʣ�ϲ�ֱ���Թ鳾��"HIC"��"+weapon->query("name")+HIC"���˺϶�Ϊһ��\n��������ɱ������$n��\n"NOR;

        if(((random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3)
         )
         ||!living(target)){
              limbs= limb[random(sizeof(limb))];
              msg +=CYN"$nֻ����������·��������˵�ɱ�����֣����޿ɱܣ����ɴ�ʧɫ����ʱ��ǰһ��\n��"+weapon->query("name")+CYN"�Ѵ���"+limbs+"����������\n"NOR;
              damage = (int)me->query_skill("sword");
              damage += (int)me->query_skill("jiuyang-shengong");
              damage *= 5;
              if(damage > 6500) damage = 6500;
              target->receive_damage("qi", damage/2);
              target->receive_wound("qi", damage/2);
              p = (int)target->query("qi")*100/(int)target->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
         if(  me->query_skill("shenghuo-ling",1 ) > 100
){
              name = xue_name[random(sizeof(xue_name))];
              msg += HIC"\n$N��������ǰһ�����˶Է�����֮�ʣ����ֱ���Ϊӥצ֮�ƣ�\n��������ץ��$n��"+name+"��\n"NOR;
           if( random(me->query("combat_exp")) > target->query("combat_exp")/3
             ){
              target->receive_wound("qi", damage/2);
               msg +=CYN"���$n��"+name+"��ץ�����ţ�ȫ����������һ������ʱ���ɶ�����\n"NOR;
           }
           message_vision(msg, me, target);
         }
         }
        message_vision(msg, me, target);
      message_vision(HIR"\nͻȻ$N���侫�⣬����������Ƹ�Ǹ衢��ʫ��ʫ��ȭ������"+song+"������������ǰȥ�����һȭ����$n��\n"NOR,me, target);

     if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 
         ){         
            target->receive_damage("qi", me->query_skill("force")/2);            
                 target->apply_condition("qishang_poison", 30+target->query_condition("qishang_poison"));
            if(me->query("neili")*2 < target->query("neili"))  
                 tell_object(me, HIR"��ֻ��"+target->name()+"����������ǿ���㰵����ȭ�ڵĸ������������Ͳ���ȥ��\n"NOR);
            else{
                 tell_object(me, HIW"�ڸ�һ����"+target->name()+"������ʱ����㰵������������������ȭ�ڵ������������˹�ȥ��\n"NOR);
                 tell_object(target, HIW"��һ���ۣ�ֻ��"+me->name()+"��ȭ�Ѿ�����������ϣ����ż���˵�����İ���˳�ƴ��˹�����\n"NOR);
                }
            target->receive_damage("qi", me->query_skill("force")*2);    
            p = (int)target->query("qi")*100/(int)target->query("max_qi");
            msg = damage_msg(me->query_skill("force")*3, "����");
            msg += "( $n"+eff_status_msg(p)+" )\n";                
            } 
            else 
               {       
                msg = "ֻ��$p����һת���Ѿ��Ƶ���$P��󡣶�$Nȴ������ղ��ܿ��ƣ�ͷ��ѣ�Σ�\n";
               }
            message_vision(msg, me, target);
 	return 1;
}