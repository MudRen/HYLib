// never-defeated.c ������
#include <ansi.h>
inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *dodge_msg = ({
        "$n�ƿ�������ǡ�ö����$N�Ĺ�����\n",
        "$n��Ȼ������ֱָ$N���������Ƶ�$Nֻ�ܻ��ء�\n",
        "$n�������ܣ���$N��ʵ��ȫ�������\n",
        "$n����һ�����ԣ��ƺ����⣬ȴ�պö��$N��һ����\n",
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("never-defeated", 1);
        return lvl * lvl * 20 * 15 / 100 / 200;
}

mapping *action_default = ({
([      "action":"$N�������Ž���������̤��һ��"+(order[random(13)])+"�������롱"NOR"����б�̣�$w��ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "����"
]),
([      "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ���������"+(order[random(13)])+"����
ħ����"NOR"��"+(order[random(13)])+"������ʽ��"NOR"��",
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "����"
]),
([      "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ��"+(order[random(13)])+"���ٱ�ǧ������ʮ��ʽ��"NOR"����
ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
        "force" : 630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "����"
]),
([      "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ������"+(order[random(13)])+"��������Ȫ��"NOR"ֱ��$n
��$l��",
        "force" : 625,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "����"
]),
([      "action" : "$N������$n�ӳ�"+(order[random(13)])+"��Ȫ��ܽ�ء�"NOR"��"+(order[random(13)])+"�������ϸǡ�"NOR"��"+(order[random(13)])+"��ʯ��������"NOR"��"+(order[random(13)])+"��
����������"NOR"��"+(order[random(13)])+"�����ף�ڡ�"NOR"��ɽ���񽣣�",
        "force" : 630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "����"
]),
([      "action": HIG"$N�������һ����â������$wʹ��"RED"�������޹���"NOR""HIG"������ǵذ㹥��$n"NOR,
        "force" : 640,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "����"
]),
([      "action" : HIW"�� ��������! ��"+HIY"$NͻȻ��ʧ�ˣ����$w�ķ����������$n��ͷ�ϡ�"+HIY"$N��Ȼ�ڰ��ʹ���˰ε����� "NOR,
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "����"
]),
([      "action" : HIC"�����콣������!��"+HIW"$N����С̫��,������ˮ��ʽ�̳�,�����ٱ�����,˲������С� "NOR,
        "force" : 620,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type":  "����"
]),
([      "action":HIY"$N�������ߣ�$w"+HIY"��һ��δ�ϣ������������г���ʱ�������󣬽��еֵ�ʱ����ת�ң����ƽ��ǽ��������ˣ������ⲻ������$n��֮������Ȼ��"NOR,
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "����"
]),
([      "action":HIW"$N���˼�������������������$w"+HIW"Ʈ����ȥ��������������һ·��Ů��������ʹ��Ӣ��ˬ�ʣ��������ˣ�"NOR,
        "force" : 630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type":  "����"
]),
([      "action" : HIW "$N��Ʈ�ݣ���̬��Ȼ������������У�����$w" HIW "�����������������"
                   "�Ž��ѵ����շ�����ľ���",
        "force" : 620,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 990,
        "damage_type":  "����"
]),
});

mapping *action_whip = ({
([      "action" : "$N�����ھ������߶����ڹ�ʩչ�������쾡�£�$w��Х��������$n���ŵ�ȥ������δ����$w����Ю��������$nһ������",
        "force" :630,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type": "����"
]),
([      "action": "$N�����ھ������߶����ڹ�ʩչ�������쾡�£�$w��Х��������$n���ŵ�ȥ������δ����$w����Ю��������$nһ������",
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type": "����"
]),
([      "action": "$N���ذα�������׹�⣬һʽ"+(order[random(13)])+"�������̡ܴ�"NOR"�������鶯���ͣ���ʵ����������������˷���$n��ѹ��ȥ",
        "force" : 640,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 695,
        "damage_type": "����"
]),
([       "action": HIR "$N����һ�������������$w������º�$n����һ��һ����ɽ�������ھ�����Ϣ����$n�ؿ�ײȥ��"NOR,
        "force" : 625,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 690,
        "damage_type": "����"
]),
([     "action": HIR "$N������$w������Ȧ������$nԽתԽ����ԽתԽ�죬$p��ʱ�����������׵���ת�˼����ۿ���Ҫˤ����"NOR,
        "force" : 610,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 990,
        "damage_type": "����"
]),
});

string *usage_skills = ({ "sword", "blade", "dagger",
                          "staff", "hammer", "club", "whip",  
                          "dodge", "parry", "force", "throwing" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_combo(string combo)
{
        return combo == "never-defeated";
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        switch (weapon ? weapon->query("skill_type") : "default")
        {
        case "whip":
                return action_whip[random(sizeof(action_whip))];
        default:
                return action_default[random(sizeof(action_default))];
        }
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( me->query("zhuanfinal/8",1) != 1)
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

        
        if (me->query("int") < 38)
                return notify_fail("����ò����񹦹�����£���"
                                   "���Լ�������������⡣\n");

	if (me->query("gender") == "����" &&
	    (int)me->query_skill("never-defeated", 1) > 239)
		return notify_fail("���޸����ԣ���������������������Ĳ����񹦡�\n");

        level = me->query_skill("never-defeated", 1);


        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        if (me->query_skill("parry", 1) < level)
                return notify_fail("��Ի����мܵ���⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        if (me->query_skill("dodge", 1) < level)
                return notify_fail("��Ի����Ṧ����⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        if (me->query_skill("sword", 1) < level)
                return notify_fail("��Ի�����������⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        if (me->query_skill("blade", 1) < level)
                return notify_fail("��Ի�����������⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        if (me->query_skill("whip", 1) < level)
                return notify_fail("��Ի����޷�����⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        if (me->query_skill("throwing", 1) < level)
                return notify_fail("��Ի�����������⻹�������޷�����"
                                   "��������Ĳ����񹦡�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����񹦲�����޷��򵥵�ͨ����ϰ������\n");
}

int difficult_level()
{
        return 500;
}

string perform_action_file(string action)
{
        return __DIR__"never-defeated/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"never-defeated/exert/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("never-defeated",1);
        level2= (int) me->query_skill("never-defeated",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
if( me->is_busy() && random(3)==0) return;
//if (!level) return;
if (!level2) return;
if (!jiali) jiali=10;

if (me->query("zhuanfinal/1") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->receive_wound("qi", victim->query("qi")/8);
        if (!userp(victim))
         victim->receive_wound("qi", 500);
	return RED"$Nʹ����ն�ɾ�!!$nͻȻ�ؿ�һʹ��Ѫ��!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->add("neili", -victim->query("neili")/8);
        if (!userp(victim))
         victim->add("neili", -500);
	return HIY"$Nʹ�������ɾ�!!$nͻȻ������ʧ!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!victim->is_busy())
	victim->start_busy(4);
	return HIY"$Nʹ�������ɾ�!!$nͻȻ��æ����!\n"NOR;
}
else

	if( random(level2)>40 
	&& random(2)==0 ) {
	victim->receive_damage("qi", (random(jiali)+150));
	victim->receive_wound("qi", (random(jiali)+150));
	return RED"ֻ��$n$l����Ѫ�񱼣��ѱ�"+weapon->name()+HIR"ն���������������˿���!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
                       string result;
       int ap, dp;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("never-defeated", 1);

        if( !weapon) return damage;
if (me->query_skill_mapped("parry") != "never-defeated") return damage;
        if( me->is_busy() && random(2)==0)  return damage;
        //if( damage < 10 )  return damage;

if (me->query("zhuanfinal/4") ==1 && random(3)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	result = HIY"$Nʹ�������ɾ�!!$Nȫ����˺��˺ܶ�!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!ob->is_busy() )
ob->start_busy(2);
	result = HIY"$Nʹ���˶��ɾ�!!$NͻȻ�����ֿ���!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	result = HIY"$Nʹ�������ɾ�!!$NͻȻ�����ָ���!\n"NOR;
}

else
 if ( random(8)==1)
        {
                damage=30;
                switch (random(4))
                {
                case 0:
                        result = HIW "$n" HIW "�溬΢Ц������һ���ѽ���"
                                            "�����н�������ȫ��������\n" NOR;
                        break;
                case 1:
                        result = HIW "$n" HIW "üͷ΢΢һ�壬��Ҳ��������"
                                            "$N" HIW "��һ�ߡ�\n" NOR;
                        break;
                case 2:
                        result = HIW "$n" HIW "����΢΢һ�����ѽ�$N" HIW 
                                            "�����������⡣\n" NOR;
                        break;
                default:
                        result = HIW "$n" HIW "һ����ߣ�����΢΢һ������"
                                            "ƮȻԶȥ��ʹ$N" HIW "�Ľ���ȫ���ô���\n" NOR;
                        break;
                }
if (ob && me)
message_vision(result,ob,me);
            return damage;
        }
}
