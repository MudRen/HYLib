// yinyang-shiertian.c ����ʮ������
// ��ʮ��֮ǰͨ�������񹦡������񹦡���ڤ�񹦡��貨΢����Ǭ
// ����Ų�ơ�����ʮ���ƺ������񽣣�����Ϊһ������S+++����ѧ��
// ����ʮ��������Լ���Ϊ�������е��书��
// Edit By Vin On 15/2/2001 

#include <ansi.h>

inherit FORCE;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", });

string *attack_name = ({
"������������", "������������", "�����޼�����", "�����޼�����", });

string *dodge_msg = ({
        HIW "$n" HIW "�������һ�Σ�$N" HIW "��Ȼ�޷�������ֻ���Ա���\n" NOR,
        HIW "ֻ��$n" HIW "��������ζ���$N" HIW "��ǰ��ʱ������������$n" HIW
        "�Ļ�Ӱ����$N" HIW "��ȫ�޷������ʵ��\n" NOR,
        HIW "$n" HIW "���Ա�����бб������һ����ȴǡ����$N" HIW "�Ĺ���ʧ֮"
        "���塣\n" NOR,
        HIW "$N" HIW "��һ�����ĺÿ죬Ȼ��$n" HIW "һ�����ƺ����Ѱ��������"
        "ȴ��$N" HIW "��һ�иպñܿ���\n" NOR,
        HIW "����$n" HIW "����һԾ���Ѳ�������Ӱ��$N" HIW "���д󺧣�ȴ�ּ�"
        "$n" HIW "���籼��������֮���ɣ���������˼�����ǡ�\n" NOR,
});

string *parry_msg = ({
        HIW "$N" HIW "һ�л���$n" HIW "���ϣ�ȴ��$n" HIW "����Ǭ����Ų���ھ�"
        "������������������¡�\n" NOR,
        HIW "$n����һ����$N" HIW "�����Լ������ػ��������ŵ������˼�����\n" NOR,
        HIW "$n�ֱۻ�ת����$N" HIW "����������һ�ƣ�$N" HIW "������ա�\n" NOR,
        HIW "$n�����������$N" HIW "����������һ����$N" HIW "���Ʋ�ס��ֱ��ǰ��ȥ��\n" NOR,
        HIW "$n���β�����$N" HIW "һ�л��£�����ʯ���󺣣�������ס�ˡ�\n" NOR,
        HIW "$n��ǣ������$N" HIW "��������������ת�˺ü���Ȧ��\n" NOR,
        HIW "$n˫�ֻ�Ȧ��$N" HIW "ֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n" NOR,
        HIW "$n����һת��$N" HIW "һ�л��ڵ��ϣ�ֻ��ó������\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("yinyang-shiertian", 1);
        return lvl * lvl * 15 * 40 / 100 / 200;
}

mapping *actionf = ({
([      "action": HIW "$N" HIW "������ָһ�����������񽣡���ǰ�̳��������ĵ�����"
                  "Ȼ���죬���ν���ֱָ$n" HIW,
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 550,
        "weapon": HIW "�������ν���" NOR,
        "damage_type":  "����"
]),
([      "action": HIR "$N" HIR "����һ�࣬һ�����������һ�ɳ����ޱȵ�������ʱ��"
                  "��ӿ��$n" HIR "ȫ�����",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 550,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": HIY "$N" HIY "����һת��ȭͷЯ�ż�����ת�������ӳ����������磬"
                  "��������������$n" HIY,
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 550,
        "weapon": HIY "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": WHT "$N" WHT "˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ��������ʮ����"
                  "������$n" WHT "ȫ�����",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "weapon": WHT "�����޼���" NOR,
        "damage_type": "����"
]),
([      "action": HIW "$N" HIW "˫��ʮָ���죬��ʮ���������ٳ�Ѩ�м������������"
                  "���񽣡�������磬ָ��$n" HIW,
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 550,
        "weapon": HIW "�������ν���" NOR,
        "damage_type":  "����"
]),
([      "action": WHT "$N" WHT "ͻȻ���η���˫�ƾӸ�����һ�С�����ʮ���ơ��ں�"
                  "Х����Ѹ���ޱȵ�����$n" WHT "ȫ�����",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "weapon": WHT "�����޼���" NOR,
        "damage_type": "����"
]),
});

mapping *actionw = ({
([      "action": HIY "$N" HIY "���ƺ��������裬$w" HIY "�仯�޳���׽��������$n"
                  HIY "������ȥ",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "���е�$w" HIY "ͻ������ɭ�ϣ�����ǧ�������۶�"
                  "������ͬ����һ���ɨ$n" HIY,
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "�������е�$w" HIY "����������һ�����$n" HIY "��"
                  "�����ң�û�а���·�",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "����$w" HIY "�û���һ��һ��ԲȦ���ƺ�Ҫ��$n" HIY
                  "���Ű�Χ",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "��Ц��ת$w" HIY "������һָ���ĵ��黨ָ֮�⣬��"
                  "��$n" HIY "ȫ��",
        "force" : 500,
        "attack": 50,
        "dodge" : 50,
        "parry" : 50,
        "damage": 500,
        "damage_type": "����"
]),
});

string main_skill()
{
        return "yinyang-shiertian";
}


int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        tell_object(me, HIW "һ�󷲳�����ӿ����ͷ���㼸��������̾�����Ǽ䣬����ۻ��ף�����һ��Ī��\n"
                        "�ı�������ʦ̩�����ָ߳���ʤ������̩ɽ��С����֮����Ȼ��������ֻ������\n����"
                        "��ѧ���ڿ����Ƕ�ô����С��Ц��\n" NOR);
        return 1;
}


