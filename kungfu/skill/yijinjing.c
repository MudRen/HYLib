// yijinjing.c ���� �׽��
// Feb.21 1998 by Java
#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/eff_msg.h";
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, oh, nh, ns, ts;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	oh = (int)me->query_skill("hunyuan-yiqi", 1);
	nh = (int)me->query_skill("yijinjing", 1);
	ns = (int)me->query("guilty");

        if ( oh < 100 )
		return notify_fail("��Ļ�Ԫһ��̫�ͣ��޷�ѧϰ�׽�񹦣�\n");
       	if ( me->query("couple/have_couple") )
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�׽�񹦣�\n");

	if ( me->query("gender") != "����" )
		return notify_fail("���ͯ��֮�壬������ϰ�׽�񹦡�\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷�����������׽�񹦡�\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����׽�񹦡�\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷�����������׽�񹦡�\n");

	if (
	me->query_skill("bahuang-gong",1)
         || me->query_skill("bingxue-xinfa",1)
         || me->query_skill("wudu-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�׽�񹦣���\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("�׽��ֻ����ѧ(learn)�������������ȡ�\n");
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"���Ϻ�����֣�����ׯ��" NOR,
    "start_my_msg" : "���������죬�ų�һ�������Ϣ˳��������������\n",
    "start_other_msg" : me->name()+"�������죬һ�Ṥ�򣬴ӿڱǴ������³�����������Խ��ԽŨ������������ȫ��\n",
    "halt_msg" : "$N����һ����������Ϣ�������˻�ȥ��վ��������\n",
    "end_my_msg" : "�㽫��Ϣ���˸�С���죬���ص���չ�վ��������\n",
    "end_other_msg" : "ֻ������"+me->name()+"�İ���������ɢ���ִӿڱǴ����˻�ȥ��\n",
    "heal_msg" : HIY"$N˫�ֺ�ʲ����ϥ�������������������䡱����ʼ�˹����ˡ�\n"NOR,
    "heal_finish_msg" : HIY"$N����վ��ֻ��ȫ��˵������������죬����������գ����գ����Ž���������¾�ѧ����\n"NOR,
    "heal_unfinish_msg" : "$N�³���Ѫ������վ�𣬵���ɫ�԰ף���������������\n",
    "heal_halt_msg" : "$Nһ�����������ӷ�˫��Ӷ���ѹ����Ϣ��վ��������\n",
    ]);
}
string *fanzhen_msg = ({
"ֻ���$n���ڸ��У���������һ�뷭ת��\n",
"���ȷ��𣬽�$n��������ֽ��ȫ��Ѫɫ��\n",
"���$n�ķ����ѣ�����������������\n",
"�����Ѳ���ȫ����$n�����������ȥ��\n",
"���$n������ת�������������߰˲���\n",
"��$nһײ��ֻ���$p�ؿ���Ѫ��ӿ��\n",
"$n����ײ��һ���޻����棬����Ϊ��ĺ�ǽ��һ�㣬����������\n",
"$n������$P��ͻȻ����һ�𣬵�ʱ���˳�ȥ��\n",
});


