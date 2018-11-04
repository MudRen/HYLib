#include <ansi.h>
#include <ansi.h>;
inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *dodge_msg = ({
        "$n΢΢һ������ȻԶȥ��ʹ$N�Ľ���ȫȻ���á�\n",
        "$n��ʱ��ƽ����������������ȣ�ʹ$NȫȻ�޷����ա�\n",
        "$n����һ�ˣ���ȥ�����κ�׷����\n",
        "$n�㲻��أ���֫�Ͱڣ���Ȼ��$N�Ľ���ȫ�������\n",
});

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 

string *parry_msg = ({
"$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨡�\n",
"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
"$n�ӻ���ȡ��һ��ѩ�׵ĳ���������Ĩ��Ĩ������ֱ������Ϸ̨�ϵĻ�����$Nһ������ͣס���Լ�����ʽ��\n"
});

string  *msg = ({
"$N����һ�䣬��������۵�$n��ǰ����಻��һ�ߣ�����$w�Ѿ��̵�$n��$l",
"������Ӱ������$N���е�$w��$n��$lֱ�����������籼�ף��ܲ��ɱ�",
"$N������ϣ�������$n�ļ���һ���ٺ�ɳ�ȥ�������е�$wȴָ��$n��$l",
"$NͻȻԾ�����࣬$nһ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�Ӻ�Ϯ��",
"$N��һ������һ������һ������һ������$n��������������������һת������$n",
"�����$N���������ϣ�˫�����õ��ģ���������֮������$n����֮�ʵ���$w����$n",
"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ�������һ������$n������֮��֮�죬ֱ�Ƿ�����˼",
"$N����һ�٣�վ��Ƭ�̣�����$n����󷽻������࣬���ſ������׵Ļص�ԭ��",
"$NǱ���������������ˣ�����$n������ת������$w��ʹ����Ҳ��������һ�㣬Խ��Խ��",
"ͻȻ$N����$w����һ�ã�����$n΢һ����֮��ֱȡ$n��$l���Ƶ���������"NOR,
"����$nһ��֮�ʣ�$N����Ծ�����ߣ���������أ����Ӹ�������ˢˢ��������$n��ȥ",
"$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n������$w�û�������ֱ��$n��$l",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
"$Nһ����У����������ڰ����һת������ޱȵķ�������������$w�ƿ�ֱ��$n$l",
"$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n������$w���Ī�⣬ֱ��$n��$l",
"$N������������ȣ�Ʈ����ȥ��ֱ�����̣����е�$wȴ���Ƕ���$n����",
"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n����Ѳ���һ�ߣ����˵ı��Ӽ���Ҫ����һ��",
"$N�����������$n������Ѹ���ޱȵ�һ���������ֱۻ�ת������$n������һ��",
"$Nһ��ͦ�̣��������ţ���̬֮�У������л�ɽ��Ů������ѧ����Ů��ʮ��ʽ���ķ��ˣ�ֻ�Ǵ���������ɭɭ��а��",
"$N����һȦ����ת$w����ش̳���ˢˢˢ������ʽ�����о���ָ��$n��Ҫ��"
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "force" || usage =="parry"; 
}
mapping query_action(object me, object weapon)
{               
       return ([
          "action":msg[random(sizeof(msg))],
          "attack":30,
          "damage":(random(6)+2)*100,
          "damage_type": "����",
          "dodge": random(180)+30,
          "force":(random(500)+150),
       ]);
}
string query_parry_msg()
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        if ((int)me->query("neili") < 1500)
                return notify_fail("�������������\n");
       if (((int)me->query_skill("kuihua-feiying", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("��Ŀ�����Ӱ��̫���ˡ�\n");
       if (((int)me->query_skill("kuihua-xinfa", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("��Ŀ����ķ�̫���ˡ�\n");

       if (((int)me->query_skill("tmdao", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");

       if (((int)me->query_skill("tmjian", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("tmzhang", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("tmdafa", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("changquan", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("��ĳ�ȭ̫���ˡ�\n");

        if ((int)me->query_skill("pixie-jian", 1) < 180)
                return notify_fail("��ġ���а���������̫ǳ��\n");

    if ( (string)me->query("gender")=="Ů��" )
        return notify_fail("Ů�Ӳ���ѧ.\n");

   if ( (string)me->query("gender")=="����" )
        return notify_fail("��������Թ�,������.\n");

        return 1;
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query_skill("pixie-jian", 1) < 180)
                return notify_fail("��ġ���а���������̫ǳ��\n");
       if ((int)me->query_skill("kuihua-dafa", 1) < 180)
               return notify_fail("�㻹û���������񹦵ľ��裬����������ϰ��\n");
       if (((int)me->query_skill("kuihua-feiying", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("��Ŀ�����Ӱ��̫���ˡ�\n");
       if (((int)me->query_skill("kuihua-xinfa", 1)+100) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("��Ŀ����ķ�̫���ˡ�\n");
       if (((int)me->query_skill("tmdao", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("tmjian", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("tmzhang", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("tmdafa", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("�����ħ��̫���ˡ�\n");
       if (((int)me->query_skill("changquan", 1)+200) < (int)me->query_skill("kuihua-dafa", 1))
               return notify_fail("��ĳ�ȭ̫���ˡ�\n");


    if ( (string)me->query("gender")=="Ů��" )
        return notify_fail("Ů�Ӳ���ѧ.\n");

   if ( (string)me->query("gender")=="����" )
        return notify_fail("��������Թ�,������.\n");

       if ((int)me->query("jing") < 130)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 70)
               return notify_fail("������������ˡ�\n");
       me->receive_damage("jing", 80);
       me->add("neili", -50);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-dafa/" + action;
}

string exert_function_file(string func)
{
       return __DIR__"kuihua-dafa/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
        object weapon;
        string name;
 int i,attack_time,isok;
 int level, level2;
        int ap, dp, mp;
         level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
 weapon = me->query_temp("weapon");

        ap = (int)me->query("combat_exp");
        dp = (int)victim->query("combat_exp");
if (me->query_skill_mapped("force") != "kuihua-xinfa")
return;

if (me->query_skill_mapped("sword") != "kuihua-dafa")
return;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return;
if (me->query("neili") < 500)
return;
if (!weapon) return;
        if (me->query_temp("weapon"))
	        name = "����" + weapon->name();
        else
	        name = "˫��";

        attack_time = (int)(me->query_skill("kuihua-dafa", 1) / 60);

        if (attack_time > 6)
                attack_time = 6;

        if (me->is_busy()
           || random(3) == 0
           || ! living(victim)
           || damage_bonus < 120
           || me->query("neili") < 300
           || me->query_temp("action_flag") == 1
           || me->query_skill("kuihua-dafa", 1) < 200)
        	return 0;

        // ������ʹ��PfmʱѶϢ�ظ�
if (!me->query_temp("action_flag") && random(ap) > dp/3 && random(2)==0)
{
        if (! me->query_temp("kuihua-mogong/hit_msg"))
	        message_vision(HIW "\n��ʱ��ֻ��$N" HIW "�����Ͱڣ���ʱ����Ϊ������Ӱ��" + name +
        	               HIW "\n�������ǰ�ִӲ�ͬ�ķ�λͬʱ����$n" HIW "��\n"
                	       NOR, me, victim);

	//me->start_busy(2);
        //me->add("neili", -attack_time * 20);
        me->set_temp("action_flag", 1);
        for (i = 0; i < attack_time; i++)
        {

                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}
isok=0;
if (level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
isok=1;	
}
if (weapon)
{
   if( random(me->query_str()) > victim->query_str()/3 || isok=1){
	victim->receive_wound("qi", me->query_str()+random(100));
	 return HIR "ֻ�����͡�һ����һ��Ѫ˿��"+victim->name()+"���̵���״������\n" NOR;
	}
}



}



int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        object wp1;
        int skill, neili, neili1;
        int level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "һ����Ц! ���Ǵ�!! " HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
       
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
        j=damage;
if (me->query_skill_mapped("force") != "kuihua-xinfa")
return damage;
if (me->query_skill_mapped("sword") != "kuihua-dafa")
return damage;


if (me->query("neili") < 500)
return damage;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
return damage;

             if (random(ap) > dp/3 && random(2)==0 )
             {
                switch (random(4))
                {
                case 0:

                        result = HIW "$N" HIW "�۾�һ����$n" HIW "��û����"
                                            "Ӱ��ͻȻ$n" HIW "���������һ��$N" HIW "��"
                                            "ͷ������Ծ����\n" NOR;
                        break;
                case 1:
                        result = HIW "$N" HIW "��ǰһ�����ƺ�����$n" HIW "��"
                                            "��һ�Σ����漴�ּ�$n" HIW "�ص�ԭ�أ�ȴ��"
                                            "��δ�뿪��\n" NOR;
                        break;
                case 2:
                        result =  HIW "$n" HIW "��Хһ������Ȼ����һת�Ѳ�������Ӱ��$N" HIW
                                           "ֻ�����߷������ϣ����漴�ּ�$n" HIW "�ص���ԭ�ء�\n" NOR;
                        break;
                case 3:
                        result =  HIW "$n" HIW "��Хһ������Ȼ����һת�Ѳ�������Ӱ��$N" HIW
                                           "ֻ�����߷������ϣ����漴�ּ�$n" HIW "�ص���ԭ�ء�\n" NOR;
                        break;

                default:
                        result = HIW "��Ȼ�䣬ֻ��$n" HIW "��֦һ�ڣ���ʱ����������"
                                            "$n" HIW "��Ӱ�ӣ�$N" HIW "ȴ�޷�����$n" HIW "�ķ�λ��\n" NOR;
                        break;
                        }
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi"))
me->add("qi",damage/5);
if ((int)me->query("eff_qi") < (int)me->query("max_qi"))
me->add("eff_qi",damage/5);
                    message_vision(result,ob,me);
             }
             
            return j;
}