string *usage_skills = ({ "unarmed", "strike", "claw", "hand", "cuff", "finger",
                          "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
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

       if( me->query("zhuanfinal/7",1) != 1)
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

        for (i = 0; i < sizeof(usage_skills); i++)
                if (me->query_skill(usage_skills[i], 1) < level)
                        return notify_fail("���" + to_chinese(usage_skills[i]) + "����⻹"
                                           "�������޷������������������ʮ�����졣\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("����ʮ�����첩����޷��򵥵�ͨ����ϰ������\n");
}

int difficult_level()
{
        return 3000;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name1, name2, weapon;
	weapon = me->query_temp("weapon");
        name1 = xue_name[random(sizeof(xue_name))];
        name2 = attack_name[random(sizeof(attack_name))];

if (weapon) return;
if( me->is_busy() && random(3)==0) return;
        victim->receive_wound("qi", damage_bonus * 3, me);
                if ((int)me->query("neili",1) < (int)me->query("max_neili",1) )
{
        me->add("neili", me->query("jiali") / 2);
}
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

if (random(6)==0)
{
	if (!victim->is_busy())
			victim->start_busy(3) + random(3);
return HIR "$n��$N����������ͬʱ����������Ѩ����ֻ����ȫ���ʹ�������ھ������Ĵ��Ҵ�,һʱ��Ȼ�޷����ƣ�\n" NOR;
}
else        if (random(5)==0)
        {
                victim->receive_wound("qi", (damage_bonus ) , me);

                return random(2) ? HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                                   "�߹Ƕ��۵�������\n" NOR:

                                   HIR "$n" HIR "һ���ҽУ���ǰ���������꡹������"
                                   "�죬������Ѫ���硣\n" NOR;
        }
else        if (victim->query("neili") < 500)
                victim->set("neili", 0);
        else
                victim->add("neili", -300);
        return NOR + HIR "$n" HIR "����$N" HIR "һ�У�" + name2 + "��ʱ�����"
               "�룬ȫ��������" + name1 + "��к������\n" NOR;
}

int ob_hit(object ob, object me, int damage, object weapon)

{
               string result;
       int ap, dp;

	weapon = me->query_temp("weapon");
        ap = ob->query_skill("parry");
        dp = me->query_skill("yinyang-shiertian", 1);
if (weapon) return damage;
if (me->query_skill_mapped("parry") != "yinyang-shiertian") return damage;
if( me->is_busy() && random(2)==0) return damage;
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
                if ((int)me->query("neili",1) < (int)me->query("max_neili",1)*2 )
                me->add("neili", me->query("max_neili") / 8);
	result = HIY"$Nʹ�������ɾ�!!$NͻȻ�����ָ���!\n"NOR;
}
if (random(6)==0)
{
	if (!ob->is_busy())
			ob->start_busy(2);
result = HIW "$n" HIW "�溬΢Ц������һ���ѽ��������н�������ȫ��������\n" NOR;
}
else        if (random(5)==0)
        {
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 10);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/10);
                        result = HIC "$n" HIC "������̾�����Ǽ䣬���ϵ���"
                                            "�������������£����˺ܶࡣ\n" NOR;

        }
else        if (random(ap * 2 / 3) < dp * 3 / 2 || random(3)==1)
        {
//                result = ([ "damage": -damage ]);
                damage=10;
                        result = HIW "$n" HIW "һ����ߣ�����΢΢һ������"
                                            "ƮȻԶȥ��ʹ$N" HIW "�Ľ���ȫ���ô���\n" NOR;
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
        }
if (result && ob && me)
message_vision(result,ob,me);

return damage;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("yinyang-shiertian", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("yinyang-shiertian", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

string perform_action_file(string action)
{
        return __DIR__"yinyang-shiertian/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"yinyang-shiertian/exert/" + action;
}