int ob_hit(object ob, object me, int damage)
{
        string msg;
        int p, skill, neili, neili1, i = 1;
        object weapon;
        skill = me->query_skill("yijinjing", 1);
        neili = me->query("neili") + 1 ;
        neili1 = ob->query("neili") + 1;
        
        if( skill > 300 )
		i += me->query_temp("combat_yield");

        if(living(me) 
        && me->query_temp("fanzhen") 
        && random(skill) * i + 30 > ob->query_skill("parry", 1)/2 
        && me->query("combat_exp") > ob->query("combat_exp")/2 
        && skill > 199 
        && neili > 500 
        && living(ob) 
        && !ob->query("env/invisibility")
        && random(3)==0)
        {
                if(!objectp(weapon = ob->query_temp("weapon"))){
                        me->add("neili", -(10+random(70)));
                        msg = random(2)?HIR"$N��������һ�ɷ���֮����":HIR"$N���Ͻ�ղ����������Ķ���";         
                        if(neili1 > neili*4*i || random(damage) > (5000 + me->query_con() * 40 * i)){
                                msg += "��ȴ��$n�ľ���һ�����飡\n"NOR;
                                damage = random(damage/2);
                        }
                        else if(neili1 > neili*3*i) {
                                msg += "��ȴ�����޷��赲$n�ľ�����\n"NOR;
                                damage = 0;
                        }
                        
                        else if(neili1 > neili*3/2*i){
                                msg += "��������˲���$n�ľ�����\n"NOR;
                                damage = -damage/2;
                        }
                        else{
                                msg += fanzhen_msg[random(sizeof(fanzhen_msg))]+NOR;             
                                p = (neili / neili1) * i;
                                if (damage <1) damage=1;
                                if( p < 1) p = 1;
                                p *= damage/2;
                                if(ob->query_skill("force") > me->query_skill("force")*3/2) p = p*2/3;
                                if(p < 10) p = 10;
                
if (ob->query("qi") > p)
{
                                ob->receive_damage("qi", p, me);
                                ob->receive_wound("qi", p/5*i, me);
}                               
                                if(wizardp(me)) tell_object(me, "Fanzhen damage: "+p+"��\n");
                                
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += "( $n"+eff_status_msg(p)+" )\n";
                                
                                damage = -8000+(-damage);
                        }       
                        message_vision(msg, me, ob);
                }
                else{
                        msg = HIR"������һ�����ε�ǽ��$N��ǰ�赲�ţ�";
                        switch(weapon->query("skill_type")) {
                                case "whip"   : p = 10; break;
                                case "sword"  : p = 8; break;
                                case "hook"   : p = 6; break;
                                case "blade"  : p = 5; break;
                                case "club"   : 
                                case "stick"  : p = 2; break;
                                case "staff"  : 
                                case "axe"    : 
                                case "hammer" : p = 1; break;
                                default       : p = 3; break;
                        }
                        p *= weapon->query("rigidity");
                        if( random(me->query("str") + p)*i > (ob->query("str")+p)/2 && neili*i > neili1*2/3) {
                                message_vision(HIR"���$N��������һ�ɷ���֮����$nֻ������һ�ȣ�" + weapon->name() + HIR"��ʱ���ֶ������ɳ����⣡\n\n"NOR, me, ob);
                                weapon->unequip();
                                weapon->move(environment(ob));
                                ob->reset_action();
                                ob->start_busy(2+random(3));
                                return -8000+(-damage);
                        }
                        else if(neili*i > neili1*2){ 
                                msg += "���$n"HIR"һ���ӱ����������"+ob->name()+HIR"�ֱ۷��飡\n"NOR;
                                ob->start_busy(1+random(3));
                                damage = -8000+(-damage);
                        }
                        else if(neili*i > neili1*3/2){ 
                                msg += "���$n"HIR"����ǰ��һ˿һ����\n"NOR;
                                damage = -5000+(-damage);
                        }
                        else if(neili*i > neili1){
                                msg += "���������$n"HIR"ǰ�����ٶȣ�\n"NOR;
                                damage = -damage*3/2;
                        }
                        else if(neili*2*i > neili1){
                                msg += "����û����ʲô���ã�\n"NOR;
                                damage = 0;
                        }
                        else{
                                msg += "��ȴ��$n"HIR"һ�´��ƣ�\n"NOR;
                                damage = random(damage/2);
                        }
                        message_vision(msg, me, weapon);
                }
                return damage;
        }
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string attack_skill)
{
	int skill;
	int i = 1,j;	

	if(!me->query_temp("fanzhen") && !me->query_temp("sl/jiuyang"))
		return 1;
	
	skill = me->query_skill("force");

	i = damage_bonus * (skill+1) / 1000;
	i = i/2+ random(i);
	if(me->query_temp("weapon"))
		i = i*3;
	if(me->query_temp("apply/damage")>=100)
		i = i/3;
        if (i<1) i=1;
	if(wizardp(me)) tell_object(me,sprintf("hit_ob: %d  ",i));
	j = me->query_skill("yijinjing",1)/20;	
        if (j<1) j=1;
	if (random(2)==0)
{
	message_vision(HIR"$N"+HIR+"����һ����ţ������ھ�����������˫�ۣ�������֮�ƹ���$n��\n" NOR, me,victim);
victim->receive_damage("qi", 10+3*random(j), me);
victim->receive_wound("qi", 10+3*random(j), me);
}	
	//i = i + ::force_hit(me,victim,damage_bonus,factor,attack_skill);

	return i;
} 


string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}
