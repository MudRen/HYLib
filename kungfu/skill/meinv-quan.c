// meinv-quan.c ��Ůȭ
// By Lgg,1998.9
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$Nʹһ��"+(order[random(13)])+"��������ġ�"NOR" ��˫�۽������",
        "force" : 180,
        "dodge" : 50,
        "damage":125,
        "lvl" : 0,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ��Ϊ"+(order[random(13)])+"�����ҹ����"NOR"�����䲻���ߵ��ֱ�룬��$n���һ��",
        "force" : 200,
        "dodge" : 50,
        "damage": 140,
        "lvl" : 10,
        "skill_name" : "���ҹ��",
        "damage_type" : "����"
]),
([      "action" : "$N��ʽһ���"+(order[random(13)])+"������׹¥��"NOR"���˵ع������̣�ίʵ�Ѳ�",
        "force" : 230,
        "dodge" : 115,
        "damage": 100,
        "lvl" : 22,
        "skill_name" : "����׹¥",
        "damage_type" : "����"
]),
([      "action" : "$N˫���������£��������಻���ĳ���ԭ����"+(order[random(13)])+"���ļ��麺��"NOR"��������
ʮ����",
        "force" : 270,
        "dodge" : 115,
        "damage": 160,
        "lvl" : 34,
        "skill_name" : "�ļ��麺",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"�����ߵ��С�"NOR"���Կ��������֮����$n���б��ж�ȥ",
        "force" : 320,
        "dodge" : 110,
        "damage": 170,
        "lvl" : 48,
        "skill_name" : "���ߵ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ"+(order[random(13)])+"��ľ���乭��"NOR"�������籧���£����ּ��Ӷ�������$nĿ�ɿڴ�
",
        "force" : 380,
        "dodge" : 125,
        "damage": 182,
        "lvl" : 60,
        "skill_name" : "ľ���乭",
        "damage_type" : "����"
]),
([      "action" : "$N��Ȼ�����������£�˫�ƴӲ���˼��ĽǶȹ��˹�����ԭ����һ��
"+(order[random(13)])+"���༧��ʫ��"NOR"",
        "force" : 450,
        "dodge" : 115,
        "damage": 194,
        "lvl" : 71,
        "skill_name" : "�༧��ʫ",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"���������ˡ�"NOR"����֫��ڱܿ��������Ż��ƹ���$n��ǰ��",
        "force" : 530,
        "dodge" : 120,
        "damage": 200,
        "lvl" : 82,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ���Լ�ͷ����һ�ᣬ��������Ļ��˳�ȥ������΢΢һЦ��ȴ
��һ��"+(order[random(13)])+"��������װ��"NOR"��",
        "force" : 530,
        "dodge" : 220,
        "damage": 210,
        "lvl" : 95,
        "skill_name" : "������װ",
        "damage_type" : "����"
]),
([      "action" : "$N��$n��ס����ָ������ȴ��һ��"+(order[random(13)])+"��Ƽ������"NOR"��",
        "force" : 530,
        "dodge" : 110,
        "damage": 111,
        "lvl" : 109,
        "skill_name" : "Ƽ������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ������üͷ������"+(order[random(13)])+"���������ġ�"NOR"��˫�����Լ��ؿڹ���",
        "force" : 530,
        "dodge" : 120,
        "damage": 224,
        "lvl" : 129,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����������ѻ������������������ˮ��Ư��һ�㣬ȴ��һ��"+(order[random(13)])+"������
΢����"NOR"",
        "force" : 530,
        "dodge" : 120,
        "damage": 250,
        "lvl" : 149,
        "skill_name" : "����΢��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"�������ǡ�"NOR"���������Լ�����б��һ�ƣ�����������������
�������಻��",
        "force" : 530,
        "dodge" : 120,
        "damage": 300,
        "lvl" : 179,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"���������¡�"NOR"������һ�ӣ���$n��$l��ȥ����Ե��$n��$lһն",
        "force" : 150,
        "dodge" : 30,
        "damage": 211,
        "lvl" : 5,
        "skill_name" : "��������",
        "damage_type" : "ն��"
]),
([      "action" : "$N˫ȭ���أ���������ʹһ��"+(order[random(13)])+"����ʩ���ġ�"NOR"����$n��$l��ȥ",
        "force" : 250,
        "dodge" : 25,
        "damage": 211,
        "lvl" : 15,
        "skill_name" : "��ʩ����",
        "damage_type" : "����"
]),
([      "action" : "$N����б�٣�������ָ���𣬷��Ƶ�ϰ����һ�㣬"+(order[random(13)])+"���Ѿ�������"NOR"��ָ�ַ���
$n��ȥ", 
        "force" : 300,
        "dodge" : 20,
        "damage": 211,
        "lvl" : 25,
        "skill_name" : "�Ѿ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ����˫�ֺ�ȭ����̧ȥ��һ��"+(order[random(13)])+"��������١�"NOR"����$n���°�",
        "force" : 320,
        "dodge" : 15,
        "damage": 211,
        "lvl" : 35,
        "skill_name" : "�������",
        "damage_type" : "ײ��"
]),
([      "action" : "$Nʩ��"+(order[random(13)])+"����Ů֯��"NOR"�����ֻ����������ң���Ͷ��֯��֮״��һ��һ�ͣ�
����$l",
        "force" : 370,
        "dodge" : 10,
        "damage": 211,
        "lvl" : 45,
        "skill_name" : "��Ů֯��",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ��"+(order[random(13)])+"�����촹����"NOR"������ǰ�ˣ�˫���Դ���֮������������ն��$n��˫��",
        "force" : 150,
        "dodge" : 30,
        "damage": 211,
        "lvl" : 55,
        "skill_name" : "���촹��",
        "damage_type" : "����"
]),
([      "action" : "$N��¶΢Ц��������ͷ��һ�ᣬ��ָ��"+(order[random(13)])+"��������ױ��"NOR"������ӽ���ȥ������$n
���ؿ�",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "������ױ",
        "lvl" : 65,
        "damage": 211,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֻ��ģ�����������ٲȻһ��"+(order[random(13)])+"��������ġ�"NOR"���ַ�����$n$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "�������",
        "lvl" : 75,
        "damage": 211,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��Ū���"NOR"��һָ���죬һָ�Եأ���Ŀ���ף���Ȼ�������������
$nȫ��Ҫ��",
        "force" : 500,
        "dodge" : 5,
        "damage": 311,
        "lvl" : 85,
        "skill_name" : "Ū����",
        "damage_type" : "����"
]),

});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry" || usage=="cuff"; }
int valid_combine(string combo) { return combo=="tianluo-diwang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ůȭ������֡�\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 10)
                return notify_fail("�����Ů�ķ���򲻹����޷�ѧ��Ůȭ��\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("�������̫�����޷�ѧϰ��Ůȭ��\n");
        return 1;
}



string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("meinv-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int i,l;
	l = (int)me->query_skill("meinv-quan", 1) / 4;
	i=me->query("per");
	i=i-20;
	if (i=0) i=2;
	if (i<0) return 0; 
	if (me->query("gender") == "����") return 0;
	if(!random(5) && me->query_skill_mapped("parry") == "meinv-quan" && (me->query("neili")>200) && me->query_skill("meinv-quan", 1) > 60)
      {
        if (me->query("gender") == "Ů��") {
	    message_vision(MAG "ֻ��$N�������裬����ƮƮ��Ʈ���鶯��������Ů�·��������ޱȡ�\n" NOR, me,victim );	
		} else {
	    message_vision(MAG "ֻ��$N����ƮƮ�����ֻ��裬һ��һʽ�����ޱȣ������������ɡ�\n" NOR, me,victim );	
			}
		 	
		if (me->query("gender") == "Ů��") 
		if (victim->query("gender") == "����") {
	    victim->start_busy(1+random(i)/2);
        me->add("neili",-30);
	    message_vision(CYN "$n���ɵô��ˣ��ó�����Ľ�ĵ��۹⿴��$N��\n" NOR, me, victim );
		 } else return RED "$n�ƺ���$N��������Ȥ��\n" NOR;
		  
		if (me->query("gender") == "����") 
		if (victim->query("gender") == "Ů��") {
		victim->start_busy(1+random(i)/2);
        me->add("neili",-30);
		message_vision(CYN "$n���ɵô��ˣ��ó�����Ľ�ĵ��۹⿴��$N��\n" NOR, me, victim );
		 } else if (victim->query("gender") == "����") {
        victim->start_busy(3+random(i)/2);
        me->add("neili",-40);
		message_vision(CYN "$nͻȻ��̬����$N���ó���ɫ�����۹�����Ŀ����㣡\n" NOR, me, victim );
		 } else return RED "$n�ƺ���$N��������Ȥ��\n" NOR;
	   
	if((me->query("neili") > 60) && (!victim->query_temp("yunu/beauty")) )
                 {
message_vision(MAG"\n$N��������������֧�ã���������ӳ�����̾һ�������ּ���֮�⡣\n"NOR,me);
                        victim->add_temp("apply/attack", -l);
                        victim->add_temp("apply/defense", -l);
                        victim->add_temp("apply/dodge", -l);
                        me->add("neili", -80);
                        victim->set_temp("yunu/beauty", 1);
                        call_out("reset_temp", l/10, me, victim); 
                        return 1;       
                }
    }	
 } 
int reset_temp(object me,object victim)
{
        int a = (int)me->query_skill("meinv-quan", 1)/4;
    if (!victim) return 0;
         victim->add_temp("apply/attack", a);
	     victim->add_temp("apply/defense", a);
         victim->add_temp("apply/dodge", a);
         victim->delete_temp("yunu/beauty");
		 message_vision(CYN "$n����ͻȻһ�壬�ָ�����Ȼ��\n" NOR, me, victim );
		 return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˣ�������ϰ��Ůȭ��\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"meinv-quan/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"�������ߣ��ж����������಻����һ��δ�ϣ������� !$n˫��һ����֪���룡\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"Ŀ��һ����һ��������ӳ� !$n һ�����ģ����������˼�ö��\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      
