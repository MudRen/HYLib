// ��������
#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N����ƽƽ�̳�һ����ʵ���Ǻ����κα仯����ȴ�к��֮����$nֻ��һ�ɴ�����$wֱ������",
"$N���Ծ�����潣�𣬽�������֮����������һ������$n�������ڽ���֮��",
"$N��̾һ�������ֺ���һ��������ָ��$n��������˿���仯��ȴ���ý������裬����ƽ����
�̺����б仯������ʤ����",
"$NѸ������һ��������������磬�������磬�޿ɵ��棡�˽�֮�죬������˼���޷��ֱ潣·ȥ��",
"$N���׳�Х������Ʊ�ã������������һ��ƽָ������������$n���������$nֻ����
���κ���֮�У������и���$N�������纣��һ�㣬һ��һ������ӿ�������Ӳ�����������ǿ",
"$N����$w��������ɽ���������ǰ���ͺ�һ�������ǽ�������ġ�����ʽ�����������ǽ�Ӱ��
����ǧ��������ֻ��$n����ζ�",
"$N����ʮ�ལ��һʱѸ�������ǻ��գ�һʱ���سٻ��������޼���Ѱ��ƽ�������ַ�˼������
˳�̣�������������������޲��ǽ��������ţ����淵�ӹ��棬ȴ�Ѳ��ٴ��κ�����",
});
string *parry_msg = ({
        "$n�Թ����أ�$vֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
        "$nʹ��һ�С��������ġ�����ȫ�������$v�γɵĽ�Ļ�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
});
int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(2)+2)*220,
                "damage_type":random(2)?"����":"����",
                "dodge":(random(2)+2)*50,
                "force":(random(2)+2)*220
        ]);
}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 550 )
                return notify_fail("�������������û�а취������������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xuantie-sword/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,flvl;
        object weapon = me->query_temp("weapon");

        lvl  = me->query_skill("xuantie-sword", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "yunv-xinfa" )
                return;
        if (lvl < 120 ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
 if (random(2)==0)
        {
flvl=random(lvl)+50;
        if (random(3)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-random(lvl));
victim->add("eff_qi",-random(lvl));
}
                return HIR "$n" HIR "������ɨ��Ҫ������Ѫ�ɳ�!!\n" NOR;

}                        }
        if (damage_bonus < 50
           || lvl < 160
           || random(2)
              || ! objectp(weapon)
           || me->query("neili") < 500
           || me->query_skill_mapped("sword") != "xuantie-sword"
      		 || me->query_skill_mapped("force") != "yunv-xinfa")
      		return damage_bonus / 4;

        if (lvl / 2 + random(lvl) > victim->query_skill("parry", 1) || random(10)==0)
        {
                me->add("neili", -100);
                victim->receive_damage("qi", damage_bonus * 4 / 5+10, me);
                victim->receive_wound("qi", damage_bonus * 4 / 5+10, me);
      
                return HIW "$N" HIW "����" + weapon->name() + HIW "����������������£�����"
                       "�ɵ�������$n" HIW "�����ƻֺ�֮����\n" NOR;
         }
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
int practice_skill(object me)
{
        if( (int)me->query("qi") < 60
        ||      (int)me->query("neili") < 55 )
                return  notify_fail("�����������������û�а취��ϰ����������\n"
);
        if(me->query_skill("xuantie-sword",1)>100)
        	return notify_fail("������ֻ��ͨ��learn���������������\n");
        me->receive_damage("qi", 50);
        me->add("neili", -55);
        write("�㰴����ѧ����һ������������\n");
        return 1;
}
