// yitiantulong.c ����������֮[��������]��
// by yfeng 2000.1.27

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int		ap,dp,damage,improve;
	string msg;
	object weapon = me->query_temp("weapon");
	object weapon1;
	int cost = me->query_skill("yitian-tulong", 1);
	
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!living(target))
		return notify_fail("�Ը����ܶ�����ҲҪ�á�������������\n");
	if(!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������ʹ�á�������������\n");
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

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");

	if(me->query_temp("yttl/yttl"))
		return notify_fail("���ʹ���꡸������������Ъ����˵�ɡ�\n");
	if( (int)me->query_skill("yitian-tulong", 1) < 120 )
		return notify_fail("�������������������죬����ʹ�á�������������\n");
	if( me->query("neili") <= 400+cost*3 )
		return notify_fail("�������������\n");
	if( me->query("jing") <= 120+cost*2 )
		return notify_fail("��ľ�������\n");
	if( me->query("max_neili") < 1200)
		return notify_fail("���������Ϊ�������޷�ʹ�á�������������\n");
	if(me->query("jing")<100+cost)
		return notify_fail("�����ھ��񲻺ã��޷�ʹ�á�������������\n");
	if(me->query_temp("combat_yield"))
		return notify_fail("�㲻����������ʹ�á�������������\n");
	if (me->query_skill_mapped("sword") != "yitian-tulong")
		return notify_fail("�������޷�ʹ�á�������������\n");
	if (me->query_skill_mapped("dodge") != "tiyunzong")
        return notify_fail("�����ʹ�á������ݡ�������Ϊ������������ʹ����������������\n");   
    if( (int)me->query_skill("tiyunzong",1) < 120 )
    	return notify_fail("��������ݲ�����죬�޷�ʹ�á�������������\n");
    if( (int)me->query_dex() < 28 )
    	return notify_fail("�����̫�ͣ�����ʹ�á�������������\n");
    if( (int)me->query_skill("dodge",1) < 120 )
    	return notify_fail("��Ļ����Ṧ̫����屿׾������ʹ�á�������������\n");
    if( me->query_temp("zong")   )
      return notify_fail("������ʹ�á������ݡ���\n");
	if(userp(me))
	{
		if( (int)me->query_skill("taiji-shengong", 1) < 140 )
			return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�������������\n");
		if( me->query_skill_mapped("force") != "taiji-shengong")
			return notify_fail("�����õ��ڹ��޷��ݶ������������������У�\n");
	}
	message_vision(HIW"\n$N��һ�������͵���˫��һ�ţ�������������������࣬����ʹ���������ݡ��������ҽ��ڿ���ƾ��һ�ţ���Ž��������ҽ���һ���������������ɣ�\n"NOR,me);
	improve = (int)me->query_dex() * 2;
	me->add_temp("apply/dodge", improve);
	me->add_temp("apply/attack",improve/2);
    me->set_temp("zong",1); 
    me->set_temp("yttl/yttl",1); 
    me->receive_damage("neili", (350+(int)me->query_skill("tiyunzong",1)/10));    
	call_out("remove_effect",30+random(30),me,improve);
	ap = me->query_skill("sword")*me->query_skill("force")*me->query_skill("dodge")/10+me->query("combat_exp");
    dp = target->query_skill("parry")*target->query_skill("force")*target->query_skill("dodge")/10+target->query("combat_exp");
    damage=me->query_skill("yitian-tulong",1)+me->query_skill("taiji-shengong",1)+me->query_skill("tiyunzong",1);
    weapon1=target->query_temp("weapon");
    if(ap*2/3+random(ap/3)>dp/2+random(dp/2))
    {
    	me->start_busy(1);
        target->start_busy(3);            
		msg=HIC"\nֻ��$N����$w"+HIC"��׼$n�������ͼ�����������������Լ����һ�����䡹�֡�\n";
		msg+=HIR"$n��ǰһ�����ѿ�����$N����ʽ��";
		if(weapon1)
			msg+="��æ�佫����"+weapon1->name()+HIR"���迪������ס�Լ���ǰ�ġ�\n\n";
		else 
			msg+="���������ұܣ����в�֧��\n\n";
		msg+=HIC"$Nһ����д�꣬���ӱ�Ҫ���¡�ֻ��$P���ֻӳ���$w"+HIC"���գ�ٿ��һ����\n";
		if(weapon1)
			msg+=HIC"ֻ����������һ����$w"+HIC"��$n��"+weapon1->name()+HIC"��һ�㣬֧ס���ӵ�������";
		else
			msg+=HIC"ֻ�����ۡ���һ����$w"+HIC"���ô̽�$n����磬ͬʱֹס��׹�����Σ�";
		msg+="�����������ָ�����д�˸����֡��֣�\n�������ֵ�һ��һ�����������������ᡢ�������ƣ����ɷ��裬�����۽�������һ��һ�ƣ�ȴ����콣��ꪣ�ɭȻ��ͬ�� \n";
		msg+=HIR"$n��Ҳ�ֵ���ס$N�Ĺ��ƣ����项��һ������һ������$n�ؿڣ�$n������ȴ������ߵķ���һ�㣬��󵹷ɳ�ȥ��\n"NOR;
		msg=replace_string(msg,"$w",weapon->name());
		message_vision(msg,me,target);
		target->receive_damage("qi",damage*(1+random(3)));
		me->receive_damage("neili",cost*2);
	    COMBAT_D->report_status(target);
		msg=HIC"\n$N������д�գ�������д�������֣������֡�ԽдԽ�죬����������˸�������������ڣ�������������\n��Ʈ�����꾪�쪣��仨��ѩ��ãã���л����Ź��񾪣�ʱʱֻ�������ߡ��������ʮ����һ��д�ϡ�\n";
		if(ap*2/3+random(ap/3)>dp/2+random(dp/2))
		{
	    	msg+=HIR"���ʮ����һ���ǳɣ���ʮ����һ����ͨ��$n����Խ��Խ���ң���֧��׾�������Ѳ�֪���˶��ٽ���\n"NOR;
			target->receive_wound("qi",100+damage);
			me->receive_damage("neili",100+cost);
			message_vision(msg,me,target);
			COMBAT_D->report_status(target);
			message_vision(HIW"\n$Nд�����桹�ֵ����һ�ʣ�"+weapon->name()+HIW"�ڵ�����һ�����������£��������ɵ�վ����\n"NOR,me,target);
	    	return 1;
		}
		message_vision(msg,me,target);
		message_vision(CYN"����$N�������У������˳��������֮�⣡\n"NOR,target);
		me->start_busy(2);
		return 1;
	}
	message_vision(CYN"$nһ����ͬС�ɣ�����˼����һ��칥���Ƶ�$N����ʽ�޷�ʹ����\n"NOR,me,target);
	me->start_busy(3);
	return 1;			
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/attack", - improve/2);
      me->delete_temp("zong");
      me->delete_temp("yttl/yttl");
      
}
