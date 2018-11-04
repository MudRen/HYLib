#include <ansi.h>

inherit F_SSERVER;

int check_fight(object me, object target, object weapon, int skill);
void remove_effect(object me, object target, object weapon, int skill);

int perform(object me, object target)
{
        string msg;
	int skill = me->query_skill("yinlong-bian", 1);
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ƾ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query_skill("yinlong-bian",1) < 100)
                return notify_fail("��ľ��������޻�������죬����ʹ�ò��ƾ���\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return notify_fail("�������޷�ʹ�ò��ƾ���\n");

        if( me->query("neili") < 1500 )
                return notify_fail("�������������\n");

        if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	msg = HIG "$Nʹ�����ƾ�������һ����$n��˫�Ⱦ�ȥ��\n";

        me->start_busy(random(2)+1);
        if((random(me->query("combat_exp")) > target->query("combat_exp")/3) 
          )
        {
		msg += HIY "���$p��$Pһ�������ȱ����ʵʵ�����������ڵ����޷�����\n" NOR;
                target->start_busy(2);
		target->add_temp("apply/dodge", -skill/3);
		target->add_temp("apply/parry", -skill/3);
		target->add_temp("apply/armor", -skill/3);
		me->set_temp("jiuyin/chan", 1);
	        me->start_perform(1, "���ƾ�");
		remove_call_out("check_fight");
	        call_out("check_fight", 1, me, target, weapon, skill);
		remove_call_out("remove_effect");
	        call_out("remove_effect", skill/20, me, target, weapon, skill);
        } 
        else {
                msg += HIW "����$p������$P�Ĳ��ƾ�������һԾ��㿪�ˡ�\n" NOR;
	        me->start_perform(8, "���ƾ�");
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        me->add("neili", -1000);
        return 1;
}

int check_fight(object me, object target, object weapon, int skill)
{
        string msg;
        object wep;
	int neili, jiali;

        if (!me) return 1;
        if (!me->query_temp("jiuyin/chan")) return 1;

        if(!living(me) || !target){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "whip"){
           remove_effect(me, target, weapon, skill);
           return 1;
           } 
        if(environment(me) != environment(target)){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           
        if(wep != weapon){
           remove_effect(me, target, weapon, skill);
           return 1;
	   }
       if (userp(me) && me->query_skill_mapped("whip") != "yinlong-bian"){
           remove_effect(me, target, weapon, skill);
           return 1;
           }   
       if( me->query("neili") <= me->query_skill("yinlong-bian", 1)/2 ){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           

       target->start_busy(2);
       me->start_perform(3, "���ƾ�");
       if (!random(3) && me->query_skill("jiuyin-zhengong", 1) > 150) {
	   message_vision(HIB"$N����$n��æ����֮�ʣ���Ȼ����һ�С�\n"NOR, me, target);
	   me->add_temp("apply/attack", skill);
	   me->add_temp("apply/damage", skill*2);
	   neili = me->query("neili");
	   jiali = me->query("jiali");
	   me->set("jiali", me->query_skill("jiuyin-zhengong", 1));
	   weapon->unequip(); 
	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	   weapon->wield();
	   me->set("jiali", jiali);
	   me->set("neili", neili-100);
	   me->add_temp("apply/attack", -skill);
	   me->add_temp("apply/damage", -skill*2);
       }
       call_out("check_fight", 1, me, target, weapon, skill);
       return 1;
}       

void remove_effect(object me, object target, object weapon, int skill)
{
	if (!me->query_temp("jiuyin/chan")) return;
        me->delete_temp("jiuyin/chan");
	if (!target) return;
	message_vision(HIW"$n˫����һ�þ���������"+weapon->name()+"���������ӵ�������������\n"NOR, me, target);
	target->add_temp("apply/dodge", skill/3);
	target->add_temp("apply/parry", skill/3);
	target->add_temp("apply/armor", skill/3);
}
